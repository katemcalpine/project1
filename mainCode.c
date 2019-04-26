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
void rotDecCipKey(char message[], char key[]);
void rotEncMsgKey(char message[], char key[]);
void subDecCip(char cipher[]);
void subDecCipKey(char message[], char key[], const char alphabetEng[]);
void subEncMsgKey(char message[], char key[], const char alphabetEng[]);

int main()
{
    int input;
    char message[255];
    char key[26];
    char cipher[255];
    const char alphabetEng[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d", &input);
    //printf("Task selected: %d\n", input);
    
    switch (input)
    {
        case 1:
            printf("Rotation Decryption Using Only Cipher\n\n");
            rotDecCip(cipher);
            break;
        case 2:
            printf("Rotation Decryption Using Cipher and Key\n\n");
            rotDecCipKey(cipher, key);
            break;
        case 3:
            printf("Rotation Encryption Using Message and Key\n\n");
            rotEncMsgKey(message, key);
            break;
        case 4:
            printf("Sustitution Decryption Using Only Cipher\n\n");
            subDecCip(cipher);
            break;
        case 5:
            printf("Substitution Decryption Using Cipher and Key\n\n");
            subDecCipKey(cipher, key, alphabetEng);
            break;
        case 6:
            printf("Substitution Encryption Using Message and Key\n\n");
            subEncMsgKey(message, key, alphabetEng);
            break;
        default:
            printf("%d is not an option.\n", input);
    }
    return 0;
}

void rotDecCip(char cipher[])
{
    FILE *input;
    input = fopen("rotation", "r");
    if(input == NULL)
    {
        perror("fopen()");
        return;
    }
    else
    {
        
    }
}

void rotDecCipKey(char message[], char key[])
{
    FILE *input;
    input = fopen("rotation", "r");
    if(input == NULL)
    {
        perror("fopen()");
        return;
    }
}

void rotEncMsgKey(char message[], char key[])
{
    FILE *input;
    input = fopen("rotation", "r");
    if(input == NULL)
    {
        perror("fopen()");
        return;
    } 
}

void subDecCip(char cipher[])
{
    FILE *input;
    input = fopen("substitution", "r");
    if(input == NULL)
    {
        perror("fopen()");
        return;
    }
}

void subDecCipKey(char message[], char key[], const char alphabetEng[])
{
    FILE *input;
    input = fopen("substitution", "r");
    if(input == NULL)
    {
        perror("fopen()");
        return;
    }
}

void subEncMsgKey(char message[], char key[], const char alphabetEng[])
{
    FILE *input;
    input = fopen("substitution", "r");
    if(input == NULL)
    {
        perror("fopen()");
        return;
    }
}