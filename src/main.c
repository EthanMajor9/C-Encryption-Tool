/*
* FILE: main.c
* PROJECT: A-01 Cryptomagic Utility
* FIRST VERSION: 01/10/2023
* PROGRAMMER: Ethan Major
* DESCRIPTION: This file contains the main function that drives the program and contains the logic for command line argument parsing,
* dynamic memory allocation and trimming the file extension off of the file specified.
*/
#include "../inc/globals.h"

void allocateMem(char** destination, const char* source);
void parseFileExtension(char** filename, char* source);

int main(int argc, char* argv[])
{
	char* cryptoMode = NULL;
	char* filename = NULL;
	
	if(argc == 1)
	{
		printf("Usage: <mode> <filename>\n");
	}
	else
	{
		if(strcmp(argv[1], kEncryptModes[0]) == 0 || strcmp(argv[1], kEncryptModes[1]) == 0)
		{
			if(argv[2] != NULL)
			{
				allocateMem(&cryptoMode, argv[1]);
				allocateMem(&filename, argv[2]);
			}
			else{
				printf("Must supply a filename!\n");
			}
		}
		else
		{
			allocateMem(&cryptoMode, kEncryptModes[0]);
			allocateMem(&filename, argv[1]);
		}
		printf("%s %s at line 38 \n", cryptoMode, filename);
	}
	
	if(cryptoMode != NULL && filename != NULL)
	{	
		free(cryptoMode);
		free(filename);
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
