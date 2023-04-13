#include "stdafx.h"
#include "login_screen.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login_screen w;
    w.show();
    return a.exec();
}

//Adding notes for Git test