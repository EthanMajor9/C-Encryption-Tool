#include "../inc/globals.h"

char* allocateMem(char* destination, const char* source);

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
				cryptoMode = allocateMem(cryptoMode, argv[1]);
				filename = allocateMem(filename, argv[2]);
			}
		}
		else
		{
			cryptoMode = allocateMem(filename, kEncryptModes[0]);
			filename = allocateMem(filename, argv[1]);
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

char* allocateMem(char* destination, const char* source)
{
	destination = (char*)malloc(sizeof(char) * strlen(source) + 1);
	strcpy(destination, source);
	
	return destination;
}
