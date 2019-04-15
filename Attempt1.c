#include <stdio.h>
#include <string.h>

void encryptRotation(char *message, int key);
void decryptRotation(char *message, int key);
void encryptSubstitution(char *message);

int main()
{
    int c;
    char *message;
    int k;
    
    printf("Please select from the following options by entering the corresponding number (1-6):\n");
    printf("1. Encryption with a rotation cipher, known key\n");
    printf("2. Decryption of a rotation cipher, known key\n");
    printf("3. Encryption with a substituation cipher, known key\n");
    printf("3. Decryption of a substituation cipher, known key\n");
    printf("3. Decryption of a rotation cipher, unknown key\n");
    printf("3. Decryption of a substituation cipher, unknown key\n");
    
    do 
    {
        printf("Selection: ");
        scanf("%d", &c);
        if (c < 1 || c > 6) 
        {
            printf("Error, please enter selection as a number between 1 and 6.\n");
        }
    } while (c < 1 || c > 6);
    
    
    if (c == 1 || c == 2) 
    {
        printf("\nEnter key (rotation amount): ");
        scanf("%d", &k);
    }
    
    
    if (c == 1 || c == 3) 
    {
        printf("\nEnter message to encode: ");
        scanf(" %[^\n]s", message);
    }
    
    else 
    {
        printf("\nEnter message to decode: ");
        scanf(" %[^\n]s", message);
    }
    
    
    switch(c) {
        case 1: encryptRotation(message, k);
            printf("%s\n", message);
            break;
        case 2: decryptRotation(message, k);
            printf("%s\n", message);
            break;
        case 3: encryptSubstitution(message);
            printf("Encoded message: %s\n", message);
            break;
//        case 4:
//            break;
//        case 5:
//            break;
//        case 6:
//            break;
        default: return 0;
    }
}
    


void encryptRotation(char *message, int key) 
{    
    int index = 0;
    int length;
    
    length = strlen(message);
    
    printf("\nEncoded message: ");
    while (index < length)
    {
        char x = message[index];
        
        if (x >= 65 && x <= 90)
        {
            x = x - key;
            if (x < 65) {
                x = x + 26;
            }
        }
        
        
        message[index] = x;

        index++;
    }
    
}



void decryptRotation(char *message, int key) 
{
    int index = 0;
    int length;
    
    length = strlen(message);
    
    printf("\nDecoded message: ");
    while (index < length)
    {
        char x = message[index];
                
        if (x >= 65 && x <= 90)
        {
            x = x + key;
            if (x > 90) {
                x = x - 26;
            }
        }
        
        message[index] = x;

        index++;
    }
    
}



void encryptSubstitution(char *message) 
{
    int index = 0;
    int length;
    
    length = strlen(message);
    char x = message[index];
    
    while (index < length)
    {
        switch(x) 
        {
            case 65: x = 66; break;
            case 66: x = 65; break;
            case 67: x = 68; break;
            case 68: x = 67; break;
            default: x = x;
        }
        
        message[index] = x;
        index++;
    }

}
