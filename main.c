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
    int n;
    char filename[50] = "data/";
    Word INPUT;
    ArrayDin Game = MakeArrayDin();
    ArrayDin HangmanWords = MakeArrayDin();
    ArrayDin AllScoreboard = MakeArrayDin();
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
        Start(&Game, &HangmanWords, &AllScoreboard, &history);
        readScoreboard(Game, AllScoreboard, sbGame);
    }
    else
    {
        Load(&Game, &HangmanWords, &AllScoreboard, &history, filename, &INPUT);
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
        printf(">>> SCOREBOARD\n");
        printf(">>> RESET SCOREBOARD\n");
        printf(">>> HISTORY <n>\n");
        printf(">>> RESET HISTORY\n");
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

            if (!isWordEqual(INPUT, validCOMMAND().Elmt[2]) && !isWordEqual(INPUT, validCOMMAND().Elmt[8]) && !isWordEqual(INPUT, validCOMMAND().Elmt[13]))
            {
                INPUT.Length = 0;
            }
            else
            {
                if (isWordEqual(INPUT, validCOMMAND().Elmt[2]))
                {
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
                }
                else
                {
                    Word tempN;
                    int idx = 0;
                    for (int i = INPUT.Length; i < currentWord.Length; i++)
                    {
                        if (currentWord.TabWord[i] != ' ')
                        {
                            tempN.TabWord[idx] = currentWord.TabWord[i];
                            idx++;
                        }
                    }
                    tempN.Length = idx;
                    n = toInt(tempN);
                }
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
                    Save(Game, HangmanWords, history, sbGame, filename);
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
                CreateGame(&Game, sbGame);
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
                DeleteGame(&Game, &GameQ, &history, sbGame);
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
                    PlayGame(Game, &HangmanWords, &GameQ, &history, sbGame);
                }
                backToMainPage();
            }
            // INPUT == SKIPGAME
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[8])))
            {
                changePage();
                if (n > 0)
                {
                    SkipGame(Game, &HangmanWords, &GameQ, n, &history, sbGame);
                }
                else
                {
                    printf("Parameter skip tidak valid.\nTIPS: Parameter harus lebih besar dari nol\n");
                }
                backToMainPage();
            }
            // INPUT == SCOREBOARD
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[11])))
            {
                changePage();
                for (int i = 0; i < (Game.Neff - 1); i++)
                {
                    printf(">>> SCOREBOARD GAME ");
                    printWord(Game.Elmt[i+1]);
                    printf("\n");
                    Scoreboard(sbGame[i]);
                    printf("\n");
                }
            }
            // INPUT == RESET SCOREBOARD
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[12])))
            {

            }
            // INPUT == HISTORY
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[13])))
            {
                changePage();
                if (n > 0)
                {
                    History(history, n);
                }
                else
                {
                    printf("Parameter history tidak valid.\nTIPS: Parameter harus lebih besar dari nol\n");
                }
            }
            // INPUT == RESET HISTORY
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[14])))
            {

            }
            // INPUT == QUIT
            else if ((isWordEqual(INPUT, validCOMMAND().Elmt[9])))
            {
                printf("Apakah Kamu ingin menyimpan data permainanmu? (y/n) ");
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