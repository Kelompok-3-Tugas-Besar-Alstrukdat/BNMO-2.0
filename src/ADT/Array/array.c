#include "array.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran INIT_SIZE
 */
ArrayDin MakeArrayDin()
{
    ArrayDin array;
    do
    {
        array.Elmt = (ElType *) malloc (INIT_SIZE * sizeof(ElType));
    }
    while (array.Elmt == NULL);
    array.Capacity = INIT_SIZE;
    array.Neff = 0;
    return array;
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array.Elmt terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array)
{
    free((*array).Elmt);
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array)
{
    return array.Neff == 0;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array)
{
    return array.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i)
{
    return array.Elmt[i];
}

/**
 * Mengubah elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
void Set(ArrayDin *array, ElType el, IdxType i)
{
    (*array).Elmt[i].Length = el.Length;
    for (int idx = 0; idx < el.Length; idx++)
    {
        (*array).Elmt[i].TabWord[idx] = el.TabWord[idx];
    }
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array)
{
    return array.Capacity;
}

/**
 * Prosedur untuk menambahkan elemen baru di index terakhir array
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertLast(ArrayDin *array, ElType el)
{
    if ((*array).Neff == (*array).Capacity)
    {
        (*array).Capacity *= 2;
        do
        {
            realloc((*array).Elmt, GetCapacity(*array));
        }
        while ((*array).Elmt == NULL);
    }
    int i = (*array).Neff;
    (*array).Elmt[i].Length = el.Length;
    for (int idx = 0; idx < (*array).Elmt[i].Length; idx++)
    {
        (*array).Elmt[i].TabWord[idx] = el.TabWord[idx];
    }
    (*array).Neff++;
}

/**
 * Prosedur untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i)
{
    (*array).Neff--;
    for (int idx = i; idx < (*array).Neff; idx++)
    {
        (*array).Elmt[idx].Length = (*array).Elmt[idx + 1].Length;
        for (int inidx = 0; inidx < (*array).Elmt[idx].Length; inidx++)
        {
            (*array).Elmt[idx].TabWord[inidx] = (*array).Elmt[idx + 1].TabWord[inidx];
        }
    }
}