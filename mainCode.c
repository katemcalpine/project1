/*
 * Encryption/Decryption Program
 * poo
 * Created on: 26/04/19
 * Author: Kate McAlpine (c3078083)
 * Class: ENGG1003
 * Lab: EFG14
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void readFile(char cipher[], char key[], char message[], int task);
int stringConversion(char message[], char key[], char cipher[], int task);
void rotDecCip(char cipher[]);
void rotDecCipKey(char cipher[], int keyInt);
void rotEncMsgKey(char message[], int keyInt);
void subDecCip(char cipher[]);
void subDecCipKey(char cipher[], char key[], const char alphabetEng[]);
void subEncMsgKey(char message[], char key[], const char alphabetEng[]);

int main()
{
	FILE *selection;
	selection = fopen("selection", "r");
    int task;
    int keyInt;
    char message[1024];
    char key[26];
    char cipher[1024];
    const char alphabetEng[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    task = 1;
    fscanf(selection, "%d", &task);
    fclose(selection);
    //printf("Task selected: %d\n", task);
    
    switch (task)
    {
        case 1:
            printf("Rotation Decryption Using Only Cipher\n\n");
            readFile(cipher, key, message, task);
            stringConversion(message, key, cipher, task);
            rotDecCip(cipher);
            break;
        case 2:
            printf("Rotation Decryption Using Cipher and Key\n\n");
            readFile(cipher, key, message, task);
            keyInt = stringConversion(message, key, cipher, task);
            rotDecCipKey(cipher, keyInt);
            break;
        case 3:
            printf("Rotation Encryption Using Message and Key\n\n");
            readFile(cipher, key, message, task);
            keyInt = stringConversion(message, key, cipher, task);
            rotEncMsgKey(message, keyInt);
            break;
        case 4:
            printf("Substitution Decryption Using Only Cipher\n\n");
            readFile(cipher, key, message, task);
            stringConversion(message, key, cipher, task);
            subDecCip(cipher);
            break;
        case 5:
            printf("Substitution Decryption Using Cipher and Key\n\n");
            readFile(cipher, key, message, task);
            stringConversion(message, key, cipher, task);
            subDecCipKey(cipher, key, alphabetEng);
            break;
        case 6:
            printf("Substitution Encryption Using Message and Key\n\n");
            readFile(cipher, key, message, task);
            stringConversion(message, key, cipher, task);
            subEncMsgKey(message, key, alphabetEng);
            break;
        default:
            printf("%d is not an option.\n", task);
    }
    return 0;
}

void readFile(char cipher[], char key[], char message[], int task)
{
    char line[1024];
    char c;
    FILE *input;
    if (task > 0 && task <= 3)
    {
        input = fopen("rotation", "r");
        if(input == NULL)
        {
            perror("fopen()");
            return;
        }
        else
        {
            //fscanf(input, "%s", message);
            fgets(line, 1024, input);
            strcpy(message, line);
            printf("%s\n", message);
            fgets(line, 26, input);
            strcpy(key, line);
            printf("%s\n", key);
            fscanf(input, "%c", &c);
            printf("%c",c);
            fclose(input);
            return;
        }
    }
    else if (task > 3 && task <= 6)
    {
        input = fopen("substitution", "r");
        if(input == NULL)
        {
            perror("fopen()");
            return;
        }
        else
        {
            fgets(line, 1024, input);
            strcpy(message, line);
            printf("%s\n", message);
            fgets(line, 26, input);
            strcpy(key, line);
            printf("%s\n", key);
            //fscanf(input, "%c", &c);
            fclose(input);
            return;
        }
    return;
    }
}

int stringConversion(char message[], char key[], char cipher[], int task)
{
	for (int i = 0; message[i] != '\0'; i++)
	    {
	        if (message[i] >= 'a' && message[i] <= 'z')
	        	message[i] -= 32;
	    }
	for (int i = 0; cipher[i] != '\0'; i++)
	    {
	        if (cipher[i] >= 'a' && cipher[i] <= 'z')
	        	cipher[i] -= 32;
	    }
    if (task > 0 && task <= 3)
    {
        int keyInt = atoi(key);
        return keyInt;
    }
    else if (task > 3 && task <= 6)
    {
        for (int i = 0; key[i] != '\0'; i++)
        {
            if (key[i] >= 'a' && key[i] <= 'z')
            	key[i] -= 32;
        }
    }
    return 0;
}

void rotDecCip(char cipher[])
{
   FILE *output;
   output = fopen("output", "w");
   return;
}

void rotDecCipKey(char cipher[], int keyInt)
{
    FILE *output;
    output = fopen("output", "w");
    return;
}

void rotEncMsgKey(char message[], int keyInt)
{
    FILE *output;
    output = fopen("output", "w");
    return;
}

void subDecCip(char cipher[])
{
    FILE *output;
    output = fopen("output", "w");
    return;
}

void subDecCipKey(char cipher[], char key[], const char alphabetEng[])
{
    FILE *output;
    output = fopen("output", "w");
    return;
}

void subEncMsgKey(char message[], char key[], const char alphabetEng[])
{
    FILE *output;
    output = fopen("output", "w");
    return;
}
