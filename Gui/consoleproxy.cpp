#include "consoleproxy.h"
#include<QTransform>
#include<mutex>
ConsoleProxy::ConsoleProxy(QGraphicsScene* scene):
    scene(scene)
{

}

void ConsoleProxy::putElement(const COORD &pos, char element)
{
    std::lock_guard<std::mutex> guard{ mutex };
    if(element==' ')
    {
        eraseElement(pos);
        return;
    }
    //    auto item=new GameItem(element);
    //    scene->addItem(item);
    //    item->setPos(pos.X,pos.Y);
}

void ConsoleProxy::eraseElement(const COORD &pos)
{
    scene->removeItem(scene->itemAt(pos.X,pos.Y,QTransform{}));
}
