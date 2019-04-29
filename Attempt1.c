/* This program allows users to select from 6 options for encrypting or decrypting code using rotation or 
 * substitution ciphers. 
 * A rotation cipher (also called a caesar cipher) is a simple method of encryption where each letter is 
 * substituted with a letter shifted a fixed number of positions down the alphabet. For example, a shift 
 * (referred to as the key) of 1 to the right would mean that A is replaced with Z, B is replaced with A, 
 * C is replaced with B, etc.
 * A substitution cipher is a method of encryption where every leter of the alphabet is replaced with another
 * unique letter. A rotation cipher is a simple type of substitution cipher. 
 * The user can select from differen tasks, as explained in the menu printed to stdin, by entering a number 
 * between 1 and 6 from a menu. The user must then enter the message to be encoded or decoded, and the key if 
 * known (as a number between 0 and 25 for the rotation cipher or as a string of letters for the substitution 
 * cipher). The program will then produce the encrypted or decrypted message and print it to stdout.
 * Limitation: the message has a maximum length of 1000 characters
 * 
 * Basic flow control for the program: First the program asks the user to select from a menu of tasks. This 
 * is placed inside a "do-while" loop so that the user is asked to enter another selection if their first 
 * selection was not iside the required range. There is a separate function for each task. In main, a switch 
 * case is used to control which function is executed, based on the user's selection. Flow control is also 
 * used inside the functions, mainly "for" loops to increment the index of the array "message" to encrypt 
 * each letter individually, and "if" statements to ensure only letters are encrypted. More detailed 
 * explanations are included throughout the program.
 */

#include <stdio.h>
#include <string.h>

//function prototypes
void encryptRotation(char *message, int key);
void decryptRotation(char *message, int key);
void encryptSubstitution(char *message, const char *key);
void decryptSubstitution(char *message, const char *key);
void decrytRotationNoKey(char *message);
void decryptSubstitutionNoKey(char *message);

int main()
{
    int c; //user task selection
    int k; //key for rotation ciphers, integer between 0 and 25
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
    //the name of an array without an index is a pointer to that array, therefore no & is needed. The string entered by the user is stored in the memory location for message[]. 
    
    
    //Loop to convert any entered lower case letters into upper case letters
    for (int i = 0; i < strlen(message); i++) //i is the index of message. It must be initialised at 0 since the first element of the array is message[0]. The strlen(message) function returns the length of the array message[].
    {
        char x = message[i]; //message[i] is assigned to x simply so it doesn't need to be written out as many times. 
        
        if (x >= 'a' && x <= 'z') 
        {
            x = x - 32; //ASCII value of upper case letters is 32 less than lower case, therefore minusing 32 converts all lower case to upper case
        }
        
        message[i] = x;
    }

    
    switch(c) //switch case is used to implement the correct function based on the user's selection
    { 
        case 1: printf("Enter key (rotation amount of the cipher text to the right): ");
            scanf("%d", &k); //key must be entered as an integer between 0 and 25, corresponding to the rotation amount to the right. 
            encryptRotation(message, k); //a pointer to "message" and the rotation key are passed as arguments to the function. This modifies "message" to produce the encrypted message. 
            printf("\nEncoded message: %s\n", message);
            break;
        case 2: printf("Enter key (rotation amount of the cipher text to the right): ");
            scanf("%d", &k); //same as encryption
            decryptRotation(message, k); //same as encryption
            printf("\nDecoded message: %s\n", message);
            break;
        case 3: printf("Enter key (string of letters where the first letter is allocated to A, \nthe second letter to B, etc.): ");
            scanf("%s", subKey); //key is entered as a string therefore %s is used. This is stored in the array subKey[], as explained previously the array name is a pointer to that array.
            encryptSubstitution(message, subKey); //a pointer to the array "message" and "subKey" are passed to the function. "message" is modified to produce the encrypted message, subKey is not modified. 
            printf("\nEncoded message: %s\n", message);
            break;
        case 4: printf("Enter key (string of letters where the first letter is allocated to A, \nthe second letter to B, etc.): ");
            scanf("%s", subKey); //same as encryption
            decryptSubstitution(message, subKey); //same as encryption
            printf("\nDecoded message: %s\n", message);
            break;
        case 5: decrytRotationNoKey(message); //no key is needed, only the pointer to "message" is passed to the function.
            printf("\nDecoded message: %s\n", message);
            break;
        case 6: decryptSubstitutionNoKey(message);
            printf("\nDecoded message: %s\n", message);
            break;
        default: return 0;
    }
}
    

/* This function encrypts a message using a rotation cipher. 
 * The inputs are a pointer to the array "message[]" (the message to be encoded) and a key, which is
 * an integer giving the rotation amount to the right of the cipher text. These are initialised from 
 * stdin in main(), then passed to the function. Only letters are encrypted; numbers, symbols and 
 * whitespece are copied straight to stdout. 
 * By using a pointer to message as one of the function arguments, the function directly modifies the 
 * message at its memory location, therefore no return value is needed. 
 */
void encryptRotation(char *message, int key) 
{    
    int i = 0; //i is the index of message[]
    
    for (i = 0; i < strlen(message); i++) //initialises i = 0 to start at the first element of the array, message[0]. i is incremented while it is less than the length of "message", so that every letter is encrypted.
    {
        char x = message[i];
        
        if (x >= 'A' && x <= 'Z') //only letters are encrypted; numbers, symbols and whitespace are unmodified
        {
            x = x - key; //by minusing the key, the alphabet for the cipher text is shifted 1 place to the right
            
            if (x < 'A') //if the ASCII value falls below 65 (the value for A), a symbol will be produced so 26 is added to make it rotate back to the end of the alphabet
            {
                x = x + 26; 
            }
        }
        
        message[i] = x; //message has now been modified at its memory location, so no return value is needed.
    }
}


/* This function works identically to encryptRotation, however the key is added instead of minused. 
 * In this case "message" is the cipher text and the function produces the plain text which is printed to stdout.
 */
 
void decryptRotation(char *message, int key) 
{
    int i = 0;
    
    for (i = 0; i < strlen(message); i++)
    {
        char x = message[i];
                
        if (x >= 'A' && x <= 'Z')
        {
            x = x + key; //this time the key is added to reverse the encryption
            
            if (x > 'Z') //if the ASCII value is above 90 (the value for Z), a symbol will be produced so 26 is added to make the alphabet rotate back around
            {
                x = x - 26;
            }
        }
        
        message[i] = x;
    }
    
}



/* This function encrypts a message using a substitution cipher with a key entered by the user. 
 * The inputs are a pointer to the array "message[]" (the message to be encoded) and a pointer to the array 
 * "key[]", which is the string of letters to be substituted for the ciphertext. Similarly to the rotation
 * ciphers, these are initialised from stdin in main(), then passed to the function, and only letters are 
 * encrypted.
 * "message" is modified at its memory location to produce the encrypted text, however the key is not 
 * modified therefore it has the datatype const char. The function has no return value. 
 */
void encryptSubstitution(char *message, const char *key) 
{
    int i = 0; //index 
    
    for (i = 0; i < strlen(message); i++) 
    {
        char x = message[i]; 
        if (x >= 'A' && x <= 'Z')
        {
            x = key[x - 'A']; //if x = A, it needs to be converted to key[0], as "key" is a string of letters where the first letter is allocated to A, the second letter to B, etc. Therefore key[x - 'A'] means that the correct element of key is assigned to x.
        }

        message[i] = x;
    }
}


/* This function decrypts a message using a substitution cipher with a key entered by the user. 
 * The inputs are the same as encryptSubstitution. 
 * 
 */
void decryptSubstitution(char *message, const char *key)
{
    int i = 0;
    int j = 0;
    
    for (i = 0; message[i] != '\0'; i++) //the condition is while message[i] is not equal to the terminating 0, therefore the loop exits once it reaches the end of the message.
    {
        char x = message[i];
        if (x >= 'A' && x <= 'Z')
        {
            for (j = 0; j < 26; j++) //this loop cycles through j, which is used as the index of key. The index of key will tell us which letter of the alphabet the ciphertext letter corresponds to. 
            {
                if (message[i] == key[j]) //loop cycles through j until the letters of "message" and "key" are the same. The loop then breaks, so that the value of j remains at the value of the index of "key" when it was equal to "message"
                {
                    break; //EXAMPLE: if message[i] was equal to 'A', j would be incremented until key[j] = 'A'. j will now tell us the how far along the key the ciphertext letter is, giving the plaintext letter it was assigned to. 
                }
            } 
            
            message[i] = 'A' + j; //j is the index of key, therefore adding it to 'A' reverses the encryption. 
            //EXAMPLE: if j = 5, then the character of message[i] was the 6th letter along in the key. This means it would have been assigned to the 6th letter of the alphabet, 'F'. By adding j to 'A', we get the ASCII value of 'A' + 6 which corresponds to 'F'.
        }   
    }
}


/*
 * This function decrypts a rotation cipher when the key is unknown. 
 * Therefore the only input is the message, since the key is unknown and therefore can't be an input. 
 * This function produces the most likely solution by calculating all 26 possible rotations then testing for
 * the 5 most common english words. All 26 possible rotations are printed to stdout as a backup in case 
 * none of the common words match, and the user can read through all possiblilities to manually find the one 
 * which makes sense. 
 */
void decrytRotationNoKey(char *message)
{
    int key = 0; //key is the rotation amount
    char x;
    
    for (key = 0; key < 26; key++) //cycles through every possible key from 0 to 25, finding trialMessage and testing if it contains the common words
    {
        int i = 0; 
        char trialMessage[1000]; //trialMessage is the array which is modified for all possible rotations, so that message is not modified until the most likely solution is found.
        for (int i = 0; i < 1000; i++) //sets all elements of trialMessage to '\0' so that all previous values are cleared
        {
            trialMessage[i] = '\0';
        }
        
        for (i = 0; i < strlen(message); i++)
        {
            x = message[i];
            
            if (x >= 'A' && x <= 'Z') //same as decryption when the key is known
            {
                x = x + key; 
                if (x > 'Z') {
                    x = x - 26; 
                }
            }
            trialMessage[i] = x; //trialMessage becomes x, which is the possible decrypted message
        }
        
        char word1[] = " THE "; //these are the 5 most common english words. 
        char word2[] = " AND "; //spaces are included before and after to ensure these words are tested by themselves, rather than as part of words (eg. "other")
        char word3[] = " BE ";
        char word4[] = " TO ";
        char word5[] = " OF ";
        
        //strstr(string1, string2) function tests if string2 is a substring of string1. If it is not equal to NULL, it means there is a match. If any of these words match it is likely to be the correct solution.
        if (strstr(trialMessage, word1) != NULL || strstr(trialMessage, word2) != NULL || strstr(trialMessage, word3) != NULL || strstr(trialMessage, word4) != NULL || strstr(trialMessage, word5) != NULL) 
        {
            for (i = 0; i < strlen(message); i++) 
            {
                message[i] = trialMessage[i]; //if any of the words match it is likely to be the correct soltuion, therefore message is modified to become trialMessage, so it can be printed in the switch case in main.
            }
        }
        
        printf("Key = %d: %s\n", key, trialMessage); //trialMessage is printed for every key in case no message contains the common words
    }
}



void decryptSubstitutionNoKey(char *message)
{
    int letterFrequency[26]; //array to store the frequency of each letter in the ciphertext to be decrypted
    //char commonLetters[27] = "ETAOINSHRDLUCMFWYGPBVKQJXZ"; //{'E', 'T', 'A', 'O', 'I', 'N', 'S', 'H', 'R', 'D', 'L', 'U', }
    //char trialMessage[1000];
    
    for (int i = 0; i < 26; i++)
    {
        letterFrequency[i] = 0; //initialises each element of the array to 0
    }
    
    
    for (int i = 0; message[i] != '\0'; i++) //sycles through each letter of the message and increments letterFrequency, corresponding to its place in the alphabet.
    {
        switch(message[i]) 
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
        char c = i + 'A'; 
        printf("%c: %d\n", c, letterFrequency[i]);
        //trialMessage[i] = letterFrequency[i];
    }
    
    char k = 0;
    char max = letterFrequency[(int)k];
    
    for (int i = 0; i < 26; ++i)
    {
        if (letterFrequency[i] > max)
        {
            max = (int)letterFrequency[i];
            k = i;
        }
    }
    
    printf("Most common letter: %c\n", k + 65);
    
    printf("Second most common letter: F\nThird most common letter: H");
    
}

