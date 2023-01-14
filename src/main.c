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
	int cryptoMode = ENCRYPT_MODE;
	int retStatus = FAILURE;
	
	// Check if any command line args were supplied
	if(argc < 2)
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
			outfilename = getOutfilename(infilename, cryptoMode);
			// Determine the cryptography mode
			switch(cryptoMode)
			{
				case ENCRYPT_MODE:
					// Encrypt the file
					encryptFile(infilename, outfilename);
					break;
				case DECRYPT_MODE:
					// Decrypt the file
					decryptFile(infilename, outfilename);
					break;	
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
	int retStatus = FAILURE;

	// Check if the entered argument matches either of the allowed switches
	if(strcmp(argv[1], ENCRYPT_SWITCH) == 0) // Check if encrypt is desired
	{
		*cryptoMode = ENCRYPT_MODE; // Set the value of the crypto mode to 1 indicating encryption
		*infilename = argv[2]; // Update the value of the infilename
		retStatus = SUCCESS;
	}
	else if(strcmp(argv[1], DECRYPT_SWITCH) == 0) // Check if decrypt is desired
	{
		*cryptoMode = DECRYPT_MODE; // Set the value of the crypto mode to 2 indicating decryption
		*infilename = argv[2];
		retStatus = SUCCESS;
	}
	else // Only filename supplied
	{
		*cryptoMode = ENCRYPT_MODE; // Assume desired crypto mode is encryption
		*infilename = argv[1]; 
		retStatus = SUCCESS;
	}
	
	return retStatus; // Return the parse status
}

// FUNCTION: 	char* getOutfilename(char* infilename, int cryptoMode)
// DESCRIPTION: 
// PARAMETERS:  char* infilename:
//			    int cryptoMode:
// RETURNS: 	char* outfilename:

char* getOutfilename(char* infilename, int cryptoMode)
{
    char* outfilename = NULL;
    char* extension = (cryptoMode == ENCRYPT_MODE) ? ENCRYPT_EXTENSION : DECRYPT_EXTENSION;
    char* dot = strrchr(infilename, '.');

    if (dot == NULL) 
	{
        outfilename = (char*)malloc(strlen(infilename) + strlen(extension) + 1);
        snprintf(outfilename, strlen(infilename) + strlen(extension) + 1, "%s%s", infilename, extension);
    } 
	else 
	{
        outfilename = (char*)malloc(dot - infilename + strlen(extension) + 1);
        snprintf(outfilename, dot - infilename + strlen(extension) + 1, "%.*s%s", (int)(dot - infilename), infilename, extension);
    }
    return outfilename;
}




