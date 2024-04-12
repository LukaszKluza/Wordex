#ifndef BUTTONLETTER_H
#define BUTTONLETTER_H

#include <QPushButton>
#include <QWidget>


class ButtonLetter : public QWidget {
    Q_OBJECT
public:
    ButtonLetter (QWidget *parent, char);
    void setColor();
    void display();
    void onClick();
    void setButtonGeometry(int width, int height);
    ~ButtonLetter();
private:
    char letter;
    QPushButton *buttonLetter;
    QWidget *parent;
    void configuration(char letter);
};

#endif // BUTTONLETTER_H
