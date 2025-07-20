#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define uint unsigned int


int main(int argc, char* argv[]){

    if (argc != 2){
        fprintf(stderr, "usage: ./hex_to_b64 hex_str");
        return -1;
    }

    static const unsigned char base64_table[64] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    static const unsigned char hex_table[16] = 
    "0123456789abcde";

    size_t hex_str_len = strlen(argv[1]);

   // Number of 0s to be prepended
    uint num_pad = (3 - (hex_str_len % 3))%3;
    size_t total_len = hex_str_len + num_pad;

    char* hex_str = (char*) malloc(total_len);
    char* b64_str = (char*) malloc((2*(total_len))/3);

    for(uint j = 0; j < num_pad; j++){
        hex_str[j] = (char) 0;   
    }
   
    strncpy(&hex_str[num_pad], argv[1], hex_str_len); 
 
    uint num_steps = (total_len) / 3;

    for (uint j=0; j < num_steps; j++){
        continue;
    }

    
    free(hex_str);
    free(b64_str);
 
    return 0;
}






