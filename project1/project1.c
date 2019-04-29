/*
 * Encryption/Decryption Program
 *
 * Created on: 26/04/19
 * Author: Kate McAlpine (c3078083)
 * Class: ENGG1003
 * Lab: Tuesday, 11am, EFG14
 */

#include <stdio.h>																//Include standard I/O library
#include <string.h>																//Include string library
#include <stdlib.h>																//Include standard library

/***************************************************************************************************************************************/
//Function Prototypes

void readFile(char cipher[], char key[], char message[], int task);				//Reads files depending on task
int stringConversion(char message[], char key[], char cipher[], int task);		//Converts lower case to upper case and key string to key integer for tasks 1 to 3
void rotDecCip(char cipher[]);													//Rotation decryption with cipher
void rotDecCipKey(char cipher[], int keyInt);									//Rotation decryption with cipher and key
void rotEncMsgKey(char message[], int keyInt);									//Rotation encryption with message and key
void subDecCip(char cipher[], const char alphabetEng[]);						//Substitution decryption with cipher
void subDecCipKey(char cipher[], char key[], const char alphabetEng[]);			//Substitution decryption with cipher and key
void subEncMsgKey(char message[], char key[], const char alphabetEng[]);		//Substitution encryption with message and key

/***************************************************************************************************************************************/
//Main Code

/*Takes I/O input from an external file named 'selection' to decide which task to implement, which is then carried out from a switch statement.
 * Also declares the variables 'task' and 'keyInt', as well as the arrays 'message', 'key', 'cipher', and alphabetEng.
 */

int main()																		//main() function of type integer begins
{
	FILE *selection;															//Declaring the variable 'selection' as a file
	selection = fopen("selection", "r");										//Opening the file 'selection' to read and assigning it to the variable 'selection'
    int task;																	//Declaring the variable 'task' of integer type
    int keyInt;																	//Declaring the variable 'keyInt' of integer type
    char message[1024];															//Declaring the array 'message' of char type to store 1024 chars
    char key[30];																//Declaring the array 'key' of char type to store 30 chars
    char cipher[1024];															//Declaring the array 'cipher' of char type to store 1024 chars
    const char alphabetEng[] = "ABCDEFGHIJKLNMNOPQRSTUVWXYZ";					//Declaring the array 'alphabetEng' of a constant char with contents
    fscanf(selection, "%d", &task);												//Scans first line of 'selection' file and stores integer into the variable 'task'
    fclose(selection);															//Closes 'selection' file
    switch (task)																//Beginning switch in relation to 'task' variable integer value from 'selection' file
    {
        case 1:																	//Case 1: Rotation Decryption Using Only Cipher
            printf("Rotation Decryption Using Only Cipher\n\n");				//Print heading line to console
            readFile(cipher, key, message, task);								//Call readFile() function
            stringConversion(message, key, cipher, task);						//Call stringConverstion() function
            rotDecCip(cipher);													//Call rotDecCip() function and pass the array 'cipher' through
            break;																//Ends case 1
        case 2:																	//Case 2: Rotation Decryption Using Cipher and Key
            printf("Rotation Decryption Using Cipher and Key\n\n");				//Print heading line to console
            readFile(cipher, key, message, task);								//Calls readFile() function
            keyInt = stringConversion(message, key, cipher, task);				//Call stringConverstion() function and junctions return integer to the variable 'keyInt'
            rotDecCipKey(cipher, keyInt);										//Call rotDecCipKey() function and pass the array 'cipher' and variable 'keyInt' through
            break;																//Ends case 2
        case 3:																	//Case 3: Rotation Encryption Using Message and Key
            printf("Rotation Encryption Using Message and Key\n\n");			//Print heading line to console
            readFile(cipher, key, message, task);								//Call readFile() function
            keyInt = stringConversion(message, key, cipher, task);				//Call stringConverstion() function and junctions return integer to the variable 'keyInt'
            rotEncMsgKey(message, keyInt);										//Call rotEncMsgKey() function and pass the array 'message' and the variable 'keyInt' through
            break;																//Ends case 3
        case 4:																	//Case 4: Substitution Decryption Using Only Cipher
            printf("Substitution Decryption Using Only Cipher\n\n");			//Print heading line to console
            readFile(cipher, key, message, task);								//Call readFile() function
            stringConversion(message, key, cipher, task);						//Call stringConverstion() function
            subDecCip(cipher, alphabetEng);										//Call subDecCip() function and pass the arrays 'cipher' and 'alphabetEng' through
            break;																//Ends case 4
        case 5:																	//Case 5: Substitution Decryption Using Cipher and Key
            printf("Substitution Decryption Using Cipher and Key\n\n");			//Print heading line to console
            readFile(cipher, key, message, task);								//Call readFile() function
            stringConversion(message, key, cipher, task);						//Call stringConverstion() function
            subDecCipKey(cipher, key, alphabetEng);								//Call subDecCipKey() and pass the arrays 'cipher', 'key', and 'alphabetEng' through
            break;																//Ends case 5
        case 6:																	//Case 6: Substitution Encryption Using Message and Key
            printf("Substitution Encryption Using Message and Key\n\n");		//Print heading line to console
            readFile(cipher, key, message, task);								//Call readFile() function
            stringConversion(message, key, cipher, task);						//Call stringConverstion() function
            subEncMsgKey(message, key, alphabetEng);							//Call subEncMsgKey() and pass the arrays 'message', 'key', and 'alphabetEng' through
            break;																//Ends case 6
        default:																//Default case
            printf("%d is not an option.\n", task);								//Print default line to console
    }
    return 0;																	//Return value 0 because function is integer type and program ends
}

/***************************************************************************************************************************************/
//Read File Function

/*This function takes the input integer from 'task' variable (which was previously taken from the 'selection' file I/O input) and opens the
 * required file, depending on the case needing to be carried out. If the case chosen is 1, 2, or 3, the file name 'rotation' will be opened,
 * read with results assigned to variables and arrays, and then closed in order to carry out the program options involving a rotation method. If
 * the case chosen is 4, 5, or 6, the file name 'substitution' will be opened, read with results assigned to variables and arrays, and then
 * closed in order to carry out the program options involving a substitution method. Each file is read as the first "block" of text is scanned
 * character by character up until a tab ascii number is reached (9), and then the result is stored into the char array 'message'. Next, the scanner
 * moves 2 places (to compensate for '\0' and '\n') so the key is scanned properly as a full line and assigned to the char array 'key', including
 * the '\n'. There is also a '\0' symbol assigned to the key array in a position just before the end, to erase gibberish being store. Finally,
 * the last "block" of file input is scanned character by character up until the end of the file, and then assigned to the char array 'cipher'.
 * The variables 'c' and 'i' are also declared, as well as the char array 'line' to use as a temp array for reading and copying.
 */

void readFile(char cipher[], char key[], char message[], int task)				//readFile() function of type void begins, with char arrays 'cipher', 'key' and 'message', and int variable 'task' passed through
{
    int i;																		//Declare integer variable 'i'
    char c;																		//Declare char variable 'c'
	char line[1024];															//Declare char array 'line' to hold 1024 values
    if (task > 0 && task <= 3)													//If variable 'task' value is 1, 2, or 3
    {
    	FILE *input;															//Declaring the variable 'input' as a file
    	input = fopen("rotation", "r");											//Opening the file 'rotation' to read and assigning it to the variable 'input'
        if(input == NULL)														//If there is no file
        {
            perror("fopen()");													//Print an 'fopen()' error to the console
        }
        else																	//If there is a file
        {
            for (i=0; c != 9; i++)												//For every character scanned in 'input' (as long as it isn't a tab ascii value (9))
            {
            	fscanf(input, "%c", &line[i]);									//Scan each character in 'input' and put it into the char array 'line'
            	c = line[i];													//Assign 'line' char array to the char variable 'c' to check for tab
            }
            line[i-1] = '\0';													//Replace last character read with '\0' so an end of array is created
        	strcpy(message, line);												//Copy char array 'line' to char array 'message'
        	fseek( input, +2, SEEK_CUR );										//Move scanner 2 places ahead to account for '\0' and '\n'
            fgets(line, 255, input);											//Read line in full in 'input' and put up to 255 chars into char array 'line'
            strcpy(key, line);													//Copy char array 'line' to char array 'key'
            for(i=0; !feof(input); i++)											//For every character scanned in 'input' until end of file
            {
            	fscanf(input, "%c", &line[i]);									//Scan each character in 'input' and put it into the char array 'line'
            }
            line[i-1]='\0';														//Replace last character read with '\0' so an end of array is created
            strcpy(cipher, line);												//Copy char array 'line' to char array 'cipher'
            fclose(input);														//Close 'rotation' file
        }
    }
    else if (task > 3 && task <= 6)												//If If variable 'task' value is 4, 5, or 6
    {
    	FILE *input;															//Declaring the variable 'input' as a file
    	input = fopen("substitution", "r");										//Opening the file 'substitution' to read and assigning it to the variable 'input'
        if(input == NULL)														//If there is no file
        {
            perror("fopen()");													//Print an 'fopen()' error to the console
        }
        else																	//If there is a file
        {
        	for (i=0; c != 9; i++)												//For every character scanned in 'input' (as long as it isn't a tab ascii value (9))
        	{
        	    fscanf(input, "%c", &line[i]);									//Scan each character in 'input' and put it into the char array 'line'
        	    c = line[i];													//Assign 'line' char array to the char variable 'c' to check for tab
        	}
        	line[i-1] = '\0';													//Replace last character read with '\0' so an end of array is created
        	strcpy(message, line);												//Copy char array 'line' to char array 'message'
        	fseek( input, +2, SEEK_CUR );										//Move scanner 2 places ahead to account for '\0' and '\n'
        	fgets(line, 255, input);											//Read line in full in 'input' and put up to 255 chars into char array 'line'
        	strcpy(key, line);													//Copy char array 'line' to char array 'key'
        	for(i=0; !feof(input); i++)											//For every character scanned in 'input' until end of file
        	{
        	    fscanf(input, "%c", &line[i]);									//Scan each character in 'input' and put it into the char array 'line'
        	}
        	line[i-1]='\0';														//Replace last character read with '\0' so an end of array is created
        	strcpy(cipher, line);												//Copy char array 'line' to char array 'cipher'
        	fclose(input);														//Close 'selection' file
        }
    return;																		//Return to main() function
    }
}

/***************************************************************************************************************************************/
//String Conversion Function

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
   	fprintf(output, "Rotation Decryption Using Only Cipher\n\n");
   	printf("Cipher: %s\n\n", cipher);
   	fprintf(output, "Cipher: %s\n\n", cipher);
   	for(ii = 0; ii < 26; ii++)
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
    fprintf(output, "Rotation Decryption Using Cipher and Key\n\n");
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
    fprintf(output, "Rotation Encryption Using Message and Key\n\n");
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
    fprintf(output, "Substitution Decryption Using Only Cipher\n\n");
    printf("Cipher:\n%s\n\n", cipher);
    fprintf(output, "Cipher:\n%s\n\n", cipher);
    fclose(output);
    return;
}

void subDecCipKey(char cipher[], char key[], const char alphabetEng[])
{
    FILE *output;
    output = fopen("output", "w");
    fprintf(output, "Substitution Decryption Using Cipher and Key\n\n");
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
    fprintf(output, "Substitution Encryption Using Message and Key\n\n");
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
