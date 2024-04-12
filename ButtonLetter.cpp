#include "ButtonLetter.h"



ButtonLetter::ButtonLetter(QWidget *parent, char letter) : letter(letter), parent(parent) {
    buttonLetter = new QPushButton(parent);

    configuration(letter);
}

void ButtonLetter::setButtonGeometry(int width, int height) {
    buttonLetter->setGeometry(width, height,30,30);

}


void ButtonLetter::configuration(char letter)
{
    buttonLetter->setStyleSheet("background-color: rgb(123, 0, 0); color: white;");
    buttonLetter->setText(QString(letter));
    buttonLetter->setFixedSize(30,30);
    buttonLetter->setStyleSheet("QPushButton {text-align: center}");
    connect(buttonLetter, &QPushButton::clicked, this, &ButtonLetter::onClick);
}

void ButtonLetter::display() {
    buttonLetter->show();
}

void ButtonLetter::onClick() {
    buttonLetter->setEnabled(false);
}

ButtonLetter::~ButtonLetter() {
    delete buttonLetter;
}
