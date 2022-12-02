/* =====| HangmanWords HANGMAN |===== */

// Include file header yang diperlukan
#include "allgames.h"

boolean isCharvalid(char kata )
{
    if(((kata >= 65) && (kata <= 90)) || ((kata >= 97) && (kata <= 122)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

boolean isUpper(char kata)
{
    if((kata >= 65) && (kata <= 90))
    {
        return true;
    }
    else
    {
        return false;
    }
}

char animasi(int x)
{
    if (x == 10) {printf("\n\n\n\n\n\n\n\n");}
    else if (x == 9) {printf("\n\n\n\n\n\n\n\n\n+==========+\n");}
    else if (x == 8) {printf("\n||\n||\n||\n||\n||\n||\n||\n||\n||\n+==========+\n");}
    else if (x == 7) {printf("\n||==================\n||\n||\n||\n||\n||\n||\n||\n||\n+==========+\n");}
    else if (x == 6) {printf("\n||==================\n||\t\t|\n||\n||\n||\n||\n||\n||\n||\n+==========+\n");}
    else if (x == 5) {printf("\n||==================\n||\t\t|\n||\t      ('.')\n||\n||\n||\n||\n||\n||\n+==========+\n");}
    else if (x == 4) {printf("\n||==================\n||\t\t|\n||\t     \\('.')\n||\n||\n||\n||\n||\n||\n+==========+\n");}
    else if (x == 3) {printf("\n||==================\n||\t\t|\n||\t     \\('.')/\n||\n||\n||\n||\n||\n||\n+==========+\n");}
    else if (x == 2) {printf("\n||==================\n||\t\t|\n||\t     \\('.')/\n||\t\t|\n||\n||\n||\n||\n||\n+==========+\n");}
    else if (x == 1) {printf("\n||==================\n||\t\t|\n||\t     \\('.')/\n||\t\t|\n||\t       /\n||\n||\n||\n||\n+==========+\n");}
    else if (x == 0) {printf("\n||==================\n||\t\t|\n||\t     \\('.')/\n||\t\t|\n||\t       / \\\n||\n||\n||\n||\n+==========+\n");}
}

void runHangman(SetMap *scoreboard, ArrayDin *HangmanWords)
{

    system("cls");
    ArrayDin hist = MakeArrayDin();
    int cek = 0, Benar = 0, cek_benar = 0, poin = 0, chance = 10, Num = 0, i = 0, j = 0;
    Word Kata_ku, Kata;
    time_t t;

    //Kata yang akan ditebak
    do
    {
        srand(time(&t));
        Num = (rand() % (HangmanWords->Neff));
    } while (Num == 0); 
    Kata.Length = HangmanWords->Elmt[Num].Length;
    for (int i = 0; i < HangmanWords->Elmt[Num].Length; i++)
    {
        Kata.TabWord[i] = HangmanWords->Elmt[Num].TabWord[i];
    }

    //Tampilan Awal
    printf("=============================== | HANGMAN by BNMO-2.0 | =============================== \n");
    printf("Selamat datang di Hangman!\n\n\n\nMemuat Permainan, Tunggu Sebentar");
    countdown();
    system("cls");

    //Tampilan Menu Awal Permainan
    int nambah = 0;
    while(nambah == 0)
    {
        printf("=============================== | HANGMAN by BNMO-2.0 | =============================== \n\n\n\n\n");
        printf("Sebelum mulai main, mau menambahkan kata ke dalam permainan? (Y/N): ");
        COMMAND();
        Word Y, N;
        Y.Length = 1;
        Y.TabWord[0] = 'Y';
        N.Length = 1;
        N.TabWord[0] = 'N';
        if (currentWord.TabWord[0] == Y.TabWord[0])
        {
            printf("Masukkan kata yang ingin ditambahkan: ");
            COMMAND();
            HangmanWords->Neff += 1;
            HangmanWords->Elmt[HangmanWords->Neff].TabWord[0] = '\0';
            for (int i = 0; i <= currentWord.Length; i++)
            {
                HangmanWords->Elmt[HangmanWords->Neff-1].TabWord[i] = currentWord.TabWord[i];
            }
            HangmanWords->Elmt[HangmanWords->Neff-1].Length = currentWord.Length;
            printf("Kata berhasil ditambahkan!\n");
            countdown();
        }
        else if (currentWord.TabWord[0] == N.TabWord[0])
        {
            printf("Mari Bermain (^o^)/\n");
            nambah = 1;
            countdown();
        }
        else
        {
            printf("Masukan tidak valid. Coba lagi\n");
            countdown();
        }
        system("cls");
    }

    while(chance > 0)
    {
        system("cls");
        printf("=============================== | HANGMAN by BNMO-2.0 | =============================== \n");
        printf("Hayuk tebak katanya!\n\n");
        animasi(chance);
        
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
                if (Kata.TabWord[i] == (hist.Elmt[j].TabWord[0] - 32))
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
        while((currentWord.Length !=1) || (!isCharvalid(currentWord.TabWord[0])))
        {
            printf("Masukkan Tidak Valid! Coba Lagi :)\n");
            printf("Masukkan tebakan:");
            COMMAND();
        }
        //Cek apakah huruf yang ditebak sudah pernah ditebak
        for (i = 0; i < hist.Neff; i++)
        {
            if (currentWord.TabWord[0] == (hist.Elmt[i].TabWord[0] - 32))
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
            if (isUpper(currentWord.TabWord[0]))
            {
                currentWord.TabWord[0] += 32;
            }
            hist.Elmt[hist.Neff].Length = currentWord.Length;
            hist.Elmt[hist.Neff].TabWord[0] = currentWord.TabWord[0];
            hist.Neff++;
            for (i = 0; i < Kata.Length; i++)
            {
                for (j = 0; j < hist.Neff; j++)
                {
                    if (Kata.TabWord[i] == hist.Elmt[j].TabWord[0] - 32)
                    {
                        cek_benar += 1;
                        break;
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
                printf("Lanjuuuuut");
                countdown();
                printf("\n");
                DeallocateArrayDin(&hist);
                hist = MakeArrayDin();

                //Generate Kata Baru
                do
                {
                    srand(time(&t));
                    Num = (rand() % (HangmanWords->Neff));
                } while (Num == 0);

                Kata.Length = HangmanWords->Elmt[Num].Length;
                for (int i = 0; i < HangmanWords->Elmt[Num].Length; i++)
                {
                    Kata.TabWord[i] = HangmanWords->Elmt[Num].TabWord[i];
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
        currentWord.Length = 0;

    }
    system("cls");
    printf("=============================== | GAME  OVER | ===============================\n");
    printf("Kata sebelumnya adalah: ");
    printWord(Kata);
    animasi(0);
    printf("\nMenghitung poin");
    countdown();
    printf("\n");
    printf("========================= | SKOR KAMU ADALAH %d | =========================\n\n\n", poin);
    toScoreboard(scoreboard, poin);
    printf("Terima Kasih Sudah Bermain (^o^)/ Bye Bye ~~\n");
}