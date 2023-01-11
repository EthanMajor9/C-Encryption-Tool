/*
* FILE: main.c
* PROJECT: A-01 Cryptomagic Utility
* FIRST VERSION: 01/10/2023
* PROGRAMMER: Ethan Major
* DESCRIPTION: This file contains the main function that drives the program and contains the logic for command line argument parsing,
* dynamic memory allocation and trimming the file extension off of the file specified.
*/

#include "../inc/globals.h"

const char* kEncryptModes[2] = {"-encrypt", "-decrypt"};

int main(int argc, char* argv[])
{
	char* cryptoMode = NULL;
	char* filename = NULL;
	FILE* fPtr = NULL;
	
	// Check if any command line args were supplied
	if(argc == 1)
	{
		printf("Usage: <mode> <filename>\n");
	}
	else
	{
		// Check if the crypto mode has been specified
		if(strcmp(argv[1], kEncryptModes[0]) == 0 || strcmp(argv[1], kEncryptModes[1]) == 0)
		{
			// Check if a filename was supplied
			if(argv[2] != NULL)
			{
				// Allocate memory and store the crypto mode and filename
				allocateMem(&cryptoMode, argv[1]);
				allocateMem(&filename, argv[2]);
			}
			else
			{
				// No file name supplied, inform user. End program
				printf("Must supply a filename!\n");
			}
		}
		else
		{
			// No crypto mode specified, set defaults
			allocateMem(&cryptoMode, kEncryptModes[0]);
			allocateMem(&filename, argv[1]);
		}
		
		// Check if the memory was allocated correctly
		if(cryptoMode != NULL && filename != NULL)
		{	
			// Try to open the desired file with read/write privileges
			fPtr = fopen(filename, "r+");
			
			// Check if the file opened successfully
			if(fPtr == NULL) // File failed to open
			{
				// Inform user of the error
				printf("Error opening the file\n");
			}
			else // File opened successfully
			{
				// Trim the file extension off of the filename supplied if there is one
				parseFileExtension(&filename, filename);
				
				// Encrypt or decrypt the file as necessary
				if(strcmp(cryptoMode, kEncryptModes[0]) == 0)
				{
					encryptFile(fPtr, filename);
				}
				else
				{
					//decryptFile(filename, fPtr);
				}
				
				// Free the file pointer, close the file stream and flush any buffers
				fclose(fPtr);
			}
			
			printf("%s %s at line 38 \n", cryptoMode, filename);	
			
			// Free all allocated memory
			free(cryptoMode);
			free(filename);
		}
	}
	
	return 0;
}

void allocateMem(char** destination, const char* source)
{
	*destination = (char*)malloc(sizeof(char) * strlen(source) + 1);
	strcpy(*destination, source);
}

void parseFileExtension(char** filename, char* source)
{
	char* token = strtok(source, ".");
	
	if(token != NULL)
	{
		strcpy(*filename, token);
	}
	else{
		strcpy(*filename, source);
	}
}


