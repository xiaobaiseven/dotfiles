/* See LICENSE file for copyright and license details. */

/* appearance */
static const char *mutevol[] = {"amixer", "-qM",    "set",
                                "Master", "toggle", NULL};
static const char *downvol[] = {"amixer", "-qM",   "set", "Master",
                                "5%-",    "umute", NULL};
static const char *upvol[] = {"amixer", "-qM",   "set", "Master",
                              "5%+",    "umute", NULL};
static const char *uplight[] = {"xbacklight", "-inc", "5", NULL};
static const char *downlight[] = {"xbacklight", "-dec", "5", NULL};
static const unsigned int borderpx = 3; /* border pixel of windows */
static const unsigned int snap = 32;    /* snap pixel */
static const unsigned int gappih = 7;   /* horiz inner gap between windows */
static const unsigned int gappiv = 7;   /* vert inner gap between windows */
static const unsigned int gappoh =
    7; /* horiz outer gap between windows and screen edge */
static const unsigned int gappov =
    7; /* vert outer gap between windows and screen edge */
static int smartgaps =
    1; /* 1 means no outer gap when there is only one window */
static const int showbar = 1;       /* 0 means no bar */
static const int topbar = 1;        /* 0 means bottom bar */
#define ICONSIZE 15                 /* icon size */
#define ICONSPACING 5               /* space between icon and title */
static const Bool viewontag = True; /* Switch view on tag switch */
static const unsigned int systraypinning =
    0; /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor
          X */
static const unsigned int systrayspacing = 2; /* systray spacing */
static const int systraypinningfailfirst =
    1; /* 1: if pinning fails, display systray on the first monitor, False:
          display systray on the last monitor*/
static const int showsystray = 1; /* 0 means no systray */
static const char *fonts[] = {"Liberation Sans:style=Bold:size=10",
                              "MiSans:style=Bold:size=10",
                              "FiraCode Nerd Font Mono:size=12"};
static const char dmenufont[] = "Liberation Sans:size=10";
static const char col_gray1[] = "#222222";
static const char col_gray2[] = "#666666";
static const char col_gray3[] = "#bd93f9";
static const char col_gray4[] = "#8be9fd";
static const char col_cyan[] = "#005577";
static const char col_border[] = "#bd93f9";
static const unsigned int baralpha = 0xb4;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm] = {col_gray3, col_gray1, col_gray2},
    [SchemeSel] = {col_gray4, col_cyan, col_border},
    [SchemeHid] = {col_cyan, col_gray1, col_border},
};
static const unsigned int alphas[][3] = {
    /*               fg      bg        border     */
    [SchemeNorm] = {OPAQUE, baralpha, borderalpha},
    [SchemeSel] = {OPAQUE, baralpha, borderalpha},
};
typedef struct {
  const char *name;
  const void *cmd;
} Sp;
const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL};
const char *spcmd2[] = {"st", "-n", "spfm", "-g", "144x41", "-e", "yazi", NULL};
const char *spcmd3[] = {"keepassxc", NULL};
static Sp scratchpads[] = {
    /* name          cmd  */
    {"spterm", spcmd1},
    {"spranger", spcmd2},
    {"keepassxc", spcmd3},
};

/* tagging */

static const char *tags[] = {"\uf015¹", "\ue5fe²", "\uf030³",
                             "\uf268⁴", "\uf269⁵", "\ue62a⁶",
                             "\ue217⁷", "\uf2dc⁸", "\uf30d⁹"};
static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    {"Gimp", NULL, NULL, 0, 1, -1},
    {"Firefox", NULL, NULL, 1 << 8, 0, -1},
    {NULL, "spterm", NULL, SPTAG(0), 1, -1},
    {NULL, "spfm", NULL, SPTAG(1), 1, -1},
    {NULL, "keepassxc", NULL, SPTAG(2), 0, -1},
};

/* layout(s) */
static const float mfact = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;   /* number of clients in master area */
static const int resizehints =
    1; /* 1 means respect size hints in tiled resizals */
#define FORCE_VSPLIT                                                           \
  1 /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const int lockfullscreen =
    1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile}, /* first entry is default */
    {"><>", NULL}, /* no layout function means floating behavior */
    {"[M]", monocle},
    {"[@]", spiral},
    {"[\\]", dwindle},
    {"H[]", deck},
    {"TTT", bstack},
    {"===", bstackhoriz},
    {"HHH", grid},
    {"###", nrowgrid},
    {"---", horizgrid},
    {":::", gaplessgrid},
    {"|M|", centeredmaster},
    {">M>", centeredfloatingmaster},
    {NULL, NULL},
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
const char *musicplay[] = {"st", "-e", "termusic", NULL};
static const char *roficmd[] = {"rofi",   "-show",  "drun",
                                "-theme", "arthur", NULL};
static const char *roficmd1[] = {"rofi",   "-show",  "run",
                                 "-theme", "arthur", NULL};
static const char *browsercmd[] = {
    "google-chrome-stable",
    "--enable-features=TouchpadOverscrollHistoryNavigation,AcceleratedVideoDecodeLinuxGL,VaapiVideoDecodeLinuxGL,VaapiVideoDecoder,VaapiIgnoreDriverChecks,UseChromeOSDirectVideoDecoder,PlatformHEVCDecoderSupport,Vulkan,DefaultANGLEVulkan,VulkanFromANGLE",
    "--ignore-gpu-blacklist",
    "--enable-accelerated-video-decode",
    "--enable-zero-copy", NULL};
static const char *radomchwp[] = {
    "/home/weixi/.config/scripts/random-change-sp.sh", NULL};
static const char *screenshotcmd[] = {"flames", NULL};

static const Key keys[] = {
    /* modifier                     key        function        argument */
    {MODKEY, XK_F11, spawn, {.v = downvol}},            /*减小音量*/
    {MODKEY, XK_F9, spawn, {.v = mutevol}},             /*静音*/
    {MODKEY, XK_F12, spawn, {.v = upvol}},              /*增加音量*/
    {MODKEY, XK_F7, spawn, {.v = uplight}},             /*增加音量*/
    {MODKEY, XK_F6, spawn, {.v = downlight}},           /*增加音量*/
    {Mod1Mask, XK_m, spawn, {.v = musicplay}},          /*增加音量*/
    {MODKEY, XK_p, spawn, {.v = dmenucmd}},             // 打开dmeun
    {MODKEY, XK_Return, spawn, {.v = termcmd}},         // 打开终端
    {MODKEY, XK_b, togglebar, {0}},                     // 状态条显示隐藏
    {MODKEY, XK_d, spawn, {.v = roficmd}},              /*打开ropfi*/
    {MODKEY | ShiftMask, XK_d, spawn, {.v = roficmd1}}, /*以命令模式打开rofi*/
    {Mod1Mask, XK_a, spawn, {.v = screenshotcmd}},      /*打开火焰截图*/
    {MODKEY, XK_r, spawn, {.v = radomchwp}},            /*随机切换壁纸*/
    {MODKEY, XK_c, spawn, {.v = browsercmd}},
    {MODKEY, XK_j, focusstackvis, {.i = +1}},
    {MODKEY, XK_k, focusstackvis, {.i = -1}},
    {MODKEY | ShiftMask, XK_j, focusstackhid, {.i = +1}},
    {MODKEY | ShiftMask, XK_k, focusstackhid, {.i = -1}},
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    {MODKEY | ShiftMask, XK_i, incnmaster, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY | ShiftMask, XK_h, setcfact, {.f = +0.25}},
    {MODKEY | ShiftMask, XK_l, setcfact, {.f = -0.25}},
    {MODKEY | ShiftMask, XK_o, setcfact, {.f = 0.00}},
    {MODKEY | ShiftMask, XK_Return, zoom, {0}},
    {MODKEY | Mod1Mask, XK_u, incrgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_u, incrgaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_i, incrigaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_i, incrigaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_o, incrogaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_o, incrogaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_6, incrihgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_6, incrihgaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_7, incrivgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_7, incrivgaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_8, incrohgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_8, incrohgaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_9, incrovgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_9, incrovgaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_0, togglegaps, {0}},
    {MODKEY | Mod1Mask | ShiftMask, XK_0, defaultgaps, {0}},
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY, XK_q, killclient, {0}},
    {MODKEY, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY, XK_f, setlayout, {.v = &layouts[1]}},
    {MODKEY, XK_m, setlayout, {.v = &layouts[2]}},
    {MODKEY | ShiftMask, XK_f, fullscreen, {0}},
    {MODKEY, XK_space, setlayout, {0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY, XK_0, view, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},
    {MODKEY, XK_y, togglescratch, {.ui = 0}},
    {MODKEY, XK_u, togglescratch, {.ui = 1}},
    {MODKEY, XK_x, togglescratch, {.ui = 2}},
    {MODKEY, XK_s, show, {0}},
    {MODKEY | ShiftMask, XK_s, showall, {0}},
    {MODKEY, XK_s, hide, {0}},
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8){MODKEY | ShiftMask, XK_q, quit, {0}},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function argument */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button1, togglewin, {0}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button1, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
