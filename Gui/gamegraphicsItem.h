#ifndef GAMEITEM_H
#define GAMEITEM_H

#include<QGraphicsItem>
#include"global.h"

class GameGraphicsItem : public QGraphicsItem
{
public:
    GameGraphicsItem(const ::Global::GameItem& item,QGraphicsItem *parent=nullptr);
    QRectF boundingRect()const override;
    QPainterPath shape()const override;
    void setColor(const Global::GameItem& item);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)override;
private:
    QColor bodyColor;
};

#endif // GAMEITEM_H
