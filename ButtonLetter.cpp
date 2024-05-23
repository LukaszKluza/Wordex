#include "ButtonLetter.h"


ButtonLetter::ButtonLetter(QWidget *parent, char letter)
    : letter(letter), buttonLetter(new QPushButton(parent)), parent(parent) {
    setConfiguration();
}
ButtonLetter::ButtonLetter(QWidget *parent, char letter, int width, int height)
    : letter(letter), width_(width), height_(height), buttonLetter(new QPushButton(parent)), parent(parent){
    setSize(width_, height_);
    setConfiguration();
}
void ButtonLetter::setConfiguration()
{
    buttonLetter->setStyleSheet("background-color: rgb(123, 0, 0); color: white;");
    buttonLetter->setText(QString(letter));
    buttonLetter->setStyleSheet("QPushButton {text-align: center}");
    connect(buttonLetter, &QPushButton::clicked, this, &ButtonLetter::onClick);
}

void ButtonLetter::setEnabled(bool status){
    buttonLetter->setEnabled(status);
}

void ButtonLetter::display() {
    buttonLetter->show();
}

void ButtonLetter::onClick() {
    emit clickedWithLetter(letter);
}
void ButtonLetter::setSize(int width, int height){
    width_ = width;
    height_ = height;
}

void ButtonLetter::setGeometry(int xAsix, int yAsix){
    setGeometry(xAsix, yAsix, width_, height_);
}

void ButtonLetter::setGeometry(int xAsix, int yAsix, int width, int height){
    buttonLetter->setGeometry(xAsix, yAsix, width, height);
}
char ButtonLetter::getLetter(){
    return letter;
}

ButtonLetter::~ButtonLetter() {
}
