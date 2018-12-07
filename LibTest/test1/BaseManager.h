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
			throw ManagerException("�����Ѵ���");
		}
		Instance = new T();
	}
	static void DestroyInstance() {
		if (Instance == NULL) {
			throw ManagerException("ɾ�������ڵĵ���");
		}
		delete(Instance);
		Instance = NULL;
	}
	static T* GetInstance() {
		if (Instance == NULL) {
			throw ManagerException("����������");
		}
		return Instance;
	}
};
template<class T>
T* BaseManager<T>::Instance = NULL;