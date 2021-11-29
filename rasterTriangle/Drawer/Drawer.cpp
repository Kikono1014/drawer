#include "../header.h"
#include "../TextStyle/TextStyle.h"
#include "Drawer.h"
using std::string;
using namespace stl;

void Drawer::SetPoint (
                       int x, int y,
                       string value, string (&frameBuffer)[HEIGHT][WIDTH],
                       TextStyle fgcolor, TextStyle bgcolor, TextStyle style
                      )
{
    frameBuffer[y][x] = Text::setStyle(value, fgcolor, bgcolor, style);
}

void Drawer::SetLine (
                      int x0, int y0, int x1, int y1,
                      string value, string (&frameBuffer)[HEIGHT][WIDTH],
                      TextStyle fgcolor, TextStyle bgcolor, TextStyle style
                     )
{
    int deltaX = x1 - x0;
    int deltaY = y1 - y0;
    int absDeltaX = abs(deltaX);
    int absDeltaY = abs(deltaY);

    int accretion = 0;

    int centerX = (int)(absDeltaX / 2);
    int centerY = (int)(absDeltaY / 2);

    if (absDeltaX >= absDeltaY) {
        int y = y0;
        int const direction = deltaY != 0 ? (deltaY > 0 ? 1 : -1) : 0;
        for (int x = x0; deltaX > 0 ? x <= x1 : x >= x1; deltaX > 0 ? x++ : x--) {
            SetPoint(x, y, value, frameBuffer, fgcolor, bgcolor, style);
            accretion += absDeltaY;

            if (accretion >= absDeltaX) {
                accretion -= absDeltaX;
                y += direction;
            }
        }
    } else {
        int x = x0;
        const int direction = deltaX != 0 ? (deltaX > 0 ? 1 : -1) : 0;
        for (int y = y0; deltaY > 0 ? y <= y1 : y >= y1; deltaY > 0 ? y++ : y--) {
            SetPoint(x, y, value, frameBuffer, fgcolor, bgcolor, style);
            accretion += absDeltaX;

            if (accretion >= absDeltaY) {
                accretion -= absDeltaY;
                x += direction;
            }
        }
    }
}

void Drawer::SetRectangle (
                           int x0, int y0, int width, int height,
                           string value, string (&frameBuffer)[HEIGHT][WIDTH],
                           TextStyle fgcolor, TextStyle bgcolor, TextStyle style
                          )
{
    int x1 = x0 - (int)(width / 2);
    int x2 = x0 + (int)(width / 2);
    int y1 = y0 - (int)(height / 2);
    int y2 = y0 + (int)(height / 2);
    SetLine(x1, y1, x2, y1, value, frameBuffer, fgcolor, bgcolor, style);
    SetLine(x1, y2, x2, y2, value, frameBuffer, fgcolor, bgcolor, style);
    SetLine(x1, y1, x1, y2, value, frameBuffer, fgcolor, bgcolor, style);
    SetLine(x2, y1, x2, y2, value, frameBuffer, fgcolor, bgcolor, style);
}

void Drawer::SetSprite (
                        int x0, int y0, int width, int height,
                        string **sprite, string (&frameBuffer)[HEIGHT][WIDTH],
                        TextStyle fgcolor, TextStyle bgcolor, TextStyle style
                       )
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            SetPoint(x0+j, y0+i, sprite[i][j], frameBuffer, fgcolor, bgcolor, style);
        }
    }
}

void Drawer::SetColorSprite (
                        int x0, int y0, int width, int height,
                        string **coloredSprite, string **sprite, string (&frameBuffer)[HEIGHT][WIDTH],
                        TextStyle fgcolor, TextStyle bgcolor, TextStyle style
                       )
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (coloredSprite[i][j] == sprite[i][j])
                SetPoint(x0+j, y0+i, sprite[i][j], frameBuffer, fgcolor, bgcolor, style);
        }
    }
}
