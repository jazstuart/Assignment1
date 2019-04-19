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
    }
    
    else 
    {
        printf("\nEnter message to decode: ");
    }
    
    scanf(" %[^\n]s", message);
    
    
    int length;
    length = strlen(message);
    
    
    for (int index = 0; index < length; index++)
    {
        char x = message[index];
        
        if (x >= 97 && x <= 122)
        {
            x = x - 32;
        }
        
        message[index] = x;
    }

    
    switch(c) {
        case 1: encryptRotation(message, k);
            printf("Encoded message: %s\n", message);
            break;
        case 2: decryptRotation(message, k);
            printf("Decoded message: %s\n", message);
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
    char y;
    
    length = strlen(message);
    
//    case 'A': printf("%c: ", x);
//                scanf("%c", &y);
//                break;
    
    while (index < length)
    {
        char x = message[index];
        switch(x) 
        {
            case 'A': y = 'Q'; break;
            case 'B': y = 'W'; break;
            case 'C': y = 'E'; break;
            case 'D': y = 'R'; break;
            case 'E': y = 'T'; break;
            case 'F': y = 'Y'; break;
            case 'G': y = 'U'; break;
            case 'H': y = 'I'; break;
            case 'I': y = 'O'; break;
            case 'J': y = 'P'; break;
            case 'K': y = 'A'; break;
            case 'L': y = 'S'; break;
            case 'M': y = 'D'; break;
            case 'N': y = 'F'; break;
            case 'O': y = 'G'; break;
            case 'P': y = 'H'; break;
            case 'Q': y = 'J'; break;
            case 'R': y = 'K'; break;
            case 'S': y = 'L'; break;
            case 'T': y = 'Z'; break;
            case 'U': y = 'X'; break;
            case 'V': y = 'C'; break;
            case 'W': y = 'V'; break;
            case 'X': y = 'B'; break;
            case 'Y': y = 'N'; break;
            case 'Z': y = 'M'; break;
            default: y = x;
        }
        
        message[index] = y;
        index++;
    }

}
