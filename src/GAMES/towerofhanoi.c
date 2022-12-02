/* =====| GAME TOWER OF HANOI |===== */

// Include file header yang diperlukan
#include "allgames.h"

boolean isTowerEqual(Stack Tower1, Stack Tower2)
{
    if (Top(Tower1) == Top(Tower2))
    {
        if (!isWordEqual(InfoTop(Tower1), InfoTop(Tower2)))
        {
            return false;
        }
        else
        {
            boolean check = true;
            int i = 0;
            while ((i <= Top(Tower1)) && check)
            {
                if (!isWordEqual(Tower1.T[i], Tower2.T[i]))
                {
                    check = false;
                }
                i++;
            }
            return check;
        }
    }
    else
    {
        return false;
    }
}

void showTower(Stack *tiangA, Stack *tiangB, Stack *tiangC, int nPir)
{
    int repA, repB, repC;
    if (!IsEmptyStack(*tiangA))
    {
        repA = (((nPir * 2) - toInt(InfoTop(*tiangA))) / 2);
    }
    else
    {
        repA = 0;
    }
    if (!IsEmptyStack(*tiangB))
    {
        repB = (((nPir * 2) - toInt(InfoTop(*tiangB))) / 2);
    }
    else
    {
        repB = 0;
    }
    if (!IsEmptyStack(*tiangC))
    {
        repC = (((nPir * 2) - toInt(InfoTop(*tiangC))) / 2);
    }
    else
    {
        repC = 0;
    }

    int max = (nPir * 2) - 1;
    for (int i = (nPir - 1); i >= 0; i--)
    {
        if (i > Top(*tiangA))
        {
            for (int empty = 0; empty < max; empty++)
            {
                if (empty == (max / 2))
                {
                    printf("|");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        else
        {
            for (int j = repA; j > 0; j--)
            {
                printf(" ");
            }
            for (int idx = (repA + toInt((*tiangA).T[i])); idx > repA; idx--)
            {
                printf("*");
            }
            for (int k = max; k > (repA + toInt((*tiangA).T[i])); k--)
            {
                printf(" ");
            }
            repA = (((nPir * 2) - toInt((*tiangA).T[i-1])) / 2);
        }
        printf("\t");

        if (i > Top(*tiangB))
        {
            for (int empty = 0; empty < max; empty++)
            {
                if (empty == (max / 2))
                {
                    printf("|");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        else
        {
            for (int j = repB; j > 0; j--)
            {
                printf(" ");
            }
            for (int idx = (repB + toInt((*tiangB).T[i])); idx > repB; idx--)
            {
                printf("*");
            }
            for (int k = max; k > (repB + toInt((*tiangB).T[i])); k--)
            {
                printf(" ");
            }
            repB = (((nPir * 2) - toInt((*tiangB).T[i-1])) / 2);
        }
        printf("\t");

        if (i > Top(*tiangC))
        {
            for (int empty = 0; empty < max; empty++)
            {
                if (empty == (max / 2))
                {
                    printf("|");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        else
        {
            for (int j = repC; j > 0; j--)
            {
                printf(" ");
            }
            for (int idx = (repC + toInt((*tiangC).T[i])); idx > repC; idx--)
            {
                printf("*");
            }
            for (int k = max; k > (repC + toInt((*tiangC).T[i])); k--)
            {
                printf(" ");
            }
            repC = (((nPir * 2) - toInt((*tiangC).T[i-1])) / 2);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++)
    {
        for (int idx = 0; idx < ((nPir * 2) - 1); idx++)
        {
            printf("-");
        }
        if (i < 2)
        {
            printf("\t");
        }
        else
        {
            printf("\n");
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int idx = 0; idx < ((nPir * 2) - 1); idx++)
        {
            if (idx == (nPir - 1))
            {
                if (i == 0)
                {
                    printf("A");
                }
                else if (i == 1)
                {
                    printf("B");
                }
                else
                {
                    printf("C");
                }
            }
            else
            {
                printf(" ");
            }
        }
        printf("\t");
    }
    printf("\n");
}

void runTowerOfHanoi(SetMap *scoreboard);
{
    char asal[5];
    char tujuan[5];
    int nPir, attempt = 0;
    Stack tiangA, tiangB, tiangC, temp;
    CreateEmptyStack(&tiangA);
    CreateEmptyStack(&tiangB);
    CreateEmptyStack(&tiangC);
    CreateEmptyStack(&temp);

    printf("==========================| T O W E R  O F  H A N O I |==========================\n");
    printf("Selamat datang di Tower of Hanoi!\n");
    do
    {
        printf("Jumlah piringan minimal adalah 5 dan maksimal adalah 10.\n");
        printf("Masukkan jumlah piringan yang ingin digunakan: ");
        COMMAND();
        nPir = toInt(currentWord);
        if (nPir < 5 || nPir > 10)
        {
            printf("Jumlah piringan yang dimasukkan tidak sesuai.\n");
        }
    }
    while ((nPir < 5) || (nPir > 10));
    for (int i = nPir; i > 0; i--)
    {
        Push(&tiangA, toWord((2*i) - 1));
        Push(&temp, toWord((2*i) - 1));
    }
    printf("\n\nMenyiapkan piringan");
    countdown();
    system("cls");
    
    printf("==========================| T O W E R  O F  H A N O I |==========================\n");
    while (!isTowerEqual(temp, tiangC))
    {
        printf("Attempt: %d\n", (attempt + 1));
        printf("\n");
        showTower(&tiangA, &tiangB, &tiangC, nPir);
        printf("\n");

        int lenTAs, lenTAj;
        char TAs, TAj;
        printf("Titik Asal: ");
        COMMAND();
        TAs = currentWord.TabWord[0];
        lenTAs = currentWord.Length;
        printf("Titik Tujuan: ");
        COMMAND();
        TAj = currentWord.TabWord[0];
        lenTAj = currentWord.Length;

        system("cls");
        printf("==========================| T O W E R  O F  H A N O I |==========================\n");
        Word change;
        if ((lenTAj == 1) && (lenTAs == 1))
        {
            if (TAs == TAj)
            {
                printf("Titik asal dan titik tujuan tidak boleh sama.\n");
            }
            else
            {
                if (TAs == 'A' || TAs == 'a')
                {
                    if (TAj == 'B' || TAj == 'b')
                    {
                        if (IsEmptyStack(tiangA))
                        {
                            printf("Tiang A kosong.\n");
                        }
                        else if (!IsEmptyStack(tiangB) && (toInt(InfoTop(tiangA)) > toInt(InfoTop(tiangB))))
                        {
                            printf("Piringan tidak boleh diletakkan di atas piringan yang lebih kecil.\n");
                        }
                        else
                        {
                            Pop(&tiangA, &change);
                            Push(&tiangB, change);
                            printf("Memindahkan piringan ke ");
                            printWord(currentWord);
                            printf("\n");
                            countdown();
                            attempt++;
                        }
                    }
                    else if (TAj == 'C' || TAj == 'c')
                    {
                        if (IsEmptyStack(tiangA))
                        {
                            printf("Tiang A kosong.\n");
                        }
                        else if (!IsEmptyStack(tiangC) && (toInt(InfoTop(tiangA)) > toInt(InfoTop(tiangC))))
                        {
                            printf("Piringan tidak boleh diletakkan di atas piringan yang lebih kecil.\n");
                        }
                        else
                        {
                            Pop(&tiangA, &change);
                            Push(&tiangC, change);
                            printf("Memindahkan piringan ke ");
                            printWord(currentWord);
                            printf("\n");
                            countdown();
                            attempt++;
                        }
                    }
                    else
                    {
                        printf("Titik tujuan tidak valid.\n");
                    }
                    
                }
                else if (TAs == 'B' || TAs == 'b')
                {
                    if (TAj == 'A' || TAj == 'a')
                    {
                        if (IsEmptyStack(tiangB))
                        {
                            printf("Tiang B kosong.\n");
                        }
                        else if (!IsEmptyStack(tiangA) && (toInt(InfoTop(tiangB)) > toInt(InfoTop(tiangA))))
                        {
                            printf("Piringan tidak boleh diletakkan di atas piringan yang lebih kecil.\n");
                        }
                        else
                        {
                            Pop(&tiangB, &change);
                            Push(&tiangA, change);
                            printf("Memindahkan piringan ke ");
                            printWord(currentWord);
                            printf("\n");
                            countdown();
                            attempt++;
                        }
                    }
                    else if (TAj == 'C' || TAj == 'c')
                    {
                        if (IsEmptyStack(tiangB))
                        {
                            printf("Tiang B kosong.\n");
                        }
                        else if (!IsEmptyStack(tiangC) && (toInt(InfoTop(tiangB)) > toInt(InfoTop(tiangC))))
                        {
                            printf("Piringan tidak boleh diletakkan di atas piringan yang lebih kecil.\n");
                        }
                        else
                        {
                            Pop(&tiangB, &change);
                            Push(&tiangC, change);
                            printf("Memindahkan piringan ke ");
                            printWord(currentWord);
                            printf("\n");
                            countdown();
                            attempt++;
                        }
                    }
                    else
                    {
                        printf("Titik tujuan tidak valid.\n");
                    }
                }
                else if (TAs == 'C' || TAs == 'c')
                {
                    if (TAj == 'A' || TAj == 'a')
                    {
                        if (IsEmptyStack(tiangC))
                        {
                            printf("Tiang C kosong.\n");
                        }
                        else if (!IsEmptyStack(tiangA) && (toInt(InfoTop(tiangC)) > toInt(InfoTop(tiangA))))
                        {
                            printf("Piringan tidak boleh diletakkan di atas piringan yang lebih kecil.\n");
                        }
                        else
                        {
                            Pop(&tiangC, &change);
                            Push(&tiangA, change);
                            printf("Memindahkan piringan ke ");
                            printWord(currentWord);
                            printf("\n");
                            countdown();
                            attempt++;
                        }
                    }
                    else if (TAj == 'B' || TAj == 'b')
                    {
                        if (IsEmptyStack(tiangC))
                        {
                            printf("Tiang C kosong.\n");
                        }
                        else if (!IsEmptyStack(tiangB) && (toInt(InfoTop(tiangC)) > toInt(InfoTop(tiangB))))
                        {
                            printf("Piringan tidak boleh diletakkan di atas piringan yang lebih kecil.\n");
                        }
                        else
                        {
                            Pop(&tiangC, &change);
                            Push(&tiangB, change);
                            printf("Memindahkan piringan ke ");
                            printWord(currentWord);
                            printf("\n");
                            countdown();
                            attempt++;
                        }
                    }
                    else
                    {
                        printf("Titik tujuan tidak valid.\n");
                    }
                }
                else if (TAs == 'C' || TAs == 'c')
                {
                    if (TAj == 'A' || TAj == 'a')
                    {
                        if (IsEmptyStack(tiangC))
                        {
                            printf("Tiang C kosong.\n");
                        }
                        else if (!IsEmptyStack(tiangA) && (toInt(InfoTop(tiangC)) > toInt(InfoTop(tiangA))))
                        {
                            printf("Piringan tidak boleh diletakkan di atas piringan yang lebih kecil.\n");
                        }
                        else
                        {
                            Pop(&tiangC, &change);
                            Push(&tiangA, change);
                            printf("Memindahkan piringan ke ");
                            printWord(currentWord);
                            printf("\n");
                            countdown();
                            attempt++;
                        }
                    }
                    else if (TAj == 'B' || TAj == 'b')
                    {
                        if (IsEmptyStack(tiangC))
                        {
                            printf("Tiang C kosong.\n");
                        }
                        else if (!IsEmptyStack(tiangB) && (toInt(InfoTop(tiangC)) > toInt(InfoTop(tiangB))))
                        {
                            printf("Piringan tidak boleh diletakkan di atas piringan yang lebih kecil.\n");
                        }
                        else
                        {
                            Pop(&tiangC, &change);
                            Push(&tiangB, change);
                            printf("Memindahkan piringan ke ");
                            printWord(currentWord);
                            printf("\n");
                            countdown();
                            attempt++;
                        }
                    }
                    else
                    {
                        printf("Titik tujuan tidak valid.\n");
                    }
                }
                else
                {
                    printf("Titik asal tidak valid.\n");

                }
            }
        }
        else
        {
            printf("Masukkan tidak valid.\n");
        }
        printf("=================================================================================\n");

        if (isTowerEqual(temp, tiangC))
        {
            system("cls");
            printf("==========================| T O W E R  O F  H A N O I |==========================\n");
            printf("Attempt: %d\n", attempt);
            showTower(&tiangA, &tiangB, &tiangC, nPir);
        }
    }

    int score;
    if (nPir == 5)
    {
        score = 5 + (attempt - 31);
    }
    else if (nPir == 6)
    {
        score = 6 + (attempt - 63);
    }
    else if (nPir == 7)
    {
        score = 7 + (attempt - 127);
    }
    else if (nPir == 8)
    {
        score = 8 + (attempt - 255);
    }
    else if (nPir == 9)
    {
        score = 9 + (attempt - 511);
    }
    else if (nPir == 10)
    {
        score = 10 + (attempt - 1023);
    }

    printf("=================================================================================\n");
    printf("                 ***  C O N G R A T U L A T I O N  ***\n");
    printf("                                   S K O R : %d", score);
    printf("\n\n\n");
    //toScoreboard(scoreboard, score);
}