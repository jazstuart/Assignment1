#include <stdio.h>

int main()
{
    char message[100] = "TEST CODE";
    int index=0;
    int value;
    
    while (index < 10) 
    {
        value = message[index];
        printf("%c has an ASCII value of %d\n", message[index], value);
        index++;
    }
    
    
    return 0;
}
