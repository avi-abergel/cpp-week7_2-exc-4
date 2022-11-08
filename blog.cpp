#include "blog.h"
#include <iostream>
#include <string.h>
#pragma warning(disable:4996)

blog::blog(char aName[100], int aBlogSize)
{
	strcpy(name, aName);
	blogSize = aBlogSize;
}

void blog:: saveInFile()
{
	char fileName[50];
	sprintf(fileName, "%s.txt", name);
	FILE* f = fopen(fileName, "a");
	if (!f)
	{
		printf("ERROR!- file not found");
		return;
	}
	else {
		fputs(text, f);
	}
	fclose(f);
}

void blog:: loadFromFile()
{
	char fileName[50];
	sprintf(fileName, "%s.txt", name);
	FILE* f = fopen(fileName, "r");
	if (!f) {
		printf("ERROR!- file not found");
		return;
	}
	else {
		fread(text, blogSize,1, f);
	}
	fclose(f);
}

void blog::addLine(char* txt)
{
	char fileName[50];
	sprintf(fileName, "%s.txt", name);
	FILE* f = fopen(fileName, "a");
	if (!f) {
		printf("ERROR!- file not found");
		return;
	}
	else {
		char newLine[100];
		sprintf(newLine, "\n%s\n", txt);
		fputs(newLine, f);
		lineCount += 1;
		strcat(text, newLine);
	}
	fclose(f);
	
}

void blog::print()
{
	printf("%s",text);
}




