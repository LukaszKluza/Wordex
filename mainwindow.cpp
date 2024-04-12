#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <ButtonLetter.h>
#include<keyboard.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Wordex");

    keyboard = new Keyboard(this);
}

MainWindow::~MainWindow()
{
    delete keyboard;
    delete ui;
}

