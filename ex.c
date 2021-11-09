#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char **argv){

char target[10000];

char path[100000];

strcpy(path, argv[1]);

char c;
char garb[3];
//printf("argc: %d, argv[1]: %s\n", argc, argv[1]);
printf("and the path is: %s\n", path);
int line = 1;

//scanf("%s", path);
scanf("%s", target);


//int fp = open(path,O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
int fp = open(path, O_RDWR);
if (fp == -1)
    {
        printf("%s", path);
        printf("\nCannot open file \n");
        exit(0);
    }

int flag = 1;

char word[1000];

int temp = read(fp, &c, 1);
//int ddd = read(fp, garb, 3);
     while (temp > 0)
    {
	if(c == '\n')
	  ++line;

	if(flag == 1)
	{
	  strcpy(word, &c);
	  flag = 0;
	}
	else if(c == ' ' || c == '\n')
	{
          flag = 1;
	  //checkword();
	   printf("\n------------------\nthe word is: %s\n------------------", word);
	  if(!strcmp(target, word))
	  {
	    if(c == '\n')
		--line;
	   // printf("%d", line);
	    printf("Line is: %d", line);
	    return 0;
	  }
	}
	else if(c != ' ' && c > 32 && c < 126 )
        {
          strcat(word, &c);
        }


       // printf ("%c", c);
        temp = read(fp, &c, 1);
//	ddd = read(fp, garb, 3);
    }


//printf("%d", line);
printf("Does not contain: %s", target);

close(fp);
return 0;
}
