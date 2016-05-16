#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    DIR *directory;
    char Currentpath[100];
    char charr, source_file[20], target_file[20];
    FILE *source, *target;

    directory = opendir("./");
    if (directory != NULL && getcwd(Currentpath, sizeof(Currentpath)) !=NULL)
    {
        fprintf(stdout, "\nYour current directory is: %s \n", getcwd(Currentpath, sizeof(Currentpath)));
        closedir(directory);
    }

   printf("Enter name of file to copy\n");
   gets(source_file);

   while(access(source_file, 0) == -1 )//in case if it does not exist

        {
        printf("\n file does not exist,please enter correct file name again:\n");
        gets(source_file);
        break;
        }

   printf("Enter name of target file\n");
   gets(target_file);
   while(access(target_file, 0) != -1)
    {
        printf("\n file name already exists, please enter correct file name again:\n");
        gets(target_file);
        break;
    }
    source = fopen(source_file, "r");
    if (access(source, 0)==-1){

        target = fopen(target_file, "w");


       while( ( charr = fgetc(source) ) != EOF )
              fputc(charr, target);

           printf("File copied successfully.\n");

           fclose(source);
           fclose(target);

    }
   return 0;

}


