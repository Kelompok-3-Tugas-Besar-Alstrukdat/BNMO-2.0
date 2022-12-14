#include "Stack.h"

void CreateEmptyStack(Stack *S)
{
    Top(*S) = NilS;
}
boolean IsEmptyStack(Stack S)
{
    return Top(S) == NilS;
}
boolean IsFullStack(Stack S)
{
    return Top(S) == MaxEl-1;
}
void Push(Stack *S, infotypeSS X)
{
    if (!IsFullStack(*S))
    {
        S->TOP ++;
        S->T[S->TOP].Length = X.Length;
        for (int i = 0; i < X.Length; i++)
        {
            S->T[S->TOP].TabWord[i] = X.TabWord[i];
        }
    }
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, infotypeSS *X)
{
    (*X).Length = S->T[S->TOP].Length;
    for (int i = 0; i < S->T[S->TOP].Length; i++)
    {
        (*X).TabWord[i] = S->T[S->TOP].TabWord[i];
    }
    S->TOP --;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
