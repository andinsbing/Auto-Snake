#pragma once
#include"timer.h"
class GameScene;

class GameControler
{
public:
	GameControler(int controlMillisceond,GameScene& scene);
	~GameControler();
	void start();
	void pause();
	//�ͷſ���Ȩ�ޣ����ٿ���
	void release(); 
private:
	void control();
	GameScene*const _scene;
	Timer<decltype(&control),GameControler*> _timer;
};