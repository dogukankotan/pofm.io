#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

void copy_() {
    DIR *directory;
    char Currentpath[100];
    char charr, source_file[20], target_file[20];
    FILE *source, *target;

  
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
}

int main(int argc, char *argv[])
{
  if (argc == 2) {
        for (int i = 1; i < argc; ++i) {
            if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
                //help();
                return;
            }
        }
        puts("Unsupported argument. Please use -h or --help for usage.");
    }
  else if (argc < 2) {
        copy_();
        return;
    }
  else {
        puts("Please give argument or for usage use -h or --help.");
    }
   return 0;
}


