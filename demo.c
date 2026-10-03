#include <stdio.h>
#include <math.h>

int main() {
        double minU = 100000000000.0, minY, minX, rU;
        for (double  x = 0; x <= 2; x += 0.3)
        {
                for (double y = 0; y <= 1; y += 0.4) 
                {
                        rU = 4.0 * cos(pow(y, 1.0/3.0)) * sin(x * fabs(pow(y, 3) - 1.4));
                        if (minU > rU) 
                        {
                                minU = rU;
                                minX = x;
                                minY = y;
                        }
                }
        }
        printf("Minimmum_U: %f\n", minU);
        printf("x and y: %f, %f\n", minX, minY); 

        return 0;
}
