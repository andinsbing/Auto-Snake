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
	void putElement(const COORD& pos, char element)const; 
	//���ָ��λ�õ�Ԫ�أ��̰߳�ȫ
	void eraseElement(const COORD& pos)const; 
	void hideCursor()const;
	void showCursor()const;
private:
	void setConsoleCorsorPos(const COORD& pos)const; 
	HANDLE getConsoleHandle()const; 
	COORD getConsoleCursorPos()const;
};

