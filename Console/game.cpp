#include "game.h"


Game::Game():
	_scene(),
	_view(200,_scene),
	_controler(200,_scene)
{
	

}

Game::~Game()
{
}

void Game::start()
{
	if (_state == over)
	{
		return;
	}
	_state = started;
	_controler.start();
}

void Game::pause()
{
	if (_state == over)
	{
		return;
	}
	_state = paused;
	_controler.pause();
}

void Game::end()
{
	if (_state == over)
	{
		return;
	}
	_state = over;
	_controler.release();
}

void Game::renew()
{
	_state = started;
	pause();
	_scene.renew();
	start();
}

bool Game::isOver() const
{
	return _state == over || (!_scene.map().count(Global::GameItem::SnakeBody));
}
 