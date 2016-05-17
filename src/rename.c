#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void rename_()
{
    DIR *directory;
    char CurrentPath[150], filenameO[50], filnameN[50];

    if (directory != NULL && getcwd(CurrentPath,sizeof(CurrentPath)) != NULL)
    {
        fprintf(stdout,"\n You are on %s\n",getcwd(CurrentPath,sizeof(CurrentPath)));
      
    } 

    printf("Please enter name of the file that will be renamed\n");
    gets(filenameO);

    while(access(filenameO,0) == -1)
          {
              printf("there is no such a file\nPlease enter something valid\nValid Files are already listed above\n");
              gets(filenameO);

          }
    if (access(filenameO,0) != -1)
    {
        printf("please enter new name\n");
        gets(filnameN);
        while (access(filnameN,0) != -1)
        {
            printf("there is a file in that name, please enter something else\n");
            gets(filnameN);
        }
        rename(filenameO,filnameN);
        printf("process is done!");

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
        rename_();
        return;
    }
  else {
        puts("Please give argument or for usage use -h or --help.");
    }
   return 0;
}