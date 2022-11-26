/* =====| GAME HANGMAN |===== */

// Include file header yang diperlukan
#include "allgames.h"

Word ApaHayoo(int N)
{
    ArrayDin Tebakan = MakeArrayDin();
    Word Kata;

    //KATA 1
    Tebakan.Elmt[0].Length = 11;
    char IF[20] = "INFORMATIKA";
    for (int i = 0; i < 11; i++)
    {
        Tebakan.Elmt[0].TabWord[i] = IF[i];
    }
    //KATA 2
    Tebakan.Elmt[1].Length = 4;
    char HM[20] = "HMIF";
    for (int i = 0; i < 4; i++)
    {
        Tebakan.Elmt[1].TabWord[i] = HM[i];
    }
    //KATA 3
    Tebakan.Elmt[2].Length = 6;
    char AS[20] = "ASSIST";
    for (int i = 0; i < 6; i++)
    {
        Tebakan.Elmt[2].TabWord[i] = AS[i];
    }
    //KATA 4
    Tebakan.Elmt[3].Length = 5;
    char KO[20] = "KOICA";
    for (int i = 0; i < 5; i++)
    {
        Tebakan.Elmt[3].TabWord[i] = KO[i];
    }
    //KATA 5
    Tebakan.Elmt[4].Length = 7;
    char GN[20] = "GANESHA";
    for (int i = 0; i < 7; i++)
    {
        Tebakan.Elmt[4].TabWord[i] = GN[i];
    }
    //KATA 6
    Tebakan.Elmt[5].Length = 10;
    char JN[20] = "JATINANGOR";
    for (int i = 0; i < 10; i++)
    {
        Tebakan.Elmt[5].TabWord[i] = JN[i];
    }
    //KATA 7
    Tebakan.Elmt[6].Length = 9;
    char PR[20] = "PRAKTIKUM";
    for (int i = 0; i < 9; i++)
    {
        Tebakan.Elmt[6].TabWord[i] = PR[i];
    }
    //KATA 8
    Tebakan.Elmt[7].Length = 10;
    char AL[20] = "ALSTRUKDAT";
    for (int i = 0; i < 10; i++)
    {
        Tebakan.Elmt[7].TabWord[i] = AL[i];
    }
    //KATA 9
    Tebakan.Elmt[8].Length = 7;
    char PO[20] = "POINTER";
    for (int i = 0; i < 7; i++)
    {
        Tebakan.Elmt[8].TabWord[i] = PO[i];
    }
    //KATA 10
    Tebakan.Elmt[9].Length = 10;
    char TB[20] = "TUGASBESAR";
    for (int i = 0; i < 10; i++)
    {
        Tebakan.Elmt[9].TabWord[i] = TB[i];
    }

    Kata.Length = Tebakan.Elmt[N].Length;
    for (int i = 0; i < Tebakan.Elmt[N].Length; i++)
    {
        Kata.TabWord[i] = Tebakan.Elmt[N].TabWord[i];
    }

    return Kata;
}

void main()
{
    system("cls");
    ArrayDin hist = MakeArrayDin();
    int cek = 0, i = 0, j = 0, Benar = 0, cek_benar = 0, poin = 0, chance = 10, Num = 0,correct = 0;
    Word Kata_ku, Kata;
    time_t t;

    srand(time(&t));
    Num = rand() % 11;
    Kata.Length = ApaHayoo(Num).Length;
    for (int i = 0; i < ApaHayoo(Num).Length; i++)
    {
        Kata.TabWord[i] = ApaHayoo(Num).TabWord[i];
    }
    //Tampilan Awal
    printf("=============================== | HANGMAN by BNMO-2.0 | =============================== \n");
    printf("Selamat datang di Hangman!\n\n\n\nMemuat Permainan, Tunggu Sebentar Yaa");
    countdown(); countdown();
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
                correct += 1;
                printf("Lanjuuuuuttt");
                countdown();
                printf("\n");
                DeallocateArrayDin(&hist);
                hist = MakeArrayDin();

                //Generate Kata Baru
                srand(time(&t));
                Num = rand() % 11;
                
                
                //Cek agar kata yang sama tidak muncul di tebak tebakan lagi
                //Nanti dulu, masi bingung, tunggu wildhan ngedit pake read file biar gampang
/*                
				boolean tes = true;
				 while (tes)
                {
                    for (int i = 0; i < idx; i++)
                    {
                        if (Num == lis[i])
                        {
                            Num = rand() % 11;
                            tes = true;
                            break;
                        }
                        else
                        {
                            tes = false;
                        }
                    }
                } */
                Kata.Length = ApaHayoo(Num).Length;
                for (int i = 0; i < ApaHayoo(Num).Length; i++)
                {
                    Kata.TabWord[i] = ApaHayoo(Num).TabWord[i];
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
    printf("Terima Kasih Sudah Bermain  (^o^)/ Bye Bye ~~\n");
    countdown();
}