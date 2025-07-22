#include <string.h>
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char* argv[]){

    if (argc != 3){
        fprintf(stderr, "usage: ./fixed_xor str1 str2\n");
        return -1;
    }

    char hex_charset[16] = "0123456789abcdef";

    if (strlen(argv[1]) != strlen(argv[2])){
        fprintf(stderr, "2 strings must be same length\n");
        return -1;
    }

    for (size_t i = 0; i < strlen(argv[1]); i++){
        unsigned int val1 = (unsigned int) (strchr(hex_charset, argv[1][i]) - hex_charset);
        unsigned int val2 = (unsigned int) (strchr(hex_charset, argv[2][i]) - hex_charset);

        fprintf(stdout, "%c", hex_charset[val1 ^ val2]);
    }

    fprintf(stdout, "\n\nFinished...\n\n");


    return 0;
}







