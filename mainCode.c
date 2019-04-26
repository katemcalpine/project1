/*
 * Encryption/Decryption Program
 * 
 * Created on: 26/04/19
 * Author: Kate McAlpine (c3078083)
 * Class: ENGG1003
 * Lab: EFG14
 */

#include <stdio.h>
#include <string.h>

void rotDecCip(char cipher[]);
void rotDecMsgKey(char message[], char key[]);
void rotEncMsgKey(char message[], char key[]);
void subDecCip(char cipher[]);
void subDecMsgKey(char message[], char key[], const char alphabetEng[]);
void subEncMsgKey(char message[], char key[]); const char alphabetEng[]);

int main()
{
    int input;
    char message[255];
    char key[26];
    char cipher[255];
    const char alphabetEng[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d", &input);
    printf("Task selected: %d\n", input);
    
    switch (input)
    {
        case 1:
            rotDecCip();
            break;
        case 2:
            rotDecMsgKey();
            break;
        case 3:
            rotEncMsgKey();
            break;
        case 4:
            subDecCip();
            break;
        case 5:
            subDecMsgKey();
            break;
        case 6:
            subEncMsgKey();
            break;
        default:
            printf("%d is not an option.\n", input);
    }
}