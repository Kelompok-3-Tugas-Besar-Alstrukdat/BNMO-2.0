#include "queue.h"

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead]
#define     TAIL(q) (q).buffer[(q).idxTail]
#define CAPACITY(q) (q).capacity

/* *** Kreator *** */
void CreateQueue(Queue *q)
{
    do
    {
        (*q).buffer = (QueueType *) malloc (INIT_CAPACITY * sizeof(QueueType));
    }
    while ((*q).buffer == NULL);
    (*q).capacity = INIT_CAPACITY;
    (*q).idxHead = IDX_UNDEF;
    (*q).idxTail = IDX_UNDEF;
}
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
void DeallocateQueue(Queue *q)
{
    free((*q).buffer);
}

/* ********* Prototype ********* */
boolean isEmptyQueue(Queue q)
{
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFullQueue(Queue q)
{
    return IDX_TAIL(q) == (CAPACITY(q) - 1);
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD */
/* IDX_HEAD selalu bernilai 0 */

int lengthQueue(Queue q)
{
    return IDX_TAIL(q) + 1;
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueueQ(Queue *q, QueueType val)
{
    if (isFullQueue(*q))
    {
        CAPACITY(*q) *= 2;
        do
        {
            realloc((*q).buffer, CAPACITY(*q));
        }
        while ((*q).buffer == NULL);
    }
    if (isEmptyQueue(*q))
    {
        IDX_HEAD(*q) = 0;
    }
    IDX_TAIL(*q)++;
    TAIL(*q).Length = val.Length;
    for (int i = 0; i < val.Length; i++)
    {
        TAIL(*q).TabWord[i] = val.TabWord[i];
    }
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q mungkin penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL bertambah satu */

void dequeueQ(Queue *q, QueueType *val)
{
    (*val).Length = HEAD(*q).Length;
    for (int i = 0; i < HEAD(*q).Length; i++)
    {
        (*val).TabWord[i] = HEAD(*q).TabWord[i + 1];
    }
    if (IDX_TAIL(*q) == 0)
    {
        IDX_HEAD(*q) = IDX_UNDEF;
    }
    else
    {
        for (int i = 0; i < IDX_TAIL(*q); i++)
        {
            (*q).buffer[i].Length = (*q).buffer[i + 1].Length;
            for (int j = 0; j < (*q).buffer[i].Length; j++)
            {
                (*q).buffer[i].TabWord[j] = (*q).buffer[i+1].TabWord[j];
            }
        }
    }
    IDX_TAIL(*q)--;
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., semua elemen bergeser ke kiri, dan q mungkin kosong */