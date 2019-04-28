/*
 * Encryption/Decryption Program
 *
 * Created on: 26/04/19
 * Author: Kate McAlpine (c3078083)
 * Class: ENGG1003
 * Lab: Tuesday, 11am, EFG14
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void readFile(char cipher[], char key[], char message[], int task);
int stringConversion(char message[], char key[], char cipher[], int task);
void rotDecCip(char cipher[]);
void rotDecCipKey(char cipher[], int keyInt);
void rotEncMsgKey(char message[], int keyInt);
void subDecCip(char cipher[], const char alphabetEng[]);
void subDecCipKey(char cipher[], char key[], const char alphabetEng[]);
void subEncMsgKey(char message[], char key[], const char alphabetEng[]);

int main()
{
	FILE *selection;
	selection = fopen("selection", "r");
    int task;
    int keyInt;
    char message[1024];
    char key[30];
    char cipher[1024];
    const char alphabetEng[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    //for (int i = 0; alphabetEng[i] != '\0'; i++)
    	//printf("%c", alphabetEng[i]);
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
            subDecCip(cipher, alphabetEng);
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
    int i;
    char c;
	char line[1024];
    //FILE *input;
    if (task > 0 && task <= 3)
    {
    	FILE *input;
    	input = fopen("rotation", "r");
        if(input == NULL)
        {
            perror("fopen()");
        }
        else
        {
            for (i=0; c != 9; i++)
            {
            	fscanf(input, "%c", &line[i]);
            	c = line[i];
            }
            line[i-1] = '\0';
        	strcpy(message, line);
        	fseek( input, +2, SEEK_CUR );
            fgets(line, 255, input);
            strcpy(key, line);
            for(i=0; !feof(input); i++)
            {
            	fscanf(input, "%c", &line[i]);
            }
            line[i-1]='\0';
            strcpy(cipher, line);
            fclose(input);
        }
    }
    else if (task > 3 && task <= 6)
    {
    	FILE *input;
    	input = fopen("substitution", "r");
        if(input == NULL)
        {
            perror("fopen()");
        }
        else
        {
        	for (i=0; c != 9; i++)
        	{
        	    fscanf(input, "%c", &line[i]);
        	    c = line[i];
        	}
        	line[i-1] = '\0';
        	strcpy(message, line);
        	fseek( input, +2, SEEK_CUR );
        	fgets(line, 255, input);
        	strcpy(key, line);
        	for(i=0; !feof(input); i++)
        	{
        	    fscanf(input, "%c", &line[i]);
        	}
        	line[i-1]='\0';
        	strcpy(cipher, line);
        	fclose(input);
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
	char cipherResult[1024];
	int i;
	int ii;
	FILE *output;
   	output = fopen("output", "w");
   	printf("Cipher: %s\n\n", cipher);
   	fprintf(output, "Cipher: %s\n\n", cipher);
   	for(ii = 1; ii < 26; ii++)
   	{
   		for(i = 0; cipher[i] != '\0'; i++)
   		{
   			if (cipher[i] >= 'A' && cipher[i] <= 'Z')
   			{
   				cipherResult[i] = ((cipher[i]-65 + (26-ii))%26) + 65;
   			}
   			else
   			{
   				cipherResult[i] = cipher[i];
   			}
   		}
   		cipherResult[i] = '\0';
   		printf("Decrypted message key: %d\n%s\n\n", ii, cipherResult);
   		fprintf(output, "Decrypted message key:%d\n%s\n", ii, cipherResult);
   	}
   	fclose(output);
    return;
}

void rotDecCipKey(char cipher[], int keyInt)
{
    FILE *output;
    output = fopen("output", "w");
    printf("Cipher:\n%s\n\n", cipher);
    fprintf(output, "Cipher:\n%s\n\n", cipher);
    printf("Key:\n%d\n\n", keyInt);
    fprintf(output, "Key:\n%d\n\n", keyInt);
    for(int i = 0; cipher[i] != '\0'; i++)
    {
    	if (cipher[i] >= 'A' && cipher[i] <= 'Z')
    	{
    		/* ((location of char in cipher array) - 65 to make it 0 ascii)
    		 * + (26 - keyInt to shift char to new ascii location in negative direction) %26 to find remainder integer)
    		 * + 65 to remainder integer to accurately represent ascii encrypted char.
    		 */
    		cipher[i] = ((cipher[i] - 65 + (26 - keyInt)) %26) + 65;
    	}
    }
    printf("Decrypted message:\n%s\n", cipher);
    fprintf(output, "Decrypted message:\n%s\n", cipher);
    fclose(output);
    return;
}

void rotEncMsgKey(char message[], int keyInt)
{
    FILE *output;
    output = fopen("output", "w");
    printf("Message:\n%s\n\n", message);
    fprintf(output, "Message:\n%s\n\n", message);
    printf("Key:\n%d\n\n", keyInt);
    fprintf(output, "Key:\n%d\n\n", keyInt);
    for(int i = 0; message[i] != '\0'; i++) {
    	if (message[i] >= 'A' && message[i] <= 'Z')
    	{
    		/* (((location of char in message array) - 65 to make it 0 ascii)
    		 * + keyInt to shift char to new ascii number in positive direction) %26 to find remainder integer)
    		 * + 65 to remainder integer to accurately represent ascii encrypted char.
    		 */
    		message[i] = (((message[i] - 65) + keyInt) %26) + 65;
    	}
    }
    printf("Encrypted message:\n%s\n", message);
    fprintf(output, "Encrypted message:\n%s\n", message);
    fclose(output);
    return;
}

void subDecCip(char cipher[], const char alphabetEng[])
{
    FILE *output;
    output = fopen("output", "w");
    printf("Cipher:\n%s\n\n", cipher);
    fprintf(output, "Cipher:\n%s\n\n", cipher);
    fclose(output);
    return;
}

void subDecCipKey(char cipher[], char key[], const char alphabetEng[])
{
    FILE *output;
    output = fopen("output", "w");
    printf("Cipher:\n%s\n\n", cipher);
    fprintf(output, "Cipher:\n%s\n\n", cipher);
    printf("Key:\n%s\n\n", key);
    fprintf(output, "Key:\n%s\n\n", key);
    for(int i = 0, ii = 0; cipher[i] != '\0';)
    {
     	if (cipher[i] >= 'A' && cipher[i] <= 'Z') // check if cipher char is a capital letter
     	{
     		if (cipher[i] == key[ii]) // matches cipher char to char in key
        	{
        		cipher[i] = alphabetEng[ii]; // change cipher char to char in alphabetEng in same index
        		i++; // move to next char in cipher array
        		ii=0; // alphabetEng and key array positions remain constant
        	}
        	else
        	{
        			ii++; // alphabetEng and key array positions move up one
        	}
        }
       	else
       	{
       			i++; // copies char and moves to next char in cipher array if char isn't a capital letter
       	}
    }
    printf("Decrypted message:\n%s\n", cipher);
    fprintf(output, "Decrypted message:\n%s\n", cipher);
    fclose(output);
    return;
}

void subEncMsgKey(char message[], char key[], const char alphabetEng[])
{
    FILE *output;
    output = fopen("output", "w");
    printf("Message:\n%s\n\n", message);
    fprintf(output, "Message:\n%s\n\n", message);
    printf("Key:\n%s\n\n", key);
    fprintf(output, "Key:\n%s\n\n", key);
    for(int i = 0, ii = 0; message[i] != '\0';)
    {
    	if (message[i] >= 'A' && message[i] <= 'Z') // check if message char is a capital letter
    	{
    		if (message[i] == alphabetEng[ii]) // matches message char to char in alphabet
    		{
    			message[i] = key[ii]; // change message char to char in key in same index
    			i++; // move to next char in message array
    			ii=0; // alphabetEng and key array positions remain constant
    		}
    		else
    		{
    				ii++; // alphabetEng and key array positions move up one
    		}
    	}
    	else
    	{
    			i++; // copies char and moves to next char in message array if char isn't a capital letter
    	}
    }
    printf("Encrypted message:\n%s\n", message);
    fprintf(output, "Encrypted message:\n%s\n", message);
    fclose(output);
    return;
}
