# Bisekcja
## Opis algorytmu
Umożliwia on znajdowanie miejsca zerowego funkcji w danym przedziale. Opiera się na twierdzeniu:
#### Bolzana-Cauchy’ego:
> Jeżeli funkcja ciągła f(x) ma na końcach przedziału domkniętego wartości różnych znaków, to wewnątrz tego przedziału, 
> istnieje co najmniej jeden pierwiastek równania f(x)=0.
#### Założenia:
- Funkcja f(x) jest ciągła w podanym przedziale.
- Funkcja f(x) przyjmuje na krańcach przedziału wartości różnych znaków.

Algorytm wykorzystuje te fakty i dzieli podany przedział na połowę, następnie sprawdza, w którym z tych dwóch przedziałów wartości funkcji dla jego krańców są różnych znaków, ponieważ to w nim znajduje się szukane przez nas miejsce zerowe. Cykl ten powtarza się aż do uzyskania przez nas odpowiedniej precyzji.
#### Analiza
Jak możemy łatwo zauważyć, ilość iteracji jaką algortm wykona zależy wyłącznie od poadnego przedziału i wyraża się zależnością:
![](https://latex.codecogs.com/gif.latex?\frac{|X1&space;-&space;X2|}{P}&space;\leq&space;2^{n},&space;n\epsilon&space;\mathbb{N},&space;P\epsilon&space;\left&space;(&space;0,&space;\infty&space;\right&space;),&space;X1\epsilon\mathbb{R},&space;X2\epsilon\mathbb{R}). Gdzie P to Precyzja z jaką szukamy miejsca zerowego, X1 lewa, a X2 prawa granica przedziału w którym jest miejsce zerowe, a n jest liczbą iteracji jaką algorytm wykona. Wzór ten sprowadza się do postaci:![](https://latex.codecogs.com/gif.latex?n&space;=&space;\log_2\tfrac{|X1-X2|}{P}), przy czym n zaokrąglamy w górę do najbliższej liczby naturalnej.
### Schemat blokowy
![alt text](https://github.com/finloop/biselect/blob/master/Bisekcja.png)
### Kod algorytmu
```c
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
```
## Doświadczenie
### Szukanie miejsc zerowych funkcji sin(x)
#### Wykres funkcji sin(x)
![alt text](https://github.com/finloop/biselect/blob/master/sinx.jpg)
> Wykres funkcji sin(x) wykanany w programie Matlab. 
#### Funkcja zwracająca wartość sin(x)
```c
double bsin(double x){
    return sin(x);
}
```
### Opis doświadczenia





