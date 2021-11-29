#include <math.h>
#include "../config.h"
#include "../TextStyle/TextStyle.h"
#include "Drawer.h"
using std::string;
using namespace stl;

Point::Point () {
    this->x = 0;
    this->y = 0;
    this->z = SCREEN_Z;
    this->value = "  ";
    this->type = BG_RGB;
    this->color = RGB(255, 255, 255);
    this->style = NONE;
}

Point::Point (int x, int y) {
    this->x = x;
    this->y = y;
    this->z = SCREEN_Z;
    this->value = "  ";
    this->type = BG_RGB;
    this->color = RGB(255, 255, 255);
    this->style = NONE;
}

Point::Point (int x, int y, string value, RGB color, TextStyle type) {
    this->x = x;
    this->y = y;
    this->z = SCREEN_Z;
    this->value = value;
    this->type = type;
    this->color = color;
    this->style = NONE;
}

Point::Point (int x, int y, string value, RGB color, TextStyle type, TextStyle style) {
    this->x = x;
    this->y = y;
    this->z = SCREEN_Z;
    this->value = value;
    this->type = type;
    this->color = color;
    this->style = style;
}

Point::Point (int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->value = "  ";
    this->type = BG_RGB;
    this->color = RGB(255, 255, 255);
    this->style = NONE;
}

Point::Point (int x, int y, int z, string value, RGB color, TextStyle type) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->value = value;
    this->type = type;
    this->color = color;
    this->style = NONE;
}

Point::Point (int x, int y, int z, string value, RGB color, TextStyle type, TextStyle style) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->value = value;
    this->type = type;
    this->color = color;
    this->style = style;
}

Polygon::Polygon () {
    this->p1 = Point(0, 0, 0, "  ", RGB(255, 255, 255), BG_RGB);
    this->p2 = Point(0, 0, 0, "  ", RGB(255, 255, 255), BG_RGB);
    this->p3 = Point(0, 0, 0, "  ", RGB(255, 255, 255), BG_RGB);
}

Polygon::Polygon (Point p1, Point p2, Point p3) {
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}


void Drawer::SetPoint (
                       string (&frameBuffer)[HEIGHT][WIDTH],
                       int x, int y, string value,
                       RGB color, TextStyle type, TextStyle style
                      )
{
    x = (x == abs(x)) ? x : WIDTH  + x;
    y = (y == abs(y)) ? y : HEIGHT + y;

    frameBuffer[y][x] = Text::setRGB(value, color, type, style);
}

void Drawer::SetLine (
                      string (&frameBuffer)[HEIGHT][WIDTH],
                      Point p0, Point p1
                     )
{
    RGB color = p0.color;
    int deltaX = p1.x - p0.x;
    int deltaY = p1.y - p0.y;
    int absDeltaX = abs(deltaX);
    int absDeltaY = abs(deltaY);
    int len = sqrt(absDeltaX*absDeltaX + absDeltaY*absDeltaY);

    RGB deltaColor = p1.color - p0.color;

    int wColorR = (p1.color.r - p0.color.r) / len;
    int wColorG = (p1.color.g - p0.color.g) / len;
    int wColorB = (p1.color.b - p0.color.b) / len;

    int accretion = 0;

    int centerX = (int)(absDeltaX / 2);
    int centerY = (int)(absDeltaY / 2);

    if (absDeltaX >= absDeltaY) {
        int y = p0.y;
        int const direction = deltaY != 0 ? (deltaY > 0 ? 1 : -1) : 0;
        for (int x = p0.x; deltaX > 0 ? x <= p1.x : x >= p1.x; deltaX > 0 ? x++ : x--) {
            SetPoint(frameBuffer, x, y, p0.value, color, p0.type, p0.style);
            accretion += absDeltaY;
            color = RGB(p0.color.r + wColorR*sqrt((x-p0.x)*(x-p0.x) + (y-p0.y)*(y-p0.y)), p0.color.g + wColorG*sqrt((x-p0.x)*(x-p0.x) + (y-p0.y)*(y-p0.y)), p0.color.b + wColorB*sqrt((x-p0.x)*(x-p0.x) + (y-p0.y)*(y-p0.y)));
            if (accretion >= absDeltaX) {
                accretion -= absDeltaX;
                y += direction;
            }
        }
    } else {
        int x = p0.x;
        const int direction = deltaX != 0 ? (deltaX > 0 ? 1 : -1) : 0;
        for (int y = p0.y; deltaY > 0 ? y <= p1.y : y >= p1.y; deltaY > 0 ? y++ : y--) {
            SetPoint(frameBuffer, x, y, p0.value, color, p0.type, p0.style);
            accretion += absDeltaX;
            color = RGB(p0.color.r + wColorR*sqrt((x-p0.x)*(x-p0.x) + (y-p0.y)*(y-p0.y)), p0.color.g + wColorG*sqrt((x-p0.x)*(x-p0.x) + (y-p0.y)*(y-p0.y)), p0.color.b + wColorB*sqrt((x-p0.x)*(x-p0.x) + (y-p0.y)*(y-p0.y)));
            if (accretion >= absDeltaY) {
                accretion -= absDeltaY;
                x += direction;
            }
        }
    }
}

void Drawer::SetRectangle (
                           string (&frameBuffer)[HEIGHT][WIDTH],
                           Point p0, int width, int height
                          )
{
    int x1 = p0.x - (int)(width / 2);
    int x2 = p0.x + (int)(width / 2);
    int y1 = p0.y - (int)(height / 2);
    int y2 = p0.y + (int)(height / 2);
    SetLine (
             frameBuffer,
             Point(x1, y1, p0.value, p0.color, p0.type, p0.style),
             Point(x2, y1, p0.value, p0.color, p0.type, p0.style)
            );
    SetLine (
             frameBuffer,
             Point(x1, y2, p0.value, p0.color, p0.type, p0.style),
             Point(x2, y2, p0.value, p0.color, p0.type, p0.style)
            );
    SetLine (
             frameBuffer,
             Point(x1, y1, p0.value, p0.color, p0.type, p0.style),
             Point(x1, y2, p0.value, p0.color, p0.type, p0.style)
            );
    SetLine (
             frameBuffer,
             Point(x2, y1, p0.value, p0.color, p0.type, p0.style),
             Point(x2, y2, p0.value, p0.color, p0.type, p0.style)
            );
}

void Drawer::SetCircle (
                           string (&frameBuffer)[HEIGHT][WIDTH],
                           Point p0, int radius
                          )
{
    for (int y = p0.y-radius; y < p0.y+radius+1; ++y) {
        for (int x = p0.x-radius; x < p0.x+radius+1; ++x) {
            int deltaX = x - p0.x;
            int deltaY = y - p0.y;
            int len = sqrt(deltaX*deltaX+deltaY*deltaY);

            if (len == radius) {
                SetPoint(frameBuffer, x, y, p0.value, p0.color, p0.type, p0.style);
            }
        }
    }
}

void Drawer::getDescribesSquare(Point p1, Point p2, Point p3, int (&square)[4]) {
    square[0] = std::max(p1.x, std::max(p2.x, p3.x));
    square[1] = std::max(p1.y, std::max(p2.y, p3.y));
    square[2] = std::min(p1.x, std::min(p2.x, p3.x));
    square[3] = std::min(p1.y, std::min(p2.y, p3.y));
}

bool Drawer::isInTriangel(int x, int y, Point p1, Point p2, Point p3) {
    double sideA = (p1.y - p2.y)*x + (p2.x - p1.x)*y + (p1.x*p2.y - p2.x*p1.y);
    double sideB = (p2.y - p3.y)*x + (p3.x - p2.x)*y + (p2.x*p3.y - p3.x*p2.y);
    double sideC = (p3.y - p1.y)*x + (p1.x - p3.x)*y + (p3.x*p1.y - p1.x*p3.y);
    return (sideA >= 0 && sideB >= 0 && sideC >= 0) || (sideA < 0 && sideB < 0 && sideC < 0);
}

Point Drawer::getIntersectionPointOfPerpendicularLines(int px, int py, Point p1, Point p2) {
    double x = 0;
    double y = 0;
    double dx = p1.x - p2.x;
    if (abs(dx) < 0.001) {
        int m = 0;
        int c = -px * m + py;
        x = p1.x;
        y = m * x + c;
    } else {
        double lineM = (p1.y - p2.y) / dx;
        if(abs(lineM) < 0.001){
            x = px;
            y = p1.y;
        } else {
            double m = -1 / lineM;
            double c = -px * m + py;
            x = ((p1.y - lineM * p1.x) - c) / (m - lineM);
            y = m * x + c;
        }
    }
    return Point(x, y, p1.value, p1.color, p1.type, p1.style);
}

void Drawer::setPolygonBrightness (Polygon &pol) {
    double wDarkness1 = (pol.p1.z < RAYLEN) ? (255 / RAYLEN) * pol.p1.z : -1;
    double wDarkness2 = (pol.p2.z < RAYLEN) ? (255 / RAYLEN) * pol.p2.z : -1;
    double wDarkness3 = (pol.p3.z < RAYLEN) ? (255 / RAYLEN) * pol.p3.z : -1;

    pol.p1.color = RGB(
        (pol.p1.color.r > wDarkness1) ? pol.p1.color.r - wDarkness1 : pol.p1.color.r,
        (pol.p1.color.g > wDarkness1) ? pol.p1.color.g - wDarkness1 : pol.p1.color.g,
        (pol.p1.color.b > wDarkness1) ? pol.p1.color.b - wDarkness1 : pol.p1.color.b);
    pol.p2.color = RGB(
        (pol.p2.color.r > wDarkness2) ? pol.p2.color.r - wDarkness2 : pol.p2.color.r,
        (pol.p2.color.g > wDarkness2) ? pol.p2.color.g - wDarkness2 : pol.p2.color.g,
        (pol.p2.color.b > wDarkness2) ? pol.p2.color.b - wDarkness2 : pol.p2.color.b);
    pol.p3.color = RGB(
        (pol.p3.color.r > wDarkness3) ? pol.p3.color.r - wDarkness3 : pol.p3.color.r,
        (pol.p3.color.g > wDarkness3) ? pol.p3.color.g - wDarkness3 : pol.p3.color.g,
        (pol.p3.color.b > wDarkness3) ? pol.p3.color.b - wDarkness3 : pol.p3.color.b);

}


void Drawer::SetPolygon(
                        string (&frameBuffer)[HEIGHT][WIDTH],
                        Point p1, Point p2, Point p3
                       )
{
    Polygon pol(p1, p2, p3);
    setPolygonBrightness(pol);

    int describesSquare[4];
    Point oldP1 = pol.p1;
    pol.p2 = pol.p2 - pol.p1;
    pol.p3 = pol.p3 - pol.p1;
    pol.p1 = pol.p1 - pol.p1;

    if (pol.p3.y == 0) {
        Point temp = pol.p3;
        pol.p3 = Point(pol.p2.x, pol.p2.y, pol.p2.value, pol.p2.color, pol.p2.type, pol.p2.style);
        pol.p2 = Point(temp.x, temp.y, temp.value, temp.color, temp.type, temp.style);
    }

    double deltaColor1R = pol.p2.color.r - pol.p1.color.r;
    double deltaColor1G = pol.p2.color.g - pol.p1.color.g;
    double deltaColor1B = pol.p2.color.b - pol.p1.color.b;

    double deltaColor2R = pol.p3.color.r - pol.p1.color.r;
    double deltaColor2G = pol.p3.color.g - pol.p1.color.g;
    double deltaColor2B = pol.p3.color.b - pol.p1.color.b;

    getDescribesSquare(pol.p1, pol.p2, pol.p3, describesSquare);
    for (int y = describesSquare[3]; y < describesSquare[1]; ++y) {
        for (int x = describesSquare[2]; x < describesSquare[0]; ++x) {

            double w1 = static_cast<double>(y * pol.p3.x - x * pol.p3.y) / static_cast<double>(pol.p2.y*pol.p3.x - pol.p2.x*pol.p3.y);
            if (w1 >= 0 && w1 <= 1) {
                double w2 = static_cast<double>(y - w1*pol.p2.y) / static_cast<double>(pol.p3.y);
                if (w2 >= 0 && (w1+w2) <= 1) {
                    double r = pol.p1.color.r + (deltaColor1R * w1) + (deltaColor2R * w2);
                    double g = pol.p1.color.g + (deltaColor1G * w1) + (deltaColor2G * w2);
                    double b = pol.p1.color.b + (deltaColor1B * w1) + (deltaColor2B * w2);

                    Drawer::SetPoint(frameBuffer, oldP1.x + x, oldP1.y + y, pol.p1.value, RGB(r, g, b), pol.p1.type, pol.p1.style);
                }
            }
        }
    }
}


void Drawer::SetCube (
                      string (&frameBuffer)[HEIGHT][WIDTH],
                      int len, Point p0
                     )
{
    p0.x = (((p0.x - CAM_X) * (SCREEN_Z - CAM_Z)) / p0.z) + CAM_X;
    p0.y = (((p0.y - CAM_Y) * (SCREEN_Z - CAM_Z)) / p0.z) + CAM_Y;

    len = ((len * (SCREEN_Z - CAM_Z)) / p0.z);

    Drawer::SetPolygon(frameBuffer,
                        Point(p0.x, p0.y, p0.z, p0.value, p0.color, p0.type, p0.style),
                        Point(p0.x+(len/2), p0.y-(len/2), p0.z+len, p0.value, p0.color, p0.type, p0.style),
                        Point(p0.x+len, p0.y, p0.z, p0.value, p0.color, p0.type, p0.style)
                        );
    Drawer::SetPolygon(frameBuffer,
                        Point(p0.x+(len/2), p0.y-(len/2), p0.z+len, p0.value, p0.color, p0.type, p0.style),
                        Point(p0.x+len+(len/2), p0.y-(len/2), p0.z+len, p0.value, p0.color, p0.type, p0.style),
                        Point(p0.x+len, p0.y, p0.z, p0.value, p0.color, p0.type, p0.style)
                        );

    Drawer::SetPolygon(frameBuffer,
                        Point(p0.x+len, p0.y, p0.z, p0.value, p0.color, p0.type, p0.style),
                        Point(p0.x+len+(len/2), p0.y-(len/2), p0.z+len, p0.value, p0.color, p0.type, p0.style),
                        Point(p0.x+len+(len/2), p0.y+(len/2), p0.z+len, p0.value, p0.color, p0.type, p0.style)
                        );
    Drawer::SetPolygon(frameBuffer,
                        Point(p0.x+len, p0.y, p0.z, p0.value, p0.color, p0.type, p0.style),
                        Point(p0.x+len+(len/2), p0.y+(len/2), p0.z+len, p0.value, p0.color, p0.type, p0.style),
                        Point(p0.x+len, p0.y+len, p0.z, p0.value, p0.color, p0.type, p0.style)
                        );

    Drawer::SetPolygon(frameBuffer,
                        Point(p0.x+len, p0.y, p0.z, p0.value, p0.color, p0.type, p0.style),
                        Point(p0.x+len, p0.y+len, p0.z, p0.value, p0.color, p0.type, p0.style),
                        Point(p0.x, p0.y+len, p0.z, p0.value, p0.color, p0.type, p0.style)
                        );
    Drawer::SetPolygon(frameBuffer,
                        Point(p0.x+len, p0.y, p0.z, p0.value, p0.color, p0.type, p0.style),
                        Point(p0.x, p0.y+len, p0.z, p0.value, p0.color, p0.type, p0.style),
                        Point(p0.x, p0.y, p0.z, p0.value, p0.color, p0.type, p0.style)
                        );
}
