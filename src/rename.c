#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main()
{
    DIR *directory;
    char CurrentPath[150], filenameO[50], filnameN[50];

    if (directory != NULL && getcwd(CurrentPath,sizeof(CurrentPath)) != NULL)
    {
        fprintf(stdout,"\n You are on %s\n The files on the directory is as following \n",getcwd(CurrentPath,sizeof(CurrentPath)));
      
    } 

    printf("please enter name of the file that will be renamed\n");
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
