#include "readline.h"

int read_line (char *str) {
    // Read line from stdin
    scanf("%[^\n]%*c", str);
    // Check number or not number
    char *pchr = str;

    while(*pchr != '\0')
    {
        if(!isdigit(*pchr)) 
            return false;
        pchr = pchr + 1;
    }
        
    return true;
}
