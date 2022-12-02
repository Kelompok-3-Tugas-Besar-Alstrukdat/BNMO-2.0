#include "../Array/array.c"
#include "../MesinKarakter/mesinkarakter.c"
#include "../MesinKata/mesinkata.c"
#include "../../CONSOLE/console.c"
int main()
{
    //Deklarasi Variabel
    ArrayDin array1,array2;
    ElType el1,el2,el3,el4,el5;
    int i;
    char kata1[7] = "WILDHAN";
    char kata2[4] = "REZA";
    char kata3[6] = "NABILA";
    char kata4[4] = "NISA";
    char kata5[5] = "VASYA";

    //Insert isi array oleh array char di atas
    for(i = 0; i < 7; i++)
    {
        el1.TabWord[i] = kata1[i];
    }
    el1.Length = 7;
    for(i = 0; i < 4; i++)
    {
        el2.TabWord[i] = kata2[i];
    }
    el2.Length = 4;
    for(i = 0; i < 6; i++)
    {
        el3.TabWord[i] = kata3[i];
    }
    el3.Length = 6;
    for(i = 0; i < 4; i++)
    {
        el4.TabWord[i] = kata4[i];
    }
    el4.Length = 4;
    for(i = 0; i < 5; i++)
    {
        el5.TabWord[i] = kata5[i];
    }
    el5.Length = 5;

    //Kosntruktor
    array1 = MakeArrayDin();
    array2 = MakeArrayDin();

    //Penggunaan isEmpty
    if (IsEmpty(array1))
    {
        printf("Array1 ini kosong loh ! \n");
    }

    //Menambahkan Elemen ke array1 dan array2
    InsertLast(&array1, el1);
    InsertLast(&array1, el2);
    InsertLast(&array1,el3);
    InsertLast(&array2, el4);
    InsertLast(&array2, el5);

    //Menampilkan panjang array1 dan array2
    printf("Ini banyak isi array 1 : %d, kalau ini banyak isi array2 : %d \n",Length(array1), Length(array2));
    
    //Menampilkan elemen dari array1 dan array2 menggunakan Get
    for (i = 0; i < Length(array1); i++)
    {
        printWord( Get(array1,i) );
    }
    printf("Di atas tuh, isi Elemen dari array 1\n");
    
    for (i = 0; i < Length(array2); i++)
    {
        printWord( Get(array2,i) );
    }
    
    printf("Di atas tuh, isi Elemen dari array 2.\n");

    //Memperbarui elemen menggunakan Set
    Set(&array1, el5, 1);
    printf("Update nilai array1 indeks ke 2\n");
    countdown();
    for (i = 0; i < 3; i++)
    {
        printWord( Get(array1,i) );
    }
    printf("Nahh sekarang, isi array1 jadi ituu\n");

    //Melihat kapasistas array
    printf("Ini adalah kapasistas dari array1; %d.\n",GetCapacity(array1));

    //Menghapus Element di indeks ke i
    for (i = 0; i < Length(array1); i++)
    {
        printWord( Get(array1,i) );
    }
    printf("Ini isi elemen array1 sebelum di delete\n");
    DeleteAt( &array1 ,  Length(array1) - 1);
    for (i = 0; i < Length(array1); i++)
    {
        printWord( Get(array1,i) );
    }
    printf("Ini isi elemen array1 setelah di delete\n");

    //Dealokasi
    printf("Mau di dealocate nihh\nDealocate");
    countdown();
    DeallocateArrayDin(&array1);
    DeallocateArrayDin(&array2);
    printf("Berhasil Deallocate!\n");
}