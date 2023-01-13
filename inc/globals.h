#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define kDecryptExtension ".txt"
#define kEncryptExtension ".crp"
#define kEncrypt "-encrypt"
#define kDecrypt "-decrypt"
#define kMaxArrSize 255

void encryptFile(char* infilename, char* outfilename);
void decryptFile(char* infilename, char* outfilename);
int parseArgs(char* argv[], char** infilename, int* cryptoMode);
char* getOutfilename(char* infilename, int cryptoMode);
int hexToInt(char hexChar);




