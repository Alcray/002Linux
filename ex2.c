#include <stdio.h>
#include <stdlib.h> // For exit()
#include <string.h>
#include <dirent.h>

void print_f(const char filename[100], char *pat)
{
    FILE *fptr;
    char path[1000000];
    
    strcpy(path, pat);
    strcat(path, "/");
    strcat(path, filename);

    char c;
  
    /*printf("Enter the filename to open \n");
    scanf("%s", filename);*/
  
    // Open file
    fptr = fopen(path, "r");
    if (fptr == NULL)
    {
	printf("%s", path);
        printf("Cannot open file \n");
        exit(0);
	return;
    }
  
    // Read contents from file
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
}

void listFilesRecursively(char *basePath)
{
    char path[1000000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    // Unable to open directory stream
    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
	    printf("\n");
            print_f(dp->d_name, basePath);
	   // printf("%s\n", dp->d_name);
            // Construct new path from our base path
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);

            listFilesRecursively(path);
        }
    }

    closedir(dir);
}

int main(){

char path[1000000];
scanf("%s", path);

listFilesRecursively(path);

return 0;
}
