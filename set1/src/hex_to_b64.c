#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define uint unsigned int


int main(int argc, char* argv[]){

    if (argc != 2){
        fprintf(stderr, "usage: ./hex_to_b64 hex_str");
        return -1;
    }

    static const char base64_table[64] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    static const char hex_table[16] = 
    "0123456789abcdef";

    size_t hex_str_len = strlen(argv[1]);

    // Each hex val is 4 bits, each b64 val is 6 bits
    // b64 string will be 2/3 length of hex string
    // val to val conversion requires hex string len is divisible by 3
    // Number of 0s to be prepended
    uint num_pad = (3 - (hex_str_len % 3))%3;
    size_t total_len = hex_str_len + num_pad;

    char* hex_str = (char*) malloc(total_len);
    char* b64_str = (char*) malloc((2*(total_len))/3);

    for(uint j = 0; j < num_pad; j++){
        hex_str[j] = '0';   
    }
   
    strncpy(&hex_str[num_pad], argv[1], hex_str_len); 
 
    for(size_t t = 0; t < total_len; t++){
        fprintf(stdout, "%c, val: %ld\n", hex_str[t], strchr(hex_table, hex_str[t]) - hex_table);
    } 

    uint num_steps = (total_len) / 3;

    for (uint j=0; j < num_steps; j++){
        //char c1 = hex_str[3*j];
        //char c2 = hex_str[3*j + 1];
        //char c3 = hex_str[3*j + 2];

        uint d1 = (uint) (strchr(hex_table, hex_str[3*j]) - hex_table);
        uint d2 = (uint) (strchr(hex_table, hex_str[3*j + 1]) - hex_table);
        uint d3 = (uint) (strchr(hex_table, hex_str[3*j + 2]) - hex_table);

        uint b64_idx1 = (d1 << 2) | ((d2 & 0b1100) >> 2);
        uint b64_idx2 = (d3) | ((d2 & 0b0011) << 4);
        //fprintf(stdout, "d1: %d d2: %d d3: %d\n", d1, d2, d3);
        //fprintf(stdout, "d1 << 2: %d, (d2 & 0b1100) >> 2: %d\n", d1<<2, (d2 & 0b1100) >> 2); 
        //fprintf(stdout, "b64_idx_1: %d b64_idx_2: %d\n", b64_idx1, b64_idx2);
        b64_str[2*j] = base64_table[b64_idx1];
        b64_str[2*j + 1] = base64_table[b64_idx2];
    }

    fprintf(stdout, "B64 str: %s\n", b64_str);

    free(hex_str);
    free(b64_str);
 
    return 0;
}






