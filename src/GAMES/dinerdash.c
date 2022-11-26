/* =====| GAME DINER DASH |===== */

// Include file header yang diperlukan
#include "allgames.h"

// Kreator Queue
void CreateDinerQ(DinerQ *dq)
{
    Capacity(*dq) = DCapacity;
    for (int i = 0; i < DCapacity; i++)
    {
        (*dq).buffer[i].Duration = Idx_Undef;
        (*dq).buffer[i].Resistance = Idx_Undef;
        (*dq).buffer[i].Price = Idx_Undef;
    }
    Idx_Head(*dq) = Idx_Undef;
    Idx_Tail(*dq) = Idx_Undef;
}
// I.S. sembarang
// F.S. Sebuah dq kosong terbentuk dengan kondisi sbb:
// - Index head bernilai Idx_Undef
// - Index Tail bernilai Idx_Undef
// Proses : Melakukan alokasi, membuat sebuah dq kosong

// Kreator Array
void CreateDinerArr(DinerArr *da)
{
    for (int i = 0; i  < DCapacity; i++)
    {
        (*da).Elmt[i] = Idx_Undef;
    }
}
// I.S. sembarang
// F.S. Sebuah da kosong terbentuk dengan kondisi sbb:
// - Elmt bernilai Idx_Undef

// Prototype
boolean isEmptyDQ(DinerQ dq)
{
    return (Idx_Head(dq) == Idx_Undef) && (Idx_Tail(dq) == Idx_Undef);
}
// Mengirim true jika dq kosong: lihat definisi di atas
boolean isFullDQ(DinerQ dq)
{
    return (Idx_Head(dq) == 0) && (Idx_Tail(dq) == (Capacity(dq) - 1));
}
// Mengirim true jika tabel penampung elemen dq sudah penuh
// yaitu Idx_Tail akan selalu di belakang Idx_Head
// Idx_Head selalu bernilai 0
int lengthDQ(DinerQ dq)
{
    return Idx_Tail(dq) - Idx_Head(dq) + 1;
}
// Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika dq kosong

// Primitif Add/Delete
void enqueueDQ(DinerQ *dq, DinerQType val)
{
    if (isEmptyDQ(*dq))
    {
        Idx_Head(*dq) = 0;
        Idx_Tail(*dq) = 0;
    }
    else
    {
        Idx_Tail(*dq)++;
    }
    Tail(*dq).Duration = val.Duration;
    Tail(*dq).Resistance = val.Resistance;
    Tail(*dq).Price = val.Price;
}
// Proses: Menambahkan val pada dq dengan aturan FIFO
// I.S. dq mungkin kosong, tabel penampung elemen dq mungkin penuh
// F.S. val menjadi Tail yang baru, Idx_Tail bertambah satu
void dequeueDQ(DinerQ *dq, DinerQType *val)
{
    (*val).Duration = Head(*dq).Duration;
    (*val).Resistance = Head(*dq).Resistance;
    (*val).Price = Head(*dq).Price;
    if (Idx_Tail(*dq) == Idx_Head(*dq))
    {
        Idx_Head(*dq) = Idx_Undef;
        Idx_Tail(*dq) = Idx_Undef;
    }
    else
    {
        Idx_Head(*dq)++;
    }
}
// Proses: Menghapus val pada dq dengan aturan FIFO
// I.S. dq tidak mungkin kosong
// F.S. val = nilai elemen Head pd I.S., semua elemen bergeser ke kiri, dan dq mungkin kosong

// Display DinerQ
void displayQueueDQ(DinerQ dq)
{
    for (int i = Idx_Head(dq); i <= Idx_Tail(dq); i++)
    {
        printf("M%d\t| %d\t\t | %d\t     | %d\t\n", i, dq.buffer[i].Duration, dq.buffer[i].Resistance, dq.buffer[i].Price);
    }
}
// Proses : Menuliskan isi DinerQ dengan traversal, DinerQ ditulis seperti dalm sebuah tabel

// Random Number Generator Nilai Atribut
void controlRand()
{
    time_t t;
    srand(time(&t));
}
// Mengontrol nilai yang akan dihasilkan
DinerQType randVal()
{
    DinerQType val;
    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            val.Duration = (rand() % 5) + 1;
        }
        else if (i == 1)
        {
            val.Resistance = (rand() % 5) + 1;
        }
        else
        {
            val.Price = ((rand() % 40) + 10) * 1000;
        }
    }
    return val;
}
// Menghasilkan nilai random

// Prosedur untuk menjalankan permainan Diner Dash
void runDinerDash(SetMap *scoreboard)
{
    printf("=============================| D I N E R  D A S H |=============================\n"); 
    printf("Selamat Datang di Diner Dash!\n");
    int Saldo = 0;
    boolean valid = false;
    DinerQ DQDash;
    DinerArr DACook, DAServe;
    
    // Control random number generator
    controlRand();

    CreateDinerQ(&DQDash);
    for (int i = 0; i < 3; i++)
    {
        enqueueDQ(&DQDash, randVal());
    }

    CreateDinerArr(&DACook);
    CreateDinerArr(&DAServe);
    
    while ((lengthDQ(DQDash) < 8) && (Idx_Head(DQDash) < 16))
    {
        printf("\nSALDO: %d\n", Saldo);
        printf("\nDaftar Pesanan\n");
        printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
        printf("--------------------------------------------\n");
        displayQueueDQ(DQDash);

        if (valid)
        {
            // Proses Memasak Makanan
            for (int i = 0; i < DCapacity; i++)
            {
                if (DACook.Elmt[i] > 0)
                {
                    DACook.Elmt[i]--;
                }
                if ((DACook.Elmt[i] == 0) && (DACook.Elmt[i] != Idx_Undef))
                {
                    DACook.Elmt[i] = Idx_Undef;
                    DAServe.Elmt[i] = DQDash.buffer[i].Resistance + 1;
                    printf("Makanan M%d telah selesai dimasak\n", i);
                }
            }
        }

        printf("\nDaftar Makanan yang sedang dimasak\n");
        printf("Makanan | Sisa durasi memasak\n");
        printf("--------------------------------\n");
        for (int i = 0; i < DCapacity; i++)
        {
            if (DACook.Elmt[i] > 0)
            {
                printf("M%d\t| %d\t\n", i, DACook.Elmt[i]);
            }
        }

        if (valid)
        {
            // Data Ketahanan Makanan yang Telah Siap Disajikan
            for (int i = 0; i < DCapacity; i++)
            {
                if (DAServe.Elmt[i] > 0)
                {
                    DAServe.Elmt[i]--;
                }
                if ((DAServe.Elmt[i] == 0) && (DACook.Elmt[i] != Idx_Undef))
                {
                    DAServe.Elmt[i] = Idx_Undef;
                    printf("Makanan M%d telah basi dan harus dimasak kembali\n", i);
                }
            }
        }

        printf("\nDaftar Makanan yang dapat disajikan\n");
        printf("Makanan | Sisa ketahanan makanan\n");
        printf("--------------------------------\n");
        for (int i = 0; i < DCapacity; i++)
        {
            if (DAServe.Elmt[i] > 0)
            {
                printf("M%d\t| %d\t\n", i, DAServe.Elmt[i]);
            }
        }

        ArrayDin command = MakeArrayDin();
        // COOK
        command.Elmt[0].Length = 4;
        char CMDCOOK[10] = "COOK";
        for (int i = 0; i < 4; i++)
        {
            command.Elmt[0].TabWord[i] = CMDCOOK[i];
        }
        // SERVE
        command.Elmt[1].Length = 5;
        char CMDSERVE[10] = "SERVE";
        for (int i = 0; i < 5; i++)
        {
            command.Elmt[1].TabWord[i] = CMDSERVE[i];
        }
        // SKIP
        command.Elmt[2].Length = 4;
        char CMDSKIP[10] = "SKIP";
        for (int i = 0; i < 4; i++)
        {
            command.Elmt[2].TabWord[i] = CMDSKIP[i];
        }

        Word Input;
        int N;
        printf("\nMASUKKAN COMMAND: ");
        COMMAND();
        system("cls");

        // Control status masukan command
        valid = true;
        printf("=============================| D I N E R  D A S H |=============================\n"); 
        if (currentWord.Length > 4)
        {
            int i = 0;
            while ((currentWord.TabWord[i] != ' ') && (i < currentWord.Length))
            {
                Input.TabWord[i] = currentWord.TabWord[i];
                i++;
            }
            Input.Length = i;

            i++;
            if (currentWord.TabWord[i] == 'M')
            {
                i++;
                Word TN;
                for (int j = i; j < currentWord.Length; j++)
                {
                    TN.TabWord[j-i] = currentWord.TabWord[j];
                }
                TN.Length = currentWord.Length - i;
                N = toInt(TN);

                // Input == COOK
                if (isWordEqual(Input, command.Elmt[0]) && (N >= Idx_Head(DQDash) && N <= Idx_Tail(DQDash)))
                {
                    if (DACook.Elmt[N] > 0)
                    {
                        valid = false;
                        printf("Makanan M%d sudah dimasak\n", N);
                    }
                    else
                    {
                        DACook.Elmt[N] = DQDash.buffer[N].Duration + 1;
                        printf("Berhasil memasak M%d\n", N);
                        enqueueDQ(&DQDash, randVal());
                    }
                }
                // Input == SERVE
                else if (isWordEqual(Input, command.Elmt[1]) && (N >= Idx_Head(DQDash) && N <= Idx_Tail(DQDash)))
                {
                    if ((Idx_Head(DQDash) == N) && (DAServe.Elmt[N] > 0))
                    {
                        DinerQType val;
                        dequeueDQ(&DQDash, &val);
                        Saldo += val.Price;
                        DAServe.Elmt[N] = Idx_Undef;
                        printf("Berhasil mengantar M%d\n", N);
                        enqueueDQ(&DQDash, randVal());
                    }
                    else
                    {
                        valid = false;
                        printf("M%d belum dapat disajikan karena M%d belum selesai\n", N, Idx_Head(DQDash));
                    }
                }
                // Input tidak valid
                else
                {
                    valid = false;
                    printf("Command yang Anda masukkan tidak valid\n");
                }
            }
            else
            {
                valid = false;
                printf("Command yang Anda masukkan tidak valid\n");
            }
        }
        else if (currentWord.Length <= 4)
        {
            for (int i = 0; i < currentWord.Length; i++)
            {
                Input.TabWord[i] = currentWord.TabWord[i];
            }
            Input.Length = currentWord.Length;

            // Input == SKIP
            if (isWordEqual(Input, command.Elmt[2]))
            {
                enqueueDQ(&DQDash, randVal());
            }
            // Input tidak valid
            else
            {
                valid = false;
                printf("Command yang Anda masukkan tidak valid\n");
            }
        }
        printf("=============================| D I N E R  D A S H |=============================\n"); 
    }
    if (lengthDQ(DQDash) > 7)
    {
        printf("               !!! G A M E  O V E R !!!\n");
        printf("    ~_~ Antrian Anda telah melebihi 7 pelanggan ~_~\n");
        printf("             Anda mendapatkan Rp%d,-\n", Saldo);
    }
    else
    {
        printf("!!! C O N G R A T U L A T I O N !!!\n");
        printf("  $$$ You earned Rp%d,- $$$\n", Saldo);
    }
}