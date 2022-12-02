#include "../Point/point.c"
#include "../LinkedList/linkedlist.c"
#include "../MesinKarakter/mesinkarakter.c"
#include "../MesinKata/mesinkata.c"

void main()
{
    LinkedList L;
    CreateEmptyLL(&L);

    if (IsEmptyLL(L))
    {
        printf("List kosong\n");
    }
    else
    {
        printf("List tidak kosong\n");
    }
    PrintBackwardLL(L);
    printf("\n\n");

    infotypeLL P1;
    CreatePoint(&P1, 1, 1);
    AlokasiLL(P1);

    for (int i = 1; i < 5; i++)
    {
        infotypeLL P;
        CreatePoint(&P, i, i);
        InsVLastLL(&L, P);
    }

    for (int i  = 5; i < 10; i++)
    {
        infotypeLL P;
        CreatePoint(&P, i, i);
        InsVFirstLL(&L, P);
    }

    if (IsEmptyLL(L))
    {
        printf("List kosong\n");
    }
    else
    {
        printf("List tidak kosong\n");
    }
    PrintForwardLL(L);
    printf("\n\n");

    DelPLL(&L, P1);
    DelVFirstLL(&L, &P1);
    DelVLastLL(&L, &P1);

    if (IsEmptyLL(L))
    {
        printf("List kosong\n");
    }
    else
    {
        printf("List tidak kosong\n");
    }
    PrintBackwardLL(L);
    printf("\n\n");

    printf("Masukkan koordinat x yang ingin ditambahkan: ");
    COMMAND();
    int x = toInt(currentWord);
    printf("Masukkan koordinat y yang ingin ditambahkan: ");
    COMMAND();
    int y = toInt(currentWord);

    infotypeLL P;
    CreatePoint(&P, x, y);
    InsVLastLL(&L, P);
    if (IsEmptyLL(L))
    {
        printf("List kosong\n");
    }
    else
    {
        printf("List tidak kosong\n");
    }
    PrintForwardLL(L);
    printf("\n\n");

    printf("Masukkan koordinat x yang ingin ditambahkan: ");
    COMMAND();
    x = toInt(currentWord);
    printf("Masukkan koordinat y yang ingin ditambahkan: ");
    COMMAND();
    y = toInt(currentWord);

    CreatePoint(&P, x, y);
    InsVLastLL(&L, P);
    if (IsEmptyLL(L))
    {
        printf("List kosong\n");
    }
    else
    {
        printf("List tidak kosong\n");
    }
    PrintForwardLL(L);
}