#include"BaseManager.h"
class ShaderManager {
	friend class BaseManager<ShaderManager>;
private:
	ShaderManager();
	char* nameStr;
public:
	char* GetName();
};