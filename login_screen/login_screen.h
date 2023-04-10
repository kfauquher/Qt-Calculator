#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_login_screen.h"

class login_screen : public QMainWindow
{
    Q_OBJECT

public:
    login_screen(QWidget *parent = nullptr);
    void NumPressed();
    void MathButtonPressed();
    void EqualButtonPressed();
    void ClearButtonPressed();
    QString mathOperator = "";
    ~login_screen();

private:
    Ui::widget_calculator ui;
};
