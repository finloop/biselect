#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definicja prototypu funkcji na której operuje algorytm.
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

// Jedna z funkcji na której może działać algorytm.
double bsin(double x){
    return sin(x);
}


// Algorytm bisekcji.
// Parametry:
// x1 lewa granica przedziału
// x2 prawa granica przedziału
// getval funkcja na której operuje algorytm (dowolna funkcja która zwraca double
// przyjmuje jeden argument double)
// Przykład: double root = bisection_with_precision(M_PI_2,13/10*M_PI , bsin);
double bisection_with_precision(double x1, double x2, fun getval)
{
    // Sprawdzenie czy osiągneliśmy wymaganą precyzję
    while(fabs(x1-x2) >= 0.0001)
    {
        printf("Working on: x1: %f, x2: %f\n", x1, x2);
        printf("Current precision: %f \n", fabs(x1-x2));
        // Obliczenie warości funkcji dla granic i środka przedziału
        double v_x1 = getval(x1);
        double s = (x1+x2)/2.0;
        double v_s = getval(s);

        // Sprawdzam czy iloczyn lewej granicy i środka jest różnych znaków 
        if(v_x1*v_s > 0)
        {  
            // Jeżeli jest takich samych znaków to znaczy, że miejsce zerowe 
            // jest w [s,x2] zatem nadpisuję lewą granicę środkiem
            // przedziału
            x1 = s;
        } else {
            // Jeżeli nie jest to znaczy, że miejsce zerowe jest w [x1,1]
            // zatem nadpisuję prawą granicę środkiem przedziału
            x2 = s;
        }
    }
    printf("Done: %f      %f\n", x1, x2);
    printf("Precision: %f \n", fabs(x1-x2));
    return (x1+x2)/2.0;
}
