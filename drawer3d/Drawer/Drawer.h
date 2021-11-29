#ifndef DRAWER
#define DRAWER
using std::string;
using namespace stl;
struct Point {
    int x;
    int y;
    int z;
    string value;
    RGB color;
    TextStyle type;
    TextStyle style;
    Point ();
    Point (int x, int y);
    Point (int x, int y, string value, RGB color, TextStyle type);
    Point (int x, int y, string value, RGB color, TextStyle type, TextStyle style);
    Point (int x, int y, int z);
    Point (int x, int y, int z, string value, RGB color, TextStyle type);
    Point (int x, int y, int z, string value, RGB color, TextStyle type, TextStyle style);
    Point operator+ (Point other) { return Point(x + other.x, y + other.y, value, color, type, style); }
    Point operator- (Point other) { return Point(x - other.x, y - other.y, value, color, type, style); }

};

struct Polygon {
    Point p1;
    Point p2;
    Point p3;

    Polygon ();
    Polygon (Point p1, Point p2, Point p3);

};

class Drawer {
public:
    static void SetPoint    (
                             string (&frameBuffer)[HEIGHT][WIDTH],
                             int x, int y, string value,
                             RGB color, TextStyle type, TextStyle style = NONE
                            );

    static void SetLine     (
                             string (&frameBuffer)[HEIGHT][WIDTH],
                             Point p0, Point p1
                            );
    static void SetRectangle(
                             string (&frameBuffer)[HEIGHT][WIDTH],
                             Point p0, int width, int height
                            );
    static void SetCircle   (
                             string (&frameBuffer)[HEIGHT][WIDTH],
                             Point p0, int radius
                            );

    static void getDescribesSquare(Point peak1, Point peak2, Point peak3, int (&square)[4]);

    static bool isInTriangel(int x, int y, Point peak1, Point peak2, Point peak3);

    static Point getIntersectionPointOfPerpendicularLines(int px, int py, Point p1, Point p2);

    static void setPolygonBrightness (Polygon &pol);

    static void SetPolygon(
                            string (&frameBuffer)[HEIGHT][WIDTH],
                            Point peak1, Point peak2, Point peak3
                          );

    static void SetCube (
                          string (&frameBuffer)[HEIGHT][WIDTH],
                          int len, Point p0
                         );
};
#endif
