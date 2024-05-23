#include "gameplay.h"
#include <memory>
#include <QMessageBox>
#include <QFile>
#include <wordloarder.h>
#include <ctime>
#include <random>
#include <iostream>

#define padding 10
#define labelSize 60

Gameplay::Gameplay(QWidget *parent) : parent(parent), keyboard(new Keyboard(parent, this)) {
    keyboard->display();

    QFile styleFile("C:/Users/Lenovo/Desktop/Studia/Semestr4/C++_2024/Wordex-Project/Wordex/Styles/style.css");
    styleFile.open(QFile::ReadOnly);
    style = QLatin1String(styleFile.readAll());

    WordLoarder& wordLoader = WordLoarder::instance();
    words = wordLoader.getWord();
    drawSolution();

    labelLetters.resize(level);
    int allWidth = level*(labelSize+padding);
    int parentWidth = parent->width();
    int parentHeight = parent->height();
    for(unsigned i=0; i<level; ++i){
        labelLetters[i].resize(level);
        for(unsigned j = 0; j<level; ++j){
            labelLetters[i][j] = new LabelLetter(parent);
            labelLetters[i][j]->setGeometry(j*(labelSize+padding) + (parentWidth-allWidth)/2 ,parentHeight/30+i*(labelSize+padding),labelSize, labelSize);
            labelLetters[i][j]->setOriginColor();
        }
    }
}

void Gameplay::update(char c){
    if(currLetter< level){
        labelLetters[currAttempt][currLetter++]->update(c);
        tempSolution += tolower(c);
    }
}
void Gameplay::erase(){
    if(currLetter>0){
        labelLetters[currAttempt][--currLetter]->update(' ');
        tempSolution.pop_back();
    }
}
void Gameplay::showMessageBox(QString name, QString message){
    QMessageBox messageBox;
    QPushButton *tryAgainButton {};
    messageBox.setObjectName(name);
    messageBox.setWindowFlag(Qt::FramelessWindowHint);
    messageBox.setStyleSheet(style);
    messageBox.setText(message);

    if(name != "Warning"){
         tryAgainButton = messageBox.addButton("Try again", QMessageBox::ActionRole);
    }

    messageBox.exec();

    if(name != "Warning" && messageBox.clickedButton() == tryAgainButton){
        tryAgain();
    }


}

void Gameplay::tryAgain(){
    for(char c = 'A'; c <= 'Z'; c++){
        keyboard->setEnabled(c, true);
    }
    for(size_t i=0; i<level; ++i){
        for(size_t j=0; j<level; ++j){
            labelLetters[i][j]->update();
            labelLetters[i][j]->setOriginColor();
        }
    }
    drawSolution();
    currAttempt=0;
    currLetter=0;
}

void Gameplay::check(){
    size_t tempScore {};

    if(currLetter != level){
        return;
    }
    if(!words.count(tempSolution)){
        showMessageBox("Warning","Uncorrect word!");
        return;
    }
    for(unsigned i =0; i<level; ++i){
        if(solution[i] == labelLetters[currAttempt][i]->getLetter()){
            labelLetters[currAttempt][i]->setCorrectColor();
            tempScore++;
        }
        else if(solution.find(labelLetters[currAttempt][i]->getLetter()) != std::string::npos){
            labelLetters[currAttempt][i]->setContainColor();
        }else{
            keyboard->setEnabled(labelLetters[currAttempt][i]->getLetter(), false);
        }
    }
    if(tempScore == level){
        showMessageBox("WinningBox", "Congratulations! \n You won!");
    }
    else if(++currAttempt==level){
        showMessageBox("LosingBox", "You lost!");
    }
    currLetter=0;
    tempSolution="";
}
void Gameplay::drawSolution(){
    size_t numWords = words.size();
    srand(time(nullptr));
    size_t randNum = rand()%numWords;
    auto it = words.begin();
    std::advance(it, randNum);
    solution = *it;
    std::cout<< solution<<std::endl;
}

template <typename T>
void Gameplay::toMap(const T& word, std::map<char, size_t> &resultMap){
    resultMap.clear();

    for(auto c: word){
        resultMap[c]++;
    }
}

Gameplay::~Gameplay(){
    for(unsigned i=0; i<level; ++i){
        for(unsigned j = 0; j<level; ++j){
            delete labelLetters[i][j];
        }
    }
    delete parent;
    delete keyboard;
}
