#include <stdio.h>
#include <string.h>
#include "iodit.h"

void main(int argc, char *argv[]) {
	if  (argc > 1) {
	    for (int i = 1; i < argc; ++i) {
	        if(strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
	            help();
	            return;
	        }
	        else if(strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "--append") == 0) {
	            // append(argv[1]);
	            return;
	        }
	        else if(strcmp(argv[i], "-i") == 0 || strcmp(argv[i], "--insert") == 0) {
	            puts("insert command");
	            return;
	        }
	        else if(strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--destroy") == 0) {
	            puts("destroy command");
	            return;
	        }
	        else if(strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--show") == 0) {
	            show(argv[1]);
	            return;
	        }
	    }
   	    puts("Unsupported argument. Please use -h or --help for usage.");
	}
	else {
		puts("Please give argument or for usage use -h or --help.");
	}
}