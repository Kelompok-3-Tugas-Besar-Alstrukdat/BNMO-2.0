/* =====| GAME TOWER OF HANOI |===== */

// Include file header yang diperlukan
#include "allgames.h"

void TowerofHanoi()
{
    ArrayDin Tiang = MakeArrayDin();
    Tiang.Neff = 3;
    int i;

    // A
    // Menyimpan tiang "A" ke dalam array tiang indeks 0
    Tiang.Elmt[0].Length = 1;
    char TA[5] = "A";
    for (i = 0; i < 1; i++)
    {
        Tiang.Elmt[0].TabWord[i] = TA[i];
    }
    // B
    // Menyimpan tiang "B" ke dalam array tiang indeks 1
    Tiang.Elmt[1].Length = 1;
    char TB[5] = "B";
    for (i = 0; i < 1; i++)
    {
        Tiang.Elmt[1].TabWord[i] = TB[i];
    }
    // C
    // Menyimpan tiang "C" ke dalam array tiang indeks 2
    Tiang.Elmt[2].Length = 1;
    char TC[5] = "C";
    for (i = 0; i < 1; i++)
    {
        Tiang.Elmt[1].TabWord[i] = TC[i];
    }
    
/*asal = tiang asal inputan user*/
/*tujuan = tiang tujuan inputan user*/
    
    if (isWordEqual(asal, Tiang.Elmt[0]){
        if (isWordEqual(tujuan, Tiang.Elmt[1]){
            push(Tiang.Elmt[0], info(TOP(Tiang.Elmt[0])));
            pop(Tiang.Elmt[1], info(TOP(Tiang.Elmt[1])));
        })
        else if (isWordEqual(tujuan, Game.Elmt[2])){
            push(Tiang.Elmt[0], info(TOP(Tiang.Elmt[0])));
            pop(Tiang.Elmt[2], info(TOP(Tiang.Elmt[2])));
        }
    })
