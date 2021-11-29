#ifndef DRAWER
#define DRAWER
using std::string;
using namespace stl;
class Drawer {
public:
    static void SetPoint    (
                            int x, int y,
                            string value, string (&frameBuffer)[HEIGHT][WIDTH],
                            TextStyle fgcolor = FG_DEFAULT, TextStyle bgcolor = BG_DEFAULT, TextStyle style = NONE
                            );
    static void SetLine     (
                            int x0, int y0, int x1, int y1,
                            string value, string (&frameBuffer)[HEIGHT][WIDTH],
                            TextStyle fgcolor = FG_DEFAULT, TextStyle bgcolor = BG_DEFAULT, TextStyle style = NONE
                            );
    static void SetRectangle(
                            int x0, int y0, int width, int height,
                            string value, string (&frameBuffer)[HEIGHT][WIDTH],
                            TextStyle fgcolor = FG_DEFAULT, TextStyle bgcolor = BG_DEFAULT, TextStyle style = NONE
                            );

    static void SetSprite   (
                            int x0, int y0, int width, int height,
                            string **sprite, string (&frameBuffer)[HEIGHT][WIDTH],
                            TextStyle fgcolor = FG_DEFAULT, TextStyle bgcolor = BG_DEFAULT, TextStyle style = NONE
                            );
    static void SetColorSprite   (
                            int x0, int y0, int width, int height,
                            string **coloredSprite, string **sprite, string (&frameBuffer)[HEIGHT][WIDTH],
                            TextStyle fgcolor = FG_DEFAULT, TextStyle bgcolor = BG_DEFAULT, TextStyle style = NONE
                            );
};
#endif
