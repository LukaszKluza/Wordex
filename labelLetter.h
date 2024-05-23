#ifndef LABELLETTER_H
#define LABELLETTER_H

#include <QWidget>
#include <QLabel>
#include <QString>

class LabelLetter
{
public:
    LabelLetter(QWidget *parent);
    LabelLetter(QWidget *parent, size_t width, size_t height);
    void setSize(size_t width, size_t height);
    void setGeometry(int xAsix, int yAsix, int width, int height);
    void setGeometry(int xAsix, int yAsix);
    void update(char c = ' ');
    char getLetter();
    void setContainColor();
    void setCorrectColor();
    void setOriginColor();
    ~LabelLetter();
    QLabel *labelLetter;

private:
    QWidget *parent;
    size_t width_, height_;
    char letter;
};

#endif // LABELLETTER_H
