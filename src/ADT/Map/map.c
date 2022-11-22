#include "map.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M)
{
    (*M).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Map M)
{
    return M.Count == Nil;
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFull(Map M)
{
    return M.Count == MaxEl;
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k)
{
    if (!IsEmpty((M)))
    {
        if (IsMember(M, k))
        {   
            int i = 0;
            while (M.Elements[i].Key != k)
            {
                i++;
            }
            return M.Elements[i].Value;
        }
        else
        {
            return Undefined;
        }
    }
    else
    {
        return Undefined;
    }
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insert(Map *M, keytype k, valuetype v)
{
    if (IsEmpty(*M))
    {
        (*M).Count = 1;
        (*M).Elements[0].Key = k;
        (*M).Elements[0].Value = v;
    }
    else
    {
        if (!IsMember(*M, k))
        {
            (*M).Elements[(*M).Count].Key = k;
            (*M).Elements[(*M).Count].Value = v;
            (*M).Count++;
        }
    }
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void Delete(Map *M, keytype k)
{
    if (IsMember(*M, k))
    {
        int i = 0;
        while ((*M).Elements[i].Key != k)
        {
            i++;
        }
        for (i; i < ((*M).Count - 1); i++)
        {
            (*M).Elements[i].Key = (*M).Elements[i + 1].Key;
            (*M).Elements[i].Value = (*M).Elements[i + 1].Value;
        }
        (*M).Count--;
    }
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMember(Map M, keytype k)
{
    boolean check = false;
    if (!IsEmpty(M))
    {
        int i = 0;
        while (!check && i < M.Count)
        {
            if (M.Elements[i].Key == k)
            {
                check = true;
            }
            i++;
        }
    }
    return check;
}
/* Mengembalikan true jika k adalah member dari M */