void append(char *filename);

void insert(char *filename);

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

void append(char *filename) {

}

void insert(char *filename) {

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
            printf("%s's text has been removed successfully!\n", filename);
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
