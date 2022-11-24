#ifndef ARRAY_DYNAMIC
#define ARRAY_DYNAMIC

#include <stdio.h>
#include <stdlib.h>
#include "../../boolean.h"
#include "../MesinKata/mesinkata.h"

#define INIT_SIZE 50

typedef int IdxType;
typedef Word ElType;

typedef struct {
    ElType *Elmt;
    int Capacity;
    int Neff;
} ArrayDin;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran INIT_SIZE
 */
ArrayDin MakeArrayDin();

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array.Elmt terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array);

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmptyArr(ArrayDin array);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i);

/**
 * Mengubah elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
void Set(ArrayDin *array, ElType el, IdxType i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array);

/**
 * Prosedur untuk menambahkan elemen baru di index terakhir array
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertLastArr(ArrayDin *array, ElType el);

/**
 * Prosedur untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAtArr(ArrayDin *array, IdxType i);

#endif