#include "Minesweeper.h"

Minesweeper::Minesweeper(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    this->resize(512 + 2 * 128,512);
    MyPushButton* startBtn1 = new MyPushButton("经典模式");
    startBtn1->setParent(this);
    qDebug() << this->width() << " " << startBtn1->size().width() * 0.5;
    startBtn1->move(this->width() / 2  - startBtn1->size().width() * 0.5, this->height() / 2 - startBtn1->width() * 0.5);

    selectP = new selectPass();
    connect(startBtn1, &QPushButton::clicked, this, [=]() 
    {
        this->hide();
        selectP->show();
    });
}

Minesweeper::~Minesweeper()
{}
