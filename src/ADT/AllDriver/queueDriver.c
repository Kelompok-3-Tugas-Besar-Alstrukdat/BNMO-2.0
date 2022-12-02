#include "../Array/array.c"
#include "../Queue/queue.c"
#include "../MesinKarakter/mesinkarakter.c"
#include "../MesinKata/mesinkata.c"
#include "../../CONSOLE/console.c"

int main()
{
    Queue P,Q;
    QueueType val1,val2,val3,val4,val5;

    int i;
    char kata1[7] = "WILDHAN";
    char kata2[4] = "REZA";
    char kata3[6] = "NABILA";
    char kata4[4] = "NISA";
    char kata5[5] = "VASYA";

    //Insert isi array oleh array char di atas
    for(i = 0; i < 7; i++)
    {
        val1.TabWord[i] = kata1[i];
    }
    val1.Length = 7;
    for(i = 0; i < 4; i++)
    {
        val2.TabWord[i] = kata2[i];
    }
    val2.Length = 4;
    for(i = 0; i < 6; i++)
    {
        val3.TabWord[i] = kata3[i];
    }
    val3.Length = 6;
    for(i = 0; i < 4; i++)
    {
        val4.TabWord[i] = kata4[i];
    }
    val4.Length = 4;
    for(i = 0; i < 5; i++)
    {
        val5.TabWord[i] = kata5[i];
    }
    val5.Length = 5;

    //Konstruktor Queue
    CreateQueue(&P);
    CreateQueue(&Q);

    //Tes fungsi isEmptyQueue untuk melihat apakah Queue masih kosong atau tidak.
    if (isEmptyQueue(P) && isEmptyQueue(Q))
    {
        printf("Queue ini masih kosong ges!!\n");
        countdown();
    }

    //Cek apakah Queue ini sudah penuh atau belum.
    if (!isFullQueue(P)){
        printf("Queue ini belum penuh ges!!\n");
        countdown();
    }

    //Menambahkan elemen val ke dalam Queue
    enqueueQ(&P, val1);
    enqueueQ(&P, val2);
    enqueueQ(&P, val3);
    enqueueQ(&Q, val4);
    enqueueQ(&Q, val5);

    //Menampilkan panjang dari Queue
    printf("%d, ini panjang dari Queue P. %d, ini panjang dari Queue Q.\n", lengthQueue(P), lengthQueue(Q));
    countdown();

    //Dequeue Queue Q dan Queue P, menggunakan fungsi Dequeue.
    dequeueQ(&P, &val1);
    dequeueQ(&P, &val2);
    dequeueQ(&Q, &val4);
    printf("Mau dequeue nih.\n");
    countdown();
    printf("%d, ini panjang dari Queue P sekarang. %d, ini panjang dari Queue Q sekarang.\n", lengthQueue(P), lengthQueue(Q));
    countdown();

    //Dealokasi Queue
    printf("Mau di dealocate nihh\nDealocate");
    countdown();
    DeallocateQueue(&P);
    DeallocateQueue(&Q);
    printf("Berhasil Deallocate!\n");
}