#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(){

//char text[] = "Hello world ";
char text[100];
char* buff = text;
size_t car;
size_t buff_size = 100;

int n = 0;
scanf("%d", &n);

//scanf("%s", &text);
car = getline(&buff, &buff_size, stdin);

for(int i = 1; i <= n; i++){
int fp;

int length = snprintf( NULL, 0, "%d", i );
char* str = malloc((length + 1)*sizeof(char));
snprintf( str, length + 1, "%d", i );

char* name = malloc((length + 1 + 6)*sizeof(char));

strncpy(name, "file_", 6);
strncat(name, str, length);

fp = open(name,O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
//O_WRONLY
write(fp, text, car * 1);
write(fp, str, length);

close(fp);
free(str);
}
}
