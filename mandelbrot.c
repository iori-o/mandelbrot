#include <stdio.h>
#include <math.h>

#define WIDTH 201
#define HEIGHT 50
#define MAX_TRAIL 200

int check_divergence(int x, int y);

int main(int argc, char *argv[])
{
    int x, y;
    for (y = 0; y < HEIGHT; ++y)
    {
        for (x = 0; x < WIDTH; ++x)
        {
            int e = check_divergence(x, y);

            if (e > 0) {
                putchar('A' + (e - 1) % 26);
            } else {
                putchar(' ');
            }
        }
    }
    puts("");
}

int check_divergence(int x, int y) {
    int i;
    double xn = 0.0;
    double yn = 0.0;

    double a = (x * 1.0 / WIDTH) * 3.0 - 2.0;
    double b = (y * 1.0 / HEIGHT) * 2.0 - 1.0;

    for (i = 0; i < MAX_TRAIL; ++i)
    {
        double pxn = xn;
        double pyn = yn;

        xn = pow(pxn, 2) - pow(pyn, 2) + a;
        yn = 2 * pxn * pyn + b;

        double z = pow(xn, 2) + pow(yn, 2);
        if (z > 4.0) {
            return i;
        }
    }
    return 0;
}
