#include "../Array/array.c"
#include "../SetMap/setmap.c"
#include "../MesinKarakter/mesinkarakter.c"
#include "../MesinKata/mesinkata.c"

int main()
{
    SetMap M;
    keytype K;
    valuetype V;
    CreateEmptyMap(&M);
    K.Length = 2;
    K.TabWord[0] = 'a'; K.TabWord[1] = 'a';
    if (IsEmptyMap(M))
    {
        printf("Map masih kosong\n");
    }
    if (!IsFullMap(M))
    {
        printf("Map masih belum penuh\n");
    }
    /*Pengecekan isi Map dan Penggunaan fungsi InsertMap*/

    /*Penggunaan fungsi IsFullMap dan InsertMap*/
    V = 10;
    InsertMap(&M, K, V);
    if (!IsFullMap(M))
    {
        printf("Map belum penuh\n");
        printf("Isi Map sekarang: \n");
        printf("Key: ");
        printWord(K); printf("\n");
    }

    printf("Isi map sekarang: \n");
    printWord(M.Elements[0].Key); printf("\n");
    printf("Value: %d\n", M.Elements[0].Value);

    /*Penggunaan fungsi Value*/
    valuetype Z;
    Z = Value(M, K);
    printf("Isi variabel Z setelah menggunakan fungsi Value: %d\n", Z);

    /*Penggunaan fungsi IsMemberMap*/
    if (IsMemberMap(M, K))
    {
        printf("K adalah anggota dari Map\n");
    }

    /*Penggunaan fungsi DeleteMap dan IsMemberMap*/
    printf("Menghapus elemen dengan key K dari Map\n");
    DeleteMap(&M, K);
    if (!IsMemberMap(M, K))
    {
        printf("K sudah bukan anggota dari Map Lagi\n");
    }
    Z = Value(M, K);
    printf("Isi variabel Z setelah menggunakan fungsi Delete: %d.\nKarena Keytype K sudah hilang dan Z = -999\n", Z);

}