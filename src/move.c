#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
int main()
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
    return 0;

}


