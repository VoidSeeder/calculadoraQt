#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn1_clicked()
{
    cleanOperationClicked();
    ui->display->insert("1");
}

void MainWindow::on_btn2_clicked()
{
    cleanOperationClicked();
    ui->display->insert("2");
}

void MainWindow::on_btn3_clicked()
{
    cleanOperationClicked();
    ui->display->insert("3");
}

void MainWindow::on_btn4_clicked()
{
    cleanOperationClicked();
    ui->display->insert("4");
}

void MainWindow::on_btn5_clicked()
{
    cleanOperationClicked();
    ui->display->insert("5");
}

void MainWindow::on_btn6_clicked()
{
    cleanOperationClicked();
    ui->display->insert("6");
}

void MainWindow::on_btn7_clicked()
{
    cleanOperationClicked();
    ui->display->insert("7");
}

void MainWindow::on_btn8_clicked()
{
    cleanOperationClicked();
    ui->display->insert("8");
}

void MainWindow::on_btn9_clicked()
{
    cleanOperationClicked();
    ui->display->insert("9");
}

void MainWindow::on_btn0_clicked()
{
    cleanOperationClicked();
    ui->display->insert("0");
}

void MainWindow::on_btnPlus_clicked()
{
    setOperationClicked();
    operationSymbol = '+';
}

void MainWindow::on_btnMinus_clicked()
{
    setOperationClicked();
    operationSymbol = '-';
}

void MainWindow::on_btnClear_clicked()
{
    memNumber = 0;
    operationSymbol = ' ';
    operationClicked = false;
    ui->display->setText("");
}

void MainWindow::setOperationClicked() {
    if(operationSymbol != ' ') {
        doOperation();
    }
    if(operationClicked == false) {
        operationClicked = true;
    }
}

void MainWindow::cleanOperationClicked() {
    if(operationClicked == true) {
        memNumber = ui->display->text().toInt();
        ui->display->setText("");
        operationClicked = false;
    }
}

void MainWindow::doOperation() {
    const int currentNumber = ui->display->text().toInt();
    switch(operationSymbol) {
    case '+':
        memNumber = memNumber + currentNumber;
        break;
    case '-':
        memNumber = memNumber - currentNumber;
        break;
    case '*':
        memNumber = memNumber * currentNumber;
        break;
    case '/':
        memNumber = memNumber / currentNumber;
        break;
    default:
        break;
    }
    operationSymbol = ' ';
    ui->display->setText(QString::number(memNumber));
}

void MainWindow::on_btnEquals_clicked()
{
    doOperation();
    setOperationClicked();
}


void MainWindow::on_btnTimes_clicked()
{
    setOperationClicked();
    operationSymbol = '*';
}


void MainWindow::on_btnDivide_clicked()
{
    setOperationClicked();
    operationSymbol = '/';
}

