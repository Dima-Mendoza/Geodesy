#include <cmath>
#include <iomanip>
#include <xlsxwriter.h>
#include "geo_three_h.h"

long double toRadian(long double a);

int main() {

    long double b = 44797.282+12*18;

    long double A = 62.21257138888888888888;
    long double B = 50.33904222222222222222;
    long double C = 67.44991694444444444444;

    //коэфициент функции широты
    long double fi = 0.00000070277777777777;

    long double epsilon = ((fi * toRadian(pow(b,2)) * toRadian(sin(A)) * toRadian(sin (C))) 
                / toRadian((sin(B))) ) / 60 / 60;
    long double W = toRadian(A) + toRadian(B) + toRadian(C) - toRadian(180) - epsilon;

    long double deltai = -1*(W/3.0);

    bool tr = deltai * -3 == W;

    std::cout << tr << endl;

    return 0;
}

long double toRadian(long double a) {
    return a * (M_PI/180.0);
}