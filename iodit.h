void append();
void insert();
void destroy();
void show();
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

void show(char *filename) {
	// We assume argv[1] is a filename to open
        FILE *file = fopen( filename, "r" );

        /* fopen returns 0, the NULL pointer, on failure */
        if ( file == 0 )
        {
            printf( "Could not open file\n" );
        }
        else 
        {
            int x;
            /* read one character at a time from file, stopping at EOF, which
               indicates the end of the file.  Note that the idiom of "assign
               to a variable, check the value" used below works because
               the assignment statement evaluates to the value assigned. */
            while  ( ( x = fgetc( file ) ) != EOF )
            {
                printf( "%c", x );
            }
            fclose( file );
        }
}