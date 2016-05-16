#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main()
{
    DIR *directory;
    char CurrentPath[150], filenamex[50], withpath[200];
    struct dirent *dir2;

    directory = opendir("./");

    if (directory != NULL && getcwd(CurrentPath,sizeof(CurrentPath)) != NULL)
    {
        fprintf(stdout,"\n You are on %s\n The files on the directory is as following \n",getcwd(CurrentPath,sizeof(CurrentPath)));
        while ((dir2 =readdir(directory)) != NULL )
        {
            printf("%s\n", dir2 -> d_name);
        }
        closedir(directory);
    } else {
        perror("could open directory");
        return EXIT_FAILURE;
    }

    printf("please enter name of the file that will be removed\n");
    gets(filenamex);

    while(access(filenamex,0) == -1)
          {
              printf("there is no such a file\nPlease enter something valid\nValid Files are already listed above\n");
              gets(filenamex);

          }
    remove(filenamex);
    printf("Deletion is done!");


}
