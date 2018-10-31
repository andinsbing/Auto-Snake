#pragma once
#include"map.h"
#include<QGraphicsScene>
#include<QTimer>

class GameView:public QObject
{
    Q_OBJECT
public:
    GameView(int refreshMillisecond,const Map& map);
	GameView(const GameView&) = delete;
    QGraphicsScene *scene()const;
private slots:
    void monitor();
private:
    void initialize();
	void update(const Position& pos, Global::GameItem item);
	char translate(Global::GameItem item);
	const Map *const _map; 
    Map _last_map_ver;
    QGraphicsScene* _scene;
    QTimer* _timer;
};
