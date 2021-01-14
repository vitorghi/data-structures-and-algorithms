#include <stdio.h>
#include <math.h>
#include "aula05.h"

complexo complexo_novo(double real, double imag){
    complexo c;
    c.real = real;
    c.imag = imag;
    return c;
}

complexo complexo_soma(complexo a, complexo b) {
    return complexo_novo(a.real + b.real, a.imag + b.imag);
}

complexo complexo_le() {
    complexo a;
    scanf("%lf %lf", &a.real, &a.imag);
    return a;
}
