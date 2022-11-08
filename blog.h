#pragma once
class blog
{
public:
	char name[100];
	int blogSize;
	char* text = new char(blogSize);
	int lineCount;
	blog(char aName[100], int aBlogSize);
	
	void saveInFile();
	void loadFromFile();
	void addLine(char* txt);
	void print();
};

