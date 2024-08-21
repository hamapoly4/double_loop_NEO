#ifndef ___CLASS_COLORDETECT
#define ___CLASS_COLORDETECT

#include "ColorSensor.h"

class ColorDetect {
private:
    static ev3api::ColorSensor mColorSensor;

    enum eColor { BLACK, BLUE, ELSE, };

    rgb_raw_t mrgb;
    float mmax;
    float mmin;
    int mhue;
    int msaturation;
    int mvalue;
    unsigned char mcolor;

public:
    ColorDetect();
    unsigned char detectColor();
    void convHSV();
    void setRGB();
    void calcMax();
    void calcMin();
    void calcH();
    void calcS();
    void calcV();
};

#endif // ___CLASS_COLORDETECT