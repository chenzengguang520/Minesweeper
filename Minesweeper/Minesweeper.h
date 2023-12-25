#pragma once

#include <QtWidgets/QWidget>
#include "ui_Minesweeper.h"
#include "MyPushButton.h"
#include "selectPass.h"
#include "MyWidget.h"

class Minesweeper : public MyWidget
{
    Q_OBJECT

public:
    Minesweeper(QWidget *parent = nullptr);
    ~Minesweeper();

private:
    Ui::MinesweeperClass ui;
    selectPass* selectP = nullptr;
};
