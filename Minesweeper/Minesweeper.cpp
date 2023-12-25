#include "Minesweeper.h"

Minesweeper::Minesweeper(QWidget *parent)
    : MyWidget()
{
    ui.setupUi(this);
    this->resize(512 + 2 * 128,512);
    MyPushButton* startBtn1 = new MyPushButton("经典模式");
    startBtn1->setParent(this);
    startBtn1->move(this->width() / 2  - startBtn1->size().width() * 0.5, this->height() / 2 - startBtn1->height() * 0.5);

    selectP = new selectPass();
    connect(startBtn1, &QPushButton::clicked, this, [=]() 
    {
        this->hide();
        selectP->createWidget();
        selectP->show();
    });

    MyPushButton* startBtn2 = new MyPushButton("挑战模式");
    startBtn2->setParent(this);
    startBtn2->move(this->width() / 2 - startBtn1->size().width() * 0.5, this->height() / 2 + startBtn1->height() * 0.5 * 2);

    connect(startBtn2, &QPushButton::clicked, this, [=]() {
    
        qDebug() << "挑战";
        selectP->recivePlus(1);
        this->hide();
        selectP->createWidget();
        selectP->show();
    });
}

Minesweeper::~Minesweeper()
{}
