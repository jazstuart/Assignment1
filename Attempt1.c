/*
 * This program allows users to select from 6 options for encrypting or decrypting code using rotation or 
 * substitution ciphers. 
 * The user can select from the tasks by entering a number between 1 and 6 from a menu. The user must then 
 * enter the key if known (as a number between 0 and 25 for the rotation cipher or as a string of letters 
 * for the substitution cipher), and the message to be encoded or decoded. The program will then produce the 
 * encrypted or decrypted message. 
 */

#include <stdio.h>
#include <string.h>

//function prototypes
void encryptRotation(char *message, int key);
void decryptRotation(char *message, int key);
void encryptSubstitution(char *message, char *key);
void decryptSubstitution(char *message, char *key);
void decrytRotationNoKey(char *message);
void decryptSubstitutionNoKey(char *message);

int main()
{
    int c; 
    int k;
    char subKey[27]; //the key for the substitution ciphers, entered as a string of uppercase characters. A length of 27 is needed rather than 26 to account for the null character (\0) at the end of the string.
    char message[1000]; //array for the message to be encoded/decoded. Length must be large enough to ensure the array does not overflow.  
    
    //User friendly menu to describe different options for encryption and decryption
    printf("Please select from the following options by entering the corresponding number (1-6):\n");
    printf("1. Encryption with a rotation cipher, known key\n");
    printf("2. Decryption of a rotation cipher, known key\n");
    printf("3. Encryption with a substituation cipher, known key\n");
    printf("4. Decryption of a substituation cipher, known key\n");
    printf("5. Decryption of a rotation cipher, unknown key\n");
    printf("6. Decryption of a substituation cipher, unknown key\n");
    
    do //Do-while loop is used so that the program asks for at least one selection, and repeats if the selection requirements are not met
    {
        printf("Selection: "); 
        scanf("%d", &c); //Selection must be entered as a number between 1 and 6
        if (c < 1 || c > 6) //Using an if statement means that error message is printed only if the selection (c) is outside the required range
        {
            printf("Error, please enter selection as a number between 1 and 6.\n");
        }
    } while (c < 1 || c > 6); //This condition ensured that if the selection is outside the required conditions (i.e. less than 1 or greater than 6), the loop will repeat and ask for a new selection.
    
    
    
    if (c == 1 || c == 3) //Selections 1 and 3 are for encryption, therefore the program asks for a message to encode
    {
        printf("Enter message to encode: ");
    }
    
    else //All other selections are for decryption
    {
        printf("Enter message to decode: ");
    }
    
    scanf(" %[^\n]", message); //%[^\n] is used so that everything including whitespace is stored, until a \n character is reached
    
    
    //Loop to convert any entered lower case letters into upper case letters
    for (int i = 0; i < strlen(message); i++) //i is the index of message. It must be initialised at 0 since the first element of the array is message[0]. The strlen(message) function returns the length of the array message[].
    {
        char x = message[i];
        
        if (x >= 'a' && x <= 'z') 
        {
            x = x - 32; //ASCII value of upper case letters is 32 less than lower case, therefore minusing 32 converts all lower case to upper case
        }
        
        message[i] = x;
    }

    
    switch(c) //switch case is used to implement the correct function based on the user's selection
    { 
        case 1: printf("Enter key (rotation amount to the right): ");
            scanf("%d", &k); //key must be entered as an integer between 0 and 25, corresponding to the rotation amount to the right. 
            encryptRotation(message, k);
            break;
        case 2: printf("Enter key (rotation amount to the right): ");
            scanf("%d", &k); //same as encryption
            decryptRotation(message, k);
            break;
        case 3: printf("Enter key (string of letters where the first letter is allocated to A, \nthe second letter to B, etc.): ");
            scanf("%s", subKey);
            encryptSubstitution(message, subKey);
            break;
        case 4: printf("Enter key (string of letters where the first letter is allocated to A, \nthe second letter to B, etc.): ");
            scanf("%s", subKey);
            decryptSubstitution(message, subKey);
            break;
        case 5: decrytRotationNoKey(message);
            break;
        case 6: decryptSubstitutionNoKey(message);
            break;
        default: return 0;
    }
    
    
    if (c == 1 || c == 3) 
    {
        printf("\nEncoded message: %s\n", message);
    }
    
    else 
    {
        printf("\nDecoded message: %s\n", message);
    }
    
}
    

/*
 * This function encrypts a message using a rotation cipher. 
 * The inputs are a pointer to the array "message" (the message to be encoded) and an integer key, which is
 * the rotation amount to the right. these are initialised using scanf in main(), then passed to the function. 
 * 
 */
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
    
    for (i = 0; message[i] != '\0'; i++)
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



void decrytRotationNoKey(char *message)
{
    int key = 0;
    char x;
    
    for (key = 0; key < 26; key++)
    {
        int i = 0;
        char trialMessage[1000];
    
        for (i = 0; i < strlen(message); i++)
        {
            x = message[i];
            
            if (x >= 'A' && x <= 'Z')
            {
                x = x + key;
                if (x > 'Z') {
                    x = x - 26;
                }
            }
            trialMessage[i] = x;
        }
        
        char word1[] = " THE ";
        char word2[] = " AND ";
        char word3[] = " BE ";
        char word4[] = " TO ";
        char word5[] = " OF ";
        
        if (strstr(trialMessage, word1) != NULL || strstr(trialMessage, word2) != NULL || strstr(trialMessage, word3) != NULL || strstr(trialMessage, word4) != NULL || strstr(trialMessage, word5) != NULL) 
        {
            for (i = 0; i < strlen(message); i++)
            {
                message[i] = trialMessage[i];
            }

            printf("Key = %d: %s\n", key, trialMessage);
        }    
    }
}



void decryptSubstitutionNoKey(char *message)
{
    int letterFrequency[26];
    
    for (int i = 0; i < 26; i++)
    {
        letterFrequency[i] = 0;
    }
    
    for (int i = 0; i < strlen(message); i++)
    {
        char x = message[i];
        
        switch(x) 
        {
            case 'A': letterFrequency[0]++; break;
            case 'B': letterFrequency[1]++; break;
            case 'C': letterFrequency[2]++; break;
            case 'D': letterFrequency[3]++; break;
            case 'E': letterFrequency[4]++; break;
            case 'F': letterFrequency[5]++; break;
            case 'G': letterFrequency[6]++; break;
            case 'H': letterFrequency[7]++; break;
            case 'I': letterFrequency[8]++; break;
            case 'J': letterFrequency[9]++; break;
            case 'K': letterFrequency[10]++; break;
            case 'L': letterFrequency[11]++; break;
            case 'M': letterFrequency[12]++; break;
            case 'N': letterFrequency[13]++; break;
            case 'O': letterFrequency[14]++; break;
            case 'P': letterFrequency[15]++; break;
            case 'Q': letterFrequency[16]++; break;
            case 'R': letterFrequency[17]++; break;
            case 'S': letterFrequency[18]++; break;
            case 'T': letterFrequency[19]++; break;
            case 'U': letterFrequency[20]++; break;
            case 'V': letterFrequency[21]++; break;
            case 'W': letterFrequency[22]++; break;
            case 'X': letterFrequency[23]++; break;
            case 'Y': letterFrequency[24]++; break;
            case 'Z': letterFrequency[25]++; break;
            default: break;
        }
    }
    
    for (int i = 0; i < 26; i++)
    {
        printf("%d: %d\n", i, letterFrequency[i]);
    }
    
    
    
}

