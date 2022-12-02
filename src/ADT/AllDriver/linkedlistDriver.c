#include "../Point/point.c"
#include "../LinkedList/linkedlist.c"
#include "../MesinKarakter/mesinkarakter.c"
#include "../MesinKata/mesinkata.c"
#include "../../CONSOLE/console.c"

void main()
{
    LinkedList L;
    CreateEmpty(&L);

    if (IsEmpty(L))
    {
        printf("List kosong\n");
    }
    else
    {
        printf("List tidak kosong\n");
    }

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

    PrintForwardLL(L);

    DelP(&L, P1);
    DelVFirstLL(&L, &P1);
    DelVLastLL(&L, &P1);

    PrintBackwardLL(L);

    InsertAfterLL(&L, SearchLL(L, P1), First(L));
    InsertBeforeLL(&L, SearchLL(L, P1), Last(L));

    PrintForwardLL(L);

    DelAfterLL(&L, SearchLL(L, P1), &P1);
    DelBeforeLL(&L, SearchLL(L, P1), &P1);

    PrintBackwardLL(L);

}