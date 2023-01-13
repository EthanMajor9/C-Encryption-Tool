#include "../inc/globals.h"

void decryptFile(char* infilename, char* outfilename)
{
	FILE* infile = NULL;
	FILE* outfile = NULL;
	char buffer[kMaxArrSize] = "";
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
				//printf("%c%c\n", c1, c2);

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
					if(isalpha(c1) != 0)
					{
						convertedInt = hexToInt(c1);
						outChar = (c1 - '0') * 16;
						printf("Line 40: %d\n", outChar);
					}
					else
					{
						outChar = (c1 - '0') * 16;
						printf("Line 45: %d\n", outChar);
					}

					if(isalpha(c2) != 0)
					{
						convertedInt = hexToInt(c2);
						outChar = outChar + convertedInt;
						printf("Line 52: %d\n", outChar);
					}
					else
					{
						outChar = (outChar - '0') + c2;
						printf("Line 57: %d\n", outChar);
					}

					outChar = outChar + 16;

					if(outChar > 127)
					{
						outChar = (outChar - 144) + 32;
					}
					
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
