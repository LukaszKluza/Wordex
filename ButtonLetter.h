#ifndef BUTTONLETTER_H
#define BUTTONLETTER_H

#include <QPushButton>
#include <QWidget>


class ButtonLetter : public QWidget{
    Q_OBJECT
public:
    ButtonLetter (QWidget *parent, char);
    void setColor();
    void display();
    void onClick();
    ~ButtonLetter();
private:
    char letter;
    QPushButton *buttonLetter;
    QWidget *parent;
};

#endif // BUTTONLETTER_H
