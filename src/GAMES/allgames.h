/* =====| Definisi Header commands.h |===== */
#ifndef _GAMES_
#define _GAMES_

/* =====| Include Header |===== */
#include "../CONSOLE/console.h"


/* =====| GAME DINER DASH |===== */
// Terdapat definisi ADT khusus untuk Diner Dash, dengan memanfaatkan prinsip ADT Queue dan Array

// Definisi konstanta
#define Idx_Undef -1
#define DCapacity 20

// Definisi Array
typedef struct
{
    int Elmt[DCapacity];
} DinerArr;

// Definisi tipe data Queue yang digunakan
typedef struct
{
    int Duration;
    int Resistance;
    int Price;
} DinerQType;

// Definisi Queue
typedef struct
{
	DinerQType buffer[DCapacity];
	int idxHead;
	int idxTail;
    int Capacity;
} DinerQ;

// Akses (Selektor)
// Jika dq adalah DinerQ, maka akses elemen
#define Idx_Head(dq) (dq).idxHead
#define Idx_Tail(dq) (dq).idxTail
#define     Head(dq) (dq).buffer[(dq).idxHead]
#define     Tail(dq) (dq).buffer[(dq).idxTail]
#define Capacity(dq) (dq).Capacity

// Kreator Queue
void CreateDinerQ(DinerQ *dq);
// I.S. sembarang
// F.S. Sebuah dq kosong terbentuk dengan kondisi sbb:
// - Index head bernilai Idx_Undef
// - Index Tail bernilai Idx_Undef
// Proses : Melakukan alokasi, membuat sebuah dq kosong

// Kreator Array
void CreateDinerArr(DinerArr *da);
// I.S. sembarang
// F.S. Sebuah da kosong terbentuk dengan kondisi sbb:
// - Elmt bernilai Idx_Undef

// Prototype
boolean isEmptyDQ(DinerQ dq);
// Mengirim true jika dq kosong: lihat definisi di atas
boolean isFullDQ(DinerQ dq);
// Mengirim true jika tabel penampung elemen dq sudah penuh
// yaitu Idx_Tail akan selalu di belakang Idx_Head
// Idx_Head selalu bernilai 0
int lengthDQ(DinerQ dq);
// Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika dq kosong

// Primitif Add/Delete
void enqueueDQ(DinerQ *dq, DinerQType val);
// Proses: Menambahkan val pada dq dengan aturan FIFO
// I.S. dq mungkin kosong, tabel penampung elemen dq mungkin penuh
// F.S. val menjadi Tail yang baru, Idx_Tail bertambah satu
void dequeueDQ(DinerQ *dq, DinerQType *val);
// Proses: Menghapus val pada dq dengan aturan FIFO
// I.S. dq tidak mungkin kosong
// F.S. val = nilai elemen Head pd I.S., semua elemen bergeser ke kiri, dan dq mungkin kosong

// Display DinerQ
void displayQueueDQ(DinerQ dq);
// Proses : Menuliskan isi DinerQ dengan traversal, DinerQ ditulis seperti dalm sebuah tabel

// Random Number Generator Nilai Atribut
void controlRand();
// Mengontrol nilai yang akan dihasilkan
DinerQType randVal();
// Menghasilkan nilai random

// Prosedur untuk menjalankan permainan Diner Dash
void runDinerDash();


/* =====| GAME RNG |===== */
// Fungsi untuk menentukan nilai integer yang random,
// dengan rentang nilai 0-100 (inclusive)
int RandomNumber();
// Prosedur yang menjalankan permainan RNG
// Prekondisi: tebakan merupakan bilangan bulat (integer)
void runRNG();


/* =====| GAME HANGMAN |===== */
// Prosedur untuk menjalankan permainan Hangman
void runHangman();


/* =====| GAME TOWER OF HANOI |===== */
// Prosedur untuk menjalankan permainan Tower of Hanoi
void runTowerOfHanoi();


/* =====| GAME SNAKE ON METEOR |===== */
// Prosedur untuk menjalankan permainan Snake on Meteor
void runSnakeOnMeteor();


/* =====| GAME HIDE IN CARTESIAN |===== */
// Prosedur untuk menjalankan permainan Hide In Cartesian
// Menebak tempat persembuyian yang berada pada koordinar cartesius
int runHideInCartesian();


/* =====| GAME MAGIC SHELL |===== */
// Prosedur untuk menjalankan permainan Magic Shell
// Menjawab pertanyaan apapun yang diberikan
void magic_shell();


#endif