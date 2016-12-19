#include <stdio.h>
#include <stdlib.h>

void generate_key(char *, int);
void encrypt(char *, const char *, int, int);
void eprint(const char *, int);

int
main() {
    char key[16] = {0},
         t0[9] = "password",
         t1[9] = "bookword";
    generate_key(key, 16);
    encrypt(t0, key, 8, 16);
    encrypt(t1, key, 8, 16);
    printf("key: %s\n", key);
    eprint(t0, 8);
    eprint(t1, 8);
}

void
generate_key(char *dst, int len) {
    int idx = 0, dice = 0;
    char src[36] = "abcdefghijklmnopqrstuvwxyz0123456789";
    for(; idx < len; idx++) {
        dice = arc4random_uniform(len);
        dst[idx] = src[dice % 36];
    }
}

void
encrypt(char *dst, const char *key, int len, int keylen) {
    for(int idx = 0; idx < len; idx++) {
        dst[idx] = dst[idx] ^ key[idx % keylen];
    }
}

void
eprint(const char *ciphertext, int len) {
    for(int idx = 0; idx < len; idx ++) {
        printf("%2.2x ", ciphertext[idx]); 
    }
    printf("\n");
}
