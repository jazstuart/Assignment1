#include <stdio.h>

int main()
{
    const char message[26] = "hello";
    char c;
    
    scanf("%c", &c);
    printf("%c\n", c);
    
    printf("%c\n", message[0]);
    printf("%s\n", message);
    
    return 0;
}
