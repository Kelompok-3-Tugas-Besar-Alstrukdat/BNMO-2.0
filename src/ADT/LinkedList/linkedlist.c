/* File : listlinier.C */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi addressLL dengan pointer */
/* infotypeLL adalah integer */

#include "linkedlist.h"

/* Definisi list : */
/* LinkedList kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan addressLL P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* Notasi Akses */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define First(L) ((L).First)
#define Last(L) ((L).Last)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyLL(LinkedList L)
{
    return (First(L) == Nil) && (Last(L) == Nil);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyLL(LinkedList *L)
{
    First(*L) = Nil;
    Last(*L) = Nil;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
addressLL AlokasiLL(infotypeLL point)
{
    ElmtList *P = (ElmtList*) malloc (sizeof(ElmtList));
    if (P == NULL)
    {
        return Nil;
    }
    else
    {
        Info(P).x = point.x;
        Info(P).y = point.y;
        Next(P) = Nil;
        Prev(P) = Nil;
        return P;
    }
}
/* Mengirimkan addressLL hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressLL tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=point, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void DealokasiLL(addressLL P)
{
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressLL P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressLL SearchLL(LinkedList L, infotypeLL point)
{
    addressLL P = First(L);
    while (((Info(P).x != point.x) || (Info(P).y != point.y)) && (Next(P) != Nil))
    {
        P = Next(P);
    }
    if ((Info(P).x == point.x) && (Info(P).y == point.y))
    {
        return P;
    }
    else
    {
        return Nil;
    }
}
/* Mencari apakah ada elemen list dengan Info(P)=point */
/* Jika ada, mengirimkan addressLL elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstLL(LinkedList *L, infotypeLL point)
{
    addressLL P;
    do
    {
        P = AlokasiLL(point);
    }
    while (P == Nil);
    InsertFirstLL(L, P);
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai point jika alokasi berhasil */
void InsVLastLL(LinkedList *L, infotypeLL point)
{
    addressLL P;
    do
    {
        P = AlokasiLL(point);
    }
    while (P == Nil);
    InsertLastLL(L, P);
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai point jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstLL(LinkedList *L, infotypeLL *point)
{
    addressLL P = First(*L);
    (*point).x = Info(First(*L)).x;
    (*point).y = Info(First(*L)).y;
    First(*L) = Next(First(*L));
    if (First(*L) == Nil)
    {
        Last(*L) = Nil;
    }
    else
    {
        Prev(First(*L)) = Nil;
    }
    DealokasiLL(P);
}
/* I.S. LinkedList L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada point */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLastLL(LinkedList *L, infotypeLL *point)
{
    addressLL P = Last(*L);
    (*point).x = Info(First(*L)).x;
    (*point).y = Info(First(*L)).y;
    Last(*L) = Prev(Last(*L));
    if (Last(*L) == Nil)
    {
        First(*L) = Nil;
    }
    else
    {
        Next(Last(*L)) = Nil;
    }
    DealokasiLL(P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada point */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstLL(LinkedList *L, addressLL P)
{
    if (P != Nil)
    {
        if (IsEmptyLL(*L))
        {
            Last(*L) = P;
        }
        else
        {
            Prev(First(*L)) = P;
        }
        Next(P) = First(*L);
        First(*L) = P;
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressLL P sebagai elemen pertama */
void InsertLastLL(LinkedList *L, addressLL P)
{
    if (P != Nil)
    {
        if (IsEmptyLL(*L))
        {
            First(*L) = P;
        }
        else
        {
            Next(Last(*L)) = P;
        }
        Prev(P) = Last(*L);
        Last(*L) = P;
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfterLL(LinkedList *L, addressLL P, addressLL Prec)
{
    if (P != Nil)
    {
        Next(Prec) = P;
        Prev(P) = Prec;
        if (Last(*L) == Prec)
        {
            Last(*L) = P;
        }
    }
}
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBeforeLL(LinkedList *L, addressLL P, addressLL Succ)
{
    if (P != Nil)
    {
        Prev(Succ) = P;
        Next(P) = Succ;
        if (First(*L) == Succ)
        {
            First(*L) = P;
        }
    }
}
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstLL(LinkedList *L, addressLL *P)
{
    (*P) = First(*L);
    First(*L) = Next(First(*L));
    if (First(*L) == Nil)
    {
        Last(*L) = Nil;
    }
    else
    {
        Prev(First(*L)) = Nil;
    }
}
/* I.S. LinkedList tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLastLL(LinkedList *L, addressLL *P)
{
    (*P) = Last(*L);
    Last(*L) = Prev(Last(*L));
    if (Last(*L) == Nil)
    {
        First(*L) = Nil;
    }
    else
    {
        Next(Last(*L)) = Nil;
    }
}
/* I.S. LinkedList tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelPLL(LinkedList *L, infotypeLL point)
{
    addressLL P = First(*L);
    while (((Info(P).x != point.x) && (Info(P).y != point.y)) && (Next(P) != Nil))
    {
        P = Next(P);
    }
    if ((Info(P).x == point.x) && (Info(P).y == point.y))
    {
        if(Prev(P) != Nil)
        {
            Next(Prev(P)) = Next(P);
        }
        if (Next(P) != Nil)
        {
            Prev(Next(P)) = Prev(P);
        }
        if ((First(*L) == P) && (Last(*L) == P))
        {
            First(*L) = Nil;
            Last(*L) = Nil;
        }
        else
        {
            if (First(*L) == P)
            {
                First(*L) = Next(P);
            }
            if (Last(*L) == P)
            {
                Last(*L) = Prev(P);
            }
        }
        DealokasiLL(P);
    }
    
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=point  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=point, maka list tetap */
/* LinkedList mungkin menjadi kosong karena penghapusan */
void DelAfterLL(LinkedList *L, addressLL *Pdel, addressLL Prec)
{
    (*Pdel) = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    if (Last(*L) == Next(Prec))
    {
        Last(*L) = Prec;
    }
    else
    {
        Prev(Next(Next(Prec))) = Prec;
    }
}
/* I.S. LinkedList tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBeforeLL(LinkedList *L, addressLL *Pdel, addressLL Succ)
{
    (*Pdel) = Prev(Succ);
    Prev(Succ) = Prev(Prev(Succ));
    if (First(*L) == Prev(Succ))
    {
        First(*L) = Succ;
    }
    else
    {
        Next(Prev(Prev(Succ))) = Succ;
    }
}
/* I.S. LinkedList tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForwardLL(LinkedList L)
{
    printf("[");
    if (!IsEmptyLL(L))
    {
        addressLL P = First(L);
        while (Next(P) != Nil)
        {
            displayPoint(Info(P));
            printf(",");
            P = Next(P);
        }
        displayPoint(Info(P));
    }
    printf("]");
}
/* I.S. LinkedList mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackwardLL(LinkedList L)
{
    printf("[");
    if (!IsEmptyLL(L))
    {
        addressLL P = Last(L);
        while (Prev(P) != Nil)
        {
            displayPoint(Info(P));
            printf(",");
            P = Prev(P);
        }
        displayPoint(Info(P));
    }
    printf("]");
}
/* I.S. LinkedList mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */