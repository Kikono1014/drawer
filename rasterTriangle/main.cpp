#include "header.h"
#include <math.h>

#include "TextStyle/TextStyle.h"
#include "Drawer/Drawer.h"
#include "Frame/Frame.h"

using std::string;
using namespace stl;

double framerate = 10.0;
string frameBuffer[HEIGHT][WIDTH];
Frame frame(framerate);

void getDescribesSquare(int peak1X, int peak1Y, int peak2X, int peak2Y, int peak3X, int peak3Y, int (&square)[4]) {
    square[0] = std::max(peak1X, std::max(peak2X, peak3X));
    square[1] = std::max(peak1Y, std::max(peak2Y, peak3Y));
    square[2] = std::min(peak1X, std::min(peak2X, peak3X));
    square[3] = std::min(peak1Y, std::min(peak2Y, peak3Y));
}

bool isInTriangel(double pixelX, double pixelY, double peak1X, double peak1Y, double peak2X, double peak2Y, double peak3X, double peak3Y) {
    double sideA = (peak1Y - peak2Y)*pixelX + (peak2X - peak1X)*pixelY + (peak1X*peak2Y - peak2X*peak1Y);
    double sideB = (peak2Y - peak3Y)*pixelX + (peak3X - peak2X)*pixelY + (peak2X*peak3Y - peak3X*peak2Y);
    double sideC = (peak3Y - peak1Y)*pixelX + (peak1X - peak3X)*pixelY + (peak3X*peak1Y - peak1X*peak3Y);
    return (sideA >= 0 && sideB >= 0 && sideC >= 0) || (sideA < 0 && sideB < 0 && sideC < 0);
}

void SetPolygon(int peak1X, int peak1Y, int peak2X, int peak2Y, int peak3X, int peak3Y) {
    int describesSquare[4];
    getDescribesSquare(peak1X, peak1Y, peak2X, peak2Y, peak3X, peak3Y, describesSquare);
    for (int y = describesSquare[3]; y < describesSquare[1]; ++y) {
        for (int x = describesSquare[2]; x < describesSquare[0]; ++x) {
            if (isInTriangel(x, y, peak1X, peak1Y, peak2X, peak2Y, peak3X, peak3Y)) {
                Drawer::SetPoint(x, y, "  ", frameBuffer, FG_DEFAULT, BG_RED);
            }
        }
    }
}

int main() {
    int width = WIDTH;
    int height = HEIGHT;
    frame.reset(width, height, frameBuffer);

    int peak1X = 3;
    int peak1Y = 17;

    int peak2X = 9;
    int peak2Y = 4;

    int peak3X = 30;
    int peak3Y = 22;

    while (true) {
        SetPolygon(15, 4, 60, 20, 7, 6);

        frame.presentFrame(width, height, frameBuffer);
        frame.updateFrame(width, height, frameBuffer);
    }

    return 0;
}
