#include <stdio.h>
#include <string.h>

void encryptRotation(char *message, int key);
void decryptRotation(char *message, int key);

int main()
{
    int c;
    char message[100];
    int k;
    
    printf("Please select from the following options by entering the corresponding number (1-6):\n");
    printf("1. Encryption with a rotation cipher, known key\n");
    printf("2. Decryption of a rotation cipher, known key\n");
    printf("3. Encryption with a substituation cipher, known key\n");
    printf("3. Decryption of a substituation cipher, known key\n");
    printf("3. Decryption of a rotation cipher, unknown key\n");
    printf("3. Decryption of a substituation cipher, unknown key\n");
    
    printf("Selection: ");
    scanf("%d", &c);
    
    if (c == 1 || c == 3) {
        printf("Enter message to encode: ");
        scanf(" %[^\n]s", message);
    }
    else {
        printf("Enter message to decode: ");
        scanf(" %[^\n]s", message);
    }
    
    printf("Enter key: ");
    scanf("%d", &k);

    switch(c) {
        case 1: encryptRotation(message, k);
            printf("%s\n", message);
            break;
        case 2: decryptRotation(message, k);
            printf("%s\n", message);
            break;
//        case 3:
//            break;
//        case 4:
//            break;
//        case 5:
//            break;
//        case 6:
//            break;
        default: return 0;
    }
}
    
//    char message[100] = "JASMINE";
//    int index = 0;
//    int key = 4;
//    int length;
//    
//    length = strlen(message);
//    
//    printf("Message to convert to code: %s\n", message);
//    printf("Encoded message: ");
//    while (index < length)
//    {
//        char x = message[index];
//        
//        x = x - key;
//        
//        if (x + key == 32) 
//        {
//            x = x + key;
//        }
//        else if (x >= 65 && x <= 90)
//        {
//            x = x;
//        }
//        else
//        {
//            x = x + 26;
//        }
//        
//        printf("%c", x);
//
//        index++;
//    }
//    
//    
//    return 0;
//}




void encryptRotation(char *message, int key) {
    
    int index = 0;
    int length;
    
    length = strlen(message);
    
    printf("Encoded message: ");
    while (index < length)
    {
        char x = message[index];
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
        
        message[index] = x;

        index++;
    }
    
}


void decryptRotation(char *message, int key) {
        
    int index = 0;
    int length;
    
    length = strlen(message);
    
    printf("Decoded message: ");
    while (index < length)
    {
        char x = message[index];
        x = x + key;
        
        if (x - key == 32) 
        {
            x = x - key;
        }
        else if (x >= 65 && x <= 90)
        {
            x = x;
        }
        else
        {
            x = x - 26;
        }
        
        message[index] = x;

        index++;
    }
    
}

