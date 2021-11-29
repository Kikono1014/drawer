namespace stl {
    enum TextStyle {
        FG_BLACK      = 30,
        FG_RED        = 31,
        FG_GREEN      = 32,
        FG_YELLOW     = 33,
        FG_BLUE       = 34,
        FG_MAGENTA    = 35,
        FG_CYAN       = 36,
        FG_WHITE      = 37,
        FG_RGB        = 38,
        FG_DEFAULT    = 39,

        BG_BLACK      = 40,
        BG_RED        = 41,
        BG_GREEN      = 42,
        BG_YELLOW     = 43,
        BG_BLUE       = 44,
        BG_MAGENTA    = 45,
        BG_CYAN       = 46,
        BG_WHITE      = 47,
        BG_RGB        = 48,
        BG_DEFAULT    = 49,

        ST_BOLD       = 1,
        ST_DIM        = 2,
        ST_UNDERLINED = 4,
        ST_BLINK      = 5,
        ST_REVERSE    = 7,
        ST_HIDDEN     = 8,

        NONE          = 0
    };

    struct RGB{
        unsigned char r;
        unsigned char g;
        unsigned char b;
        RGB ();
        RGB (unsigned char r, unsigned char g, unsigned char b);
        RGB operator+ (RGB const other)    { return RGB(r + other.r, g + other.g, b + other.b); }
        RGB operator- (RGB const other)    { return RGB(r - other.r, g - other.g, b - other.b); }
        RGB operator* (RGB const other)    { return RGB(r * other.r, g * other.g, b * other.b); }
        RGB operator* (double const value) { return RGB(r * value  , g * value  , b * value  ); }
        RGB operator/ (double const value) { return RGB(r / value  , g / value  , b / value  ); }
    };

    class Text {
    public:
        static std::string setStyle(std::string text, TextStyle fgcolor = FG_DEFAULT, TextStyle bgcolor = BG_DEFAULT, TextStyle style = NONE);
        static std::string setRGB  (std::string text, RGB color, TextStyle fgrgb = NONE, TextStyle style = NONE);
    };

}



