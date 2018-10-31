#include "gamecontroler.h"
#include"gamescene.h"
GameControler::GameControler(int controlMillisceond,GameScene & scene):
    _scene(&scene),
    _timer(controlMillisceond,&GameControler::control,std::move(const_cast<GameControler*>(this)))
{
   this->start();
}

GameControler::~GameControler()
{
}

void GameControler::start()
{
    _timer.run();
}

void GameControler::pause()
{
    _timer.pause();
}

void GameControler::release()
{
    _timer.finish();
}

void GameControler::control()
{
    _scene->advance();
}
