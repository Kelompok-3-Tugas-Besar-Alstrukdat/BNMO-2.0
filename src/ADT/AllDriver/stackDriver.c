#include "../Array/array.c"
#include "../Stack/stack.c"
#include "../MesinKarakter/mesinkarakter.c"
#include "../MesinKata/mesinkata.c"

int main()
{
    Stack S;
    infotypeSS X;

    /*Penggunaan fungsi CreatEmptyStack, IsEmptyStack, dan IsFullStack*/
    CreateEmptyStack(&S);
    if (IsEmptyStack(S))
    {
        printf("Stack masih kosong\n");
    }
    if (!IsFullStack(S))
    {
        printf("Stack masih belum penuh\n");
    }
    /*Pengecekan isi Stack dan Penggunaan fungsi Push*/
    for (int i = 0; i < MaxEl; i++)
    {
        X.Length = 2;
        X.TabWord[0] = 'a'; X.TabWord[1] = 'b';
        Push(&S, X);
    }
    if (IsFullStack(S))
    {
        printf("Stack sudah penuh\n");
    }
    infotypeSS Z;
    /*Penggunaan fungsi Pop*/
    Pop(&S, &Z);
    printf("Isi variabel Z setelah Pop: ");
    printWord(Z); 
    printf("\nS.TOP sekarang: %d\nElemen di TOP sekarang adalah: ", S.TOP);
    printWord(S.T[S.TOP]); printf("\n");

}