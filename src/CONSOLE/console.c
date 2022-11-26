/* =====| CONSOLE |===== */
#include "console.h"


/* =====| COMMAND CREATE GAME |===== */
// Prosedur untuk membuat serta menambahkan permainan ke dalam daftar permainan
void CreateGame(ArrayDin *game)
{
    int i = 1;
    boolean cek = true;
    printf("Masukkan nama game yang akan ditambahkan: ");
    COMMAND();

    // Syarat menambahkan game adalah nama permainan yang ingin ditambahkan belum ada di daftar permainan
    while((cek == true) && (i < (*game).Neff)) {
        if (isWordEqual(currentWord, (*game).Elmt[i])){
            cek = false;
        }
        i++;
    }
    if (cek == false){
        printf("game dengan nama tersebut sudah ada!\n");
    }
    else{
        InsertLast(&(*game), currentWord);
        int n = toInt((*game).Elmt[0]);
        n++;
        for (i=0; i < toWord(n).Length; i++){
            (*game).Elmt[0].TabWord[i] = toWord(n).TabWord[i];
        }
        (*game).Elmt[0].Length = toWord(n).Length;
        printf("Berhasil menambahkan game!\n");
    }
}


/* =====| COMMAND DELETE GAME |===== */
// Prosedur untuk menghapus permainan yang ada dalam daftar permainan
// Permainan yang ada pada sistem tidak dapat dihapus
void DeleteGame(ArrayDin *game, Queue *Gameq)
{
    printf("Masukkan nomor permainan yang akan dihapus: ");
    COMMAND();
    int num = toInt(currentWord);

    //Syarat game yang dapat dihapus
    //game sistem berjumlah 7 dan tidak dapat dihapus
    if((num > 0) && (num < 8))
    {
        printf("Permainan sistem tidak dapat dihapus.\n");
    }

    //Selain game sistem dapat dihapus namun tidak dapat dihapus jika game berada dalam antrian game
    else if ((num > 7) && (num < (*game).Neff))
    {
        boolean check = true;
        int i = 0;
        while (check && (i <= IDX_TAIL(*Gameq)))
        {
            if (isWordEqual((*game).Elmt[num], (*Gameq).buffer[i]))
            {
                check = false;
            }
            i++;
        }
        if (check)
        {
            DeleteAt(game, num);
            printf("Permainan berhasil dihapus.\n");
        }
        else
        {
            printf("Permainan yang sedang dalam antrian tidak dapat dihapus.\n");
        }
    }
    //game tidak dapat dihapus jika tidak ada di daftar game
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
// Prosedur untuk mencatat permainan yang baru saja dimainkan ke history
void toHistory(Stack *history, Word gamename)
{

}
// Prosedur untuk menampilkan history permainan
void History(Stack history, int n)
{

}
// Prosedur untuk menghapus daftar permainan yang telah dimainkan pada history
void ResetHistory(Stack *history)
{
    
}


/* =====| COMMAND LIST GAME |===== */
// Prosedur untuk menampilkan daftar permainan yang ada
void ListGame(ArrayDin *game)
{
    printf("Berikut adalah daftar permainan yang tersedia.\n");
    for (int i = 1; i < (*game).Neff; i++)
    {
        printf("%d. ", i);
        printWord((*game).Elmt[i]);
        printf("\n");
    }
}


/* =====| COMMAND LOAD |===== */
// Prosedur untuk menjalankan program BNMO dengan membaca savefile yang ada
void Load(ArrayDin *game, char *filename, Word *INPUT)
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
            int i = 0;
            STARTWORD(filename);
            while (!EndWord)
            {
                (*game).Elmt[i].Length = currentWord.Length;
                for (int j = 0; j < currentWord.Length; j++)
                {
                    (*game).Elmt[i].TabWord[j] = currentWord.TabWord[j];
                }
                ADVWORD();
                i++;
            }
            (*game).Neff = i;
            success = true;
            printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");

            filename[0] = 'd';
            filename[1] = 'o';
            filename[2] = 'c';
            filename[3] = 's';
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
void PlayGame (Queue *q)
{
    ArrayDin game = MakeArrayDin();
    game.Neff = 7;
    int i;

    // RNG
    // Menyimpan nama permainan "RNG" ke dalam array game indeks 0
    game.Elmt[0].Length = 3;
    char GMRNG[20] = "RNG";
    for (i = 0; i < 3; i++)
    {
        game.Elmt[0].TabWord[i] = GMRNG[i];
    }
    // DINER DASH
    // Menyimpan nama permainan "DINER DASH" ke dalam array game indeks 1
    game.Elmt[1].Length = 10;
    char GMDD[20] = "DINER DASH";
    for (i = 0; i < 10; i++)
    {
        game.Elmt[1].TabWord[i] = GMDD[i];
    }
    // DINOSAUR IN EARTH
    // Menyimpan nama permainan "HANGMAN" ke dalam array game indeks 2
    game.Elmt[2].Length = 7;
    char GMDIE[20] = "HANGMAN";
    for (i = 0; i < 7; i++)
    {
        game.Elmt[2].TabWord[i] = GMDIE[i];
    }
    // RISEWOMAN
    // Menyimpan nama permainan "TOWER OF HANOI" ke dalam array game indeks 3
    game.Elmt[3].Length = 14;
    char GMRW[20] = "TOWER OF HANOI";
    for (i = 0; i < 14; i++)
    {
        game.Elmt[3].TabWord[i] = GMRW[i];
    }
    // EIFFEL TOWER
    // Menyimpan nama permainan "SNAKE ON METEOR" ke dalam array game indeks 4
    game.Elmt[4].Length = 15;
    char GMET[20] = "SNAKE ON METEOR";
    for (i = 0; i < 15; i++)
    {
        game.Elmt[4].TabWord[i] = GMET[i];
    }
    // HIDE IN CARTESIAN
    // Menyimpan nama permainan "HIDE IN CARTESIAN" ke dalam array game indeks 5
    game.Elmt[5].Length = 17;
    char GMHIC[20] = "HIDE IN CARTESIAN";
    for (i = 0; i < 17; i++)
    {
        game.Elmt[5].TabWord[i] = GMHIC[i];
    }
    // MAGIC SHELL
    // Menyimpan nama permainan "MAGIC SHELL" ke dalam array game indeks 6
    game.Elmt[6].Length = 11;
    char GMMS[20] = "MAGIC SHELL";
    for (i = 0; i < 11; i++)
    {
        game.Elmt[6].TabWord[i] = GMMS[i];
    }

    //Menjalankan permainan sesuai antrian permainan
    if (!isEmptyQueue(*q)){
        if (isWordEqual(HEAD(*q), game.Elmt[0])){
            runRNG();
        }
        else if (isWordEqual(HEAD(*q), game.Elmt[1])){
            runDinerDash();
        }
        else if (isWordEqual(HEAD(*q), game.Elmt[2])){
            runHangman();
        }
        else if (isWordEqual(HEAD(*q), game.Elmt[3])){
            runTowerOfHanoi();
        }
        else if (isWordEqual(HEAD(*q), game.Elmt[4])){
            runSnakeOnMeteor();
        }
        else if (isWordEqual(HEAD(*q), game.Elmt[5])){
            runHideInCartesian();
        }
        else if (isWordEqual(HEAD(*q), game.Elmt[6])){
            magic_shell();
        }
        else {
            printf("Skor Anda : %d\n", RandomNumber());
        }
        QueueType val;
        dequeueQ(q, &val);
    }
}


/* =====| COMMAND QUEUE GAME |===== */
// Prosedur untuk menambahkan permainan ke dalam daftar antrian
void QueueGame(ArrayDin *game, Queue *Q)
{
    int i = 0;
    printf("Berikut adalah daftar antrian permainanmu: \n");
    if (lengthQueue(*Q) == 0){
        printf("\n-- Permainan Tidak Ada --\n");
        printf("\nDaftar antrian permainanmu masih kosong, silakan tambahkan permainan terlebih dahulu!\n");
    }
    else{
        for (i = 0; i < lengthQueue(*Q); i++){
            printf("%d.  ",(i+1));
            printWord(Q->buffer[i]);
            printf("\n");
        }
    }
    printf("\n\nBerikut adalah permainan yang tersedia: \n");
    for (i=1;i < (game->Neff);i++){
            printf("%d.  ",i);
            printWord(game->Elmt[i]);
            printf("\n");
    }
    printf("Nomor permainan yang mau ditambahkan ke antrian: ");
    COMMAND();
    int a;
    a = toInt(currentWord);
    if ( (a>0) && (a < (game->Neff)) ){
        printf("Permainan berhasil ditambahkan ke dalam daftar antrian.\n");
        enqueueQ(Q,game->Elmt[a]);
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
void Save(ArrayDin array, char *filename)
{
    char text[50];
    static FILE *savefile;

    savefile = fopen(filename, "w");
    if (savefile == NULL)
    {
        printf("Gagal untuk menyimpan file. Silahkan coba lagi\n");
    }
    else
    {
        for (int i = 0; i < array.Neff; i++)
        {
            toStr(array.Elmt[i], text);
            fputs(text, savefile);
            fputs("\n", savefile);
        }
        fputs(".", savefile);
    }
    fclose(savefile);
}


/* =====| COMMAND SCOREBOARD |===== */
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
        if (IsMemberMap((*scoreboard), currentWord))
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
    if (scoreboard.Count > 1)
    {
        for (int i = 1; i < scoreboard.Count; i++)
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
    printf("Daftar SCOREBOARD:\n");
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

    //Jika Ingin Mereset Semua Daftar Scoreboard
    if (N == 0)
    {
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET ALL SCOREBOARD? (YA/TIDAK):");
        COMMAND();
        if (currentWord.Length == 2 && currentWord.TabWord[0] == 'Y' && currentWord.TabWord[1] == 'A')
        {
            //Mereset Semua Scoreboard
            for (int i = 1; i < game.Neff; i++)
            {
                //Perlu diperbaiki karena belum tahu aku belum tahu cara identifikasi game ke-berapa dari scoreboard nya
                DeleteMap(scoreboard, scoreboard->Elements[i-1].Key);
            }
            printf("SCOREBOARD BERHASIL DI-RESET\n");
        }
        else if (currentWord.Length == 5 && currentWord.TabWord[0] == 'T' && currentWord.TabWord[1] == 'I' && currentWord.TabWord[2] == 'D' && currentWord.TabWord[3] == 'A' && currentWord.TabWord[4] == 'K')
        {
            printf("RESET SCOREBOARD DIBATALKAN\n");
        }
        else
        {
            printf("INPUT TIDAK VALID\n");
        }
    }
    //Jika Hanya Ingin Mereset Salah Satu Scoreboard Permainan
    else if (N > 0 && N < game.Neff)
    {
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ");
        printWord(game.Elmt[N]);
        printf(" ? (YA/TIDAK):");
        COMMAND();
        if (currentWord.Length == 2 && currentWord.TabWord[0] == 'Y' && currentWord.TabWord[1] == 'A')
        {
            //Perlu diperbaiki karena belum tahu aku belum tahu cara identifikasi game ke-berapa dari scoreboard nya
            DeleteMap(scoreboard, scoreboard->Elements[N-1].Key);
            printf("SCOREBOARD BERHASIL DI-RESET\n");
        }
        else if (currentWord.Length == 5 && currentWord.TabWord[0] == 'T' && currentWord.TabWord[1] == 'I' && currentWord.TabWord[2] == 'D' && currentWord.TabWord[3] == 'A' && currentWord.TabWord[4] == 'K')
        {
            printf("RESET SCOREBOARD DIBATALKAN\n");
        }
        else
        {
            printf("INPUT TIDAK VALID\n");
        }
    }
    //Jika Masukan tidak sesuai atau nomor lebih besar dari nomor terakhir di daftar scoreboard
    else
    {
        printf("INPUTAN TIDAK VALID, NOMOR TIDAK ADA DI DAFTAR SCOREBOARD.\n");
    }
}


/* =====| COMMAND SKIPGAME |===== */
// Prosedur untuk melewati permainan sebanyak n
// Memulai permainan jika daftar antrian tidak kosong
void SkipGame(Queue *gameq, int n)
{
    QueueType val;
    for (int i = 0; i < n; i++){
        if (isEmptyQueue(*gameq))
        {
            break;
        }
        dequeueQ(gameq, &val);
    }
    if (!isEmptyQueue(*gameq)){
        PlayGame(gameq);
    }
    else
    {
        printf("Tidak ada permainan lagi dalam daftar antrian.\n");
    }
}


/* =====| COMMAND START |===== */
// Prosedur untuk menjalankan program BNMO dengan membaca file konfigurasi config.txt
void Start(ArrayDin *game)
{
    int i = 0;
    STARTWORD("docs/config.txt");
    while (!EndWord)
    {
        (*game).Elmt[i].Length = currentWord.Length;
        for (int j = 0; j < currentWord.Length; j++)
        {
            (*game).Elmt[i].TabWord[j] = currentWord.TabWord[j];
        }
        ADVWORD();
        i++;
    }
    (*game).Neff = i;
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}


/* =====| ANOTHER COMMAND |===== */
// Menyimpan Command-command yang valid ke dalam sebuah array
ArrayDin validCOMMAND()
{
    ArrayDin command = MakeArrayDin();
    command.Neff = 11;
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
    return command;
}
// Fungsi untuk memeriksa apakah Kata merupakan sebuah perintah yang valid atau bukan.
// Jika valid akan mengembalikan true dan akan mengembalikan false jika tidak valid
boolean isCOMMAND(Word Kata)
{
    // Memeriksa apakah Kata merupakan sebuah perintah atau bukan
    int i = 0;
    boolean check;
    while ((check == false) && (i < 11))
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