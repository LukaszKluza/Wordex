#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include <vector>
#include "ButtonLetter.h"

class Keyboard : public QWidget
{
    Q_OBJECT
public:
    Keyboard(QWidget *parent);
    virtual ~Keyboard();
private:
    QWidget *parent;
    std::vector<char> firstRow {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    std::vector<char> secondRow {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    std::vector<char> thirdRow {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
    std::vector<ButtonLetter*> buttonLetters;
};

#endif // KEYBOARD_H
