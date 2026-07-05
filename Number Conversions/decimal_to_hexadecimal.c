//write a code block that reads a file then turn that to a function


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(type) \
    type type##_max(type x, type y) \
    { return x>y ? x:y;}


char * decimal_to_hexadecimal(unsigned int dmal) {

    char hexaDecimal[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char *hDmal;

    hDmal = malloc(sizeof(char) * 1);

    int i=0;
    while (dmal>0) {
        int qt;
        qt = dmal%16;
        hDmal[i] = hexaDecimal[qt];
        dmal /= 16;

        char *temp = realloc(hDmal, sizeof(char) * (i+2));
        if (temp == NULL) {
            fprintf(stderr,"Error: realloc decimal to hexadec");
            free(hDmal);
            exit(1);
        }
        hDmal = temp;

        i++;
    }


    if (i==0) {
        char *temp = realloc(hDmal, sizeof(char) * (i+2));
        if (temp == NULL) {
            fprintf(stderr,"Error: realloc decimal to hexadec");
            exit(1);
        }
        hDmal = temp;
        hDmal[i] = '0';
        i++;
    }

    hDmal[i]='\0';

    char *rev_hDmal;
    size_t len = strlen(hDmal);
    size_t init = 0;

    rev_hDmal = malloc(sizeof(char) * (i+1));

    while (init<len) {

        rev_hDmal[init] = hDmal[i - 1];

        i--;
        init++;
    }
    rev_hDmal[init] = '\0';

    free(hDmal);
    return rev_hDmal;
}

//Knowing max 33

char *st_decimal_to_hexadecimal(unsigned int dmal) {

    char hexaDecimal[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char hDmal[33];

    int i=0;
    while (dmal>0) {
        int qt;
        qt = dmal%16;
        hDmal[i] = hexaDecimal[qt];
        dmal /= 16;
        i++;
    }

    if (i==0) {
        hDmal[i] = '0';
        i++;
    }

    hDmal[i]='\0';

    char *rev_hDmal;
    size_t len = strlen(hDmal);
    size_t init = 0;

    rev_hDmal = malloc(sizeof(char) * (i+1));

    while (init<i) {

        rev_hDmal[init] = hDmal[len - 1];

        len--;
        init++;
    }
    rev_hDmal[init] = '\0';

    return rev_hDmal;
}



int main() {

    char *aa;

    // 20 integer test cases for hexadecimal conversion
    int testCase[20] = {
        0,          // Zero boundary
        1,          // Single digit
        9,          // Last single decimal digit
        10,         // First 'A' in hex
        15,         // Last single-digit hex (F)
        16,         // First two-digit hex (10)
        255,        // Max 8-bit / one byte (FF)
        256,        // 9-bit boundary (100)
        1023,       // 3FF
        4095,       // FFF
        4096,       // 1000
        32767,      // Max positive signed 16-bit short (7FFF)
        65535,      // Max unsigned 16-bit (FFFF)
        16777215,   // Max 24-bit RGB style (FFFFFF)
        2147483647, // Max positive signed 32-bit int (7FFFFFFF)
        -1,         // Negative boundary (typically FFFFFFFF in two's complement)
        -15,        // Negative single-digit hex equivalent
        -256,       // Negative multi-byte boundary
        -2147483648,// Min negative signed 32-bit int (80000000)
        12345678    // Arbitrary random large pattern (BC614E)
    };

    for (int i = 0; i < 20; ++i) {
        aa = st_decimal_to_hexadecimal(testCase[i]);
        printf("%s  ", aa);
        free(aa);
    }

}
