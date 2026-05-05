#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // for sleep()

// 定义用于存储流量的结构体
typedef struct {
    unsigned long long total_recv;
    unsigned long long total_sent;
} NetStats;

/**
 * 从 /proc/net/dev 获取当前网络流量
 * 注意：这里简单累加了所有接口的流量（包括 lo, eth0, wlan0 等）
 * 如果需要只监控特定网卡（如 eth0），需要修改 sscanf 的匹配逻辑
 */
int get_net_io(NetStats *stats) {
    FILE *fp = fopen("/proc/net/dev", "r");
    if (!fp) {
        perror("无法打开 /proc/net/dev");
        return -1;
    }

    stats->total_recv = 0;
    stats->total_sent = 0;

    char line[256];
    // 跳过前两行标题
    fgets(line, sizeof(line), fp);
    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp)) {
        char interface[16];
        unsigned long long rx_bytes, tx_bytes;
        
        // /proc/net/dev 格式: interface: rx_bytes ... tx_bytes ...
        // %[^:] 表示读取直到冒号为止的字符串（即网卡名）
        if (sscanf(line, " %[^:]: %llu %*u %*u %*u %*u %*u %*u %*u %*u %llu", 
                   interface, &rx_bytes, &tx_bytes) == 3) {
            stats->total_recv += rx_bytes;
            stats->total_sent += tx_bytes;
        }
    }

    fclose(fp);
    return 0;
}

void print_speed(unsigned long long bytes_per_sec, char is_upload) {
    double val = (double)bytes_per_sec;
    
    // 这里的逻辑与 Python 代码一致：先转为 KB，判断是否超过 1024KB (即 1MB)
    double kb_val = val / 1024.0;

    if (kb_val >= 1024.0) {
        // 大于 1MB/s，显示 MB
        printf("%s %.2fMB/s ", is_upload ? "\uf062" : "\uf063", kb_val / 1024.0);
    } else {
        // 小于 1MB/s，显示 KB
        printf("%s %.2fKB/s ", is_upload ? "\uf062" : "\uf063", kb_val);
    }
}

int main() {
    NetStats prev, curr;

    // 初始化第一次读取
    if (get_net_io(&prev) != 0) {
        return 1;
    }

    // 模拟一次循环（Python 原代码只调用了一次函数）
    // 如果需要实时监控，可以将下面的逻辑放入 while(1) 循环中
    
    sleep(1); // 等待 1 秒计算差值

    if (get_net_io(&curr) != 0) {
        return 1;
    }

    // 计算差值 (Bytes)
    unsigned long long recv_diff = curr.total_recv - prev.total_recv;
    unsigned long long sent_diff = curr.total_sent - prev.total_sent;

    // 打印结果 (包含 Nerd Font 图标)
    // \uf063 = 下载箭头, \uf062 = 上传箭头
    print_speed(recv_diff, 0); // 0 表示下载
    print_speed(sent_diff, 1); // 1 表示上传
    printf("\n");

    return 0;
}
