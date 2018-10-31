#include "widget.h"
#include "ui_widget.h"
#include<QPixmap>
#include<QBrush>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    ui_scene(new QGraphicsScene(this)),
    scene(new GameScene()),
    view{new GameView(100,this->scene->map())},
    controler(new GameControler(100,*scene))
{
    this->ui->setupUi(this);
    this->ui_scene=view->scene();
    ui->gameView->setScene(ui_scene);
    inlitBackGround();
    ui->gameView->resize((Global::GameArea::WIDTH+1)*Global::ItemSize::WIDTH,
                         (Global::GameArea::HEIGHT+1)*Global::ItemSize::HEIGHT );
    this->resize(ui->gameView->size());
}

Widget::~Widget()
{
    delete ui;
}

void Widget::inlitBackGround()
{
    QPixmap bg(::Global::ItemSize::WIDTH,::Global::ItemSize::HEIGHT);
    QPainter painter(&bg);
//    painter.setBrush(QBrush(Qt::gray));
    painter.setBrush(QBrush(Qt::black));
    painter.drawRect(0,0,::Global::ItemSize::WIDTH,::Global::ItemSize::HEIGHT);
    ui->gameView->setBackgroundBrush({bg});
}
