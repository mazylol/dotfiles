/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const unsigned int gappih    = 20;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 20;       /* vert inner gap between windows */
static const unsigned int gappoh    = 20;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 20;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Fira Code Regular:size=12" };
static const char dmenufont[]       = "Fira Code Regular:size=12";
static const char col_gray1[]       = "#2d2a2e"; /* main */
static const char col_gray2[]       = "#000000"; /* border */
static const char col_gray3[]       = "#bbbbbb"; /* tag */
static const char col_gray4[]       = "#eeeeee"; /* text */
static const char col_cyan[]        = "#403E41"; /* highlight */
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class         instance  title           tags mask  isfloating  monitor */
	{ "Gimp",        NULL,     NULL,           0,         1,          0,           0,        -1 },
	{ "Firefox",     NULL,     NULL,           1 << 8,    0,          0,          -1,        -1 },
	{ "Alacritty",   NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ NULL,          NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
/* symbol     arrange function */
 { "[]=",      tile },    /* first entry is default */ /* 0 */
 { "[M]",      monocle },                              /* 1 */
 { "[@]",      spiral },                               /* 2 */
 { "[\\]",     dwindle },                              /* 3 */
 { "H[]",      deck },                                 /* 4 */
 { "TTT",      bstack },                               /* 5 */
 { "===",      bstackhoriz },                          /* 6 */
 { "HHH",      grid },                                 /* 7 */
 { "###",      nrowgrid },                             /* 8 */
 { "---",      horizgrid },                            /* 9 */
 { ":::",      gaplessgrid },                          /* 10 */
 { "|M|",      centeredmaster },                       /* 11 */
 { ">M>",      centeredfloatingmaster },               /* 12 */
 { "><>",      NULL },    /* no layout function means floating behavior */
 { NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define AltMask Mod1Mask
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
static const char *termcmd[]  = { "alacritty", NULL };
static const char *screenshot[] = { "flameshot", "gui", NULL };
static const char *browser[] = { "firefox", NULL };
static const char *music[] = { "spotify", NULL };
static const char	*lock[] = { "i3lock", "-c", "000000", NULL };
static const char *discord[] = { "discord", NULL };
static const char *audio[] = { "pavucontrol", NULL };
static const char *files[] = { "nautilus", NULL };
static const char *keepassxc[] = { "keepassxc", NULL };
static const char *virtmanager[] = { "virt-manager", NULL };
static const char *code[] = { "code", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	
 /* dwm stuff */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },


	/* app launchers */
 	{ MODKEY|ControlMask,           XK_Return, spawn,          {.v = screenshot } },
 	{ MODKEY|ControlMask,           XK_w,      spawn,          {.v = browser } },
	{ MODKEY|ControlMask,						XK_m,      spawn,          {.v = music } },
	{	MODKEY|ControlMask,						XK_l,      spawn,          {.v = lock } },
	{	MODKEY|ControlMask,						XK_d,      spawn,          {.v = discord } },
	{	MODKEY|ControlMask,						XK_a,      spawn,          {.v = audio } },
 	{ MODKEY|ControlMask,						XK_f,      spawn,          {.v = files } },
	{ MODKEY|ControlMask,           XK_k,      spawn,          {.v = keepassxc } },
	{ MODKEY|ControlMask,           XK_v,      spawn,          {.v = virtmanager} },
	{ MODKEY|ControlMask,           XK_c,      spawn,          {.v = code} },
	
 	/* dwm modding */
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
 	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },

	/* layouts */
	{ MODKEY|AltMask|ShiftMask,     XK_t,      setlayout,			 {.v = &layouts[0]} }, /* tile */
	{ MODKEY|AltMask|ShiftMask,     XK_m,      setlayout,      {.v = &layouts[1]} }, /* monocle */
	{ MODKEY|AltMask|ShiftMask,     XK_s,      setlayout,      {.v = &layouts[2]} }, /* spiral */
	{ MODKEY|AltMask|ShiftMask,     XK_d,      setlayout,      {.v = &layouts[3]} }, /* dwindle */
	{ MODKEY|AltMask|ShiftMask,     XK_b,      setlayout,      {.v = &layouts[5]} }, /* bstack */
	{ MODKEY|AltMask|ShiftMask,     XK_g,      setlayout,      {.v = &layouts[7]} }, /* grid */
	{ MODKEY|AltMask|ShiftMask,     XK_n,      setlayout,      {.v = &layouts[8]} }, /* nrowgrid */
	{ MODKEY|AltMask|ShiftMask,     XK_h,      setlayout,      {.v = &layouts[9]} }, /* horizgrid */

	/* gaps */
 	{ MODKEY|AltMask,               XK_u,      incrgaps,       {.i = +1 } },
	{ MODKEY|AltMask|ShiftMask,     XK_u,      incrgaps,       {.i = -1 } },
	{ MODKEY|AltMask,               XK_i,      incrigaps,      {.i = +1 } },
	{ MODKEY|AltMask|ShiftMask,     XK_i,      incrigaps,      {.i = -1 } },
	{ MODKEY|AltMask,               XK_o,      incrogaps,      {.i = +1 } },
	{ MODKEY|AltMask|ShiftMask,     XK_o,      incrogaps,      {.i = -1 } },
	{ MODKEY|AltMask,               XK_6,      incrihgaps,     {.i = +1 } },
	{ MODKEY|AltMask|ShiftMask,     XK_6,      incrihgaps,     {.i = -1 } },
	{ MODKEY|AltMask,               XK_7,      incrivgaps,     {.i = +1 } },
	{ MODKEY|AltMask|ShiftMask,     XK_7,      incrivgaps,     {.i = -1 } },
	{ MODKEY|AltMask,               XK_8,      incrohgaps,     {.i = +1 } },
	{ MODKEY|AltMask|ShiftMask,     XK_8,      incrohgaps,     {.i = -1 } },
	{ MODKEY|AltMask,               XK_9,      incrovgaps,     {.i = +1 } },
	{ MODKEY|AltMask|ShiftMask,     XK_9,      incrovgaps,     {.i = -1 } },
	{ MODKEY|AltMask,               XK_0,      togglegaps,     {0} },
	{ MODKEY|AltMask|ShiftMask,     XK_0,      defaultgaps,    {0} },

	/* dwm specific */
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, focusmon,       {.i = +1 } },
	{ MODKEY,                       XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY,                       XK_period, tagmon,         {.i = +1 } },

	/* tag keys */
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

