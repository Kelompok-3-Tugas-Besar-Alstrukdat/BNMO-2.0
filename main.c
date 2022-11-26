//---------------------------------------------------------- INCLUDE FILE HEADER ----------------------------------------------------//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "src/CONSOLE/console.h"


void backToMainPage()
{
    printf("\n\n\n\n\nK E M B A L I  K E  H A L A M A N  U T A M A ");
    countdown();
    system("cls");
}

void changePage()
{
    printf("\n\n\n\n\nM O H O N  T U N G G U ");
    countdown();
    system("cls");
    printf("==================================| B N M O |==================================\n");
}

void loadGame(Word game)
{
    printf("\n\n\n\n\nS E D A N G  M E M U A T  ");
    for (int i = 0; i < game.Length; i++)
    {
        printf("%c ", game.TabWord[i]);
    }
    countdown();
    system("cls");
    printf("==================================| B N M O |==================================\n");
}

void main()
{
    char filename[50] = "docs/";
    Word INPUT;
    ArrayDin Game = MakeArrayDin(), AllScoreboard = MakeArrayDin();
    Queue GameQ;
    Stack history;
    SetMap sbGame[100];
    CreateQueue(&GameQ);
    CreateEmptyStack(&history);

    display();
    printf("====================================| B N M O |====================================\n");
    printf("Masukkan command START atau LOAD <namafile>.txt untuk menjalan BNMO.\n");
    fetchBNMO(&INPUT);
    if (isWordEqual(INPUT,validCOMMAND().Elmt[0]))
    {
        Start(&Game, &AllScoreboard, &history);
        readScoreboard(Game, AllScoreboard, sbGame);
    }
    else
    {
        Load(&Game, &AllScoreboard, &history, &filename, &INPUT);
        readScoreboard(Game, AllScoreboard, sbGame);
    }

    printf("\n\n\n\n\nM O H O N  T U N G G U ");
    countdown();
    system("cls");

    while (!isWordEqual(INPUT,validCOMMAND().Elmt[9]))
    {
        printf("==================================| B N M O |==================================\n");
        printf("Menu dan command yang dapat diakses:\n");
        printf(">>> LIST GAME\n");
        printf(">>> QUEUE GAME\n");
        printf(">>> CREATE GAME\n");
        printf(">>> DELETE GAME\n");
        printf(">>> PLAY GAME\n");
        printf(">>> SKIPGAME <n>\n");
        printf(">>> SAVE <namafile>.txt\n");
        printf(">>> QUIT\n");
        printf(">>> HELP\n");
        printf("\nMASUKKAN COMMAND: ");
        COMMAND();
        for (int i = 0; i < currentWord.Length; i++)
        {
            INPUT.TabWord[i] = currentWord.TabWord[i];
        }
        INPUT.Length = currentWord.Length;
        
        if (!isCOMMAND(INPUT))
        {
            int i = 0;
            while ((currentWord.TabWord[i] != ' ') && (i < currentWord.Length))
            {
                INPUT.TabWord[i] = currentWord.TabWord[i];
                i++;
            }
            INPUT.Length = i;

            int j = 5;
            for (int i = INPUT.Length; i < currentWord.Length; i++)
            {
                if (currentWord.TabWord[i] != ' ')
                {
                    filename[j] = currentWord.TabWord[i];
                    j++;
                }
            }
            filename[j] = '\0';

            if (!isWordEqual(INPUT, validCOMMAND().Elmt[2]) && !isWordEqual(INPUT, validCOMMAND().Elmt[8]))
            {
                INPUT.Length = 0;
            }
        }

        if (isCOMMAND(INPUT))
        {
            // INPUT == START atau INPUT == LOAD
            if ((isWordEqual(INPUT, validCOMMAND().Elmt[0])) || (isWordEqual(INPUT, validCOMMAND().Elmt[1])))
            {
                changePage();
                printf("BNMO sudah dijalankan.\n");
                backToMainPage();
            }
            // INPUT == SAVE
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[2])))
            {
                changePage();
                if (validExtension(filename))
                {
                    Save(Game, filename);
                    printf("Save file berhasil disimpan.\n");
                }
                else
                {
                    printf("Harap periksa kembali extension file Kamu.\nFormat save: SAVE <namafile>.txt\n");
                }
                backToMainPage();
            }
            // INPUT == CREATEGAME
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[3])))
            {
                changePage();
                CreateGame(&Game);
                backToMainPage();
            }
            // INPUT == LISTGAME
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[4])))
            {
                changePage();
                ListGame(Game);
            }
            // INPUT == DELETEGAME
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[5])))
            {
                changePage();
                DeleteGame(&Game, &GameQ);
                backToMainPage();
            }
            // INPUT == QUEUEGAME
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[6])))
            {
                changePage();
                QueueGame(&Game, &GameQ);
                backToMainPage();
            }
            // INPUT == PLAYGAME
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[7])))
            {
                if (isEmptyQueue(GameQ))
                {
                    changePage();
                    printf("Daftar antrian Kamu kosong. Silahkan tambahkan permainan terlebih dahulu.\n");
                }
                else
                {
                    loadGame(HEAD(GameQ));
                    PlayGame(&GameQ);
                }
                backToMainPage();
            }
            // INPUT == SKIPGAME
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[8])))
            {
                changePage();
                int idx = 5, n = 0;
                while (filename[idx] != '\0')
                {
                    idx++;
                }
                int digit = 0;
                for (int tidx = (idx - 1); tidx >= 5; tidx--)
                {
                    n += ((filename[tidx] - '0') * pow(10, digit));
                    digit++;
                }
                if (n > 0)
                {
                    SkipGame(&GameQ, n);
                }
                else
                {
                    printf("Parameter skip tidak valid.\nTIPS: Parameter harus lebih besar dari nol\n");
                }
                backToMainPage();
            }
            // INPUT == QUIT
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[9])))
            {
                printf("Apakah Kamu ingin menyimpan data permainanmu? (y/n)\t");
                COMMAND();
                if (currentWord.TabWord[0] == 'y')
                {
                    INPUT.Length = 0;
                    backToMainPage();
                }
                else if (currentWord.TabWord[0] == 'n')
                {
                    system("cls");
                    printf("==================================| B N M O |==================================\n");
                    printf("           ^_^ T E R I M A  K A S I H  T E L A H  B E R M A I N ^_^\n");
                    printf("                              B Y E  B Y E ");
                    countdown();
                    system("cls");
                }
                else
                {
                    INPUT.Length = 0;
                    changePage();
                    printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
                    backToMainPage();
                }
            }
            // INPUT == HELP
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[10])))
            {
                changePage();
                Help();
            }
        }
        else
        {
            changePage();
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
            backToMainPage();
        }
    }
}