#include "../inc/globals.h"

void decryptFile(char* infilename, char* outfilename)
{
	FILE* infile = NULL;
	FILE* outfile = NULL;
	char buffer[kMaxArrSize] = "";
	char outChar = 0;
	int convertedInt = 0;
	char c1 = 0;
	char c2 = 0;

	infile = fopen(infilename, "r");
	outfile = fopen(outfilename, "w");

	if(infile != NULL && outfile != NULL)
	{
		while(fgets(buffer, sizeof(buffer), infile) > 0)
		{
			for (int i = 0; i < strlen(buffer); i += 2) 
			{
        		c1 = buffer[i];
				c2 = buffer[i + 1];
				printf("%c%c\n", c1, c2);

				if(c1 == 'T' && c2 == 'T')
				{
					printf("Found a tab\n");
				}
    		}

    		if (strlen(buffer) % 2 != 0) 
			{
        		c1 = buffer[strlen(buffer) - 1];
				printf("%c\n", c1);
    		}
		}

		if(ferror(infile))
		{
			printf("There was an error reading the file\n");
		}
	}
	else
	{
		printf("There was an error opening the files\n");
	}

	if(fclose(infile) != 0 || fclose(outfile) != 0)
	{
		printf("There was an error closing the file\n");
	}

}

int hexToInt(char hexChar)
{
	int convertedInt;
	switch(hexChar)
	{
		case 'A':
            convertedInt = 10;
            break;
        case 'B':
            convertedInt = 11;
            break;
        case 'C':
            convertedInt = 12;
            break;
        case 'D':
            convertedInt = 13;
            break;
        case 'E':
            convertedInt = 14;
            break;
        case 'F':
            convertedInt = 15;
            break;
	}
	return convertedInt;
}
