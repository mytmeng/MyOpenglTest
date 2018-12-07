#include"ShaderManager.h"
ShaderManager::ShaderManager() {
	nameStr = "Hello";
}
char* ShaderManager::GetName() {
	return this->nameStr;
}