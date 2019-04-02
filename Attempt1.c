#include <stdio.h>

int main()
{
    
    
    char message[100] = "JASMINE";
    int index = 0;
    //int value;
    int key = 4;
    
    printf("Message to convert to code: %s\n", message);
    printf("Encoded message: ");
    while (index < 9)
    {
        char x = message[index];
        //value = x;
        //printf("%c has an ASCII value of %d\n", x, value);
        
        x = x - key;
        
        if (x + key == 32) 
        {
            x = x + key;
        }
        else if (x >= 65 && x <= 90)
        {
            x = x;
        }
        else
        {
            x = x + 26;
        }
        
        //printf("Encoded character is %c\n", x);
        printf("%c", x);

        index++;
    }
    
    
    return 0;
}
