#ifndef WORDLETTER_H
#define WORDLETTER_H

#include <QWidget>

namespace Ui {
class WordLetter;
}

class WordLetter : public QWidget
{
    Q_OBJECT

public:
    explicit WordLetter(QWidget *parent = nullptr);
    ~WordLetter();

private:
    Ui::WordLetter *ui;
};

#endif // WORDLETTER_H
