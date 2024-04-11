#include "ButtonLetter.h"

ButtonLetter::ButtonLetter(QWidget *parent, char letter) : letter(letter), parent(parent) {
    buttonLetter = new QPushButton(parent);
    buttonLetter->setStyleSheet("background-color: rgb(123, 0, 0); color: white;");
    buttonLetter->setText(QString(letter));
    buttonLetter->setStyleSheet("QPushButton {text-align: center}");
    connect(buttonLetter, &QPushButton::clicked, this, &ButtonLetter::onClick);
}

void ButtonLetter::display() {
    buttonLetter->show();
}

void ButtonLetter::onClick() {
    buttonLetter->setEnabled(false);
    buttonLetter->setStyleSheet("QPushButton {background-color: blue}");
}

ButtonLetter::~ButtonLetter() {
    delete buttonLetter;
}
