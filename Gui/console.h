#pragma once
#include<mutex>
#include<Windows.h>

class Console
{
	static std::mutex cusorMutex;
public:
	Console();
	~Console();
	//��ָ��λ�����Ԫ�أ��̰߳�ȫ
	void putElement(const COORD& pos, char element); 

	//���ָ��λ�õ�Ԫ�أ��̰߳�ȫ
	void eraseElement(const COORD& pos); 
private:
	void setConsoleCorsorPos(const COORD& pos); 
	HANDLE getConsoleHandle(); 
	COORD getConsoleCursorPos();
};

