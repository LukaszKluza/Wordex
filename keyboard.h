#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "ButtonLetter.h"
#include <QPushButton>

class Gameplay;

class Keyboard: public QObject
{
public:
    Keyboard(QWidget *window, Gameplay *gameplay);
    void display();
    void handleLetterClick(char letter);
    void handleEraseClick();
    void handleEnterClick();
    void setEnabled(char letter, bool status);
    ~Keyboard();
private:
    void displayRow(int begining, int number, int rowIndex);
    ButtonLetter **buttonLetters;
    QWidget *window;
    Gameplay *gameplay;
    QPushButton *enter, *erase;
};

#endif // KEYBOARD_H
