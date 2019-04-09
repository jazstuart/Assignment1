#include <stdio.h>
#include <string.h>

//char encryptRotation(char message, int key);

int main()
{
//    char c=1;
//    char message[100];
//    
//    printf("Please select from the following options by entering the corresponding number (1-6):\n");
//    printf("1. Encryption with a rotation cipher, known key\n");
//    printf("2. Decryption of a rotation cipher, known key\n");
//    printf("3. Encryption with a substituation cipher, known key\n");
//    printf("3. Decryption of a substituation cipher, known key\n");
//    printf("3. Decryption of a rotation cipher, unknown key\n");
//    printf("3. Decryption of a substituation cipher, unknown key\n");
//    
//    //scanf("%c", &c);
//    
//    if (c == 1 || c == 3) {
//        printf("Enter message to encode: ");
//        printf("%s", message);
//    }
//    else {
//        printf("Enter message to decode: ");
//        scanf("%s", message);
//    }
//
//    switch(c) {
//        case 1: encryptRotation(message, c);
//            break;
////        case 2: 
////            break;
////        case 3:
////            break;
////        case 4:
////            break;
////        case 5:
////            break;
////        case 6:
////            break;
//        default: return 0;
//    }

    
    char message[100] = "JASMINE";
    int index = 0;
    int key = 4;
    int length;
    
    length = strlen(message);
    
    printf("Message to convert to code: %s\n", message);
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
        
        printf("%c", x);

        index++;
    }
    
    
    return 0;
}




//char encryptRotation(char message, int key) {
//    
//}
