#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void help(){
    puts("By this function, you will be able to create a file in your current path or in a given path. Usage: After calling the function you will be asked the file name. If you write a name with extension as following 'example.txt', the file will be created your current path. If you write 'C:\\users\\opsys\\desktop\\example.txt', the file will be created at given path. To create a file, there has not to be a file in that name at that path.");
}

void create()
{
    DIR *directory;
    char CurrentPath[150], filenamex[50], withpath[200];

    directory = opendir("./");
    if (directory != NULL && getcwd(CurrentPath, sizeof(CurrentPath)) != NULL)
    {
        fprintf(stdout, "\n Your current directory is: %s \n", getcwd(CurrentPath, sizeof(CurrentPath)));
        closedir(directory);
    }

    FILE *filename;
    printf("Enter File Name to create\n");
    gets(filenamex);
    if (filenamex == "\n" )
    {
        printf("enter something that is valid");
    }
    sprintf(withpath,"&s&s",CurrentPath,filenamex);

    while(access(withpath,0) != -1)//dneeme
        {
            printf("the word you entered is existing. please enter something that doesnt exist\n");
            gets(filenamex);
            sprintf(withpath,"&s&s",CurrentPath,filenamex);
        }

    if (access(withpath,0) == -1)
    {
        filename = fopen(filenamex,"w");
        fclose(filename);
        printf("You are done with creating the file!");
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
        create();
        return;
    }
  else {
        puts("Please give argument or for usage use -h or --help.");
    }
   return 0;
}