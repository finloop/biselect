#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef double( * fun ) (double);
double bsin(double);

double bisection_with_precision(double x1, double x2, fun getval);

int main()
{
    double x1 = M_PI_2;
    double x2 = 13/10*M_PI;
    double r = bisection_with_precision(x1,x2 , bsin);
    printf("Done: %f\n", r);
    return 0;
}

double bsin(double x){
    return sin(x);
}

double bisection_with_precision(double x1, double x2, fun getval)
{
    // 0.0001 to precyzja jej zwiększenie to
    while(fabs(x1-x2) >= 0.0001)
    {
        printf("Working on: x1: %f, x2: %f\n", x1, x2);
        printf("Current precision: %f \n", fabs(x1-x2));
        double v_x1 = getval(x1);
        double v_x2 = getval(x2);
        double s = (x1+x2)/2.0;
        double v_s = getval(s);

        if(v_x1*v_s > 0)
        {
            x1 = s;
            printf("x1: Found root on the right side.\n");
        } else
        if (v_s*v_x2 > 0)
        {
            x2 = s;
            printf("x2: Found root on the left side \n");
        } else {
            printf("x0: Found zero in one of known values.\n");
            if (v_x1 == 0)
                return x1;
            if (v_x2 == 0)
                return x2;
            if (v_s == 0)
                return s;
        }
    }
    printf("Done: %f      %f\n", x1, x2);
    printf("Precision: %f \n", fabs(x1-x2));
    return (x1+x2)/2.0;
}
