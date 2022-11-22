/* =====| GAME MAGIC SHELL |===== */

// Include file header yang diperlukan
#include "allgames.h"

// Prosedur untuk menjalankan permainan Magic Shell
// Menjawab pertanyaan apapun yang diberikan
void magic_shell() {
    ArrayDin magshell = MakeArrayDin();
    magshell.Neff = 2;
    // Ya
    magshell.Elmt[0].Length = 2;
    magshell.Elmt[0].TabWord[0] = 'Y';
    magshell.Elmt[0].TabWord[1] = 'a';

    time_t t;
    srand(time(&t));
    
    Word Input;
    Input.Length = 2;
    Input.TabWord[0] = 'Y';
    Input.TabWord[1] = 'a';

    while (isWordEqual(Input, magshell.Elmt[0])) {
        printf("============================| M A G I C  S H E L L |=============================\n");
        printf("Silahkan tanyakan apa saja!\n");
        COMMAND();
        int num = (rand() % 9) + 1;

        if (num == 1) {
            printf("Ya\n");
        }
        else if (num == 2) {
            printf("Tidak\n");
        }
        else if (num == 3) {
            printf("Kamu nanyeaaa?\n");
        }
        else if (num == 4) {
            printf("Kamu nanyea bertanyea tanyeaaa?\n");
        }
        else if (num == 5) {
            printf("Capek ah ditanyain mulu...\n");
        }
        else if (num == 6) {
            printf("Bisa jadi\n");
        }
        else if (num == 7) {
            printf("Mungkin\n");
        }
        else if (num == 8) {
            printf("Mungkin nanti\n");
        }
        else if (num == 9) {
            printf("Mungkin tidak\n");
        }
        else {
            printf("Coba tanya lagi\n");
        }

        printf("\nMasih mau nanyeaaa? (Ya/Tidak)\n");
        COMMAND();
        Input.Length = currentWord.Length;
        for (int i = 0; i < currentWord.Length; i++)
        {
            Input.TabWord[i] = currentWord.TabWord[i];
        }
        countdown();
        system("cls");
    }
    system("cls");
    printf("============================| M A G I C  S H E L L |=============================\n");
    printf("Puja kerang ajaib!!! Ulululululululu!!!\n");
}