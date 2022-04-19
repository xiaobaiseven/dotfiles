/* See LICENSE file for copyright and license details. */

/* appearance */
static const char *mutevol[] = { "amixer", "-qM", "set", "Master", "toggle", NULL };
static const char *downvol[] = { "amixer", "-qM", "set", "Master", "5%-", "umute", NULL };
static const char *upvol[]   = { "amixer", "-qM", "set", "Master", "5%+", "umute", NULL };
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 8;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 8;       /* vert inner gap between windows */
static const unsigned int gappoh    = 8;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 8;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray             = 1;   /* 0 means no systray */
static const Bool viewontag         = True;     /* Switch view on tag switch */
static const char *fonts[]          = { "文泉驿正黑:size=10","Fira Code Nerd Font Mono:size=12" };
static const char dmenufont[]       = "文泉驿正黑:size=12";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const unsigned int baralpha = 0x80;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
	[SchemeHid]  = { col_cyan,  col_gray1, col_cyan  },
};
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};
/* tagging */
static const char *tags[] = { "\uf015¹", "\ue5fe²", "\uf030³", "\uf268⁴", "\uf269⁵", "\ue62a⁶", "\ue217⁷", "\uf2dc⁸", "\uf30d⁹" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[平铺模式]",      tile },    /* first entry is default */
	{ "[浮动模式]",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };
static const char *roficmd[]  = { "rofi", "-show", "drun", "-theme", "gaara-theme", NULL };
static const char *roficmd1[]  = { "rofi", "-show", "run", "-theme", "gaara-theme", NULL };
static const char *browsercmd[]  = { "google-chrome-stable", "--proxy-server=socks5://127.0.0.1:1089", NULL };
static const char *chromecmd[]  = { "google-chrome-stable",  NULL };
static const char *radomchwp[]  = { "/home/dora/.config/scripts/random-change-sp.sh",  NULL };
static const char *screenshotcmd[] = { "flameshot", "gui", NULL };
//static const char *firefoxcmd[]  = { "firefox",  NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = roficmd } },/*打开ropfi*/
	{ MODKEY|ShiftMask,             XK_d,      spawn,          {.v = roficmd1 } },/*以命令模式打开rofi*/
	{ MODKEY|ShiftMask,             XK_a,      spawn,          {.v = screenshotcmd } },/*打开火焰截图*/
	{ MODKEY,                       XK_c,      spawn,          {.v = chromecmd } },/*打开chrome*/
	{ MODKEY,                       XK_r,      spawn,          {.v = radomchwp } },/*随机切换壁纸*/
	{ MODKEY|ShiftMask,             XK_c,      spawn,          {.v = browsercmd } },/*以代理模式打开chrome*/
	//{ Mod1Mask,                     XK_f,      spawn,          {.v = firefoxcmd } },/*打开firefox*/
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },//打开dmenu
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },//打开终端
	{ MODKEY,                       XK_b,      togglebar,      {0} },//隐藏状态栏
	{ MODKEY|ShiftMask,             XK_b,      rotatestack,    {.i = +1 } },//循环交换两个窗口的位置
	{ MODKEY|ShiftMask,             XK_p,      rotatestack,    {.i = -1 } },
	{ MODKEY,                       XK_j,      focusstackvis,  {.i = +1 } },//光标在窗口之间循环
	{ MODKEY,                       XK_k,      focusstackvis,  {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      focusstackhid,  {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      focusstackhid,  {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },//将窗口回复垂直逻辑
	{ MODKEY|ShiftMask,             XK_i,      incnmaster,     {.i = -1 } },  //将窗口改为横着
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },//左右调整窗口占比
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },//交换两个刚打开的窗口的位置
	{ MODKEY,                       XK_Tab,    view,           {0} },//切换标签
	{ MODKEY,                       XK_q,      killclient,     {0} },//关闭当前窗口
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },//窗口改为平铺模式
	{ MODKEY,                       XK_n,      setlayout,      {.v = &layouts[1]} },//窗口改为浮动模式
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },//当前窗口占满屏幕
	{ MODKEY,                       XK_F11,    spawn,          {.v = downvol } },/*减小音量*/
	{ MODKEY,                       XK_F9,     spawn,          {.v = mutevol } },/*静音*/
	{ MODKEY,                       XK_F12,    spawn,          {.v = upvol   } },/*增加音量*/
	{ MODKEY|ShiftMask,             XK_f,      fullscreen,     {0} },  //将当前窗口全屏
	{ MODKEY,                       XK_space,  setlayout,      {0} }, //窗口改为平铺模式
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },//窗口改为浮动模式
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },//显示全部标签
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_h,      incrgaps,       {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_l,      incrgaps,       {.i = -1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_h,      incrogaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_l,      incrogaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask|ControlMask,  XK_h,      incrigaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ControlMask,  XK_l,      incrigaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
	{ Mod1Mask|ControlMask,         XK_y,      incrihgaps,     {.i = +1 } },
	{ MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } },
	{ MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } },
	{ MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_y,      incrohgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_o,      incrohgaps,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } },
	{ MODKEY,                       XK_y,      togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                       XK_s,      show,           {0} }, //显示隐藏的窗口
	{ MODKEY,                       XK_v,      hide,           {0} }, //隐藏窗口
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

