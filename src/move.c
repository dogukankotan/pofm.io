#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

void help(){
  printf("This command moves a file in your current directory to any directory, if you want to move a file in other directory to any directory\n you can enter file name by giving directory,\nyou just need to enter a file name,\nthen enter a directory where you want to move\n");
}

void move()
{
    DIR *directory;
    char source_file[20], target_file[20],Currentpath[100],charr,del;
    FILE *source, *target;

    directory = opendir("./");
    if (directory != NULL && getcwd(Currentpath, sizeof(Currentpath)) !=NULL)
    {
        fprintf(stdout, "\nYour current directory is: %s \n", getcwd(Currentpath, sizeof(Currentpath)));
        closedir(directory);
    }


   printf("Enter name of file to move\n");
   gets(source_file);
   if (source_file=='\n'){
    printf("please enter such a valid name");
   }

   while(access(source_file, 0) == -1 )//in case if it does not exist

        {
        printf("\n file does not exist, please enter file name again:\n");
        gets(source_file);
        break;
        }

   printf("Enter name of target file to move by giving path if you wish\n");
   gets(target_file);

   if (target_file=='\n'){
    printf("please enter such a valid name");
   }
   while(access(target_file, 0) != -1)//If the file exists in the destination directory
    {
        printf("\n file name already exists, please enter file name again\n");
        gets(target_file);
        break;
    }
    source = fopen(source_file, "r");
    if (access(source, 0)==-1){

        target = fopen(target_file, "w");


       while( ( charr = fgetc(source) ) != EOF )
              fputc(charr, target);

           printf("File moved successfully.\n");

           fclose(target);
           fclose(source);
           del = remove(source_file);



    }

}

int main(int argc, char *argv[])
{
  if (argc == 2) {
        for (int i = 1; i < argc; ++i) {
            if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
                help();
                return;
            }
        }
        puts("Unsupported argument. Please use -h or --help for usage.");
    }
  else if (argc < 2) {
        move();
        return;
    }
  else {
        puts("Please give argument or for usage use -h or --help.");
    }
   return 0;
}