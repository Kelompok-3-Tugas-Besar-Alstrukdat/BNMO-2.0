#include "set.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptySet(Set *S)
{
    (*S).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(Set S)
{
    return S.Count == Nil;
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFullSet(Set S)
{
    return S.Count == MaxEl;
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void InsertSet(Set *S, infotype Elmt)
{
    if (!IsMemberSet(*S, Elmt))
    {
        if (IsEmptySet(*S))
        {
            (*S).Count = 1;
        }
        else
        {
            (*S).Count++;
        }
        for (int i = 0; i < Elmt.Length; i++)
        {
            (*S).Elements[(*S).Count - 1].TabWord[i] = Elmt.TabWord[i];
        }
        (*S).Elements[(*S).Count - 1].Length = Elmt.Length;
    }
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSet(Set *S, infotype Elmt)
{
    if (IsMemberSet(*S, Elmt))
    {
        int i = 0;
        while (!isWordEqual((*S).Elements[i], Elmt))
        {
            i++;
        }
        for (i; i < ((*S).Count - 1); i++)
        {
            for (int j = 0; j < Elmt.Length; j++)
            {
                (*S).Elements[i].TabWord[j] = (*S).Elements[i + 1].TabWord[j];
            }
            (*S).Elements[i].Length = (*S).Elements[i + 1].Length;
        }
        (*S).Count--;
    }
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberSet(Set S, infotype Elmt)
{
    boolean check = false;
    if (!IsEmptySet(S))
    {
        int i = 0;
        while (!check && (i < S.Count))
        {
            if (isWordEqual(S.Elements[i], Elmt))
            {
                check = true;
            }
            i++;
        }
    }
    return check;
}
/* Mengembalikan true jika Elmt adalah member dari S */