#include<iostream>
#include<Windows.h>
#include<functional>
#include<mutex>
#include<algorithm>
#include<list>
#include"timer.h" 
#include"global.h"
#include"gamescene.h"
#include"gameview.h"
#include"map.h"
#include"gamecontroler.h"

using namespace std;
 
void fun(int val)
{
	cout << "fun called" << val << " ";
}  

  
int console_main()
{ 
	system("cls"); 
	for (int i = 0; i <  Global::GameArea::HEIGHT; i++)
	{
		for (int i = 0; i < Global::GameArea::WIDTH; i++)
		{
			cout << ' ';
		}
		cout << "|\n";
	}
	for (int i = 0; i < Global::GameArea::WIDTH; i++)
	{
		cout << '-';
	}
	cout << endl;
	GameScene scene;  
    GameView view(50,scene.map());
	GameControler controler(50, scene);

	cin.get();//pause
	return 0;
}
