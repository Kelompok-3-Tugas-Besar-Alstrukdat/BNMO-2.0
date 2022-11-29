/* =====| GAME RNG |===== */

// Include file header yang diperlukan
#include "allgames.h"

// Fungsi untuk menentukan nilai integer yang random,
// dengan rentang nilai 0-100 (inclusive)
int RandomNumber()
{
    time_t t;
    srand(time(&t));
    int num = (rand() % 101); // Diperoleh dari num = (rand() % (100 - 0 + 1)) + 0
    return num;
}
// Prosedur yang menjalankan game RNG
// Prekondisi: tebakan merupakan bilangan bulat (integer)
void runRNG(SetMap *scoreboard)
{
    printf("===================================| R N G |===================================\n");
    printf("RNG telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    int X = RandomNumber(), score = 110, attempt = 0, tebakan;
    do
    {
        attempt++;
        score -= 10;
        printf("Tebakan: ");
        COMMAND();
        tebakan = toInt(currentWord);
        if (X < tebakan)
        {
            printf("Lebih kecil\n");
        }
        else if (X > tebakan)
        {
            printf("Lebih besar\n");
        }
        else
        {
            printf("\nYa, X adalah %d\n", X);
        }
    }
    while ((attempt < 10) && (tebakan != X));
    if (tebakan != X)
    {
        printf("\nMaaf, Anda kurang beruntung. Kesempatan Anda telah habis. Coba lagi lain waktu.\n");
    }
    printf("S K O R : %d\n", score);
    printf("\n\n\n");
    toScoreboard(scoreboard, score);
}