#include "../inc/globals.h"

void encryptFile(char* infilename, char* outfilename)
{
	FILE* infile = NULL;
	FILE* outfile = NULL;
	char buffer[MAX_BUFFER_SIZE] = "";
	unsigned char outChar = ' ';

	infile = fopen(infilename, "r");
	outfile = fopen(outfilename, "w");

	if(infile != NULL && outfile != NULL)
	{
		while(fgets(buffer, sizeof(buffer), infile) != NULL)
		{
			for(int i = 0; i < strlen(buffer); i++)
			{
				switch(buffer[i])
				{
					// Character read is a tab
					case 9:
						fprintf(outfile, "%c%c", 'T', 'T');
						break;
					// Character read is a carriage return
					case 10:
						fprintf(outfile, "\n");
						break;
					// Any other character was read
					default:
						outChar = buffer[i] - 16;
						outChar = (outChar < 32) ? (outChar - 32) + 144 : outChar;
						fprintf(outfile, "%02X", outChar);
						break;
				}
			}
		}
		fclose(infile);
		fclose(outfile);
	}
	else
	{
		printf("There was an error opening the file!\n");
	}
}



