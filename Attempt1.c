

#include <stdio.h>
#include <string.h>

//function prototypes
void encryptRotation(char *message, int key);
void decryptRotation(char *message, int key);
void encryptSubstitution(char *message, char *key);
void decryptSubstitution(char *message, char *key);

int main()
{
    int c; 
    int k;
    char subKey[27]; //the key for the substitution ciphers, entered as a string of uppercase characters. A length of 27 is needed rather than 26 to account for the null character (\0) at the end of the string.
    char message[500]; //array for the message to be encoded/decoded. Length must be large enough to ensure the array does not overflow.  
    
    //User friendly menu to describe different options for encryption and decryption
    printf("Please select from the following options by entering the corresponding number (1-6):\n");
    printf("1. Encryption with a rotation cipher, known key\n");
    printf("2. Decryption of a rotation cipher, known key\n");
    printf("3. Encryption with a substituation cipher, known key\n");
    printf("4. Decryption of a substituation cipher, known key\n");
    printf("5. Decryption of a rotation cipher, unknown key\n");
    printf("6. Decryption of a substituation cipher, unknown key\n");
    
    do //do-while loop is used so that the program asks for at least one selection, and repeats if the selection requirements are not met
    {
        printf("Selection: "); 
        scanf("%d", &c); //selection must be entered as a number between 1 and 6
        if (c < 1 || c > 6) //Using an if statement means that error message is printed only if the selection (c) is outside the required range
        {
            printf("Error, please enter selection as a number between 1 and 6.\n");
        }
    } while (c < 1 || c > 6);
    
    
    if (c == 1 || c == 2) //menu items 1 and 2 correspond to rotation cipher decryption or decryption, therefore an integer key is only asked for if the user selects one of these menu items
    {
        printf("\nEnter key (rotation amount to the right): ");
        scanf("%d", &k); //key must be entered as an integer between 0 and 25, corresponding to the rotation amount to the right. 
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
    int j = 0;
    
    for (i = 0; i < strlen(message); i++)
    {
        char x = message[i];
        if (x >= 'A' && x <= 'Z')
        {
            for (j = 0; j < 27; j++)
            {
                if (message[i] == key[j])
                {
                    break;
                }
            } 
            
            message[i] = 'A' + j;
        }   
    }
}


