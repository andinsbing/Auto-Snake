#include "gamegraphicsItem.h"
#include<QPainter>
#include<QColor>
GameGraphicsItem::GameGraphicsItem(const Global::GameItem &item, QGraphicsItem *parent):
    QGraphicsItem(parent),
    bodyColor()
{
    setColor(item);
}

QRectF GameGraphicsItem::boundingRect() const
{
    return QRectF{0,
                0,
                ::Global::ItemSize::WIDTH,
                ::Global::ItemSize::HEIGHT};
}

QPainterPath GameGraphicsItem::shape() const
{
    QPainterPath shape;
    shape.addEllipse(::Global::ItemSize::WIDTH/4, ::Global::ItemSize::HEIGHT/4,
                     ::Global::ItemSize::WIDTH/2, ::Global::ItemSize::HEIGHT/2);
    return shape;
}

void GameGraphicsItem::setColor(const Global::GameItem &item)
{
    switch(item)
    {
        case ::Global::GameItem::Food:
        //254 hash for food
//        this->bodyColor.setRgb( 69,169,169,254);
        this->bodyColor.setRgb( 255,255,255,254);
        break;
        case ::Global::GameItem::None:
        this->bodyColor.setRgb(0,0,0,0);
//        this->bodyColor.setRgb(255,255,255);
        break;
        case ::Global::GameItem::SnakeBody:
//        this->bodyColor.setRgb(50,100,100,100);
//        this->bodyColor.setRgb(238,238,0,200);
         this->bodyColor.setRgb(255,255,255);
        break;
        case ::Global::GameItem::Wall:
        this->bodyColor.setRgb(	46,139,87);
//        this->bodyColor.setRgb(	0,0,0);
        break;
    default:
        this->bodyColor.setRgb(200,40,30);
    }
    this->update();
}

void GameGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    if(this->bodyColor.alpha()==254)
    {
       painter->fillPath(this->shape(),bodyColor);
    }
    else
    {
        painter->fillRect(this->boundingRect(),bodyColor);
    }
}


