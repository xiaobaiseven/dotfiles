#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpd/client.h>

// --- 配置 ---
#define MAX_DISPLAY_LEN 50 

/**
 * UTF-8 截断函数 (防止中文乱码)
 */
void truncate_utf8(char *src, int max_len) {
    if (!src) return;
    
    int len = strlen(src);
    int char_count = 0;
    int i = 0;

    while (i < len && char_count < max_len) {
        unsigned char c = src[i];
        int bytes = 1;
        
        // 判断 UTF-8 字节长度
        if ((c & 0x80) == 0) bytes = 1;       // ASCII
        else if ((c & 0xE0) == 0xC0) bytes = 2;
        else if ((c & 0xF0) == 0xE0) bytes = 3; // 中文通常是3字节
        else if ((c & 0xF8) == 0xF0) bytes = 4;

        i += bytes;
        char_count++;
    }
    
    // 截断
    src[i] = '\0';
}

int main() {
    struct mpd_connection *conn;
    struct mpd_status *status;
    struct mpd_song *song;
    
    const char *artist;
    const char *title;

    // 1. 连接 MPD
    conn = mpd_connection_new(NULL, 0, 3000);

    // 检测连接错误 (MPD未运行)
    if (mpd_connection_get_error(conn) != MPD_ERROR_SUCCESS) {
        printf("MPD未运行");
        mpd_connection_free(conn);
        return 1; 
    }

    // 2. 获取状态
    status = mpd_run_status(conn);
    if (!status) {
        printf("获取状态失败");
        mpd_connection_free(conn);
        return 1;
    }

    // 3. 检查是否正在播放
    if (mpd_status_get_state(status) != MPD_STATE_PLAY) {
        printf("MPD未播放音乐");
	mpd_status_free(status);
        mpd_connection_free(conn);
        return 0; 
    }
    mpd_status_free(status);

    // 4. 获取歌曲信息
    song = mpd_run_current_song(conn);
    if (!song) {
        mpd_connection_free(conn);
        return 0;
    }

    // 5. 提取标签
    title = mpd_song_get_tag(song, MPD_TAG_TITLE, 0);   // 先获取标题
    artist = mpd_song_get_tag(song, MPD_TAG_ARTIST, 0); // 后获取艺术家

    // 兜底处理
    if (!title) {
        title = mpd_song_get_uri(song); // 没标题用文件名
    }
    if (!artist) {
        artist = "未知艺术家"; 
    }
    if (!title) {
        title = "未知标题";
    }

    // 6. 格式化输出: "歌曲标题 - 艺术家" (顺序已交换)
    char buffer[512];
    snprintf(buffer, sizeof(buffer), "%s - %s", title, artist);

    // 7. 截断
    truncate_utf8(buffer, MAX_DISPLAY_LEN);

    // 8. 输出结果
    printf("%s", buffer);

    // 9. 清理资源
    mpd_song_free(song);
    mpd_connection_free(conn);

    return 0;
}

