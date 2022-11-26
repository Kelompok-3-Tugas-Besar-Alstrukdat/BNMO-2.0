/* =====| HEADER CONSOLE |===== */
#ifndef _CONSOLE_
#define _CONSOLE_


/* =====| Include Header |===== */
// C Header
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// ADT Header
#include "../boolean.h"
#include "../ADT/Array/array.h"
#include "../ADT/LinkedList/linkedlist.h"
#include "../ADT/SetMap/setmap.h"
#include "../ADT/MesinKata/mesinkata.h"
#include "../ADT/Point/point.h"
#include "../ADT/Queue/queue.h"
#include "../ADT/Stack/stack.h"
#include "../GAMES/allgames.h"


/* =====| COMMAND CREATE GAME |===== */
// Prosedur untuk membuat serta menambahkan permainan ke dalam daftar permainan
void CreateGame(ArrayDin *Game);


/* =====| COMMAND DELETE GAME |===== */
// Prosedur untuk menghapus permainan yang ada dalam daftar permainan
// Permainan yang ada pada sistem tidak dapat dihapus
void DeleteGame(ArrayDin *Game, Queue *Gameq);


/* =====| COMMAND HELP |===== */
// Prosedur untuk menampilkan informasi command yang dapat dijalankan BNMO
void Help();


/* =====| COMMAND HISTORY |===== */
// Prosedur untuk mencatat permainan yang baru saja dimainkan ke history
void toHistory(Stack *history, Word gamename);
// Prosedur untuk menampilkan history permainan
void History(Stack history, int n);
// Prosedur untuk menghapus daftar permainan yang telah dimainkan pada history
void ResetHistory(Stack *history);


/* =====| COMMAND LIST GAME |===== */
// Prosedur untuk menampilkan daftar permainan yang ada
void ListGame(ArrayDin Game);


/* =====| COMMAND LOAD |===== */
// Prosedur untuk menjalankan program BNMO dengan membaca savefile yang ada
void Load(ArrayDin *Game, ArrayDin *AllScoreboard, Stack *history, char *filename, Word *INPUT);


/* =====| COMMAND PLAY GAME |===== */
// Menjalankan permainan sesuai dengan daftar antrian
void PlayGame (Queue *GameQ, SetMap *scoreboard);


/* =====| COMMAND QUEUE GAME |===== */
// Prosedur untuk menambahkan permainan ke dalam daftar antrian
void QueueGame(ArrayDin *Game, Queue *GameQ);


/* =====| COMMAND SAVE |===== */
// Fungsi untuk memeriksa ekstensi file
boolean validExtension(char *filename);
// Prosedur untuk menyimpan file <savefile>.txt
void Save(ArrayDin array, char *filename);


/* =====| COMMAND SCOREBOARD |===== */
// Prosedur untuk membaca scoreboard dari file konfigurasi ataupun savefile
void readScoreboard(ArrayDin Game, ArrayDin AllScoreboard, SetMap *sbGame);
// Prosedur untuk mencatat skor yang didapatkan ke scoreboard permainan yang bersesuaian
void toScoreboard(SetMap *scoreboard, int score);
// Prosedur untuk menampilkan scoreboard setiap permainan
void Scoreboard(SetMap scoreboard);
// Prosedur untuk menghapus skor yang ada pada scoreboard
void ResetScoreboard(SetMap *scoreboard, ArrayDin game);


/* =====| COMMAND SKIPGAME |===== */
// Prosedur untuk melewati permainan sebanyak n
// Memulai permainan jika daftar antrian tidak kosong
void SkipGame(Queue *Game, int n, SetMap *scoreboard);


/* =====| COMMAND START |===== */
// Prosedur untuk menjalankan program BNMO dengan membaca file konfigurasi config.txt
void Start(ArrayDin *Game, ArrayDin *AllScoreboard, Stack *history);


/* =====| ANOTHER COMMAND |===== */
// Menyimpan Command-command yang valid ke dalam sebuah array
ArrayDin validCOMMAND();
// Fungsi untuk memeriksa apakah Kata merupakan sebuah perintah yang valid atau bukan.
// Jika valid akan mengembalikan true dan akan mengembalikan false jika tidak valid
boolean isCOMMAND(Word Kata);


/* =====| FETCHBNMO |===== */
// Prosedur untu menjalankan fungsi Start atau Load bergantung dengan masukkan pengguna
void fetchBNMO(Word *INPUT);


/* =====| COUNTDOWN |===== */
// Prosedur untu menghasilkan waktu hitung mundur dengan menampilkan "."
void countdown();


/* =====| DISPLAY |===== */
// Prosedur untu menampilkan welcome page saat memulai BNMO
void display();


#endif