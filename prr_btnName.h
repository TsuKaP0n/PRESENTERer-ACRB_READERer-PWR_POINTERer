const String appMenu_str[4][4] = {
  {"MPC-BE", "Ac.Readr", "DIG.SIGNAGE", "PwrPoint"},
  {"Photo", "Chrome", "MOVIE & TV", "WIN + TAB"},
  {"Folder", "Alt+Tab", "CLOSE WINDOW", "ALT + TAB"},
  {"stopwatch", "about", "", "ALT + TAB"}
};
const int16_t appMenu_pos[4][2] = {
  {105, 216},
  {117, 219},
  {117, 230},
  {105, 235}
};
const uint8_t appMenu_btnMode[4][4] = {
  {20, 1, 40, 10},
  {27, 30, 5, 202},
  {15, 200, 90, 200},
  {95, 97, 243, 200}
};  

const String subMenu[200][10] = {
  {"1", "ACROBAT READER - 1/1",
      "next pdf",  "25",
      "PgUp",      "135",
      "PgDn",      "230",
      "FULLSCREEN", "NEXT TAB"},
  {"5", "WINDOWS MOVIE & TV - 1/5",
      "next",     "40",
      "fullScrn", "120",
      "",         "225",
      "ESC", "ALT + TAB"},
  {"6", "WINDOWS MOVIE & TV - 2/5",
      "next",     "40",
      "ShiftTab", "115",
      "Tab",      "230",
      "ENTER","PLAY BUTTON"},
  {"7", "WINDOWS MOVIE & TV - 3/5",
      "next",   "40",
      "Left",   "135",
      "Right",  "220",
      "ENTER", "PLAY BUTTON"},
  {"8", "WINDOWS MOVIE & TV - 4/5",
      "next",     "40",
      "Vol.Down", "110",
      "Vol.Up",   "233",
      "MUTE", "PLAY BUTTON"},
  {"9", "WINDOWS MOVIE & TV - 5/5",
      "next",     "40",
      "",         "110",
      "CLOSE",    "225",
      "", ""},
  {"10", "POWERPOINT - EDIT",
      "Up",     "48",
      "Down",   "125",
      "START",  "225",
      "SHOW THIS", "ALT + TAB"},
  {"11", "POWERPOINT - SLIDESHOW",
      "return", "35",
      "PgUp",   "135",
      "PgDn",   "230",
      "PAGE LIST", "ALT + TAB"},
  {"12", "POWERPOINT - SLIDE LIST",
      "Left",   "45",
      "Right",  "128",
      "SELECT", "219",
      "ESC", ""},
  {"15", "FILE EXPLORER - 1/2",
      "Up",   "50",
      "Down", "120",
      "OPEN", "219",
      "LEFT/RIGHT", "UPPER FOLDER"},
  {"16", "FILE EXPLORER - 2/2",
      "Left",   "45",
      "Right",  "120",
      "OPEN",   "219",
      "UP/DOWN", "UPPER FOLDER"},
  {"20", "MPC-BE - 1/5 TOP",
      "next",     "40",
      "FullScrn", "120",
      "",         "230",
      "", "CLOSE"},
  {"21", "MPC-BE - 2/5 5 SECONDS JUMP",
      "next",     "40",
      "     <<",  "120",
      "    >>",   "220",
      "PLAY/PAUSE", "MPC-BE TOP"},
  {"22", "MPC-BE - 3/5 FRAME STEP",
      "next",     "40",
      "       <", "120",
      "      >",  "220",
      "PLAY/PAUSE", "MPC-BE TOP"},
  {"23", "MPC-BE - 4/5 VOLUME",
      "next",     "40",
      "Vol.-",    "130",
      "Vol.+",    "230",
      "MUTE", "MPC-BE TOP"},
  {"24", "MPC-BE - 5/5 CLOSE",
      "next",     "40",
      "",         "120",
      "Close",    "230",
      "","MPC-BE TOP"},
  {"27", "WINDOWS PHOTO - 1/2",
      "next",     "40",
      "FullScrn", "120",
      "CLOSE",    "230",
      "", ""},
  {"28", "WINDOWS PHOTO - 2/2",
      "next",     "40",
      "LEFT",     "120",
      "RIGHT",    "230",
      "", ""},
  {"30", "GOOGLE CHROME - 1/5",
      "next", "40",
      "PgUp", "123",
      "PgDn", "220",
      "FULLSCREEN", "NEXT TAB"},
  {"31", "GOOGLE CHROME - 2/5",
      "next", "40",
      "UP",   "128",
      "DOWN", "220",
      "FULLSCREEN", "NEXT TAB"},
  {"32", "GOOGLE CHROME - 3/5",
      "next",     "40",
      "PrvLink",  "115",
      "NxtLink",  "220",
      "FULLSCREEN", "GO"},
  {"33", "GOOGLE CHROME - 4/5",
      "next",     "40",
      "PrvPage",  "110",
      "NxtPage",  "215",
      "PREV.TAB", "NEXT TAB"},
  {"34", "GOOGLE CHROME - 5/5",
      "next",     "40",
      "Minimize", "110",
      "Esc",      "240",
      "",""},
  {"40", "REPEATING DISPLAY - SETTING",
      "Ac.Readr", "25",
      "---",      "150",
      "PwrPoint", "205",
      "",""},
  {"41", "REPEATING ACR.READER - 1/3",
      "PgUp",     "40",
      "PgDn",     "128",
      "ENTER",    "215",
      "",""},
  {"42", "REPEATING ACR.READER - 2/3",
      "PgUp",     "40",
      "PgDn",     "128",
      "ENTER",    "215",
      "",""},
  {"44", "REPEATING ACR.READER - 1/3",
      "PgUp",     "40",
      "PgDn",     "128",
      "ENTER",    "215",
      "",""},
  {"45", "REPEATING ACR.READER - 2/3",
      "PgUp",     "40",
      "PgDn",     "128",
      "ENTER",    "215",
      "",""},
  {"48", "REPEATING ACR.READER - 3/3",
      "decrease", "25",
      "increase", "139",
      "START",    "242",
      "",""},
  {"49", "REPEATING DISPLAY",
      "---",      "55",
      "---",      "150",
      "STOP",     "220",
      "",""},
  {"90", "",    //  90:  ALT + F4 (Close Window)
      "", "",
      "", "",
      "", "",
      "", ""},
  {"95", "STOPWATCH",
      "Start",      "35",
      "Stop/Clear", "105",
      "Write",      "240",
      "HIDE STOPWATCH", "NEXT COL."},
  {"97", "about this",
      "", "45",
      "", "128",
      "", "219",
      "", ""},
  {"200", "[ALT]+[TAB]",
      "Left",   "45",
      "Right",  "128",
      "SELECT", "219",
      "", ""},
  {"202", "[WINDOWS]+[TAB]",
      "Left",   "45",
      "Right",  "128",
      "SELECT", "219",
      "TAB", "" },
  {"205", "ORCHIS LAUNCHER",
      "Up",     "48",
      "Down",   "128",
      "SELECT", "220",
      "", ""},
  {"239", "",
      "NO",     "50",
      "---",    "148",
      "YES",    "230",
      "", ""},

  {"","","","","","","","","",""}
};

const String btnMss[50][3] = {
  {"40", "1. OPEN THE FILE.", "2. SELECT THE APPLICATION."},
  {"41", "", "RESIST THE START PAGE."},
  {"42", "", "SELECT THE END PAGE."},
  {"44", "", "SELECT THE START PAGE."},
  {"45", "", "SELECT THE END PAGE."},
  {"48", "TIME INTERVAL?",
         " -> "},   /// with additional action
  {"49", "     sec. / ",
         "   TO SHOW THE NEXT PAGE"},   /// with additional action
  {"239", "HAVE ALREADY OPENED",
          ""},      /// with additional action

  {"", "", ""}
};

const short int btnStrokeNextmode[200][27] = {
  {1, 0,   // Acrobat Reader: TOP
    0, 0, 0, 0, 0,                    // botton "a"   /// with additional action
    KEY_PAGE_UP, 0, 0, 0, 0,          // botton "b"
    KEY_PAGE_DOWN, 0, 0, 0, 0,        // botton "c"
    KEY_LEFT_CTRL, 'l', 0, 0, 0,      // botton "B" = "b with a"
    KEY_LEFT_CTRL, KEY_TAB, 0, 0, 0}, // botton "C" = "c with a"
  {5, 2,   // movie & TV: TOP (play)
    0, 0, 0, 0, 6,
    KEY_LEFT_ALT, KEY_RETURN, 0, 0, 0,
    0x20, 0, 0, 0, 0,
    KEY_ESC, 0, 0, 0,
    0, 0, 0, 0, 99},
  {6, 2,   // movie & TV (tab)
    0, 0, 0, 0, 7,
    KEY_LEFT_SHIFT, KEY_TAB, 0, 0, 0,
    KEY_TAB, 0, 0, 0, 0,
    KEY_RETURN, 0, 0, 0, 0,
    0, 0, 0, 0, 5},
  {7, 2,   // movie & TV (arrow)
    0, 0, 0, 0, 8,
    KEY_LEFT_ARROW, 0, 0, 0, 0,
    KEY_RIGHT_ARROW, 0, 0, 0, 0,
    KEY_RETURN, 0, 0, 0, 0,
    0, 0, 0, 0, 5},
  {8, 2,   // movie & TV (volume)
    0, 0, 0, 0, 9,
    KEY_F8, 0, 0, 0, 0,
    KEY_F9, 0, 0, 0, 0,
    KEY_F7, 0, 0, 0, 0,
    0, 0, 0, 0, 5},
  {9, 2,   // movie & TV (close)
    0, 0, 0, 0, 5,
    0, 0, 0, 0, 0,
    KEY_LEFT_ALT, KEY_F4, 0, 0, 0,  /// with additional action
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 5},
  {10, 0,   // PowerPoint: TOP (edit)
    KEY_PAGE_UP, 0, 0, 0, 0,
    KEY_PAGE_DOWN, 0, 0, 0, 0,
    KEY_F5, 0, 0, 0, 11,
    KEY_LEFT_SHIFT, KEY_F5, 0, 0, 11,
    0, 0, 0, 0, 200},
  {11, 0,   // PowerPoint (slideshow)
    KEY_ESC, 0, 0, 0, 10,
    KEY_PAGE_UP, 0, 0, 0, 0,
    KEY_PAGE_DOWN, 0, 0, 0, 0,
    '-', 0, 0, 0, 12,
    0, 0, 0, 0, 200},
  {12, 0,   // PowerPoint (slide list)
    KEY_LEFT_ARROW, 0, 0, 0, 0,
    KEY_RIGHT_ARROW, 0, 0, 0, 0,
    KEY_RETURN, 0, 0, 0, 11,
    KEY_ESC, 0, 0, 0, 11,
    0, 0, 0, 0, 0},
  {15, 1,   // File Explorer 1/2 (entrance)
    KEY_UP_ARROW, 0, 0, 0, 0,
    KEY_DOWN_ARROW, 0, 0, 0, 0,
    KEY_RETURN, 0, 0, 0, 240,
    0, 0, 0, 0, 16,
    KEY_LEFT_ALT, KEY_UP_ARROW, 0, 0, 0},
  {16, 1,   // File Explorer 2/2
    KEY_LEFT_ARROW, 0, 0, 0, 0,
    KEY_RIGHT_ARROW, 0, 0, 0, 0,
    KEY_RETURN, 0, 0, 0, 240,
    0, 0, 0, 0, 15,
    KEY_LEFT_ALT, KEY_UP_ARROW, 0, 0, 0},
  {20, 2,   // MPC-BE (top)
    0, 0, 0, 0, 21,
    KEY_LEFT_CTRL, KEY_RETURN, 0, 0, 0,
    0x20, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0},     /// with additional action
  {21, 2,   // MPC-BE (jump backward/forward)
    0, 0, 0, 0, 22,
    KEY_LEFT_ARROW, 0, 0, 0, 0,
    KEY_RIGHT_ARROW, 0, 0, 0, 0,
    0x20, 0, 0, 0, 0,
    0, 0, 0, 0, 20},
  {22, 2,   // MPC-BE (frame step back/forward)
    0, 0, 0, 0, 23,
    KEY_LEFT_CTRL, KEY_LEFT_ARROW, 0, 0, 0,
    KEY_LEFT_CTRL, KEY_RIGHT_ARROW, 0, 0, 0,
    0x20, 0, 0, 0, 0,
    0, 0, 0, 0, 20},
  {23, 2,   // MPC-BE (volume control)
    0, 0, 0, 0, 24,
    KEY_DOWN_ARROW, 0, 0, 0, 0,
    KEY_UP_ARROW, 0, 0, 0, 0,
    KEY_LEFT_CTRL, 'm', 0, 0, 0,
    0, 0, 0, 0, 20},
  {24, 2,   // MPC-BE (display)
    0, 0, 0, 0, 20,
    0, 0, 0, 0, 0,
    KEY_LEFT_ALT, 'x', 0, 0, 0,     /// with additional action
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 20},
  {27, 2,   // photo (display)
    0, 0, 0, 0, 28,
    KEY_LEFT_GUI, KEY_LEFT_SHIFT, KEY_RETURN, 0, 0,
    KEY_LEFT_ALT, KEY_F4, 0, 0, 0,  /// with additional action
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0},
  {28, 2,   // photo (changing)
    0, 0, 0, 0, 27,
    KEY_LEFT_ARROW, 0, 0, 0, 0,
    KEY_RIGHT_ARROW, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0},
  {30, 2,   // Google Chrome (top)
    0, 0, 0, 0, 31,
    KEY_PAGE_UP, 0, 0, 0, 0,
    KEY_PAGE_DOWN, 0, 0, 0, 0,
    KEY_F11, 0, 0, 0, 0,
    KEY_LEFT_CTRL, KEY_TAB, 0, 0, 0},
  {31, 2,   // Google Chrome (up/down)
    0, 0, 0, 0, 32,
    KEY_UP_ARROW, 0, 0, 0, 0,
    KEY_DOWN_ARROW, 0, 0, 0, 0,
    KEY_F11, 0, 0, 0, 0,
    KEY_LEFT_CTRL, KEY_TAB, 0, 0, 0},
  {32, 2,   // Google Chrome (link)
    0, 0, 0, 0, 33,
    KEY_LEFT_SHIFT, KEY_TAB, 0, 0, 0,
    KEY_TAB, 0, 0, 0, 0,
    KEY_F11, 0, 0, 0, 0,
    KEY_RETURN, 0, 0, 0, 0},
  {33, 2,   // Google Chrome (page)
    0, 0, 0, 0, 34,
    KEY_LEFT_ALT, KEY_LEFT_ARROW, 0, 0, 0,
    KEY_LEFT_ALT, KEY_RIGHT_ARROW, 0, 0, 0,
    KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_TAB, 0, 0,
    KEY_LEFT_CTRL, KEY_TAB, 0, 0, 0},
  {34, 2,   // Google Chrome (minimize)
    0, 0, 0, 0, 30,
    0, 0, 0, 0, 0,    /// with additional action
    KEY_ESC, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0},
  {40, 0,   // REPEATING DISPLAY (application)
    0, 0, 0, 0, 41,    /// with additional action
    0, 0, 0, 0, 0,
    KEY_F5, 0, 0, 0, 44,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0},
  {41, 0,   // REPEATING Acr.Reader (start page)
    KEY_PAGE_UP, 0, 0, 0, 0,
    KEY_PAGE_DOWN, 0, 0, 0, 0,
    0, 0, 0, 0, 42,    /// with additional action
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0},
  {42, 0,   // REPEATING Acr.Reader (end page)
    KEY_PAGE_UP, 0, 0, 0, 0,    /// with additional action
    KEY_PAGE_DOWN, 0, 0, 0, 0,  /// with additional action
    0, 0, 0, 0, 48,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0},
  {44, 0,   // REPEATING PowerPoint (start page)
    KEY_PAGE_UP, 0, 0, 0, 0,
    KEY_PAGE_DOWN, 0, 0, 0, 0,
    0, 0, 0, 0, 45,    /// with additional action
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0},
  {45, 0,   // REPEATING PowerPoint (end page)
    KEY_PAGE_UP, 0, 0, 0, 0,    /// with additional action
    KEY_PAGE_DOWN, 0, 0, 0, 0,  /// with additional action
    0, 0, 0, 0, 48,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0},
  {48, 0,   // REPEATING DISPLAY (interval)
    0, 0, 0, 0, 0,    /// with additional action
    0, 0, 0, 0, 0,    /// with additional action
    0, 0, 0, 0, 0,    /// with additional action
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0},
  {49, 0,   // REPEATING DISPLAY (play)
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,    /// with additional action
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0},
  
  // 90: ALT + F4 (Close Window)
  // 95: stopwatch    /// with additional action
  {97, 2,   // about this
    0, 0, 0, 0, 240,
    0, 0, 0, 0, 240,
    0, 0, 0, 0, 240,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0},
  {202, 1,   // window selection (Win + Tab)
    KEY_LEFT_ARROW, 0, 0, 0, 0,
    KEY_RIGHT_ARROW, 0, 0, 0, 0,
    KEY_RETURN, 0, 0, 0, 0,   /// with additional action
    KEY_TAB, 0, 0, 0, 0,    /// with additional action
    0, 0, 0, 0, 0},
  // 200:  window selection (Alt + Tab)    /// with additional action
  {205, 1,   // Orchis Launcher
    KEY_UP_ARROW, 0, 0, 0, 0,
    KEY_DOWN_ARROW, 0, 0, 0, 0,
    KEY_RETURN, 0, 0, 0, 240,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0},
  {239, 0,   // the first question  
    0, 0, 0, 0, 240,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,  /// with additional action
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0},
  // 240:  application menu
  // 241:  application menu
  // 242:  application menu
  // 243:  application menu

  {0, 0,   // 
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0}
};
