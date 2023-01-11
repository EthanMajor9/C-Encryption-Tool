#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define kDecryptExtension ".txt"
#define kEncryptExtension ".crp"

void encryptFile(FILE* filePtr, char* filename);
void allocateMem(char** destination, const char* source);
void parseFileExtension(char** filename, char* source);
void decryptFile(FILE* filePtr, char* filename);

const extern char* kEncryptModes[2];


