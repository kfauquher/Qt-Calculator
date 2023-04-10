#include "stdafx.h"
#include "login_screen.h"
#include <QRegularExpression>

double calcVal = 0.0;
bool divTrigger = false;
bool multTrigger = false;
bool addTrigger = false;
bool subTrigger = false;
QString currentOperator;

login_screen::login_screen(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.lineEdit_display->setText("0");

    // Connect all the number buttons to the NumPressed slot function
    connect(ui.pushButton_0, &QPushButton::released, this, &login_screen::NumPressed);
    connect(ui.pushButton_1, &QPushButton::released, this, &login_screen::NumPressed);
    connect(ui.pushButton_2, &QPushButton::released, this, &login_screen::NumPressed);
    connect(ui.pushButton_3, &QPushButton::released, this, &login_screen::NumPressed);
    connect(ui.pushButton_4, &QPushButton::released, this, &login_screen::NumPressed);
    connect(ui.pushButton_5, &QPushButton::released, this, &login_screen::NumPressed);
    connect(ui.pushButton_6, &QPushButton::released, this, &login_screen::NumPressed);
    connect(ui.pushButton_7, &QPushButton::released, this, &login_screen::NumPressed);
    connect(ui.pushButton_8, &QPushButton::released, this, &login_screen::NumPressed);
    connect(ui.pushButton_9, &QPushButton::released, this, &login_screen::NumPressed);

    // Connect all the operator buttons to their respective slot functions
    connect(ui.pushButton_divide, &QPushButton::released, this, &login_screen::MathButtonPressed);
    connect(ui.pushButton_multi, &QPushButton::released, this, &login_screen::MathButtonPressed);
    connect(ui.pushButton_plus, &QPushButton::released, this, &login_screen::MathButtonPressed);
    connect(ui.pushButton_subtract, &QPushButton::released, this, &login_screen::MathButtonPressed);

    // Connect the equal button to its slot function
    connect(ui.pushButton_equal, &QPushButton::released, this, &login_screen::EqualButtonPressed);

    // Connect the clear button to its slot function
    connect(ui.pushButton_clear, &QPushButton::released, this, &login_screen::ClearButtonPressed);
}

void login_screen::NumPressed()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString buttonValue = button->text();
    QString displayValue = ui.lineEdit_display->text();

    if (displayValue == "0" && buttonValue != ".") {
        ui.lineEdit_display->setText(buttonValue);
    }
    else {
        ui.lineEdit_display->setText(displayValue + buttonValue);
    }
}

void login_screen::MathButtonPressed()
{
    QString displayValue = ui.lineEdit_display->text();
    calcVal = displayValue.toDouble();

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString buttonValue = button->text();

    if (buttonValue == "/") {
        currentOperator = "/";
    }
    else if (buttonValue == "*") {
        currentOperator = "*";
    }
    else if (buttonValue == "+") {
        currentOperator = "+";
    }
    else {
        currentOperator = "-";
    }

    ui.lineEdit_display->setText("");
}

void login_screen::EqualButtonPressed()
{
    double solution = 0.0;
    QString displayValue = ui.lineEdit_display->text();
    double currentValue = displayValue.toDouble();

    if (currentOperator == "+") {
        solution = calcVal + currentValue;
    }
    else if (currentOperator == "-") {
        solution = calcVal - currentValue;
    }
    else if (currentOperator == "*") {
        solution = calcVal * currentValue;
    }
    else if (currentOperator == "/") {
        solution = calcVal / currentValue;
    }

    ui.lineEdit_display->setText(QString::number(solution));
    currentOperator = "";
}

void login_screen::ClearButtonPressed()
{
    ui.lineEdit_display->setText("");
}

login_screen::~login_screen()
{
}
