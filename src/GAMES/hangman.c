/* =====| GAME HANGMAN |===== */

// Include file header yang diperlukan
#include "allgames.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <string.h>
void clrscr()
{
    printf("\e[1;1H\e[2J");
}
int main() 
{
	printf("=========================| H A N G M A N |=========================\n");
    clrscr();
    int quit=1;
while(quit!=0)
{
    int letters=1;
    char* word="thisisuselesstrust me";
    switch(rand()%20)
	{
    case 1: word="book"; letters = 4; break;
    case 2: word="car"; letters =3; break;
    case 3: word="tree"; letters= 4; break;
    case 4: word="game"; letters=4; break;
    case 5: word="understand"; letters=10; break;
    case 6: word="family"; letters=6; break;
    case 7: word="pen"; letters=3; break;
    case 8: word="coffee"; letters=6; break;
    case 9: word="email"; letters=5; break;
    case 10: word="facebook"; letters=8; break;
    case 11: word="football"; letters=8; break;
    case 12: word="online"; letters=6; break;
    case 13: word="come"; letters=4; break;
    case 14: word="please"; letters=6; break;
    case 15: word="introduction"; letters=12; break;
    case 16: word="project"; letters=7; break;
    case 17: word="create"; letters=6; break;
    case 18: word="programming"; letters=11; break;
    case 19: word="warrior"; letters=7; break;
    case 20: word="weird"; letters=5; break;
    case 21: word="handsome"; letters=8; break;
    case 22: word="amazing"; letters=7; break;
    default: word="knife"; letters=5; break;
    }
    char answer[100];
    char wanswer[100]=" ";
    strcpy(answer,"");
	for(int i=1;i<=letters;i++)
	{
	    strcat(answer,"_ ");
	    printf("_ ");
	}
	int b=0;
	int c=0;
	int p=1;
	int finish=0;
	while(c<10)
	{   
	    printf("\nMasukkan tebakan: ");
	    char letter;
	    scanf("%s",&letter);
	    clrscr();
	    if(strchr(word,letter)!=0)
	    {
	        for(int j=0;j<=letters-1;j++)
			{
	            if(letter==word[j])
	            {
	                p=j*2;
	                if(answer[p]!=letter) finish++;
	                answer[p]=letter;

	            }
	        }
	        printf("%s\n",answer);
	        printf("Tebakanmu benar!\n");
	        if(finish==letters) {break; b=0;}
	        if(b!=0) printf("Tebakkan sebelumnya:  %s",wanswer);
	        if(c>0)c--;
	    }
	    else
	    {
	        wanswer[2*b]=letter;
	        strcat(wanswer," ");
	        b++;
	       clrscr(); c++;
	       if(c==1) printf("o-----------\n|          |\n|\n|");
			if(c==2) printf("o-----------\n|          |\n|\n|\n|\n|\n|\n|\n");
			if(c==3) printf("o-----------\n|          |\n|          O\n|\n|\n|\n|"); 
			if(c==4) printf("o-----------\n|          |\n|          O\n|\n|\n|\n|\n|\n"); 
			if(c==5) printf("o-----------\n|          |\n|          O\n|          |\n|          ");
			if(c==6) printf("o-----------\n|          |\n|          O\n|          |\n|          |\n|\n|");
			if(c==7) printf("o-----------\n|          |\n|          O\n|          |\n|          |\n|\n|\n|\n");  
			if(c==8) printf("o-----------\n|          |\n|          O\n|          |\n|          |\n|         / \\\n");  
			if(c==9) printf("o-----------\n|          |\n|          O\n|          |\n|          |\n|         / \\\n|\n|\n");  
			if(c==10) printf("o-----------\n|          |\n|          O \n|         \\|/\n|          |\n|         / \\\n");
			if(c==10){ clrscr(); printf("o-----------\n|          |\n|          O \n|         \\|/\n|          |\n|         / \\\n|\n|\n");}
			if(c!=10)
			{
	       printf("Kesempatan: %d\n",10-c); 
	       printf("%s\n",answer);
	       printf("Tebakkan sebelumnya:  %s",wanswer);
	       }
	    }   	
    }
    if(finish==letters) 
	{    
        printf("Berhasil menebak kata \"%s\" kamu mendapatkan poin %d \n",word, letters);
    }
	else
	{
	    printf("Kesempatanmu habis! Kamu tidak berhasil menebak kata \"%s\" \n\n",word); 
	}
	printf("Pilih:\n 1-Main lagi \n 0-Keluar\n");
	scanf("%d",&quit);
	clrscr();
}
    return 0;
}
