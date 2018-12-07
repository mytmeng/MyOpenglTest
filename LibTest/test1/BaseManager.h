#include<iostream>
class ManagerException {
public:
	char* msg;
	ManagerException() {

	}
	ManagerException(char* msg) {
		this->msg = msg;
	}
	ManagerException(ManagerException* rhs) {
		this->msg = rhs->msg;
	}
};
template<class T> 
class BaseManager{
private :
	BaseManager() {

	}
	static T* Instance;
public:
	static void CreateInstance() {
		if (Instance != NULL) {
			throw ManagerException("单利已创建");
		}
		Instance = new T();
	}
	static void DestroyInstance() {
		if (Instance == NULL) {
			throw ManagerException("删除不存在的单利");
		}
		delete(Instance);
		Instance = NULL;
	}
	static T* GetInstance() {
		if (Instance == NULL) {
			throw ManagerException("单例不存在");
		}
		return Instance;
	}
};
template<class T>
T* BaseManager<T>::Instance = NULL;