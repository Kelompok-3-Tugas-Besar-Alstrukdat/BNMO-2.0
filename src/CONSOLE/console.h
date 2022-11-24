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
#include "../ADT/Map/map.h"
#include "../ADT/MesinKata/mesinkata.h"
#include "../ADT/Point/point.h"
#include "../ADT/Queue/queue.h"
#include "../ADT/Set/set.h"
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
void toHistory(Stack *history);
// Prosedur untuk menampilkan history permainan
void History(Stack history, int n);
// Prosedur untuk menghapus daftar permainan yang telah dimainkan pada history
void ResetHistory(Stack *history);


/* =====| COMMAND LOAD |===== */
// Prosedur untuk menjalankan program BNMO dengan membaca savefile yang ada
void Load(ArrayDin *Game, char *filename, Word *INPUT);


/* =====| COMMAND PLAY GAME |===== */
// Menjalankan permainan sesuai dengan daftar antrian
void PlayGame (Queue *q);


/* =====| COMMAND QUEUE GAME |===== */
// Prosedur untuk menambahkan permainan ke dalam daftar antrian
void QueueGame(ArrayDin *Game, Queue *Q);


/* =====| COMMAND SAVE |===== */
// Fungsi untuk memeriksa ekstensi file
boolean validExtension(char *filename);
// Prosedur untuk menyimpan file <savefile>.txt
void Save(ArrayDin array, char *filename);


/* =====| COMMAND SCOREBOARD |===== */
// Prosedur untuk mencatat skor yang didapatkan ke scoreboard permainan yang bersesuaian
void toScoreboard(Map *scoreboard, Set *player);
// Prosedur untuk menampilkan scoreboard setiap permainan
void Scoreboard(Map scoreboard);
// Prosedur untuk menghapus skor yang ada pada scoreboard
void ResetScoreboard(Map *scoreboard, Set *player);


/* =====| COMMAND SKIPGAME |===== */
// Prosedur untuk melewati permainan sebanyak n
// Memulai permainan jika daftar antrian tidak kosong
void SkipGame(Queue *game, int n);


/* =====| COMMAND START |===== */
// Prosedur untuk menjalankan program BNMO dengan membaca file konfigurasi config.txt
void Start(ArrayDin *Game);


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


#endif