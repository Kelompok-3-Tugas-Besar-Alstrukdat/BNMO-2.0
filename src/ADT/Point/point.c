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
boolean isPointEqual(Point p1, Point p2)
{
    return (p1.x == p2.x) && (p1.y == p2.y);
}
/* Mengirimkan nilai benar jika p1 dan p2 sama */

void displayPoint (Point p)
{
    printf("(%d,%d)", ABSIS(p), ORDINAT(p));
}
/* Nilai p ditulis ke layar dg format "(X,Y)" */