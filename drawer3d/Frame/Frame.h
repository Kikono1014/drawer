#ifndef FRAME
#define FRAME
using std::string;
class Frame{
private:
    double framerate;
public:
    Frame(double framerate);

    double getFramerate();
    void setFramerate(double framerate);

    void setFrameBuffer(int x, int y, string value, string (&frameBuffer)[HEIGHT][WIDTH]);

    void delay(double time);
    void clear();
    void presentFrame(int width, int height, string (&frameBuffer)[HEIGHT][WIDTH]);
    void reset(int width, int height, string (&frameBuffer)[HEIGHT][WIDTH]);
    void updateFrame(int width, int height, string (&frameBuffer)[HEIGHT][WIDTH]);
};
#endif
