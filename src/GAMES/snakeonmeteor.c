/* =====| GAME SNAKE ON METEOR |===== */

// Include file header yang diperlukan
#include "../CONSOLE/console.h"
#include "allgames.h"

// Mengirim true jika coordinate berada di object
boolean isOnObject(LinkedList object, Point coordinate)
{
    addressLL Adr = First(object);
    while ((Next(Adr) != NilLL) && (!isPointEqual(Info(Adr), coordinate)))
    {
        Adr = Next(Adr);
    }
    return isPointEqual(Info(Adr), coordinate);
}
// Mengirim true jika masukkan valid
boolean validMove(Word move)
{
    return
    (move.Length == 1)
    &&
    (   (move.TabWord[0] == 'A') ||
        (move.TabWord[0] == 'W') ||
        (move.TabWord[0] == 'S') ||
        (move.TabWord[0] == 'D') ||
        (move.TabWord[0] == 'a') ||
        (move.TabWord[0] == 'w') ||
        (move.TabWord[0] == 's') ||
        (move.TabWord[0] == 'd')    );
}
// Mengirim true jika permainan berakhir dengan kondisi yang telah ditentukan
boolean SoMOver(LinkedList snake, LinkedList obstacle, Point meteor)
{
    Point temp1, temp2, temp3, temp4;
    CreatePoint(&temp1, ((Info(First(snake)).x + 1) % 5), Info(First(snake)).y);
    CreatePoint(&temp2, Info(First(snake)).x, ((Info(First(snake)).y + 1) % 5));
    int val;
    val = ((Info(First(snake)).x - 1) % 5);
    if (val < 0)
    {
        val += 5;
    }
    CreatePoint(&temp3, val, Info(First(snake)).y);
    val = ((Info(First(snake)).y - 1) % 5);
    if (val < 0)
    {
        val += 5;
    }
    CreatePoint(&temp4, Info(First(snake)).x, val);

    return
    (isPointEqual(Info(First(snake)), meteor))
    ||
    (SearchLL(obstacle, Info(First(snake))) != NilLL)
    ||
    ((isOnObject(snake, temp1)) && (isOnObject(snake, temp2)) && (isOnObject(snake, temp3)) && (isOnObject(snake, temp4)))
    ||
    ((isOnObject(snake, temp1)) && (isOnObject(snake, temp2)) && (isOnObject(snake, temp3)) && ((isPointEqual(temp4, meteor))))
    ||
    ((isOnObject(snake, temp1)) && (isOnObject(snake, temp2)) && (isPointEqual(temp3, meteor)) && ((isOnObject(snake, temp4))))
    ||
    ((isOnObject(snake, temp1)) && (isPointEqual(temp2, meteor)) && ((isOnObject(snake, temp3))) && ((isOnObject(snake, temp4))))
    ||
    ((isPointEqual(temp1, meteor)) && ((isOnObject(snake, temp2))) && ((isOnObject(snake, temp3))) && ((isOnObject(snake, temp4))));
}

// Prosedur untuk menjalankan permainan Snake on Meteor
void runSnakeOnMeteor(SetMap *scoreboard)
{
    time_t t;
    srand(time(&t));

    Point head, food, meteor, obspoint;
    LinkedList snake, obstacle;
    int Turn = 1, count = 0, obsnum = 0;
    
    CreateEmptyLL(&snake);
    CreateEmptyLL(&obstacle);
    CreatePoint(&head, (rand() % 5), (rand() % 5));
    CreatePoint(&meteor, -1, -1);
    CreatePoint(&food, head.x, head.y);
    
    InsVFirstLL(&snake, head);
    if ((rand() % 2) == 0)
    {
        for (int i = 0; i < 2; i++)
        {
            head.x++;
            head.x %= 5;
            InsVLastLL(&snake, head);
        }   
    }
    else
    {
        for (int i = 0; i < 2; i++)
        {
            head.y++;
            head.y %= 5;
            InsVLastLL(&snake, head);
        }
    }

    CreatePoint(&obspoint, -1, -1);
    InsVFirstLL(&obstacle, obspoint);
    do
    {
        CreatePoint(&obspoint, (rand() % 5), (rand() % 5));
        if ((!isOnObject(snake, obspoint)) && (!isOnObject(obstacle, obspoint)))
        {
            InsVFirstLL(&obstacle, obspoint);
            obsnum++;
        }
    }
    while (obsnum < 5);

    printf("=========================| S N A K E  O N  M E T E O R |=========================\n");
    printf("Selamat datang di Snake on Meteor!\n");
    printf("Menyiapkan area permainan");
    countdown();
    system("cls");

    printf("=========================| S N A K E  O N  M E T E O R |=========================\n");
    while (!SoMOver(snake, obstacle, meteor))
    {
        addressLL Adr, ObsAdr;
        int temp;

        if (isPointEqual(Info(First(snake)), food))
        {
            if (Turn > 1)
            {
                Point tempTail;
                temp = ((Info(Last(snake)).x - 1) % 5);
                if (temp < 0)
                {
                    temp += 5;
                }
                CreatePoint(&tempTail, temp, Info(Last(snake)).y);
                if (isOnObject(snake, tempTail) || ((isOnObject(obstacle, tempTail))))
                {
                    CreatePoint(&tempTail, ((Info(Last(snake)).x + 1) % 5), Info(Last(snake)).y);
                    if (isOnObject(snake, tempTail) || ((isOnObject(obstacle, tempTail))))
                    {
                        temp = ((Info(Last(snake)).y - 1) % 5);
                        if (temp < 0)
                        {
                            temp += 5;
                        }
                        CreatePoint(&tempTail, Info(Last(snake)).x, temp);
                        if (isOnObject(snake, tempTail) || ((isOnObject(obstacle, tempTail))))
                        {
                            CreatePoint(&tempTail, Info(Last(snake)).x, ((Info(Last(snake)).y + 1) % 5));
                            if (isOnObject(snake, tempTail) || ((isOnObject(obstacle, tempTail))))
                            {
                                break;
                            }
                        }
                    }
                }
                InsVLastLL(&snake, tempTail);
            }

            do
            {
                CreatePoint(&food, (rand() % 5), (rand() % 5));
            }
            while ((isOnObject(snake, food)) || (isPointEqual(food, meteor)) || ((isOnObject(obstacle, food))));
        }

        printf("=================================================================================\n");
        printf("T U R N  %d\n", Turn);
        printf("Berikut merupakan peta permainan.\n");
        printf("+-----+-----+-----+-----+-----+\n");
        for (int j = 0; j < 5; j++)
        {
            printf("|");
            for (int i = 0; i < 5; i++)
            {
                Point currP;
                CreatePoint(&currP, i, j);
                Adr = First(snake);
                ObsAdr = First(obstacle);
                count = 0;

                if (((isOnObject(obstacle, currP))))
                {
                    if (ObsAdr != NilLL)
                    {
                        printf("  X  |");
                        ObsAdr = Next(ObsAdr);
                    }
                }
                else
                {
                    if (isPointEqual(currP, meteor))
                    {
                        printf("  m  |");
                    }
                    else
                    {
                        if (SearchLL(snake, currP) != NilLL)
                        {
                            while (Adr != SearchLL(snake, currP))
                            {
                                Adr = Next(Adr);
                                count++;
                            }
                            
                            if (count == 0)
                            {
                                printf("  H  |");
                            }
                            else
                            {
                                printf("  %d  |", count);
                            }
                        }
                        else if (isPointEqual(currP, food))
                        {
                            printf("  o  |");
                        }
                        else
                        {
                            printf("     |");
                        }
                    }
                }
            }
            printf("\n+-----+-----+-----+-----+-----+\n");
        }

        printf("MASUKKAN COMMAND: ");
        COMMAND();
        system("cls");

        printf("=========================| S N A K E  O N  M E T E O R |=========================\n");
        if (validMove(currentWord))
        {
            Point tempHead;
            if ((currentWord.TabWord[0] == 'A') || (currentWord.TabWord[0] == 'a'))
            {
                temp = ((Info(First(snake)).x - 1) % 5);
                if (temp < 0)
                {
                    temp += 5;
                }
                CreatePoint(&tempHead, temp, Info(First(snake)).y);
            }
            else if ((currentWord.TabWord[0] == 'W') || (currentWord.TabWord[0] == 'w'))
            {
                temp = ((Info(First(snake)).y - 1) % 5);
                if (temp < 0)
                {
                    temp += 5;
                }
                CreatePoint(&tempHead, Info(First(snake)).x, temp);
            }
            else if ((currentWord.TabWord[0] == 'S') || (currentWord.TabWord[0] == 's'))
            {
                CreatePoint(&tempHead, Info(First(snake)).x, ((Info(First(snake)).y + 1) % 5));
            }
            else if ((currentWord.TabWord[0] == 'D') || (currentWord.TabWord[0] == 'd'))
            {
                CreatePoint(&tempHead, ((Info(First(snake)).x + 1) % 5), Info(First(snake)).y);
            }

            if ((SearchLL(snake, tempHead) == NilLL) && (!isPointEqual(tempHead, meteor)))
            {
                addressLL move = Last(snake);
                while(move != First(snake))
                {
                    Info(move) = Info(Prev(move));
                    move = Prev(move);
                }
                Info(First(snake)) = tempHead;

                Turn++;
                if (Turn > 1)
                {
                    do
                    {
                        CreatePoint(&meteor, (rand() % 5), (rand() % 5));
                    }
                    while ((isPointEqual(meteor, food)) || ((isOnObject(obstacle, meteor))));
                }

                printf("Berhasil bergerak!\n");
                if ((SearchLL(snake, meteor) != NilLL) || (SearchLL(obstacle, Info(First(snake))) != NilLL) || SoMOver(snake, obstacle, meteor))
                {
                    if ((SearchLL(snake, meteor) != NilLL) && (SearchLL(obstacle, Info(First(snake))) != NilLL))
                    {
                        printf("OHHH... TIDAK! ANDA TERKENA METEOR DAN MENGENAI OBSTACLE!\n");    
                    }
                    else if ((SearchLL(snake, meteor) != NilLL) && (SoMOver(snake, obstacle, meteor)))
                    {
                        printf("OHHH... TIDAK! ANDA TERKENA METEOR DAN TIDAK DAPAT BERGERAK!\n");    
                    }
                    else if((SearchLL(snake, meteor) != NilLL))
                    {
                        printf("OHHH... TIDAK! ANDA TERKENA METEOR!\n");
                    }
                    else if((SearchLL(obstacle, Info(First(snake))) != NilLL))
                    {
                        printf("OHHH... TIDAK! ANDA MENGENAI OBSTACLE!\n");
                    }
                    else
                    {
                        printf("OHHH... TIDAK! ANDA TIDAK DAPAT BERGERAK!\n");
                    }
                    printf("+-----+-----+-----+-----+-----+\n");
                    for (int j = 0; j < 5; j++)
                    {
                        printf("|");
                        for (int i = 0; i < 5; i++)
                        {
                            Point currP;
                            CreatePoint(&currP, i, j);
                            Adr = First(snake);
                            count = 0;

                            if (((isOnObject(obstacle, currP))))
                            {
                                if (ObsAdr != NilLL)
                                {
                                    if (isOnObject(snake, currP))
                                    {
                                        printf("  H  |");
                                    }
                                    else
                                    {
                                        printf("  X  |");
                                    }
                                    ObsAdr = Next(ObsAdr);
                                }
                            }
                            else
                            {
                                if (isPointEqual(currP, meteor))
                                {
                                    printf("  m  |");
                                }
                                else
                                {
                                    if (SearchLL(snake, currP) != NilLL)
                                    {
                                        while (Adr != SearchLL(snake, currP))
                                        {
                                            Adr = Next(Adr);
                                            count++;
                                        }

                                        if (count == 0)
                                        {
                                            printf("  H  |");
                                        }
                                        else
                                        {
                                            printf("  %d  |", count);
                                        }
                                    }
                                    else if (isPointEqual(currP, food))
                                    {
                                        printf("  o  |");
                                    }
                                    else
                                    {
                                        printf("     |");
                                    }
                                }
                            }
                        }
                        printf("\n+-----+-----+-----+-----+-----+\n");
                    }
                    if ((SearchLL(snake, meteor) != NilLL) && (!isPointEqual(Info(First(snake)), meteor)))
                    {
                        DelPLL(&snake, meteor);
                    }
                }
                else
                {
                    printf("Anda beruntung tidak terkena meteor!\n");
                }
            }
            else
            {
                if (SearchLL(snake, tempHead) == NilLL)
                {
                    printf("Meteor masih panas! Anda belum dapat menuju ke titik tersebut.\nSilahkan masukkan command yang lain.\n");
                }
                else
                {
                    printf("Tidak dapat bergerak ke tubuh sendiri!\nSilahkan masukkan command yang lain.\n");
                }
            }
        }
        else
        {
            printf("Command tidak valid! Silahkan masukkan command yang valid.\n");
            printf("Command Valid:\n");
            printf("> \"W\" atau \"w\" untuk bergerak ke atas\n");
            printf("> \"A\" atau \"a\" untuk bergerak ke kiri\n");
            printf("> \"S\" atau \"s\" untuk bergerak ke bawah\n");
            printf("> \"D\" atau \"s\" untuk bergerak ke kanan\n");
        }
    }
    system("cls");
    int score = 0;
    printf("=========================| S N A K E  O N  M E T E O R |=========================\n");
    if (isPointEqual(Info(First(snake)), meteor))
    {
        printf("Permainan berakhir, kepala snake terkena meteor!\n");
        DelPLL(&snake, meteor);
    }
    else if (SearchLL(obstacle, Info(First(snake))) != NilLL)
    {
        printf("Permainan berakhir, kepala snake terkena obstacle!\n");
    }
    else
    {
        printf("Permainan berakhir, kepala snake dikelilingi tubuhnya!\n");
    }
    if (!IsEmptyLL(snake))
    {
        addressLL collect = First(snake);
        while (collect != NilLL)
        {
            score++;
            collect = Next(collect);
        }
        score *= 2;
    }
    printf("=================================================================================\n");
    printf("                           !!!  G A M E   O V E R  !!!\n");
    printf("                                   S K O R : %d", score);
    printf("\n\n\n");
    toScoreboard(scoreboard, score);
}