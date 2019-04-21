#include <stdio.h>
#include <string.h>

void encryptRotation(char *message, int key);
void decryptRotation(char *message, int key);
void encryptSubstitution(char *message, char *key);
void decryptSubstitution(char *message, char *key);

int main()
{
    int c;
    int k;
    char subKey[27];
    char message[81];
    
    printf("Please select from the following options by entering the corresponding number (1-6):\n");
    printf("1. Encryption with a rotation cipher, known key\n");
    printf("2. Decryption of a rotation cipher, known key\n");
    printf("3. Encryption with a substituation cipher, known key\n");
    printf("4. Decryption of a substituation cipher, known key\n");
    printf("5. Decryption of a rotation cipher, unknown key\n");
    printf("6. Decryption of a substituation cipher, unknown key\n");
    
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
        printf("\nEnter key (rotation amount to the right): ");
        scanf("%d", &k);
    }
    else if (c == 3 || c == 4)
    {
        printf("Enter key (string of letters where the first letter is allocated to A, \nthe second letter to B, etc.): ");
        scanf("%s", subKey);
    }
    
    
    if (c == 1 || c == 3) 
    {
        printf("\nEnter message to encode: ");
    }
    
    else 
    {
        printf("\nEnter message to decode: ");
    }
    
    scanf(" %[^\n]", message);
    
    
    int length;
    length = strlen(message);
    
    
    for (int i = 0; i < length; i++)
    {
        char x = message[i];
        
        if (x >= 'a' && x <= 'z')
        {
            x = x - 32;
        }
        
        message[i] = x;
    }

    
    switch(c) {
        case 1: encryptRotation(message, k);
            break;
        case 2: decryptRotation(message, k);
            break;
        case 3: encryptSubstitution(message, subKey);
            break;
        case 4: decryptSubstitution(message, subKey);
            break;
//        case 5:
//            break;
//        case 6:
//            break;
        default: return 0;
    }
    
    
    if (c == 1 || c == 3) 
    {
        printf("Encoded message: %s\n", message);
    }
    
    else 
    {
        printf("Decoded message: %s\n", message);
    }
    
}
    


void encryptRotation(char *message, int key) 
{    
    int i = 0;
    
    for (i = 0; i < strlen(message); i++)
    {
        char x = message[i];
        
        if (x >= 'A' && x <= 'Z')
        {
            x = x - key;
            if (x < 'A') {
                x = x + 26;
            }
        }
        
        message[i] = x;
    }
    
}



void decryptRotation(char *message, int key) 
{
    int i = 0;
    
    for (i = 0; i < strlen(message); i++)
    {
        char x = message[i];
                
        if (x >= 'A' && x <= 'Z')
        {
            x = x + key;
            if (x > 'Z') {
                x = x - 26;
            }
        }
        
        message[i] = x;
    }
    
}



void encryptSubstitution(char *message, char *key) 
{
    int i = 0;
    
    for (i = 0; i < strlen(message); i++)
    {
        char x = message[i];
        if (x >= 'A' && x <= 'Z')
        {
            x = key[x - 'A'];
        }

        message[i] = x;
    }
}



void decryptSubstitution(char *message, char *key)
{
    int i = 0;
    
    for (i = 0; i < strlen(message); i++)
    {
        char x = message[i];
        if (x >= 'A' && x <= 'Z')
        {
            x = ;
        }
    }
}


