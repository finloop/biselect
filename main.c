#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definicja prototypu funkcji na której operuje algorytm.
typedef double( * fun ) (double);

double bsin(double);
double wiel(double);

double bisection_with_precision(double x1, double x2, fun getval, double precision);

int main()
{
    double x1 = 2.5;
    double x2 = 5.0;
    double r = bisection_with_precision(x1,x2 , sin, 0.01);
    printf("Done: %f\n", r);
    return 0;
}

// Jedna z funkcji na której może działać algorytm.
double bsin(double x){
    return sin(x);
}

// Jedna z funkcji na której może działać algorytm.
double wiel(double x){
    return 3*(x-3)*(x-50)*(x+50);
}

// Algorytm bisekcji.
// Parametry:
// x1 lewa granica przedziału
// x2 prawa granica przedziału
// getval funkcja na której operuje algorytm (dowolna funkcja która zwraca double
// przyjmuje jeden argument double)
// Przykład: double root = bisection_with_precision(M_PI_2,13/10*M_PI , bsin);
double bisection_with_precision(double x1, double x2, fun getval, double precision)
{
    // Sprawdzenie czy osiągneliśmy wymaganą precyzję
    printf("  %-10s%-10s%-10s%-16s%-15s\n", "Iteracja", "X1", "X2", "Obecna precyzja", "Szukana precyzja");
    int i = 0;
    printf("  %-10d%-10f%-10f%-16f%-15f\n", i, x1, x2, fabs(x1-x2), precision);
    while(fabs(x1-x2) > precision)
    {
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
        i++;
        printf("  %-10d%-10f%-10f%-16f%-15f\n", i, x1, x2, fabs(x1-x2), precision);
    }
    return (x1+x2)/2.0;
}
