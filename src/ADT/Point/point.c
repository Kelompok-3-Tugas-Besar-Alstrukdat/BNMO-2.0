#include "point.h"

/**** Konstruktor POINT ****/
void CreatePoint (Point *p, int x, int y)
{
    ABSIS(*p) = x;
    ORDINAT(*p) = y;
}
/* Membentuk sebuah point p dari x dan y dengan x sebagai absis dan y sebagai ordinat */

/**** Predikat ****/
boolean isOrigin (Point p)
{
    return (ABSIS(p) == 0) && (ORDINAT(p) == 0);
}
/* Mengirimkan nilai benar jika p adalah titik origin yaitu titik <0,0> */

void displayPoint (Point p)
{
    printf("(%d,%d)", ABSIS(p), ORDINAT(p));
}
/* Nilai p ditulis ke layar dg format "(X,Y)" */