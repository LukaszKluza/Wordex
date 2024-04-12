#include "wordletter.h"
#include "ui_wordletter.h"

WordLetter::WordLetter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WordLetter)
{
    ui->setupUi(this);
}

WordLetter::~WordLetter()
{
    delete ui;
}
