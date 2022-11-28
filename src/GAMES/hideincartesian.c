/* =====| GAME HIDE IN CARTESIAN |===== */

// Include file header yang diperlukan
#include "allgames.h"

// Prosedur untuk menjalankan permainan Hide In Cartesian
// Menebak tempat persembuyian yang berada pada koordinar cartesius
int runHideInCartesian(SetMap *scoreboard)
{
    int i, count = 0;
    boolean clear = false;
    ArrayDin Coordinate = MakeArrayDin();
    Point Hide;
    Word HideOut;

    // TITIK ASAL
    Coordinate.Elmt[0].Length = 10;
    char CMDTA[15] = "TITIK ASAL";
    for (i = 0; i < 10; i++)
    {
        Coordinate.Elmt[0].TabWord[i] = CMDTA[i];
    }
    // SUMBU X
    Coordinate.Elmt[1].Length = 7;
    char CMDSX[15] = "SUMBU X";
    for (i = 0; i < 7; i++)
    {
        Coordinate.Elmt[1].TabWord[i] = CMDSX[i];
    }
    // SUMBU Y
    Coordinate.Elmt[2].Length = 7;
    char CMDSY[15] = "SUMBU Y";
    for (i = 0; i < 7; i++)
    {
        Coordinate.Elmt[2].TabWord[i] = CMDSY[i];
    }
    // KUADRAN 1
    Coordinate.Elmt[3].Length = 9;
    char CMDK1[15] = "KUADRAN 1";
    for (i = 0; i < 9; i++)
    {
        Coordinate.Elmt[3].TabWord[i] = CMDK1[i];
    }
    // KUADRAN 2
    Coordinate.Elmt[4].Length = 9;
    char CMDK2[15] = "KUADRAN 2";
    for (i = 0; i < 9; i++)
    {
        Coordinate.Elmt[4].TabWord[i] = CMDK2[i];
    }
    // KUADRAN 3
    Coordinate.Elmt[5].Length = 9;
    char CMDK3[15] = "KUADRAN 3";
    for (i = 0; i < 9; i++)
    {
        Coordinate.Elmt[5].TabWord[i] = CMDK3[i];
    }
    // KUADRAN 4
    Coordinate.Elmt[6].Length = 9;
    char CMDK4[15] = "KUADRAN 4";
    for (i = 0; i < 9; i++)
    {
        Coordinate.Elmt[6].TabWord[i] = CMDK4[i];
    }

    time_t t;
    srand(time(&t));

    printf("======================| H I D E  I N  C A R T E S I A N |======================\n");
    printf("Kamu adalah teman dekat Indra. Setiap sore Indra diminta oleh ibunya untuk\n"); ;
    printf("mencari Kenz, adiknya, agar membawa Kenz pulang karena hari sudah mulai gelap.\n");
    printf("Namun, Kenz cukup bandel dan masih ingin bermain dengan teman-temannya. Jadi,\n");
    printf("Kenz pun bersembunyi agar tidak berhasil ditemukan Indra. Bantulah Indra untuk\n");
    printf("mencari Kenz sebelum matahari terbenam.\n");
    printf("\n\nPetunjuk yang dapat kamu berikan kepada Indra: (Case Sensitive)\n");
    printf(">>> TITIK ASAL\n");
    printf(">>> SUMBU X\n");
    printf(">>> SUMBU Y\n");
    printf(">>> KUADRAN 1\n");
    printf(">>> KUADRAN 2\n");
    printf(">>> KUADRAN 3\n");
    printf(">>> KUADRAN 4\n");
    printf("\n\nB A C A  D U L U  P E T U N J U K N Y A ");
    for (i = 0; i < 7; i++)
    {
        countdown();
    }

    while (!clear && count < 5)
    {
        CreatePoint(&Hide, ((rand() % 19) - 9), ((rand() % 19) - 9));
        if ((Hide.x == 0) && (Hide.y == 0))
        {
            HideOut.Length = Coordinate.Elmt[0].Length;
            for (i = 0; i < HideOut.Length; i++)
            {
                HideOut.TabWord[i] = Coordinate.Elmt[0].TabWord[i];
            }
        }
        else if ((Hide.x != 0) && (Hide.y == 0))
        {
            HideOut.Length = Coordinate.Elmt[1].Length;
            for (i = 0; i < HideOut.Length; i++)
            {
                HideOut.TabWord[i] = Coordinate.Elmt[1].TabWord[i];
            }
        }
        else if ((Hide.x == 0) && (Hide.y != 0))
        {
            HideOut.Length = Coordinate.Elmt[2].Length;
            for (i = 0; i < HideOut.Length; i++)
            {
                HideOut.TabWord[i] = Coordinate.Elmt[2].TabWord[i];
            }
        }
        else if ((Hide.x > 0) && (Hide.y > 0))
        {
            HideOut.Length = Coordinate.Elmt[3].Length;
            for (i = 0; i < HideOut.Length; i++)
            {
                HideOut.TabWord[i] = Coordinate.Elmt[3].TabWord[i];
            }
        }
        else if ((Hide.x < 0) && (Hide.y > 0))
        {
            HideOut.Length = Coordinate.Elmt[4].Length;
            for (i = 0; i < HideOut.Length; i++)
            {
                HideOut.TabWord[i] = Coordinate.Elmt[4].TabWord[i];
            }
        }
        else if ((Hide.x < 0) && (Hide.y < 0))
        {
            HideOut.Length = Coordinate.Elmt[5].Length;
            for (i = 0; i < HideOut.Length; i++)
            {
                HideOut.TabWord[i] = Coordinate.Elmt[5].TabWord[i];
            }
        }
        else if ((Hide.x > 0) && (Hide.y < 0))
        {
            HideOut.Length = Coordinate.Elmt[6].Length;
            for (i = 0; i < HideOut.Length; i++)
            {
                HideOut.TabWord[i] = Coordinate.Elmt[6].TabWord[i];
            }
        }

        system("cls");
        printf("======================| H I D E  I N  C A R T E S I A N |======================\n");
        printf("Petunjuk yang dapat kamu berikan kepada Indra: (Case Sensitive)\n");
        printf(">>> TITIK ASAL\n");
        printf(">>> SUMBU X\n");
        printf(">>> SUMBU Y\n");
        printf(">>> KUADRAN 1\n");
        printf(">>> KUADRAN 2\n");
        printf(">>> KUADRAN 3\n");
        printf(">>> KUADRAN 4\n");
        printf("\nKesempatan: %d\n", (5 - count));
        printf("\n\nDimanakah Kenz bersembunyi? ");
        COMMAND();
        countdown();
        if (isWordEqual(currentWord, HideOut))
        {
            clear = true;
        }
        else
        {
            system("cls");
            printf("======================| H I D E  I N  C A R T E S I A N |======================\n");
            printf("Yahhh, tebakanmu salah ~_~\n");
            printf("Kenz mungkin sudah pindah ke tempat lain nihhh...\n");
            countdown();
        }
        count++;
    }

    if (clear)
    {
        system("cls");
        printf("======================| H I D E  I N  C A R T E S I A N |======================\n");
        printf("K A M U  B E R H A S I L  M E M B A N T U  I N D R A  M E N E M U K A N  K E N Z\n");
        printf("        ! ! ! K A M U  A D A L A H  T E M A N  Y A N G  H E B A T ! ! !\n");
    }
    else
    {
        system("cls");
        printf("======================| H I D E  I N  C A R T E S I A N |======================\n");
        printf("                      K E N Z  B E R H A S I L  K A B U R\n");
        printf("                        ! ! ! K A M U   G A G A L ! ! !\n");
    }
    int score = 100 - (count * 20);
    printf("                                 S K O R : %d\n", score);
    printf("\n\n\n");
    toScoreboard(scoreboard, score);
}