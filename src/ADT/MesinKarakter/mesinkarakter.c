#include "mesinkarakter.h"

/* State Mesin */
char currentChar;
boolean EOP;
static FILE *pita;
static int retval;

void START(char *filename)
{
    pita = fopen(filename,"r");
    ADV();
}
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari file dokumen.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADV()
{
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK);
    if (EOP)
    {
        fclose(pita);
    }
}
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

void CharCOMMAND()
{
    pita = stdin;
    ADVCharCMD();
}
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != ENTER maka EOP akan padam (false)
          Jika currentChar = ENTER maka EOP akan menyala (true) */

void ADVCharCMD()
{
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == ENTER);
}
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != ENTER
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = ENTER
          Jika  currentChar = ENTER maka EOP akan menyala (true) */

char GetCC()
{
    return currentChar;
}
/* Mengirimkan currentChar */