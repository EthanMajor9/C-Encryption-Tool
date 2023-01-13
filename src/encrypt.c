#include "../inc/globals.h"

void encryptFile(char* infilename, char* outfilename)
{
	FILE* infile = NULL;
	FILE* outfile = NULL;
	char buffer[kMaxArrSize] = "";
	unsigned char outChar = ' ';

	infile = fopen(infilename, "r");
	outfile = fopen(outfilename, "w");

	if(infile != NULL && outfile != NULL)
	{
		while(fgets(buffer, sizeof(buffer), infile) != NULL)
		{
			for(int i = 0; i < strlen(buffer); i++)
			{
				if(buffer[i] == 9)
				{
					fprintf(outfile, "%c%c", 'T', 'T');
				}
				else if(buffer[i] == 10)
				{
					fprintf(outfile, "\n");
				}
				else
				{
					outChar = buffer[i] - 16;

					if(outChar < 32)
					{
						outChar = (outChar - 32) + 144;
					}

					fprintf(outfile, "%02X", outChar);
				}
			}
		}
	}
	else
	{
		printf("There was an error opening the file!\n");
	}

	fclose(infile);
	fclose(outfile);
}



