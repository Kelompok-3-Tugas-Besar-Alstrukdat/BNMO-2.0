#ifndef _MAP_
#define _MAP_

#include <stdio.h>
#include "../MesinKata/mesinkata.h"
#include "../../boolean.h"

/* MODUL SetMap
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define Nil 0
#define MaxEl 100
#define Undefined -999

// typedef int bool;
typedef Word keytype;
typedef int valuetype;
typedef int address;

typedef struct {
	keytype Key;
	valuetype Value;
} infotype;

typedef struct {
	infotype Elements[MaxEl];
	address Count;
} SetMap;

/* Definisi SetMap M kosong : M.Count = Nil */
/* M.Count = jumlah element SetMap */
/* M.Elements = tempat penyimpanan element SetMap */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(SetMap *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah SetMap M kosong berkapasitas MaxEl */
/* Ciri SetMap kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(SetMap M);
/* Mengirim true jika SetMap M kosong*/
/* Ciri SetMap kosong : count bernilai Nil */

boolean IsFullMap(SetMap M);
/* Mengirim true jika SetMap M penuh */
/* Ciri SetMap penuh : count bernilai MaxEl */

/* ********** Operator Dasar SetMap ********* */
valuetype Value(SetMap M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertMap(SetMap *M, keytype k, valuetype v);
/* Menambahkan Elmt sebagai elemen SetMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(SetMap *M, keytype k);
/* Menghapus Elmt dari SetMap M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMap(SetMap M, keytype k);
/* Mengembalikan true jika k adalah member dari M */

#endif