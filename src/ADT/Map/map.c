#include "map.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M)
{
    (*M).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M)
{
    return M.Count == Nil;
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullMap(Map M)
{
    return M.Count == MaxEl;
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k)
{
    if (!IsEmptyMap((M)))
    {
        if (IsMemberMap(M, k))
        {   
            int i = 0;
            while (!isWordEqual(M.Elements[i].Key, k))
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

void InsertMap(Map *M, keytype k, valuetype v)
{
    if (IsEmptyMap(*M))
    {
        (*M).Count = 1;
        for (int i = 0; i < k.Length; i++)
        {
            (*M).Elements[0].Key.TabWord[i] = k.TabWord[i];
        }
        (*M).Elements[0].Key.Length = k.Length;
        (*M).Elements[0].Value = v;
    }
    else
    {
        if (!IsMemberMap(*M, k))
        {
            for (int i = 0; i < k.Length; i++)
            {
                (*M).Elements[(*M).Count].Key.TabWord[i] = k.TabWord[i];
            }
            (*M).Elements[(*M).Count].Key.Length = k.Length;
            (*M).Elements[(*M).Count].Value = v;
            (*M).Count++;
        }
    }
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(Map *M, keytype k)
{
    if (IsMemberMap(*M, k))
    {
        int i = 0;
        while (!isWordEqual((*M).Elements[i].Key, k))
        {
            i++;
        }
        for (i; i < ((*M).Count - 1); i++)
        {
            for (int j = 0; j < k.Length; j++)
            {
                (*M).Elements[i].Key.TabWord[j] = (*M).Elements[i + 1].Key.TabWord[j];
            }
            (*M).Elements[i].Key.Length = (*M).Elements[i + 1].Key.Length;
            (*M).Elements[i].Value = (*M).Elements[i + 1].Value;
        }
        (*M).Count--;
    }
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMap(Map M, keytype k)
{
    boolean check = false;
    if (!IsEmptyMap(M))
    {
        int i = 0;
        while (!check && i < M.Count)
        {
            if (isWordEqual(M.Elements[i].Key, k))
            {
                check = true;
            }
            i++;
        }
    }
    return check;
}
/* Mengembalikan true jika k adalah member dari M */