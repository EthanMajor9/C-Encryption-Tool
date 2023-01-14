#include "../inc/globals.h"

void decryptFile(char* infilename, char* outfilename)
{
	FILE* infile = NULL;
	FILE* outfile = NULL;
	char buffer[MAX_BUFFER_SIZE] = "";
	unsigned char outChar = 0;
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

				if(c1 == 'T' && c2 == 'T')
				{
					fprintf(outfile, "\t");
				}
				else if(c1 == '\n' || c2 == '\n')
				{
					fprintf(outfile, "\n");
				}
				else
				{
					// Determine if the first character is alphabetical
					convertedInt = (isalpha(c1) != 0) ? hexToInt(c1) : (c1 - '0');
					outChar = convertedInt * 16;

					convertedInt = (isalpha(c2) != 0) ? hexToInt(c2) : (c2 - '0');
					outChar += convertedInt + 16;

					outChar = (outChar > 127) ? (outChar - 144) + 32 : outChar;
					fprintf(outfile,"%c", outChar);	
				}
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
}

int hexToInt(char hexChar)
{
	int hexValues[HEX_ARR_SIZE] = {0};
	hexValues['A'] = 10;
	hexValues['B'] = 11;
	hexValues['C'] = 12;
	hexValues['D'] = 13;
	hexValues['E'] = 14;
	hexValues['F'] = 15;

	return hexValues[hexChar];
}
