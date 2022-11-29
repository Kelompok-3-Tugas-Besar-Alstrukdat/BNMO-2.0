/* =====| CONSOLE |===== */
#include "console.h"


/* =====| COMMAND CREATE GAME |===== */
// Prosedur untuk membuat serta menambahkan permainan ke dalam daftar permainan
void CreateGame(ArrayDin *Game, SetMap *scoreboard)
{
    int i = 1;
    boolean cek = true;
    printf("Masukkan nama Game yang akan ditambahkan: ");
    COMMAND();

    // Syarat menambahkan Game adalah nama permainan yang ingin ditambahkan belum ada di daftar permainan
    while((cek == true) && (i < (*Game).Neff)) {
        if (isWordEqual(currentWord, (*Game).Elmt[i])){
            cek = false;
        }
        i++;
    }
    if (cek == false){
        printf("Game dengan nama tersebut sudah ada!\n");
    }
    else{
        // Membuat scoreboard baru untuk permainan yang baru ditambahkan
        CreateEmptyMap(&(scoreboard[(*Game).Neff-1]));
        // Menambahkan permainan ke dalam daftar permainan
        InsertLastArr(&(*Game), currentWord);
        int n = toInt((*Game).Elmt[0]);
        n++;
        for (i=0; i < toWord(n).Length; i++){
            (*Game).Elmt[0].TabWord[i] = toWord(n).TabWord[i];
        }
        (*Game).Elmt[0].Length = toWord(n).Length;
        printf("Berhasil menambahkan Game!\n");
    }
}


/* =====| COMMAND DELETE GAME |===== */
// Prosedur untuk menghapus permainan yang ada dalam daftar permainan
// Permainan yang ada pada sistem tidak dapat dihapus
void DeleteGame(ArrayDin *Game, Queue *Gameq, Stack *history, SetMap *scoreboard)
{
    ListGame(*Game);
    printf("Masukkan nomor permainan yang akan dihapus: ");
    COMMAND();
    int num = toInt(currentWord);

    // Syarat permainan yang dapat dihapus
    // Permainan sistem berjumlah 7 dan tidak dapat dihapus
    if((num > 0) && (num < 8))
    {
        printf("Permainan sistem tidak dapat dihapus.\n");
    }

    // Selain permainan sistem dapat dihapus namun tidak dapat dihapus jika Game berada dalam antrian Game
    else if ((num > 7) && (num < (*Game).Neff))
    {
        boolean check = true;
        int i = 0;
        while (check && (i <= IDX_TAIL(*Gameq)))
        {
            if (isWordEqual((*Game).Elmt[num], (*Gameq).buffer[i]))
            {
                check = false;
            }
            i++;
        }
        if (check)
        {
            // Menghapus scoreboard dari permainan yang dihapus
            for (int idx = (num - 1); idx < (*Game).Neff - 1; idx++)
            {
                CreateEmptyMap(&(scoreboard[idx]));
                for (int idxEl = 0; idxEl < scoreboard[idx + 1].Count; idxEl++)
                {
                    InsertMap(&(scoreboard[idx]), scoreboard[idx + 1].Elements[idxEl].Key, scoreboard[idx + 1].Elements[idxEl].Value);
                }
            }
            // Menghapus history permainan yang dihapus
            Stack tempHist;
            CreateEmptyStack(&tempHist);
            for (int idxT = 0; idxT <= Top(*history); idxT++)
            {
                if (!isWordEqual((*Game).Elmt[num], (*history).T[idxT]))
                {
                    Push(&tempHist, (*history).T[idxT]);
                }
            }
            CreateEmptyStack(history);
            for (int repeat = 0; repeat <= Top(tempHist); repeat++)
            {
                Push(history, tempHist.T[repeat]);
            }
            // Menghapus permainan dari daftar permainan
            DeleteAtArr(Game, num);
            printf("Permainan berhasil dihapus.\n");
        }
        else
        {
            printf("Permainan yang sedang dalam antrian tidak dapat dihapus.\n");
        }
    }
    // Permainan tidak dapat dihapus jika tidak ada di daftar permainan
    else
    {
        printf("Permainan tidak ditemukan.\n");
    }
}


/* =====| COMMAND HELP |===== */
// Prosedur untuk menampilkan informasi command yang dapat dijalankan BNMO
void Help()
{
    printf("H E L P\n");
    printf(" 1. START\n");
    printf("    Command START, membaca file konfigurasi yang akan digunakan sebagai data permainan pada BNMO.\n");
    printf(" 2. LOAD\n");
    printf("    Command LOAD <filename>.txt, membaca save file <filename> yang akan digunakan sebagai data permainan pada BNMO.\n");
    printf(" 2. SAVE\n");
    printf("    Command SAVE <filename>.txt, menyimpan \"state\" permainan pemain ke suatu file <filename>.txt agar dapat digunakan kembali.\n");
    printf(" 4. CREATE GAME\n");
    printf("    Command CREATE GAME, menambahkan permainan baru pada daftar permainan.\n");
    printf(" 5. LIST GAME\n");
    printf("    Command LIST GAME, menampilkan daftar permainan yang dijalankan pada BNMO.\n");
    printf(" 6. DELETE GAME\n");
    printf("    Command DELETE GAME, menghapus permainan dari daftar permainan.\n");
    printf(" 7. QUEUE GAME\n");
    printf("    Command QUEUE GAME, menambahkan permainan ke dalam daftar antrian untuk dimainkan dan akan hilang saat keluar dari BNMO.\n");
    printf(" 8. PLAY GAME\n");
    printf("    Command PLAY GAME, menjalankan permainan pertama pada daftar antrian dan menghapusnya dari daftar antrian.\n");
    printf(" 9. SKIP GAME\n");
    printf("    Command SKIPGAME <n>, melewatkan permainan sebanyak <n> dan menjalankan permainan pada urutan <n> + 1\n");
    printf("    serta menghapus permainan yang dilewati dari daftar antrian.\n");
    printf("10. QUIT\n");
    printf("    Command QUIT, keluar dari permaina BNMO.\n");
}


/* =====| COMMAND HISTORY |===== */
// Prosedur untuk menampilkan history permainan
void History(Stack history, int n)
{
    if (n > 0){
        if (!IsEmptyStack(history)){
            printf("Berikut adalah history permainan Anda.\n");
            if (n < (Top(history) + 1)){
                int idx = Top(history);
                for (int i = 1; i <= n; i++){
                    printf("%d. ", i);
                    printWord(history.T[idx]);
                    printf("\n");
                    idx--;
                }
            }
            else{
                int idx = Top(history);
                for (int i = 1; i <= (Top(history) + 1); i++){
                    printf("%d. ", i);
                    printWord(history.T[idx]);
                    printf("\n");
                    idx--;
                }
            }
        }
        else{
            printf("Belum ada permainan yang dimainkan.\n");
        }
    }
    else{
        printf("Nilai yang Anda masukkan tidak valid.\n");
    }
}
// Prosedur untuk menghapus daftar permainan yang telah dimainkan pada history
void ResetHistory(Stack *history)
{
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? (YA/TIDAK) ");
    COMMAND();
    if (currentWord.Length == 2 && currentWord.TabWord[0] == 'Y' && currentWord.TabWord[1] == 'A')
    {
        CreateEmptyStack(history);
        printf("History berhasil di-reset.\n");
    }
    else if (currentWord.Length == 5 && currentWord.TabWord[0] == 'T' && currentWord.TabWord[1] == 'I' &&
             currentWord.TabWord[2] == 'D' && currentWord.TabWord[3] == 'A' && currentWord.TabWord[4] == 'K')
    {
        printf("History tidak jadi di-reset.\nBerikut adalah daftar permainan yang telah dimainkan\n");
        History(*history, Top(*history) + 1);
    }
    else
    {
        printf("Masukan tidak valid, history tidak jadi di-reset.\nBerikut adalah daftar permainan yang telah dimainkan.\n");
        History(*history, Top(*history) + 1);
    }
}


/* =====| COMMAND LIST GAME |===== */
// Prosedur untuk menampilkan daftar permainan yang ada
void ListGame(ArrayDin Game)
{
    printf("Berikut adalah daftar permainan yang tersedia.\n");
    for (int i = 1; i < Game.Neff; i++)
    {
        printf("%d. ", i);
        printWord(Game.Elmt[i]);
        printf("\n");
    }
}


/* =====| COMMAND LOAD |===== */
// Prosedur untuk menjalankan program BNMO dengan membaca savefile yang ada
void Load(ArrayDin *Game, ArrayDin *HangmanWords, ArrayDin *AllScoreboard, Stack *history, char *filename, Word *INPUT)
{
    boolean success = false;
    do
    {
        int j = 5;
        for (int i = (*INPUT).Length; i < currentWord.Length; i++)
        {
            if (currentWord.TabWord[i] != ' ')
            {
                filename[j] = currentWord.TabWord[i];
                j++;
            }
        }
        filename[j] = '\0';

        FILE *test;
        test = fopen(filename, "r");
        if (test != NULL)
        {
            fclose(test);
            int i, idx;
            // Membaca file savefile <filename>.txt
            STARTWORD(filename);
            idx = toInt(currentWord);
            (*Game).Neff = (idx + 1);
            for (i = 0; i <= idx; i++)
            {
                (*Game).Elmt[i].Length = currentWord.Length;
                for (int j = 0; j < currentWord.Length; j++)
                {
                    (*Game).Elmt[i].TabWord[j] = currentWord.TabWord[j];
                }
                ADVWORD();
            }

            idx = toInt(currentWord);
            ADVWORD();
            Word tempData;
            Stack tempHistory;
            CreateEmptyStack(&tempHistory);
            for (i = 0; i < idx; i++)
            {
                Push(&tempHistory, currentWord);
                ADVWORD();
            }
            for (i = 0; i < idx; i++)
            {
                Pop(&tempHistory, &tempData);
                Push(history, tempData);
            }

            i = 0;
            while (!EndWord)
            {
                (*AllScoreboard).Elmt[i].Length = currentWord.Length;
                for (int j = 0; j < currentWord.Length; j++)
                {
                    (*AllScoreboard).Elmt[i].TabWord[j] = currentWord.TabWord[j];
                }
                ADVWORD();
                i++;
            }
            (*AllScoreboard).Neff = i;

            // Membaca file hangman.txt
            STARTWORD("data/hangman.txt");
            i = 0;
            while (!EndWord)
            {
                (*HangmanWords).Elmt[i].Length = currentWord.Length;
                for (int j = 0; j < currentWord.Length; j++)
                {
                    (*HangmanWords).Elmt[i].TabWord[j] = currentWord.TabWord[j];
                }
                ADVWORD();
                i++;
            }
            (*HangmanWords).Neff = i;
            success = true;
            printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");

            filename[0] = 'd';
            filename[1] = 'a';
            filename[2] = 't';
            filename[3] = 'a';
            filename[4] = '/';
            filename[5] = '\0';
        }
        else
        {
            fclose(test);
            printf("Nama file yang Kamu masukkan salah. Periksa kembali dan pastikan nama file benar.\n");
            (*INPUT).Length = 0;
            fetchBNMO(INPUT);
        }
    }
    while (success == false);
}


/* =====| COMMAND PLAY GAME |===== */
// Menjalankan permainan sesuai dengan daftar antrian
void PlayGame (ArrayDin DataGame, ArrayDin *HangmanWords, Queue *GameQ, Stack *history, SetMap *scoreboard)
{
    ArrayDin Game = MakeArrayDin();
    Game.Neff = 7;
    int i;

    // RNG
    // Menyimpan nama permainan "RNG" ke dalam array Game indeks 0
    Game.Elmt[0].Length = 3;
    char GMRNG[20] = "RNG";
    for (i = 0; i < 3; i++)
    {
        Game.Elmt[0].TabWord[i] = GMRNG[i];
    }
    // DINER DASH
    // Menyimpan nama permainan "DINER DASH" ke dalam array Game indeks 1
    Game.Elmt[1].Length = 10;
    char GMDD[20] = "DINER DASH";
    for (i = 0; i < 10; i++)
    {
        Game.Elmt[1].TabWord[i] = GMDD[i];
    }
    // DINOSAUR IN EARTH
    // Menyimpan nama permainan "HANGMAN" ke dalam array Game indeks 2
    Game.Elmt[2].Length = 7;
    char GMDIE[20] = "HANGMAN";
    for (i = 0; i < 7; i++)
    {
        Game.Elmt[2].TabWord[i] = GMDIE[i];
    }
    // RISEWOMAN
    // Menyimpan nama permainan "TOWER OF HANOI" ke dalam array Game indeks 3
    Game.Elmt[3].Length = 14;
    char GMRW[20] = "TOWER OF HANOI";
    for (i = 0; i < 14; i++)
    {
        Game.Elmt[3].TabWord[i] = GMRW[i];
    }
    // EIFFEL TOWER
    // Menyimpan nama permainan "SNAKE ON METEOR" ke dalam array Game indeks 4
    Game.Elmt[4].Length = 15;
    char GMET[20] = "SNAKE ON METEOR";
    for (i = 0; i < 15; i++)
    {
        Game.Elmt[4].TabWord[i] = GMET[i];
    }
    // HIDE IN CARTESIAN
    // Menyimpan nama permainan "HIDE IN CARTESIAN" ke dalam array Game indeks 5
    Game.Elmt[5].Length = 17;
    char GMHIC[20] = "HIDE IN CARTESIAN";
    for (i = 0; i < 17; i++)
    {
        Game.Elmt[5].TabWord[i] = GMHIC[i];
    }
    // MAGIC SHELL
    // Menyimpan nama permainan "MAGIC SHELL" ke dalam array Game indeks 6
    Game.Elmt[6].Length = 11;
    char GMMS[20] = "MAGIC SHELL";
    for (i = 0; i < 11; i++)
    {
        Game.Elmt[6].TabWord[i] = GMMS[i];
    }

    //Menjalankan permainan sesuai antrian permainan
    if (!isEmptyQueue(*GameQ)){
        Push(history, HEAD(*GameQ));
        if (isWordEqual(HEAD(*GameQ), Game.Elmt[0])){
            runRNG(&scoreboard[0]);
        }
        else if (isWordEqual(HEAD(*GameQ), Game.Elmt[1])){
            runDinerDash(&scoreboard[1]);
        }
        else if (isWordEqual(HEAD(*GameQ), Game.Elmt[2])){
            runHangman(&scoreboard[2], HangmanWords);
        }
        else if (isWordEqual(HEAD(*GameQ), Game.Elmt[3])){
            //runTowerOfHanoi(&scoreboard[3]);
        }
        else if (isWordEqual(HEAD(*GameQ), Game.Elmt[4])){
            runSnakeOnMeteor(&scoreboard[4]);
        }
        else if (isWordEqual(HEAD(*GameQ), Game.Elmt[5])){
            runHideInCartesian(&scoreboard[5]);
        }
        else if (isWordEqual(HEAD(*GameQ), Game.Elmt[6])){
            magic_shell(&scoreboard[6]);
        }
        else {
            int idx = 1;
            while (!isWordEqual(Head(*GameQ), DataGame.Elmt[idx]))
            {
                idx++;
            }
            char show[(2 * Head(*GameQ).Length) - 1];
            int j, k = 0;
            for (j = 0; j < Head(*GameQ).Length; j++)
            {
                if ((j % 2) == 1)
                {
                    show[j] = ' ';
                    k++;
                }
                else
                {
                    if (Head(*GameQ).TabWord[k] != ' ')
                    {
                        show[j] = Head(*GameQ).TabWord[k];
                    }
                }
            }
            for (j = 0; j < ((76 - (2 * Head(*GameQ).Length)) / 2); j++)
            {
                printf("=");
            }
            printf("| %s |", show);
            for (j = 0; j < ((76 - (2 * Head(*GameQ).Length)) / 2); j++)
            {
                printf("=\n");
            }
            int score = RandomNumber();
            printf("Skor: %d\n", score);
            toScoreboard(&scoreboard[idx - 1], score);
        }
        QueueType val;
        dequeueQ(GameQ, &val);
    }
}


/* =====| COMMAND QUEUE GAME |===== */
// Prosedur untuk menambahkan permainan ke dalam daftar antrian
void QueueGame(ArrayDin *Game, Queue *GameQ)
{
    int i = 0;
    printf("Berikut adalah daftar antrian permainanmu: \n");
    if (lengthQueue(*GameQ) == 0){
        printf("\n-- Permainan Tidak Ada --\n");
        printf("\nDaftar antrian permainanmu masih kosong, silakan tambahkan permainan terlebih dahulu!\n");
    }
    else{
        for (i = 0; i < lengthQueue(*GameQ); i++){
            printf("%d.  ",(i+1));
            printWord(GameQ->buffer[i]);
            printf("\n");
        }
    }
    printf("\n\nBerikut adalah permainan yang tersedia: \n");
    for (i=1;i < (Game->Neff);i++){
            printf("%d.  ",i);
            printWord(Game->Elmt[i]);
            printf("\n");
    }
    printf("Nomor permainan yang mau ditambahkan ke antrian: ");
    COMMAND();
    int a;
    a = toInt(currentWord);
    if ( (a>0) && (a < (Game->Neff)) ){
        printf("Permainan berhasil ditambahkan ke dalam daftar antrian.\n");
        enqueueQ(GameQ,Game->Elmt[a]);
    }
    else{
        printf("Nomor permainan tidak valid, silakan masukkan nomor permainan yang ada pada list.\n");
    }
}


/* =====| COMMAND SAVE |===== */
// Fungsi untuk memeriksa ekstensi file
boolean validExtension(char *filename)
{
    boolean valid = true;
    char check[5], extension[5] = ".txt";
    int str_len = 0;
    while (filename[str_len] != '\0')
    {
        str_len++;
    }
    for (int i = 3; i >=0; i--)
    {
        check[3-i] = filename[str_len - 1 - i];
    }
    for (int i = 0; i < 5; i++)
    {
        if (check[i] != extension[i])
        {
            valid = false;
            break;
        }
    }
    return valid;
}
// Prosedur untuk menyimpan file <savefile>.txt
void Save(ArrayDin Game, ArrayDin HangmanWords, Stack history, SetMap *scoreboard, char *filename)
{
    char text[50];
    static FILE *savefile;
    
    savefile = fopen(filename, "w");
    if (savefile == NULL)
    {
        printf("Gagal untuk menyimpan file. Silahkan coba lagi\n");
        fclose(savefile);
    }
    else
    {
        // Menyimpan state permainan
        // Daftar permainan
        for (int i = 0; i < Game.Neff; i++)
        {
            toStr(Game.Elmt[i], text);
            fputs(text, savefile);
            fputs("\n", savefile);
        }
        // History permainan
        toStr(toWord(Top(history) + 1), text);
        fputs(text, savefile);
        fputs("\n", savefile);
        for (int j = Top(history); j >= 0 ; j--)
        {
            toStr(history.T[j], text);
            fputs(text, savefile);
            fputs("\n", savefile);
        }
        // Scoreboard permainan
        for (int k = 0; k < (Game.Neff - 1); k++)
        {
            toStr(toWord(scoreboard[k].Count), text);
            fputs(text, savefile);
            fputs("\n", savefile);
            for (int idx = 0; idx < scoreboard[k].Count; idx++)
            {
                toStr(scoreboard[k].Elements[idx].Key, text);
                fputs(text, savefile);
                fputs(" ", savefile);
                toStr(toWord(scoreboard[k].Elements[idx].Value), text);
                fputs(text, savefile);
                fputs("\n", savefile);
            }
        }
        fputs(".", savefile);
        fclose(savefile);

        // Menyimpan file hangman.txt
        savefile = fopen("data/hangman.txt", "w");
        if (savefile == NULL)
        {
            do
            {
                savefile = fopen("data/hangman.txt", "w");
            }
            while (savefile == NULL);
        }
        for (int i = 0; i < HangmanWords.Neff; i++)
        {
            toStr(HangmanWords.Elmt[i], text);
            fputs(text, savefile);
            fputs("\n", savefile);
        }
        fputs(".", savefile);
        fclose(savefile);
    }
}


/* =====| COMMAND SCOREBOARD |===== */
// Prosedur untuk membaca scoreboard dari file konfigurasi ataupun savefile
void readScoreboard(ArrayDin Game, ArrayDin AllScoreboard, SetMap *scoreboard)
{
    Word tempVal;
    int k, nidx = 0, num = 0;
    for (int i = 0; i < (Game.Neff - 1); i++)
    {
        CreateEmptyMap(&scoreboard[i]);
        if (!IsEmptyArr(AllScoreboard))
        {
            num = nidx;
            scoreboard[i].Count = toInt(AllScoreboard.Elmt[num]);
            for (int j = 0; j < scoreboard[i].Count; j++)
            {
                nidx++;
                k = 0;
                while(AllScoreboard.Elmt[nidx].TabWord[k] != ' ')
                {
                    scoreboard[i].Elements[j].Key.TabWord[k] = AllScoreboard.Elmt[nidx].TabWord[k];
                    k++;
                }
                scoreboard[i].Elements[j].Key.Length = k;
                k++;
                int length;
                for (length = k; length < AllScoreboard.Elmt[nidx].Length; length++)
                {
                    tempVal.TabWord[length - k] = AllScoreboard.Elmt[nidx].TabWord[length];
                }
                tempVal.Length = (length - k);
                scoreboard[i].Elements[j].Value = toInt(tempVal);
            }
            nidx++;
        }
    }
}
// Prosedur untuk mencatat skor yang didapatkan ke scoreboard permainan yang bersesuaian
void toScoreboard(SetMap *scoreboard, int score)
{
    do
    {
        printf("MASUKKAN NAMA PEMAIN: ");
        COMMAND();
        if (currentWord.Length > 20)
        {
            printf("Maksimal jumlah karakter nama pemain adalah 20 karakter.\n");
        }
        else if (IsMemberMap((*scoreboard), currentWord))
        {
            printf("Nama yang dimasukkan sudah ada. Harap gunakan nama lain.\n");
        }
    }
    while (IsMemberMap((*scoreboard), currentWord) || currentWord.Length > 20);
    InsertMap(scoreboard, currentWord, score);
}
// Prosedur untuk menampilkan scoreboard setiap permainan
void Scoreboard(SetMap scoreboard)
{
    printf("|         NAMA         |   SKOR   |\n");
    printf("|----------------------|----------|\n");
    if (scoreboard.Count > 0)
    {
        for (int i = 0; i < scoreboard.Count; i++)
        {
            int temp = scoreboard.Elements[i].Value;
            int valuedigit = 0;
            while (temp > 0)
            {
                temp /= 10;
                valuedigit++;
            }
            printf("| ");
            printWord(scoreboard.Elements[i].Key);
            for (int j = 0; j < (20 - scoreboard.Elements[i].Key.Length); j++)
            {
                printf(" ");
            }
            printf(" | ");
            printf("%d", scoreboard.Elements[i].Value);
            for (int j = 0; j < (8 - valuedigit); j++)
            {
                printf(" ");
            }
            printf(" |\n");
        }
    }
    else
    {
        printf("|------- SCOREBOARD KOSONG -------|\n");
    }
}
// Prosedur untuk menghapus skor yang ada pada scoreboard
void ResetScoreboard(SetMap *scoreboard, ArrayDin game)
{
    //Tampilan Awal Sebelum Reset Scoreboard
    printf("DAFTAR SCOREBOARD:\n");
    printf("0. ALL\n");
    for (int i = 1; i < game.Neff; i++)
    {
        printf("%d. ", i);
        printWord(game.Elmt[i]);
        printf("\n");
    }
    printf("\n");
    //Meminta Input Nomor Scoreboard yang akan direset
    printf("SCOREBOARD YANG INGIN DIHAPUS:");
    COMMAND();
    int N = toInt(currentWord);
    printf("\n");

    //Jika Ingin Mereset Semua Daftar Scoreboard
    if (N == 0)
    {
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET ALL SCOREBOARD? (YA/TIDAK):");
        COMMAND();
        printf("\n");
        if (currentWord.Length == 2 && currentWord.TabWord[0] == 'Y' && currentWord.TabWord[1] == 'A')
        {
            //Mereset Semua Scoreboard
            for (int i = 1; i < game.Neff; i++)
            {
                CreateEmptyMap(&scoreboard[i-1]);
            }
            printf("Scoreboard berhasil di-reset\n");
        }
        else if (currentWord.Length == 5 && currentWord.TabWord[0] == 'T' && currentWord.TabWord[1] == 'I' && currentWord.TabWord[2] == 'D' && currentWord.TabWord[3] == 'A' && currentWord.TabWord[4] == 'K')
        {
            printf("Reset scoreboard dibatalkan\n");
        }
        else
        {
            printf("Masukan tidak valid\n");
        }
    }
    //Jika Hanya Ingin Mereset Salah Satu Scoreboard Permainan
    else if (N > 0 && N < game.Neff)
    {
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ");
        printWord(game.Elmt[N]);
        printf(" ? (YA/TIDAK):");
        COMMAND();
        printf("\n");
        if (currentWord.Length == 2 && currentWord.TabWord[0] == 'Y' && currentWord.TabWord[1] == 'A')
        {
            CreateEmptyMap(&scoreboard[N-1]);
            printf("Scoreboard berhasil di-reset\n");
        }
        else if (currentWord.Length == 5 && currentWord.TabWord[0] == 'T' && currentWord.TabWord[1] == 'I' && currentWord.TabWord[2] == 'D' && currentWord.TabWord[3] == 'A' && currentWord.TabWord[4] == 'K')
        {
            printf("Reset scoreboard dibatalkan\n");
        }
        else
        {
            printf("Masukan tidak valid\n");
        }
    }
    //Jika Masukan tidak sesuai atau nomor lebih besar dari nomor terakhir di daftar scoreboard
    else
    {
        printf("\n");
        printf("INPUTAN TIDAK VALID, NOMOR TIDAK ADA DI DAFTAR SCOREBOARD.\n");
    }
}


/* =====| COMMAND SKIPGAME |===== */
// Prosedur untuk melewati permainan sebanyak n
// Memulai permainan jika daftar antrian tidak kosong
void SkipGame(ArrayDin Game, ArrayDin *HangmanWords, Queue *GameQ, int n, Stack *history, SetMap *scoreboard)
{
    QueueType val;
    for (int i = 0; i < n; i++){
        if (isEmptyQueue(*GameQ))
        {
            break;
        }
        dequeueQ(GameQ, &val);
    }
    if (!isEmptyQueue(*GameQ)){

        PlayGame(Game, HangmanWords, GameQ, history, scoreboard);
    }
    else
    {
        printf("Tidak ada permainan lagi dalam daftar antrian.\n");
    }
}


/* =====| COMMAND START |===== */
// Prosedur untuk menjalankan program BNMO dengan membaca file konfigurasi config.txt
void Start(ArrayDin *Game, ArrayDin *HangmanWords)
{
    // Membaca file konfigurasi config.txt
    STARTWORD("data/config.txt");
    int i, idx;
    i = 0;
    while (!EndWord)
    {
        (*Game).Elmt[i].Length = currentWord.Length;
        for (int j = 0; j < currentWord.Length; j++)
        {
            (*Game).Elmt[i].TabWord[j] = currentWord.TabWord[j];
        }
        i++;
        ADVWORD();
    }
    (*Game).Neff = i;

    // Membaca file hangman.txt
    STARTWORD("data/hangman.txt");
    i = 0;
    while (!EndWord)
    {
        (*HangmanWords).Elmt[i].Length = currentWord.Length;
        for (int j = 0; j < currentWord.Length; j++)
        {
            (*HangmanWords).Elmt[i].TabWord[j] = currentWord.TabWord[j];
        }
        ADVWORD();
        i++;
    }
    (*HangmanWords).Neff = i;
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}


/* =====| ANOTHER COMMAND |===== */
// Menyimpan Command-command yang valid ke dalam sebuah array
ArrayDin validCOMMAND()
{
    ArrayDin command = MakeArrayDin();
    command.Neff = 15;
    int i;

    // START
    // Menyimpan perintah "START" ke dalam array command indeks 0
    command.Elmt[0].Length = 5;
    char CMDSTART[15] = "START";
    for (i = 0; i < 5; i++)
    {
        command.Elmt[0].TabWord[i] = CMDSTART[i];
    }

    // LOAD
    // Menyimpan perintah "LOAD" ke dalam array command indeks 1
    command.Elmt[1].Length = 4;
    char CMDLOAD[15] = "LOAD";
    for (i = 0; i < 4; i++)
    {
        command.Elmt[1].TabWord[i] = CMDLOAD[i];
    }

    // SAVE
    // Menyimpan perintah "SAVE" ke dalam array command indeks 2
    command.Elmt[2].Length = 4;
    char CMDSAVE[15] = "SAVE";
    for (i = 0; i < 4; i++)
    {
        command.Elmt[2].TabWord[i] = CMDSAVE[i];
    }

    // CREATE GAME
    // Menyimpan perintah "CREATE GAME" ke dalam array command indeks 3
    command.Elmt[3].Length = 11;
    char CMDCG[15] = "CREATE GAME";
    for (i = 0; i < 11; i++)
    {
        command.Elmt[3].TabWord[i] = CMDCG[i];
    }

    // LIST GAME
    // Menyimpan perintah "LIST GAME" ke dalam array command indeks 4
    command.Elmt[4].Length = 9;
    char CMDLG[15] = "LIST GAME";
    for (i = 0; i < 9; i++)
    {
        command.Elmt[4].TabWord[i] = CMDLG[i];
    }

    // DELETE GAME
    // Menyimpan perintah "DELETE GAME" ke dalam array command indeks 5
    command.Elmt[5].Length = 11;
    char CMDDG[15] = "DELETE GAME";
    for (i = 0; i < 11; i++)
    {
        command.Elmt[5].TabWord[i] = CMDDG[i];
    }

    // QUEUE GAME
    // Menyimpan perintah "QUEUE GAME" ke dalam array command indeks 6
    command.Elmt[6].Length = 10;
    char CMDQG[15] = "QUEUE GAME";
    for (i = 0; i < 10; i++)
    {
        command.Elmt[6].TabWord[i] = CMDQG[i];
    }

    // PLAY GAME
    // Menyimpan perintah "PLAY GAME" ke dalam array command indeks 7
    command.Elmt[7].Length = 9;
    char CMDPG[15] = "PLAY GAME";
    for (i = 0; i < 9; i++)
    {
        command.Elmt[7].TabWord[i] = CMDPG[i];
    }

    // SKIPGAME
    // Menyimpan perintah "SKIPGAME" ke dalam array command indeks 8
    command.Elmt[8].Length = 8;
    char CMDSG[15] = "SKIPGAME";
    for (i = 0; i < 8; i++)
    {
        command.Elmt[8].TabWord[i] = CMDSG[i];
    }

    // QUIT
    // Menyimpan perintah "QUIT" ke dalam array command indeks 9
    command.Elmt[9].Length = 4;
    char CMDQUIT[15] = "QUIT";
    for (i = 0; i < 4; i++)
    {
        command.Elmt[9].TabWord[i] = CMDQUIT[i];
    }

    // HELP
    // Menyimpan perintah "HELP" ke dalam array command indeks 10
    command.Elmt[10].Length = 4;
    char CMDHELP[15] = "HELP";
    for (i = 0; i < 4; i++)
    {
        command.Elmt[10].TabWord[i] = CMDHELP[i];
    }

    // SCOREBOARD
    // Menyimpan perintah "SCOREBOARD" ke dalam array command indeks 11
    command.Elmt[11].Length = 10;
    char CMDSCOREBOARD[15] = "SCOREBOARD";
    for (i = 0; i < 10; i++)
    {
        command.Elmt[11].TabWord[i] = CMDSCOREBOARD[i];
    }
    
    // RESET SCOREBOARD
    // Menyimpan perintah "RESET SCOREBOARD" ke dalam array command indeks 12
    command.Elmt[12].Length = 16;
    char CMDRESSCOREBOARD[20] = "RESET SCOREBOARD";
    for (i = 0; i < 16; i++)
    {
        command.Elmt[12].TabWord[i] = CMDRESSCOREBOARD[i];
    }

    // HISTORY
    // Menyimpan perintah "HISTORY" ke dalam array command indeks 13
    command.Elmt[13].Length = 7;
    char CMDHISTORY[15] = "HISTORY";
    for (i = 0; i < 7; i++)
    {
        command.Elmt[13].TabWord[i] = CMDHISTORY[i];
    }

    // RESET HISTORY
    // Menyimpan perintah "RESET HISTORY" ke dalam array command indeks 14
    command.Elmt[14].Length = 13;
    char CMDRESHISTORY[15] = "RESET HISTORY";
    for (i = 0; i < 13; i++)
    {
        command.Elmt[14].TabWord[i] = CMDRESHISTORY[i];
    }
    return command;
}
// Fungsi untuk memeriksa apakah Kata merupakan sebuah perintah yang valid atau bukan.
// Jika valid akan mengembalikan true dan akan mengembalikan false jika tidak valid
boolean isCOMMAND(Word Kata)
{
    // Memeriksa apakah Kata merupakan sebuah perintah atau bukan
    int i = 0;
    boolean check;
    while ((check == false) && (i < 15))
    {
        if (isWordEqual(Kata, validCOMMAND().Elmt[i]))
        {
            check = true;
        }
        i++;
    }
    return check;
}


/* =====| FETCHBNMO |===== */
// Prosedur untu menjalankan fungsi Start atau Load bergantung dengan masukkan pengguna
void fetchBNMO(Word *INPUT)
{
    do
    {
        printf("MASUKKAN COMMAND: ");
        COMMAND();
        int i;
        for (i = 0; i < currentWord.Length; i++)
        {
            (*INPUT).TabWord[i] = currentWord.TabWord[i];
        }
        (*INPUT).Length = currentWord.Length;

        if (!isWordEqual((*INPUT),validCOMMAND().Elmt[0]))
        {
            i = 0;
            while ((currentWord.TabWord[i] != ' ') && (i < currentWord.Length))
            {
            (*INPUT).TabWord[i] = currentWord.TabWord[i];
                i++;
            }
            (*INPUT).Length = i;

            if (isWordEqual((*INPUT),validCOMMAND().Elmt[0]))
            {
                (*INPUT).Length = 0;
            }
        }
        if (!isCOMMAND(*INPUT))
        {
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
        }
        else
        {
            if (isWordEqual((*INPUT),validCOMMAND().Elmt[10]))
            {
                Help();
            }
            else
            {
                if (!isWordEqual((*INPUT),validCOMMAND().Elmt[0]) && !isWordEqual((*INPUT),validCOMMAND().Elmt[1]))
                {
                    printf("Masukkan command START atau LOAD <namafile>.txt untuk menjalan BNMO.\n");
                }
            }
        }
    }
    while (!isWordEqual((*INPUT),validCOMMAND().Elmt[0]) && !isWordEqual((*INPUT),validCOMMAND().Elmt[1]));
}


/* =====| COUNTDOWN |===== */
// Prosedur untu menghasilkan waktu hitung mundur dengan menampilkan "."
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


/* =====| DISPLAY |===== */
// Prosedur untu menampilkan welcome page saat memulai BNMO
void display()
{
    printf("                   .^^^^^^^^^^^^^^^^^:.           ^^^^^^^^          .^^^^^^^:  \n");
    printf("                   J@&&&&&&&&&&&&&&&&&#B57.      :#@&&&&&&G^        ?@&&&&&@G  \n"); 
    printf("                   Y@@@@@@@@@@@@@@@@@@@@@@#~     :&@@@@@@@@&?       ?@@@@@@@G  \n");
    printf("                   J@@@@@@@@PYYYY5G@@@@@@@@#.    :&@@@@@@@@@@G:     ?@@@@@@@G  \n");
    printf("                   J@@@@@@@@~      J@@@@@@@@:    :&@@@@@@@@@@@&7    ?@@@@@@@G  \n");
    printf("                   J@@@@@@@@! ....^G@@@@@@@J     :&@@@@@@@@@@@@@P:  ?@@@@@@@G  \n");
    printf("                   J@@@@@@@@&####&@@@@@@BY^      :&@@@@@@@&@@@@@@#7 ?@@@@@@@G  \n");
    printf("                   J@@@@@@@@@@@@@@@@@@@@B57:     :&@@@@@@&!P@@@@@@@5J@@@@@@@G  \n");
    printf("                   J@@@@@@@@PJJJYY5G@@@@@@@&?    :&@@@@@@@: ?&@@@@@@@@@@@@@@G  \n");
    printf("                   J@@@@@@@@~       ?@@@@@@@@!   :&@@@@@@@^  ^G@@@@@@@@@@@@@G  \n");
    printf("                   J@@@@@@@@!     .^P@@@@@@@@7   :&@@@@@@@^    J&@@@@@@@@@@@G  \n");
    printf("                   J@@@@@@@@#BBBBB#@@@@@@@@@B:   :&@@@@@@@^     ^B@@@@@@@@@@G  \n");
    printf("                   Y@@@@@@@@@@@@@@@@@@@@@@&5:    :&@@@@@@@^      .J@@@@@@@@@G  \n");
    printf("                   ?################BBGPY7:      :B#######:        ~G#######P  \n");
    printf("                   .:....:. ........       ....   .......   .:^~~~^:..   ....  \n");
    printf("                   7######B~          .Y######G.        .!YG#&@@@@@&#G57:      \n");
    printf("                   ?@@@@@@@@Y.       ~B@@@@@@@#.      ^5#@@@@@@@@@@@@@@@&P!    \n");
    printf("                   ?@@@@@@@@@B~     J@@@@@@@@@#.    .Y@@@@@@@@@@@@@@@@@@@@@P:  \n");
    printf("                   ?@@@@@@@@@@@J  ^G@@@@@@@@@@#.   .G@@@@@@@@&BP55G#@@@@@@@@#^ \n");
    printf("                   ?@@@@@@@@@@@@GJ&@@@@@@@@@@@#.   Y@@@@@@@@J:     .7#@@@@@@@B.\n");
    printf("                   ?@@@@@@@@@@@@@@@@@@@@@@@@@@#.  .&@@@@@@@7         ^&@@@@@@@!\n");
    printf("                   ?@@@@@@@@@@@@@@@@@@@@@@@@@@#.  :&@@@@@@@~         .#@@@@@@@7\n");
    printf("                   ?@@@@@@@@@@@@@@@@@@&@@@@@@@#.   G@@@@@@@B~       :P@@@@@@@&:\n");
    printf("                   ?@@@@@@@#!B@@@@@@@YJ@@@@@@@#.   ^&@@@@@@@@GJ7!7?P&@@@@@@@@7 \n");
    printf("                   ?@@@@@@@# .5@@@@#! 7@@@@@@@#.    ^B@@@@@@@@@@@@@@@@@@@@@&7  \n");
    printf("                   ?@@@@@@@#.  !#@5.  7@@@@@@@#.     .?#@@@@@@@@@@@@@@@@@&Y:   \n");
    printf("                   ?@@@@@@@#.   :!    7@@@@@@@#.       .~YB&@@@@@@@@@&#57:     \n");
    printf("                   :~~~~~~~^          :~~~~~~~^            :~7JYYYJ?!^.        \n");
    printf("\n                          S E L A M A T  D A T A N G  D I  B N M O\n");
    printf("\n\n\n\n\nM E M U A T  B N M O ");
    countdown();
    system("cls");
}
