#include <stdio.h>

void
simple_cipher(char *s, int len) {
    for(int idx = 0; idx < len; idx++) {
        if(s[idx] == '\0') {
            return;
        } else if(s[idx] >= 'a' && s[idx] <= 'z') {
            s[idx] = (((s[idx] - 'a') + 13) % 26) + 'a';
        }
    }
    return;
}

int
main() {
    char f[16] = "this is a test";
    printf("%s\n", f);
    simple_cipher(f, 16);
    printf("%s\n", f);
    simple_cipher(f, 16);
    printf("%s\n", f);
    return 0;
}
