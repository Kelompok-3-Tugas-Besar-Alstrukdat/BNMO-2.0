#include "mesinkata.h"

/* State Mesin Kata */
boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    while (currentChar == BLANK || currentChar == ENTER)
    {
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD(char *filename)
{
    START(filename);
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        ADVWORD();
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD()
{
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyWord */

void CopyWord()
{
    currentWord.Length = 0;
    while ((currentChar != MARK) && (currentChar != ENTER))
    {
        // jika lebih akan terpotong
        if (currentWord.Length < NMax)
        {
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
        {
            break;
        }
    }
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void COMMAND()
{
    CharCOMMAND();
    if (currentChar == ENTER)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        ADVCMD();
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = ENTER;
          atau EndWord = false, currentWord adalah command yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir command */

void ADVCMD()
{
    if (currentChar == ENTER)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyCMD();
    }
}
/* I.S. : currentChar adalah karakter pertama command yang akan diakuisisi
   F.S. : currentWord adalah command terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari command berikutnya, mungkin ENTER
          Jika currentChar = ENTER, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyCMD */

void CopyCMD()
{
    currentWord.Length = 0;
    while (currentChar != ENTER)
    {
        currentWord.TabWord[currentWord.Length++] = currentChar;
        ADVCharCMD();
    }
}
/* Mengakuisisi command, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari command
   F.S. : currentWord berisi command yang sudah diakuisisi;
          currentChar = ENTER;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi. */

void printWord(Word Kata)
{
    for (int i = 0; i < Kata.Length; i++)
    {
        printf("%c", Kata.TabWord[i]);
    }
    printf("\n");
}
/* Menampilkan Kata ke layar
   Prekondisi: Kata terdifinisi */

void toStr(Word Kata, char *string)
{
    int i;
    for (i = 0; i < Kata.Length; i++)
    {
        string[i] = Kata.TabWord[i];
    }
    string[i] = '\0';
}
/* Mengubah kata yang merupakan tipe kata menjadi string */

Word toWord(int val)
{
    Word charInt;
    int temp = val, len = 0;
    while (temp > 0)
    {
        temp /= 10;
        len++;
    }
    
    temp = val;
    for (int i = len - 1; i >= 0; i--)
    {
        charInt.TabWord[i] = (char) ((temp % 10) + '0');
        temp /= 10;
    }
    charInt.Length = len;
    return charInt;
}
/* Mengubah kata yang merupakan tipe kata menjadi string */

int toInt (Word Kata)
{
    int num = 0;
    for (int i = 0; i < Kata.Length; i++)
    {
        num += ((Kata.TabWord[i] - '0') * (pow(10,(Kata.Length - 1 - i))));
    }
    return num;
}
/* Mengubah kata yang merupakan angka numerik menjadi integer
   Prekondisi : Kata merupakan bilangan numerik */

boolean isWordEqual (Word Kata1, Word Kata2)
{
    boolean check = true;
    if (Kata1.Length != Kata2.Length)
    {
        return !check;
    }
    else
    {
        int i = 0;
        while (check && (i < Kata1.Length))
        {
            if (Kata1.TabWord[i] != Kata2.TabWord[i])
            {
                check = false;
            }
            i++;
        }
        return check;
    }
}
/* Memeriksa apakah Kata1 dan Kata2 sama, jika Kata1 dan Kata2 sama akan mengembalikan true
   Prekondisi : Kata1 dan Kata2 terdefinisi */