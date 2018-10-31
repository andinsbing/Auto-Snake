#include<iostream>
#include "gameview.h"
#include"gamescene.h"
#include<mutex>
#include"gamegraphicsItem.h"

using ::Global::GameArea::WIDTH;
using ::Global::GameArea::HEIGHT;

GameView::GameView(int refreshMillisecond, const Map& map) :
	_map(&map),
    _last_map_ver(),
    _scene(new QGraphicsScene(this)),
    _timer(new QTimer(this))
{
	ASSERT_NOT_NULLPTR(_map, "_map²»ÄÜÎª¿Õ"); 
    this->initialize();
    _timer->setInterval(refreshMillisecond);
    QObject::connect(_timer,SIGNAL(timeout()),this,SLOT(monitor()));
    _timer->start();
} 



void GameView::monitor()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			Position pos{ j, i };
			auto item = _map->getGameItem(pos);
			if (item != _last_map_ver.getGameItem(pos))
			{
                update(pos, item);
			}
		}
    }
}

void GameView::initialize()
{
    for(int i=0;i<Global::GameArea::HEIGHT;i++)
    {
        for(int j=0;j<Global::GameArea::WIDTH;j++)
        {
            auto item=new GameGraphicsItem(Global::GameItem::None);
            _scene->addItem(item);
            item->setPos(j*Global::ItemSize::WIDTH,i*Global::ItemSize::HEIGHT);
        }
    }
}

QGraphicsScene *GameView::scene() const
{
    return this->_scene;
}

void GameView::update(const Position & pos, ::Global::GameItem item)
{
	_last_map_ver.setGameItem(pos, item);
//    if(item==Global::GameItem::None)
//    {
//        _scene->removeItem(_scene->itemAt(pos.x*::Global::ItemSize::WIDTH,pos.y*Global::ItemSize::WIDTH,{}));
//        return;
//    }
    static_cast<GameGraphicsItem*>(_scene->itemAt(pos.x*::Global::ItemSize::WIDTH+::Global::ItemSize::WIDTH/2,
                                          pos.y*Global::ItemSize::WIDTH+Global::ItemSize::WIDTH/2,
                                          {}))->setColor(item);
}

