#include  <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592

int  main() {

    double u = 398600.4;
    double wE = 7.2921159 * pow(10, -5);
    double rp, vA, vW;
    double i = 63.4;
    int ra;

    i = (i * PI) / 180;
    rp = (pow(wE, 2) * pow(45000, 4) * pow(cos(i), 2))/((2*u) - pow(wE,2) * pow(45000, 3) * pow(cos(i), 2));

    FILE * ex1;
    ex1 = fopen("ex1.txt", "wt");

    for(ra = 0; ra < 60000; ra = ra + 10) {
        vA = sqrt((2*u*rp)/(ra * (ra + rp)));
        vW = wE * ra * cos(i);
        if(vW >= vA) {fprintf(ex1, "%d %.12f %.12f\n", ra, vA, vA);}
        else {fprintf(ex1, "%d %.12f %.12f\n", ra, vA, vW);}
    }

    fclose(ex1);

    return 0;
}