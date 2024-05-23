#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <QWidget>
#include <memory>
#include <vector>
#include <unordered_set>
#include "labelLetter.h"
#include "keyboard.h"
#include "map"

class Gameplay
{
public:
    Gameplay(QWidget *parent);
    void displayGameBoard();
    void update(char c);
    void erase();
    void check();
    void tryAgain();
    void drawSolution();
    template<typename T>
    void toMap(const T& word, std::map<char, size_t> &resultMap);
    ~Gameplay();

private:
    unsigned level = 5;
    QWidget *parent;
    Keyboard *keyboard;
    QString style;
    size_t currAttempt = {}, currLetter = {};
    std::vector<std::vector<LabelLetter *>> labelLetters;
    std::string solution;
    std::string tempSolution;
    std::unordered_set<std::string> words;

    void showMessageBox(QString name, QString message);
};

#endif // GAMEPLAY_H
