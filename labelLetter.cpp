#include "labelLetter.h"

LabelLetter::LabelLetter(QWidget *parent): parent(parent){
    labelLetter = new QLabel(parent);
}
LabelLetter::LabelLetter(QWidget *parent, size_t width, size_t height):parent(parent), width_(width), height_(height){
    labelLetter = new QLabel(parent);
    setSize(width_, height_);
}
void LabelLetter::setSize(size_t width, size_t height){
    width_ = width;
    height_ = height;
    labelLetter->setFixedSize(width, height);
}
void LabelLetter::setGeometry(int xAsix, int yAsix){
    setGeometry(xAsix, yAsix, width_, height_);
}

void LabelLetter::setGeometry(int xAsix, int yAsix, int width, int height){
    labelLetter->setGeometry(xAsix, yAsix, width, height);
}
void LabelLetter::update(char c){
    labelLetter->setText(QString(c));
    letter = c;
}
char LabelLetter::getLetter(){
    return tolower(letter);
}
void LabelLetter::setContainColor(){
    labelLetter->setStyleSheet("background-color: #FF8413; border-radius: 10px; text-align: center; qproperty-alignment: 'AlignCenter'");
}
void LabelLetter::setCorrectColor(){
    labelLetter->setStyleSheet("background-color: #33CC66; border-radius: 10px; text-align: center; qproperty-alignment: 'AlignCenter'");
}
void LabelLetter::setOriginColor(){
    labelLetter->setStyleSheet("background-color: #AAA; border-radius: 10px; text-align: center; qproperty-alignment: 'AlignCenter'");
}
LabelLetter::~LabelLetter(){
    if (labelLetter != nullptr) {
           delete labelLetter;
           labelLetter = nullptr;
     }
}
