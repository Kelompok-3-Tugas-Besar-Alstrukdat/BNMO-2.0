/* File: mesinkata.h */
#ifndef MESIN_KATA
#define MESIN_KATA

#include <stdio.h>
#include <math.h>
#include "../../boolean.h"
#include "../MesinKarakter/mesinkarakter.h"

#define NMax 100
#define BLANK ' '
#define ENTER '\n'

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;

/* Primitif Umum */
void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD(char *filename);
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void COMMAND();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = ENTER;
          atau EndWord = false, currentWord adalah command yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir command */

void ADVCMD();
/* I.S. : currentChar adalah karakter pertama command yang akan diakuisisi
   F.S. : currentWord adalah command terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari command berikutnya, mungkin ENTER
          Jika currentChar = ENTER, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyCMD */

void CopyCMD();
/* Mengakuisisi command, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari command
   F.S. : currentWord berisi command yang sudah diakuisisi;
          currentChar = ENTER;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi. */

void printWord(Word Kata);
/* Menampilkan Kata ke layar
   Prekondisi: Kata terdifinisi */

void toStr(Word Kata, char *string);
/* Mengubah kata yang merupakan tipe kata menjadi string */

Word toWord(int val);
/* Mengubah kata yang merupakan tipe kata menjadi string */

int toInt (Word Kata);
/* Mengubah kata yang merupakan angka numerik menjadi integer
   Prekondisi : Kata merupakan bilangan numerik */

boolean isWordEqual (Word Kata1, Word Kata2);
/* Memeriksa apakah Kata1 dan Kata2 sama, jika Kata1 dan Kata2 sama akan mengembalikan true
   Prekondisi : Kata1 dan Kata2 terdefinisi */

#endif