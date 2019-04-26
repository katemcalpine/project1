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

void readFile(char cipher[], char key[], char message[], int task);
void rotDecCip(char cipher[]);
void rotDecCipKey(char cipher[], char key[]);
void rotEncMsgKey(char message[], char key[]);
void subDecCip(char cipher[]);
void subDecCipKey(char cipher[], char key[], const char alphabetEng[]);
void subEncMsgKey(char message[], char key[], const char alphabetEng[]);

int main()
{
    int task;
    char message[1024];
    char key[26];
    char cipher[1024];
    const char alphabetEng[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d", &task);
    //printf("Task selected: %d\n", task);
    
    switch (task)
    {
        case 1:
            printf("Rotation Decryption Using Only Cipher\n\n");
            readFile(cipher, key, message, task);
            rotDecCip(cipher);
            break;
        case 2:
            printf("Rotation Decryption Using Cipher and Key\n\n");
            readFile(cipher, key, message, task);
            rotDecCipKey(cipher, key);
            break;
        case 3:
            printf("Rotation Encryption Using Message and Key\n\n");
            readFile(cipher, key, message, task);
            rotEncMsgKey(message, key);
            break;
        case 4:
            printf("Substitution Decryption Using Only Cipher\n\n");
            readFile(cipher, key, message, task);
            subDecCip(cipher);
            break;
        case 5:
            printf("Substitution Decryption Using Cipher and Key\n\n");
            readFile(cipher, key, message, task);
            subDecCipKey(cipher, key, alphabetEng);
            break;
        case 6:
            printf("Substitution Encryption Using Message and Key\n\n");
            readFile(cipher, key, message, task);
            subEncMsgKey(message, key, alphabetEng);
            break;
        default:
            printf("%d is not an option.\n", input);
    }
    return 0;
}

void readFile(char cipher[], char key[], char message[], int task);
{
    char str[1024];
    char c;
    if (task >=1 && task == 3)
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
            fgets(str, 1024, input);
            strcpy(message, str);
            fgets(str, 26, input);
            strcpy(key, str);
            //fscanf(input, "%c", &c);
        }
    }
    else if (task > 3 && task <= 6)
    {
        FILE *input;
        input = fopen("substitution", "r");
        if(input == NULL)
        {
            perror("fopen()");
            return;
        }
        else
        {
            fgets(str, 1024, input);
            strcpy(message, str);
            fgets(str, 26, input);
            strcpy(key, str);
            //fscanf(input, "%c", &c);
        }
    }
}

void rotDecCip(char cipher[])
{
   FILE *output;
   output = fopen("output", "w");
}

void rotDecCipKey(char message[], char key[])
{
    FILE *output;
    output = fopen("output", "w");
}

void rotEncMsgKey(char message[], char key[])
{
    FILE *output;
    output = fopen("output", "w"); 
}

void subDecCip(char cipher[])
{
    FILE *output;
    output = fopen("output", "w");
}

void subDecCipKey(char message[], char key[], const char alphabetEng[])
{
    FILE *output;
    output = fopen("output", "w");
}

void subEncMsgKey(char message[], char key[], const char alphabetEng[])
{
    FILE *output;
    output = fopen("output", "w");
}