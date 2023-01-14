#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define DECRYPT_EXTENSION ".txt"
#define ENCRYPT_EXTENSION ".crp"
#define ENCRYPT_SWITCH "-encrypt"
#define DECRYPT_SWITCH "-decrypt"
#define ENCRYPT_MODE 1
#define DECRYPT_MODE 2
#define MAX_BUFFER_SIZE 255
#define HEX_ARR_SIZE 6
#define SUCCESS 1
#define FAILURE 0

int parseArgs(char* argv[], char** infilename, int* cryptoMode);
char* getOutfilename(char* infilename, int cryptoMode);
void encryptFile(char* infilename, char* outfilename);
void decryptFile(char* infilename, char* outfilename);
int hexToInt(char hexChar);




