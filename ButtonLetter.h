#ifndef BUTTONLETTER_H
#define BUTTONLETTER_H

#include <QPushButton>
#include <QWidget>
#include <memory>


class ButtonLetter : public QWidget{
    Q_OBJECT
public:
    ButtonLetter (QWidget *parent, char c);
    ButtonLetter (QWidget *parent, char c, int height, int width = 0);
    void setConfiguration();
    void setColor();
    void setEnabled(bool status);
    void setSize(int width, int height);
    void setGeometry(int xAsix, int yAsix, int width, int height);
    void setGeometry(int xAsix, int yAsix);
    char getLetter();
    void display();
    void onClick();
    ~ButtonLetter();

    signals:
        void clickedWithLetter(char letter);


private:
    char letter;
    size_t width_, height_;
    QPushButton *buttonLetter;
    QWidget *parent;
};

#endif // BUTTONLETTER_H
