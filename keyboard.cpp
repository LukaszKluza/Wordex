#include "keyboard.h"

#define ull unsigned long long

Keyboard::Keyboard(QWidget *parent) : parent(parent) {
    for(ull i=0; i<firstRow.size(); ++i){
        ButtonLetter *newButtonLetter = new ButtonLetter(parent, firstRow[i]);
        newButtonLetter->setButtonGeometry(30*i,0);
        newButtonLetter->display();
        buttonLetters.push_back(newButtonLetter);
    }
}

Keyboard::~Keyboard(){
    for (ButtonLetter* button : buttonLetters) {
        delete button;
    }
}
