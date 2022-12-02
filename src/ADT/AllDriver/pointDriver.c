#include "../Array/array.c"
#include "../Point/point.c"
#include "../MesinKarakter/mesinkarakter.c"
#include "../MesinKata/mesinkata.c"
#include "../../CONSOLE/console.c"
int main()
{
    Point P,O,I,N;

    //Konstruktor Point
    CreatePoint(&P, 4, 4);
    CreatePoint(&O, 0, 0);
    CreatePoint(&I, 0, 1);
    CreatePoint(&N, 1, 0);

    //Mengecek apakah suatu Poin adalah titik asal atau tidak
    if( isOrigin(O) )
    {
        printf("Karena Point O merupakan titik asal maka pesan ini ditampilkan\n");
    }
    
    if (!isOrigin(P) )
    {
        printf("Karena Point P bukan merupakan titik asal maka pesan ini ditampilkan\n");
    }
    
    countdown(); 
    printf("\n");

    //Menampilkan Poin dengan format (x,y)
    displayPoint(P);
    printf("Ini punya point P\n");
    displayPoint(O);
    printf("Ini punya point O\n");
    displayPoint(I);
    printf("Ini punya point I\n");
    displayPoint(N);
    printf("Ini punya point N\n");
}