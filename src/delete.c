#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
void delete()
{
    DIR *directory;
    char CurrentPath[150], filenamex[50], withpath[200];

    if (directory != NULL && getcwd(CurrentPath,sizeof(CurrentPath)) != NULL)
    {
        fprintf(stdout,"\n You are on %s\n The files on the directory is as following \n",getcwd(CurrentPath,sizeof(CurrentPath)));
        
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
        delete();
        return;
    }
  else {
        puts("Please give argument or for usage use -h or --help.");
    }
   return 0;
}