#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"gamescene.h"
#include"gameview.h"
#include"map.h"
#include"gamecontroler.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
private:
    void inlitBackGround();
    Ui::Widget *ui;
    QGraphicsScene* ui_scene;
    GameScene* scene;
    GameView* view;
    GameControler* controler;
};

#endif // WIDGET_H
