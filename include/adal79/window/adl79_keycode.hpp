#ifndef __ADAL79_WINDOW_ADL79_KEYCODE_H_
#define __ADAL79_WINDOW_ADL79_KEYCODE_H_

#include <SDL3/SDL.h>

constexpr int adlk_UNKNOWN              = SDLK_UNKNOWN;

// typewriter keys
constexpr int adlk_A                    = SDLK_A;
constexpr int adlk_B                    = SDLK_B;
constexpr int adlk_C                    = SDLK_C;
constexpr int adlk_D                    = SDLK_D;
constexpr int adlk_E                    = SDLK_E;
constexpr int adlk_F                    = SDLK_F;
constexpr int adlk_G                    = SDLK_G;
constexpr int adlk_H                    = SDLK_H;
constexpr int adlk_I                    = SDLK_I;
constexpr int adlk_J                    = SDLK_J;
constexpr int adlk_K                    = SDLK_K;
constexpr int adlk_L                    = SDLK_L;
constexpr int adlk_M                    = SDLK_M;
constexpr int adlk_N                    = SDLK_N;
constexpr int adlk_O                    = SDLK_O;
constexpr int adlk_P                    = SDLK_P;
constexpr int adlk_Q                    = SDLK_Q;
constexpr int adlk_R                    = SDLK_R;
constexpr int adlk_S                    = SDLK_S;
constexpr int adlk_T                    = SDLK_T;
constexpr int adlk_U                    = SDLK_U;
constexpr int adlk_V                    = SDLK_V;
constexpr int adlk_W                    = SDLK_W;
constexpr int adlk_X                    = SDLK_X;
constexpr int adlk_Y                    = SDLK_Y;
constexpr int adlk_Z                    = SDLK_Z;

// numerics
constexpr int adlk_0                    = SDLK_0;
constexpr int adlk_1                    = SDLK_1;
constexpr int adlk_2                    = SDLK_2;
constexpr int adlk_3                    = SDLK_3;
constexpr int adlk_4                    = SDLK_4;
constexpr int adlk_5                    = SDLK_5;
constexpr int adlk_6                    = SDLK_6;
constexpr int adlk_7                    = SDLK_7;
constexpr int adlk_8                    = SDLK_8;
constexpr int adlk_9                    = SDLK_9;

// numerics keypad keys
constexpr int adlk_KP_ENTER             = SDLK_KP_ENTER;
constexpr int adlk_KP_1                 = SDLK_KP_1;
constexpr int adlk_KP_2                 = SDLK_KP_2;
constexpr int adlk_KP_3                 = SDLK_KP_3;
constexpr int adlk_KP_4                 = SDLK_KP_4;
constexpr int adlk_KP_5                 = SDLK_KP_5;
constexpr int adlk_KP_6                 = SDLK_KP_6;
constexpr int adlk_KP_7                 = SDLK_KP_7;
constexpr int adlk_KP_8                 = SDLK_KP_8;
constexpr int adlk_KP_9                 = SDLK_KP_9;
constexpr int adlk_KP_0                 = SDLK_KP_0;


constexpr int adlk_RETURN               = SDLK_RETURN;
constexpr int adlk_ESCAPE               = SDLK_ESCAPE;
constexpr int adlk_BACKSPACE            = SDLK_BACKSPACE;
constexpr int adlk_TAB                  = SDLK_TAB;
constexpr int adlk_SPACE                = SDLK_SPACE;
constexpr int adlk_EXCLAIM              = SDLK_EXCLAIM;
constexpr int adlk_DBLAPOSTROPHE        = SDLK_DBLAPOSTROPHE;
constexpr int adlk_HASH                 = SDLK_HASH;
constexpr int adlk_DOLLAR               = SDLK_DOLLAR;
constexpr int adlk_PERCENT              = SDLK_PERCENT;
constexpr int adlk_AMPERSAND            = SDLK_AMPERSAND;
constexpr int adlk_APOSTROPHE           = SDLK_APOSTROPHE;
constexpr int adlk_LEFTPAREN            = SDLK_LEFTPAREN;
constexpr int adlk_RIGHTPAREN           = SDLK_RIGHTPAREN;
constexpr int adlk_ASTERISK             = SDLK_ASTERISK;
constexpr int adlk_PLUS                 = SDLK_PLUS;
constexpr int adlk_COMMA                = SDLK_COMMA;
constexpr int adlk_MINUS                = SDLK_MINUS;
constexpr int adlk_PERIOD               = SDLK_PERIOD;
constexpr int adlk_SLASH                = SDLK_SLASH;
constexpr int adlk_COLON                = SDLK_COLON;
constexpr int adlk_SEMICOLON            = SDLK_SEMICOLON;
constexpr int adlk_LESS                 = SDLK_LESS;
constexpr int adlk_EQUALS               = SDLK_EQUALS;
constexpr int adlk_GREATER              = SDLK_GREATER;
constexpr int adlk_QUESTION             = SDLK_QUESTION;
constexpr int adlk_AT                   = SDLK_AT;
constexpr int adlk_LEFTBRACKET          = SDLK_LEFTBRACKET;
constexpr int adlk_BACKSLASH            = SDLK_BACKSLASH;
constexpr int adlk_RIGHTBRACKET         = SDLK_RIGHTBRACKET;
constexpr int adlk_CARET                = SDLK_CARET;
constexpr int adlk_UNDERSCORE           = SDLK_UNDERSCORE;
constexpr int adlk_GRAVE                = SDLK_GRAVE;

constexpr int adlk_LEFTBRACE            = SDLK_LEFTBRACE;
constexpr int adlk_PIPE                 = SDLK_PIPE;
constexpr int adlk_RIGHTBRACE           = SDLK_RIGHTBRACE;
constexpr int adlk_TILDE                = SDLK_TILDE;
constexpr int adlk_DELETE               = SDLK_DELETE;
constexpr int adlk_PLUSMINUS            = SDLK_PLUSMINUS;
constexpr int adlk_CAPSLOCK             = SDLK_CAPSLOCK;
constexpr int adlk_F1                   = SDLK_F1;
constexpr int adlk_F2                   = SDLK_F2;
constexpr int adlk_F3                   = SDLK_F3;
constexpr int adlk_F4                   = SDLK_F4;
constexpr int adlk_F5                   = SDLK_F5;
constexpr int adlk_F6                   = SDLK_F6;
constexpr int adlk_F7                   = SDLK_F7;
constexpr int adlk_F8                   = SDLK_F8;
constexpr int adlk_F9                   = SDLK_F9;
constexpr int adlk_F10                  = SDLK_F10;
constexpr int adlk_F11                  = SDLK_F11;
constexpr int adlk_F12                  = SDLK_F12;
constexpr int adlk_PRINTSCREEN          = SDLK_PRINTSCREEN;
constexpr int adlk_SCROLLLOCK           = SDLK_SCROLLLOCK;
constexpr int adlk_PAUSE                = SDLK_PAUSE;
constexpr int adlk_INSERT               = SDLK_INSERT;
constexpr int adlk_HOME                 = SDLK_HOME;
constexpr int adlk_PAGEUP               = SDLK_PAGEUP;
constexpr int adlk_END                  = SDLK_END;
constexpr int adlk_PAGEDOWN             = SDLK_PAGEDOWN;

// control keys
constexpr int adlk_RIGHT                = SDLK_RIGHT;
constexpr int adlk_LEFT                 = SDLK_LEFT;
constexpr int adlk_DOWN                 = SDLK_DOWN;
constexpr int adlk_UP                   = SDLK_UP;

constexpr int adlk_NUMLOCKCLEAR         = SDLK_NUMLOCKCLEAR;
constexpr int adlk_KP_DIVIDE            = SDLK_KP_DIVIDE;
constexpr int adlk_KP_MULTIPLY          = SDLK_KP_MULTIPLY;
constexpr int adlk_KP_MINUS             = SDLK_KP_MINUS;
constexpr int adlk_KP_PLUS              = SDLK_KP_PLUS;


constexpr int adlk_KP_PERIOD            = SDLK_KP_PERIOD;
constexpr int adlk_APPLICATION          = SDLK_APPLICATION;
constexpr int adlk_POWER                = SDLK_POWER;
constexpr int adlk_KP_EQUALS            = SDLK_KP_EQUALS;
constexpr int adlk_F13                  = SDLK_F13;
constexpr int adlk_F14                  = SDLK_F14;
constexpr int adlk_F15                  = SDLK_F15;
constexpr int adlk_F16                  = SDLK_F16;
constexpr int adlk_F17                  = SDLK_F17;
constexpr int adlk_F18                  = SDLK_F18;
constexpr int adlk_F19                  = SDLK_F19;
constexpr int adlk_F20                  = SDLK_F20;
constexpr int adlk_F21                  = SDLK_F21;
constexpr int adlk_F22                  = SDLK_F22;
constexpr int adlk_F23                  = SDLK_F23;
constexpr int adlk_F24                  = SDLK_F24;
constexpr int adlk_EXECUTE              = SDLK_EXECUTE;
constexpr int adlk_HELP                 = SDLK_HELP;
constexpr int adlk_MENU                 = SDLK_MENU;
constexpr int adlk_SELECT               = SDLK_SELECT;
constexpr int adlk_STOP                 = SDLK_STOP;
constexpr int adlk_AGAIN                = SDLK_AGAIN;
constexpr int adlk_UNDO                 = SDLK_UNDO;
constexpr int adlk_CUT                  = SDLK_CUT;
constexpr int adlk_COPY                 = SDLK_COPY;
constexpr int adlk_PASTE                = SDLK_PASTE;
constexpr int adlk_FIND                 = SDLK_FIND;
constexpr int adlk_MUTE                 = SDLK_MUTE;
constexpr int adlk_VOLUMEUP             = SDLK_VOLUMEUP;
constexpr int adlk_VOLUMEDOWN           = SDLK_VOLUMEDOWN;
constexpr int adlk_KP_COMMA             = SDLK_KP_COMMA;
constexpr int adlk_KP_EQUALSAS400       = SDLK_KP_EQUALSAS400;
constexpr int adlk_ALTERASE             = SDLK_ALTERASE;
constexpr int adlk_SYSREQ               = SDLK_SYSREQ;
constexpr int adlk_CANCEL               = SDLK_CANCEL;
constexpr int adlk_CLEAR                = SDLK_CLEAR;
constexpr int adlk_PRIOR                = SDLK_PRIOR;
constexpr int adlk_RETURN2              = SDLK_RETURN2;
constexpr int adlk_SEPARATOR            = SDLK_SEPARATOR;
constexpr int adlk_OUT                  = SDLK_OUT;
constexpr int adlk_OPER                 = SDLK_OPER;
constexpr int adlk_CLEARAGAIN           = SDLK_CLEARAGAIN;
constexpr int adlk_CRSEL                = SDLK_CRSEL;
constexpr int adlk_EXSEL                = SDLK_EXSEL;
constexpr int adlk_KP_00                = SDLK_KP_00;
constexpr int adlk_KP_000               = SDLK_KP_000;
constexpr int adlk_THOUSANDSSEPARATOR   = SDLK_THOUSANDSSEPARATOR;
constexpr int adlk_DECIMALSEPARATOR     = SDLK_DECIMALSEPARATOR;
constexpr int adlk_CURRENCYUNIT         = SDLK_CURRENCYUNIT;
constexpr int adlk_CURRENCYSUBUNIT      = SDLK_CURRENCYSUBUNIT;
constexpr int adlk_KP_LEFTPAREN         = SDLK_KP_LEFTPAREN;
constexpr int adlk_KP_RIGHTPAREN        = SDLK_KP_RIGHTPAREN;
constexpr int adlk_KP_LEFTBRACE         = SDLK_KP_LEFTBRACE;
constexpr int adlk_KP_RIGHTBRACE        = SDLK_KP_RIGHTBRACE;
constexpr int adlk_KP_TAB               = SDLK_KP_TAB;
constexpr int adlk_KP_BACKSPACE         = SDLK_KP_BACKSPACE;
constexpr int adlk_KP_A                 = SDLK_KP_A;
constexpr int adlk_KP_B                 = SDLK_KP_B;
constexpr int adlk_KP_C                 = SDLK_KP_C;
constexpr int adlk_KP_D                 = SDLK_KP_D;
constexpr int adlk_KP_E                 = SDLK_KP_E;
constexpr int adlk_KP_F                 = SDLK_KP_F;
constexpr int adlk_KP_XOR               = SDLK_KP_XOR;
constexpr int adlk_KP_POWER             = SDLK_KP_POWER;
constexpr int adlk_KP_PERCENT           = SDLK_KP_PERCENT;
constexpr int adlk_KP_LESS              = SDLK_KP_LESS;
constexpr int adlk_KP_GREATER           = SDLK_KP_GREATER;
constexpr int adlk_KP_AMPERSAND         = SDLK_KP_AMPERSAND;
constexpr int adlk_KP_DBLAMPERSAND      = SDLK_KP_DBLAMPERSAND;
constexpr int adlk_KP_VERTICALBAR       = SDLK_KP_VERTICALBAR;
constexpr int adlk_KP_DBLVERTICALBAR    = SDLK_KP_DBLVERTICALBAR;
constexpr int adlk_KP_COLON             = SDLK_KP_COLON;
constexpr int adlk_KP_HASH              = SDLK_KP_HASH;
constexpr int adlk_KP_SPACE             = SDLK_KP_SPACE;
constexpr int adlk_KP_AT                = SDLK_KP_AT;
constexpr int adlk_KP_EXCLAM            = SDLK_KP_EXCLAM;
constexpr int adlk_KP_MEMSTORE          = SDLK_KP_MEMSTORE;
constexpr int adlk_KP_MEMRECALL         = SDLK_KP_MEMRECALL;
constexpr int adlk_KP_MEMCLEAR          = SDLK_KP_MEMCLEAR;
constexpr int adlk_KP_MEMADD            = SDLK_KP_MEMADD;
constexpr int adlk_KP_MEMSUBTRACT       = SDLK_KP_MEMSUBTRACT;
constexpr int adlk_KP_MEMMULTIPLY       = SDLK_KP_MEMMULTIPLY;
constexpr int adlk_KP_MEMDIVIDE         = SDLK_KP_MEMDIVIDE;
constexpr int adlk_KP_PLUSMINUS         = SDLK_KP_PLUSMINUS;
constexpr int adlk_KP_CLEAR             = SDLK_KP_CLEAR;
constexpr int adlk_KP_CLEARENTRY        = SDLK_KP_CLEARENTRY;
constexpr int adlk_KP_BINARY            = SDLK_KP_BINARY;
constexpr int adlk_KP_OCTAL             = SDLK_KP_OCTAL;
constexpr int adlk_KP_DECIMAL           = SDLK_KP_DECIMAL;
constexpr int adlk_KP_HEXADECIMAL       = SDLK_KP_HEXADECIMAL;
constexpr int adlk_LCTRL                = SDLK_LCTRL;
constexpr int adlk_LSHIFT               = SDLK_LSHIFT;
constexpr int adlk_LALT                 = SDLK_LALT;
constexpr int adlk_LGUI                 = SDLK_LGUI;
constexpr int adlk_RCTRL                = SDLK_RCTRL;
constexpr int adlk_RSHIFT               = SDLK_RSHIFT;
constexpr int adlk_RALT                 = SDLK_RALT;
constexpr int adlk_RGUI                 = SDLK_RGUI;
constexpr int adlk_MODE                 = SDLK_MODE;
constexpr int adlk_SLEEP                = SDLK_SLEEP;
constexpr int adlk_WAKE                 = SDLK_WAKE;
constexpr int adlk_CHANNEL_INCREMENT    = SDLK_CHANNEL_INCREMENT;
constexpr int adlk_CHANNEL_DECREMENT    = SDLK_CHANNEL_DECREMENT;
constexpr int adlk_MEDIA_PLAY           = SDLK_MEDIA_PLAY;
constexpr int adlk_MEDIA_PAUSE          = SDLK_MEDIA_PAUSE;
constexpr int adlk_MEDIA_RECORD         = SDLK_MEDIA_RECORD;
constexpr int adlk_MEDIA_FAST_FORWARD   = SDLK_MEDIA_FAST_FORWARD;
constexpr int adlk_MEDIA_REWIND         = SDLK_MEDIA_REWIND;
constexpr int adlk_MEDIA_NEXT_TRACK     = SDLK_MEDIA_NEXT_TRACK;
constexpr int adlk_MEDIA_PREVIOUS_TRACK = SDLK_MEDIA_PREVIOUS_TRACK;
constexpr int adlk_MEDIA_STOP           = SDLK_MEDIA_STOP;
constexpr int adlk_MEDIA_EJECT          = SDLK_MEDIA_EJECT;
constexpr int adlk_MEDIA_PLAY_PAUSE     = SDLK_MEDIA_PLAY_PAUSE;
constexpr int adlk_MEDIA_SELECT         = SDLK_MEDIA_SELECT;
constexpr int adlk_AC_NEW               = SDLK_AC_NEW;
constexpr int adlk_AC_OPEN              = SDLK_AC_OPEN;
constexpr int adlk_AC_CLOSE             = SDLK_AC_CLOSE;
constexpr int adlk_AC_EXIT              = SDLK_AC_EXIT;
constexpr int adlk_AC_SAVE              = SDLK_AC_SAVE;
constexpr int adlk_AC_PRINT             = SDLK_AC_PRINT;
constexpr int adlk_AC_PROPERTIES        = SDLK_AC_PROPERTIES;
constexpr int adlk_AC_SEARCH            = SDLK_AC_SEARCH;
constexpr int adlk_AC_HOME              = SDLK_AC_HOME;
constexpr int adlk_AC_BACK              = SDLK_AC_BACK;
constexpr int adlk_AC_FORWARD           = SDLK_AC_FORWARD;
constexpr int adlk_AC_STOP              = SDLK_AC_STOP;
constexpr int adlk_AC_REFRESH           = SDLK_AC_REFRESH;
constexpr int adlk_AC_BOOKMARKS         = SDLK_AC_BOOKMARKS;
constexpr int adlk_SOFTLEFT             = SDLK_SOFTLEFT;
constexpr int adlk_SOFTRIGHT            = SDLK_SOFTRIGHT;
constexpr int adlk_CALL                 = SDLK_CALL;
constexpr int adlk_ENDCALL              = SDLK_ENDCALL;
constexpr int adlk_LEFT_TAB             = SDLK_LEFT_TAB;
constexpr int adlk_LEVEL5_SHIFT         = SDLK_LEVEL5_SHIFT;
constexpr int adlk_MULTI_KEY_COMPOSE    = SDLK_MULTI_KEY_COMPOSE;
constexpr int adlk_LMETA                = SDLK_LMETA;
constexpr int adlk_RMETA                = SDLK_RMETA;
constexpr int adlk_LHYPER               = SDLK_LHYPER;
constexpr int adlk_RHYPER               = SDLK_RHYPER;

#endif // __ADAL79_WINDOW_ADL79_KEYCODE_H_
