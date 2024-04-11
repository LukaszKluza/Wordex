#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <ButtonLetter.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Wordex");
    int width = this->width();
    int height = this->height();
    ButtonLetter *buttonLetter = new ButtonLetter(this,'c');
    buttonLetter->display();


    QPushButton *newButton = new QPushButton(this);
    newButton->setGeometry((width-50)/2,(height-50)/2,50,50);
    newButton->setStyleSheet("background-color: rgb(123, 0, 0); color: white;");
    newButton->setText("KOKO");
    newButton->setStyleSheet("QPushButton {text-align: center}");
    newButton->show();
    connect(newButton, &QPushButton::clicked, this,[=](){
        newButton->setText("KIKI");
        newButton->setEnabled(false);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

