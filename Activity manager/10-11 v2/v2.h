#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_v2.h"

class v2 : public QMainWindow
{
    Q_OBJECT

public:
    v2(QWidget *parent = Q_NULLPTR);

private:
    Ui::v2Class ui;
};
