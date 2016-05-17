void append(char *argv[], int argc);

void insert(char *argv[], int argc);

void destroy(char *filename);

void show(char *filename);

void help();


void help() {
    puts("Usage:");
    puts("-a or --append:");
    puts("\tLinux or Mac:");
    puts("\t\t./iodit filename -a text");
    puts("\tWindows:");
    puts("\t\tiodit.exe filename -a text");
    puts("\tExample: textfile.txt -a hello world");

    puts("-i or --insert:");
    puts("\tLinux or Mac:");
    puts("\t\t./iodit filename -i position text");
    puts("\tWindows:");
    puts("\t\tiodit.exe filename -i position text");
    puts("\tExample: textfile.txt -i 51 hello world");

    puts("-d or --destroy:");
    puts("\tLinux or Mac:");
    puts("\t\t./iodit filename -d");
    puts("\tWindows:");
    puts("\t\tiodit.exe filename -d");

    puts("-s or --show:");
    puts("\tLinux or Mac:");
    puts("\t\t./iodit filename -s");
    puts("\tWindows:");
    puts("\t\tiodit.exe filename -s");
}

void append(char *argv[], int argc) {
    FILE *file;
    char *filename;
    filename = argv[1];
    if (access(filename, 0) == -1)
        {
            printf("%s File does not exist!\n", filename);
        }
        else {
            if (access(filename, 2) != -1){
                file = fopen(filename, "a");
                fprintf(file,"\r\n" );
                for (int e = 3; e < argc ; ++e) { 
                    if (argv[e][0]!='\0'){
                        fprintf(file, "%s ", argv[e]);
                    }
                    else{
                        printf("Text Not Added.\n");
                    }
                }
                if (argc > 3){
                    printf("Text Added Succcessfully.\n");
                }
                else{
                    printf("You have to give argument. More help use -h or --help.\n");
                }
                fclose(file);
            }
            else {
                printf("%s text file does not have the Write Permission!\n", filename);
            }
        }
}

void insert(char *argv[], int argc) {
    FILE *file1, *file2;
    char *filename;
    filename = argv[1];
    int i,r,y,n,index,nl=0;
    int linelength = 0;
    long offset = 0;
    if (access(filename, 0) == -1)
        {
            printf("%s File does not exist!\n", filename);
        }
        else {
            if (access(filename, 2) != -1){
                if (argc > 4){
                    file1 = fopen(filename, "r+");
                    file2 = fopen("newww.txt", "w+");
                    while((r=fgetc(file1))!=EOF)//copying file1 contents into file2 contents
                    {
                        fputc(r,file2);

                        if(r == '\n' && ++nl == atoi(argv[3]) ){
                            offset = ftell ( file1);//save location in file
                            while ( ( r = fgetc ( file1)) != '\n' && r != EOF) {
                                linelength++;//count characters in line
                            }
                            fseek ( file1, offset, SEEK_SET);//seek  back to start of line
                            //get index where to insert text
                            do {
                                printf("Please give index of line (give less than %d):\n", linelength);
                                if ( ( scanf("%d", &index)) != 1) {
                                    scanf ( "%*[^\n]");//input not an integer. clear buffer
                                    index = linelength;
                                }
                            } while ( index >= linelength || index < 0);

                            while ( index) {
                                r = fgetc ( file1);
                                fputc(r,file2);
                                index--;
                            }
                            for (int e = 4; e < argc ; ++e) { 
                                if (argv[e][0]!='\0'){
                                    fprintf(file2, "%s ", argv[e]);
                                }
                                else{
                                    printf("Text Not Added.\n");
                                }
                            }
                        }
                    }
                    fclose(file1);
                    fclose(file2);
                    file1=fopen(filename, "w+");
                    file2=fopen("newww.txt", "r");
                    while((y=fgetc(file2))!=EOF){
                        fputc(y,file1);
                    }
                    fclose(file1);
                    fclose(file2);
                    remove("newww.txt");
                    printf("Text has been inserted successfully.\n");
                }
                else{
                    printf("You have to give argument. More help use -h or --help.\n");
                }
            }
            else {
                printf("%s text file does not have the Write Permission!\n", filename);
            }
        }
}

void destroy(char *filename) {
    FILE *file;
    if (access(filename, 0) == -1)
    {
        printf("%s File does not exist!\n", filename);
    }
    else {
        if (access(filename, 2) != -1)
        {
            file = fopen(filename, "w+");
            fclose(file);
            printf("%s text has been removed successfully!\n", filename);
        }
        else {
            printf("%s text file does not have the Write Permission!\n", filename);
        }
    }
}

void show(char *filename) {
    if (access(filename, 0) == -1) {
        printf("%s File does not exist!\n", filename);
    }
    else {
        FILE *file = fopen(filename, "r");
        if (file == 0) {
            printf("Could not open file\n");
        }
        else {
            int x;
            while ((x = fgetc(file)) != EOF) {
                putchar(x);
            }
            fclose(file);
        }
    }
}
