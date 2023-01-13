/*
* FILE: main.c
* PROJECT: A-01 Cryptomagic Utility
* FIRST VERSION: 01/10/2023
* PROGRAMMER: Ethan Major
* DESCRIPTION: This file contains the main function that drives the program and contains the logic for command line argument parsing,
* dynamic memory allocation and trimming the file extension off of the file specified.
*/

#include "../inc/globals.h"

int main(int argc, char* argv[])
{
	char* infilename = NULL;
	char* outfilename = NULL;
	int cryptoMode = 0;
	int retStatus = 0;
	
	// Check if any command line args were supplied
	if(argc == 1)
	{
		printf("Usage: <mode> <filename>\n");
	}
	else
	{
		// Parse the command line arguments
		retStatus = parseArgs(argv, &infilename, &cryptoMode);

		// Check the return status indicating the command line arguments are valid
		if(!retStatus) // Invalid args
		{
			printf("Must enter a filename!\n");
		}
		else // Valid args
		{
			// Determine the cryptography mode
			if(cryptoMode == 1) // Encrypt
			{
				// Get the full name of the encrypted file
				outfilename = getOutfilename(infilename, cryptoMode);

				// Encrypt the file
				encryptFile(infilename, outfilename);
			}
			else // Decrypt
			{
				// Get the full name of the decrypted file
				outfilename = getOutfilename(infilename, cryptoMode);

				// Decrypt the file
				decryptFile(infilename, outfilename);
			}
			// Free the allocated memory
			free(outfilename);
		}
	}
	return 0;
}

// FUNCTION: 	int parseArgs(char* argv[], char** infilename, int* cryptoMode))
// DESCRIPTION: This function takes in the command line arguments array and parses through them to ensure they are valid and stores them appropriately upon successful validation
// PARAMETERS:  char* argv[]: Arguments array supplied by the user in the CLI
//			    char** infilename: Variable containing the address of the infilename variable
//			    int* cryptoMode: Variable containing the address of the cryptoMode variable
// RETURNS: 	int retStatus: Returns 1 if the args are successfully parsed and validated
//						   	   Returns 0 if the args entered are not validated
int parseArgs(char* argv[], char** infilename, int* cryptoMode)
{
	int retStatus = 0;

	// Check if the entered argument matches either of the allowed switches
	if(strcmp(argv[1], kEncrypt) == 0) // Check if encrypt is desired
	{
		*cryptoMode = 1; // Set the value of the crypto mode to 1 indicating encryption

		if(argv[2] != NULL) // Check if the user supplied a filename
		{
			*infilename = argv[2]; // Update the value of the infilename
			retStatus = 1; // Update retStatus indicating successful arg validation
		}
	}
	else if(strcmp(argv[1], kDecrypt) == 0) // Check if decrypt is desired
	{
		*cryptoMode = 2; // Set the value of the crypto mode to 2 indicating decryption

		if(argv[2] != NULL) // Check if the user supplied a filename
		{
			*infilename = argv[2];
			retStatus = 1;
		}
	}
	else // Only filename supplied
	{
		*cryptoMode = 1; // Assume desired crypto mode is encryption
		*infilename = argv[1]; 
		retStatus = 1;
	}
	return retStatus; // Return the parse status
}

// FUNCTION: 	char* getOutfilename(char* infilename, int cryptoMode)
// DESCRIPTION: 
// PARAMETERS:  char* infilename:
//			    int cryptoMode:
// RETURNS: 	char* temp:
char* getOutfilename(char* infilename, int cryptoMode)
{
	char* temp = (char*)malloc(sizeof(char) * strlen(infilename) + 1);
	strcpy(temp, infilename);
	char* token = strtok(temp, ".");

	if(token == NULL)
	{
		if(cryptoMode == 1)
		{
			strcat(temp, kEncryptExtension);
		}
		else
		{
			strcat(temp, kDecryptExtension);
		}
	}
	else
	{
		if(cryptoMode == 1)
		{
			strcpy(temp, strcat(token, kEncryptExtension));
		}
		else
		{
			strcpy(temp, strcat(token, kDecryptExtension));
		}
	}
	return temp;
}



