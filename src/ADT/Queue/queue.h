/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
#ifndef QUEUE
#define QUEUE

#include <stdio.h>
#include <stdlib.h>
#include "../../boolean.h"
#include "../MesinKata/mesinkata.h"

#define IDX_UNDEF -1
#define INIT_CAPACITY 50

/* Definisi elemen dan address */
typedef Word QueueType;
typedef struct {
	QueueType *buffer;
	int idxHead;
	int idxTail;
    int capacity;
} Queue;


/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead]
#define     TAIL(q) (q).buffer[(q).idxTail]
#define CAPACITY(q) (q).capacity

/* *** Kreator *** */
void CreateQueue(Queue *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/**
 * Destruktor
 * I.S. Queue terdefinisi
 * F.S. q.buffer terdealokasi
 */
void DeallocateQueue(Queue *q);

/* ********* Prototype ********* */
boolean isEmptyQueue(Queue q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFullQueue(Queue q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD */
/* IDX_HEAD selalu bernilai 0 */

int lengthQueue(Queue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */

/* *** Primitif Add/Delete *** */
void enqueueQ(Queue *q, QueueType val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q mungkin penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL bertambah satu */

void dequeueQ(Queue *q, QueueType *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., semua elemen bergeser ke kiri, dan q mungkin kosong */

#endif