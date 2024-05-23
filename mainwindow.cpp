#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <ButtonLetter.h>
#include "keyboard.h"
#include "gameplay.h"
#include <iostream>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Wordex");
    gameplay = new Gameplay(this);
}

void MainWindow::keyPressEvent(QKeyEvent *event){
  char letter = event->key();
  if(letter >= 'A' && letter <='Z'){
      gameplay->update(letter);
  }
  else if(Qt::Key_Return == event->key()){
      gameplay->check();
  }
  else if (Qt::Key_Backspace == event->key()) {
      gameplay->erase();
  }
  else if(Qt::Key_Escape == event->key()){
      close();
      qApp->quit();
  }
  else{
      QWidget::keyPressEvent(event);
  }
}

MainWindow::~MainWindow()
{
    delete gameplay;
    delete ui;
}

