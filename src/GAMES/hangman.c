/* =====| GAME HANGMAN |===== */

// Include file header yang diperlukan
#include "../ADT/Array/array.c"
#include "../ADT/MesinKata/mesinkata.c"
#include "../ADT/MesinKarakter/mesinkarakter.c"
#include "../ADT/SetMap/setmap.c"
#include "../ADT/Stack/stack.c"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void countdown()
{
    int check;
    time_t start_t, end_t;
    float diff_t;
    check = 0;
    time(&start_t);
    time(&end_t);
    
    diff_t = difftime(end_t, start_t);
    while (diff_t != 4){
        time(&end_t);
        diff_t = (float) difftime(end_t, start_t);
        
        if ((diff_t == 1 ) && (check != -1) && (check != -2) && (check != -99)) {
            printf(".");
            check = -1;
        }
        if ((diff_t == 2 ) && (check == -1)) {
            printf(".");
            check = -2;
        }
        if ((diff_t == 3 ) && (check == -2)) {
            printf(".");
            check = -99;
        }
    }
}


void main()
{
    //Baca File
    ArrayDin Game = MakeArrayDin();
    FILE *test;
    char filename[25] = "../../data/hangman.txt";
    test = fopen(filename, "r");

    if (test == NULL)
    {
        printf("File tidak ditemukan\n");
        countdown();
    }
    else
    {
        fclose(test);
        int i, j, idx;
        STARTWORD(filename);
        idx = toInt(currentWord);
        Game.Neff = (idx + 1);
        for (i = 0; i <= idx; i++)
        {
            Game.Elmt[i].Length = currentWord.Length;
            for (int j = 0; j < currentWord.Length; j++)
            {
                Game.Elmt[i].TabWord[j] = currentWord.TabWord[j];
            }
            ADVWORD();
        }

        system("cls");
            ArrayDin hist = MakeArrayDin();
            int cek = 0, Benar = 0, cek_benar = 0, poin = 0, chance = 10, Num = 0;
            Word Kata_ku, Kata;
            time_t t;

            //Kata yang akan ditebak
            do
            {
                srand(time(&t));
                Num = (rand() % (Game.Neff));
            } while (Num == 0); 
            Kata.Length = Game.Elmt[Num].Length;
            for (int i = 0; i < Game.Elmt[Num].Length; i++)
            {
                Kata.TabWord[i] = Game.Elmt[Num].TabWord[i];
            }

            //Tampilan Awal
            printf("=============================== | HANGMAN by BNMO-2.0 | =============================== \n");
            printf("Selamat datang di Hangman!\n\n\n\nMemuat Permainan, Tunggu Sebentar Yaa");
            countdown(); countdown();
            system("cls");

            //Tampilan Menu Awal Permainan
            int nambah = 0;
            while(nambah == 0)
            {
                printf("=============================== | HANGMAN by BNMO-2.0 | =============================== \n\n\n\n\n");
                printf("Mau Langsung Main atau Nambahin Kata Dulu Nih??[Main/Nambah]: ");
                COMMAND();
                if (currentWord.Length == 6)
                {
                    printf("Masukkan kata yang ingin ditambahkan: ");
                    COMMAND();
                    Game.Neff += 1;
                    Game.Elmt[Game.Neff].TabWord[0] = '\0';
                    for (int i = 0; i <= currentWord.Length; i++)
                    {
                        Game.Elmt[Game.Neff-1].TabWord[i] = currentWord.TabWord[i];
                    }
                    Game.Elmt[Game.Neff-1].Length = currentWord.Length;
                    printf("Kata berhasil ditambahkan!\n");
                    countdown();
                }
                else if (currentWord.Length == 4)
                {
                    printf("Okeey, Mari Bermain (^o^)/\n");
                    nambah = 1;
                    countdown();
                }
                else
                {
                    printf("Inputnya Salah nihh, Coba lagi yaa\n");
                    countdown();
                }
                system("cls");
            }


            while(chance > 0)
            {
                system("cls");
                printf("=============================== | HANGMAN by BNMO-2.0 | =============================== \n");
                printf("Kata Apa Nichh???\n\n");

                //Tebakan Sebelumnya
                printf("Tebakan sebelumnya:");
                if (hist.Neff == 0)
                {
                    printf("-\n");
                }
                else
                {
                    for (i = 0; i < hist.Neff; i++)
                    {
                        printWord(hist.Elmt[i]);
                    }
                    printf("\n");
                }

                //Tampilan Saat Menebak Kata
                printf("KATA:");
                for (i = 0; i < Kata.Length; i++)
                {
                    for (j = 0; j < hist.Neff; j++)
                    {
                        if (Kata.TabWord[i] == hist.Elmt[j].TabWord[0])
                        {
                            printf("%c", Kata.TabWord[i]);
                            cek = 1; //Apabila huruf dicetak, maka nanti tidak akan dicetak "_"
                            Benar += 1;
                            break;
                        }
                    }
                    if (cek == 0)
                    {
                        printf("_");
                    }
                    else
                    {
                        cek = 0; //Reset nilai cek
                    }
                }
                printf("\n");

                //Kesempatan Menebak
                printf("Kesempatan: %d\n", chance);

                //Input Huruf yang akan ditebak
                printf("Masukkan tebakan:");
                COMMAND();
                cek = 0;
                while(currentWord.Length >1)
                {
                    printf("CUKUP SATU KARAKTER SAJA YAA\n");
                    printf("Masukkan tebakan:");
                    COMMAND();
                }
                //Cek apakah huruf yang ditebak sudah pernah ditebak
                for (i = 0; i < hist.Neff; i++)
                {
                    if (currentWord.TabWord[0] == hist.Elmt[i].TabWord[0])
                    {
                        printf("Kamu Udah Pernah Menebak Ini :D\n");
                        cek = 1;
                        countdown();
                        break;
                    }
                }
                //Jika belum pernah ditebak
                if (cek == 0)
                {
                    hist.Elmt[hist.Neff].Length = currentWord.Length;
                    hist.Elmt[hist.Neff].TabWord[0] = currentWord.TabWord[0];
                    hist.Neff++;
                    for (i = 0; i < Kata.Length; i++)
                    {
                        for (j = 0; j < hist.Neff; j++)
                        {
                            if (Kata.TabWord[i] == hist.Elmt[j].TabWord[0])
                            {
                                cek_benar += 1;
                            }
                        }
                    }
                    if (Benar == cek_benar)
                    {
                        chance--;
                    }

                    if (cek_benar == Kata.Length)
                    {
                        poin += Kata.Length;
                        printf("=============================== | BERHASIL MENEBAK KATA ");
                        printWord(Kata);
                        printf("! KAMU MENDAPATKAN %d POIN! | ===============================\n", Kata.Length);
                        printf("POIN KAMU SEKARANG: %d\n", poin);
                        printf("Lanjuuuuuttt");
                        countdown();
                        printf("\n");
                        DeallocateArrayDin(&hist);
                        hist = MakeArrayDin();

                        //Generate Kata Baru
                        do
                        {
                            srand(time(&t));
                            Num = (rand() % (Game.Neff));
                        } while (Num == 0);

                        Kata.Length = Game.Elmt[Num].Length;
                        for (int i = 0; i < Game.Elmt[Num].Length; i++)
                        {
                            Kata.TabWord[i] = Game.Elmt[Num].TabWord[i];
                        }
                    }
                    
                }
                //Jika sudah pernah ditebak
                else
                {
                    cek = 0;
                }
                cek_benar = 0;
                Benar = 0;

            }
            printf("=============================== | GAME  OVER | ===============================\n");
            printf("Menghitung poin");
            countdown();
            printf("\n");
            printf("========================= | SKOR KAMU ADALAH %d | =========================\n\n\n", poin);
            printf("Terima Kasih Sudah Bermain (^o^)/ Bye Bye ~~\n");
    }

    
}