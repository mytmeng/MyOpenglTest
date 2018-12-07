#include"ShaderTool.h"
#include<iostream>

char* ReadTextFile(const char* path) {
	FILE* file = fopen(path, "rt");
	fseek(file, 0, SEEK_END);
	unsigned long length = ftell(file);
	//char* data = new char[length+1];
	void* mem = malloc(sizeof(char) * (length+1));
	char* data = (char*)mem;
	memset(data, 0, length+1);
	fseek(file, 0, SEEK_SET);
	fread(data, 1, length, file);
	fclose(file);
	std::cout<<length<<std::endl;

	return data;
}