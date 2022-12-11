/* See LICENSE file for copyright and license details. */

/* appearance */
static const char *mutevol[] = {"amixer", "-qM",    "set",
                                "Master", "toggle", NULL};
static const char *downvol[] = {"amixer", "-qM",   "set", "Master",
                                "5%-",    "umute", NULL};
static const char *upvol[] = {"amixer", "-qM",   "set", "Master",
                              "5%+",    "umute", NULL};
static const unsigned int borderpx =
    2; /* 窗口边框大小border pixel of windows */
static const unsigned int newclientathead = 1; /* 定义新窗口在栈顶还是栈底 */
static const unsigned int snap = 32;           /* snap pixel */
static const unsigned int gappih =
    10; /* 窗口与窗口 缝隙大小horiz inner gap between windows */
static const unsigned int gappiv =
    10; /* 窗口与窗口 缝隙大小vert inner gap between windows */
static const unsigned int gappoh =
    10; /* horiz outer gap between windows and screen edge */
static const unsigned int gappov =
    10; /* vert outer gap between windows and screen edge */
static const int smartgaps =
    0; /* 1 means no outer gap when there is only one window */
static const int showbar = 1; /* 是否显示状态栏0 means no bar */
static const int topbar = 1; /* 指定状态栏位置 0底部 1顶部 0 means bottom bar */
#define ICONSIZE 16   /* icon size */
#define ICONSPACING 5 /* space between icon and title */
static const unsigned int systraypinning =
    0; /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor
          X */
static const unsigned int systrayspacing = 2; /* systray spacing */
static const int systraypinningfailfirst =
    1; /* 1: if pinning fails, display systray on the first monitor, False:
          display systray on the last monitor*/
static const int showsystray = 1;   /* 0 means no systray */
static const Bool viewontag = True; /* Switch view on tag switch */
static const char *fonts[] = {"LXGW WenKai Light:size=10",
                              "Fira Code Nerd Font Mono:size=12"};
static const char dmenufont[] = "LXGW WenKai Light:size=10";
static const char col_gray1[] = "#222222"; // 状态条底色
static const char col_gray2[] = "#444444"; // 当static const unsigned int
//                // borderpx不为0时，非活动窗口外边框颜色
static const char col_gray3[] = "#bd93f9"; // 当前非活动的title字体颜色
static const char col_gray4[] = "#8be9fd"; // 当前活动的title字体颜色
static const char col_cyan[] = "#111111";  // title底色
static const unsigned int baralpha = 0x99; /* 状态栏透明度 */
static const unsigned int borderalpha = 0xdd; /* 边框透明度 */
static const char *colors[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm] = {col_gray3, col_gray1, col_gray2},
    [SchemeSel] = {col_gray4, col_cyan, col_cyan},
    [SchemeHid] = {col_cyan, col_gray1, col_cyan},
};
static const unsigned int alphas[][3] = {
    /*               fg      bg        border     */
    [SchemeNorm] = {OPAQUE, baralpha, borderalpha},
    [SchemeSel] = {OPAQUE, baralpha, borderalpha},
};
/* tagging */
static const char *tags[] = {"\uf015¹", "\ue5fe²", "\uf030³",
                             "\uf268⁴", "\uf269⁵", "\ue62a⁶",
                             "\ue217⁷", "\uf2dc⁸", "\uf30d⁹"};

static int gappi = 12; /* 窗口与窗口 缝隙大小 */
static int gappo = 12; /* 窗口与边缘 缝隙大小 */
static const int _gappo =
    12; /* 窗口与窗口 缝隙大小 不可变 用于恢复时的默认值 */
static const int _gappi =
    12; /* 窗口与边缘 缝隙大小 不可变 用于恢复时的默认值 */
static const int overviewgappo = 24; /* overview时 窗口与边缘 缝隙大小 */
static const int overviewgappi = 60; /* overview时 窗口与窗口 缝隙大小 */
static const char *overviewtag = "窗口预览";
static const Layout overviewlayout = {"\uf30d", overview};
static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    {"Gimp", NULL, NULL, 0, 1, -1},
    {"Firefox", NULL, NULL, 1 << 8, 0, -1},
};

/* layout(s) */
static const float mfact = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;   /* number of clients in master area */
static const int resizehints =
    1; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen =
    1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[平铺]", tile}, /* first entry is default */
    {"[浮动]", NULL}, /* no layout function means floating behavior */
    {"[单页]", monocle},
    {"[网格]", magicgrid},
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                        \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

/* commands */
static char dmenumon[2] =
    "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
    "dmenu_run", "-m",      dmenumon, "-fn",    dmenufont, "-nb",     col_gray1,
    "-nf",       col_gray3, "-sb",    col_cyan, "-sf",     col_gray4, NULL};
static const char *termcmd[] = {"st", NULL};
// static const char *termalacritty[] = {"alacritty", NULL};
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = {"alacritty", "-t", scratchpadname, NULL};
static const char *scratchpadstcmd[] = {"st",     "-t", scratchpadname, "-g",
                                        "120x34", "-e", "ranger",       NULL};
static const char *roficmd[] = {"rofi",   "-show",       "drun",
                                "-theme", "gaara-theme", NULL};
static const char *roficmd1[] = {"rofi",   "-show",       "run",
                                 "-theme", "gaara-theme", NULL};
static const char *firefoxcmd[] = {"firefox", NULL};
// static const char *chromecmd[] = {"google-chrome-stable",
//                                 "--enable-features=VaapiVideoDecoder", NULL};
static const char *radomchwp[] = {
    "/home/xihe/.config/scripts/random-change-sp.sh", NULL};
static const char *screenshotcmd[] = {"flames", "gui", NULL};

static const Key keys[] = {
    /* modifier                     key        function        argument */
    {MODKEY, XK_d, spawn, {.v = roficmd}},              /*打开ropfi*/
    {MODKEY | ShiftMask, XK_d, spawn, {.v = roficmd1}}, /*以命令模式打开rofi*/
    {Mod1Mask, XK_a, spawn, {.v = screenshotcmd}},      /*打开火焰截图*/
    //{MODKEY, XK_c, spawn, {.v = chromecmd}},            /*打开chrome*/
    {MODKEY, XK_c, spawn, {.v = firefoxcmd}}, /*打开chrome*/
    {MODKEY, XK_r, spawn, {.v = radomchwp}},  /*随机切换壁纸*/
    //{MODKEY, XK_g, spawn, {.v = browsercmd}},
    ///*以代理模式打开chrome*/
    {MODKEY, XK_p, spawn, {.v = dmenucmd}},     // 打开dmenu
    {MODKEY, XK_Return, spawn, {.v = termcmd}}, // 打开终端
    //{Mod1Mask, XK_Return, spawn, {.v = termcmd}},     // 打开终端
    //{MODKEY, XK_Return, spawn, {.v = termalacritty}}, // 打开终端
    {MODKEY, XK_b, togglebar, {0}}, // 隐藏状态栏
    {MODKEY | ShiftMask,
     XK_b,
     rotatestack,
     {.i = +1}}, // 循环交换两个窗口的位置
    {MODKEY | ShiftMask, XK_p, rotatestack, {.i = -1}},
    {MODKEY, XK_j, focusstackvis, {.i = +1}}, // 光标在窗口之间循环
    {MODKEY, XK_k, focusstackvis, {.i = -1}},
    {MODKEY | ShiftMask, XK_j, focusstackhid, {.i = +1}},
    {MODKEY | ShiftMask, XK_k, focusstackhid, {.i = -1}},
    {MODKEY, XK_i, incnmaster, {.i = +1}}, // 将窗口回复垂直逻辑
    {MODKEY | ShiftMask, XK_i, incnmaster, {.i = -1}}, // 将窗口改为横着
    {MODKEY, XK_h, setmfact, {.f = -0.05}}, // 左右调整窗口占比
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY | ShiftMask, XK_Return, zoom, {0}}, // 交换两个刚打开的窗口的位置
    {MODKEY, XK_Tab, view, {0}},                // 切换标签
    {MODKEY, XK_q, killclient, {0}},            // 关闭当前窗口
    {MODKEY, XK_t, setlayout, {.v = &layouts[0]}}, // 窗口改为平铺模式
    {MODKEY, XK_n, setlayout, {.v = &layouts[1]}}, // 窗口改为浮动模式
    {MODKEY, XK_m, setlayout, {.v = &layouts[2]}}, // 当前窗口占满屏幕
    {MODKEY, XK_g, setlayout, {.v = &layouts[3]}}, // 当前窗口占满屏幕
    {MODKEY, XK_a, toggleoverview, {0}},           // 当前窗口占满屏幕
    {MODKEY, XK_F11, spawn, {.v = downvol}},       /*减小音量*/
    {MODKEY, XK_F9, spawn, {.v = mutevol}},        /*静音*/
    {MODKEY, XK_F12, spawn, {.v = upvol}},         /*增加音量*/
    {MODKEY | ShiftMask, XK_f, fullscreen, {0}},   // 将当前窗口全屏
    {MODKEY, XK_space, setlayout, {0}},            // 窗口改为平铺模式
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}}, // 窗口改为浮动模式
    {MODKEY, XK_0, view, {.ui = ~0}},                    // 显示全部标签
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},
    {MODKEY | Mod1Mask, XK_h, incrgaps, {.i = +1}},
    {MODKEY | Mod1Mask, XK_l, incrgaps, {.i = -1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_h, incrogaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_l, incrogaps, {.i = -1}},
    {MODKEY | Mod1Mask | ControlMask, XK_h, incrigaps, {.i = +1}},
    {MODKEY | Mod1Mask | ControlMask, XK_l, incrigaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_0, togglegaps, {0}},
    {MODKEY | Mod1Mask | ShiftMask, XK_0, defaultgaps, {0}},
    {Mod1Mask | ControlMask, XK_y, incrihgaps, {.i = +1}},
    {MODKEY, XK_o, incrihgaps, {.i = -1}},
    {MODKEY | ControlMask, XK_y, incrivgaps, {.i = +1}},
    {MODKEY | ControlMask, XK_o, incrivgaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_y, incrohgaps, {.i = +1}},
    {MODKEY | Mod1Mask, XK_o, incrohgaps, {.i = -1}},
    {MODKEY | ShiftMask, XK_y, incrovgaps, {.i = +1}},
    {MODKEY | ShiftMask, XK_o, incrovgaps, {.i = -1}},
    {MODKEY, XK_y, togglescratch, {.v = scratchpadcmd}},
    {MODKEY, XK_u, togglescratch, {.v = scratchpadstcmd}},
    {MODKEY, XK_s, show, {0}}, // 显示隐藏的窗口
    {MODKEY, XK_v, hide, {0}}, // 隐藏窗口
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8){MODKEY | ShiftMask, XK_q, quit, {0}},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
/* click                event mask      button          function argument */
static const Button buttons[] = {
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button1, togglewin, {0}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
