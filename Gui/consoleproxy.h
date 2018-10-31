#ifndef CONSOLEPROXY_H
#define CONSOLEPROXY_H

#include<QGraphicsScene>
#include"gamegraphicsItem.h"
#include<windows.h>
#include<mutex>

class ConsoleProxy
{
public:
    ConsoleProxy(QGraphicsScene* scene);
    //在指定位置输出元素，线程安全
    void putElement(const COORD& pos, char element);

    //清除指定位置的元素，线程安全
    void eraseElement(const COORD& pos);
private:
    QGraphicsScene* scene;
    std::mutex mutex;
};

#endif // CONSOLEPROXY_H
