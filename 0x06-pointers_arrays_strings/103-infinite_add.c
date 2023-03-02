#include "main.h"
#include <string.h>

char* infinite_add(char* n1, char* n2, char* r, int size_r) {
    int len1 = strlen(n1), len2 = strlen(n2);
    int carry = 0, sum = 0, max_len = len1 > len2 ? len1 : len2;
    
    if (max_len + 1 > size_r) return 0; // check if result fits in r
    
    r[max_len + 1] = '\0'; // add terminating null character
    for (int i = 1; i <= max_len; i++) {
        int digit1 = (i <= len1) ? n1[len1 - i] - '0' : 0;
        int digit2 = (i <= len2) ? n2[len2 - i] - '0' : 0;
        sum = digit1 + digit2 + carry;
        carry = sum / 10;
        r[max_len + 1 - i] = (sum % 10) + '0';
    }
    if (carry == 0) {
        // no more carry, remove leading zero
        memmove(r, r + 1, max_len + 1);
        return r;
    }
    else if (max_len + 2 > size_r) {
        // carry overflows r, cannot store result
        return 0;
    }
    else {
        // add carry as leading digit
        r[0] = carry + '0';
        return r;
    }
}

