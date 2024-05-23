#include "keyboard.h"
#include "gameplay.h"

#define padding 5
#define size 45


Keyboard::Keyboard(QWidget *window, Gameplay *gameplay) : window(window), gameplay(gameplay)
{
    char alphabet[26] = {'Q','W','E','R','T','Y','U','I','O','P', 'A', 'S', 'D', 'F','G','H','J','K','L','Z','X','C','V','B','N','M'};
    buttonLetters = new ButtonLetter*[26];
    for(int i=0; i<26; ++i){
        buttonLetters[i] = new ButtonLetter(window, alphabet[i], size,size);
        connect(buttonLetters[i], &ButtonLetter::clickedWithLetter, this, &Keyboard::handleLetterClick);
    }

    enter = new QPushButton(window);
    erase = new QPushButton(window);
    connect(erase, &QPushButton::clicked, this, &Keyboard::handleEraseClick);
    connect(enter, &QPushButton::clicked, this, &Keyboard::handleEnterClick);

}

void Keyboard::display(){
    displayRow(0,10,0);
    displayRow(10,9,1);
    displayRow(19,7,2);   
}

void Keyboard::displayRow(int begining, int number, int rowIndex){
    int allWidth = number*(size+padding)-padding;
    for(int i=begining; i<begining+number; ++i){
        buttonLetters[i]->display();
        buttonLetters[i]->setGeometry((i-begining)*(size+padding) + (window->width()-allWidth)/2 ,5*window->height()/7+rowIndex*(size+padding));
    }
    if(rowIndex == 2){
        enter->show();
        erase->show();
        enter->setText("ENTER");
        erase->setText("ERASE");
        enter->setGeometry((window->width()-allWidth)/2 -1.5*size-padding ,5*window->height()/7+rowIndex*(size+padding), 1.5*size, size);
        erase->setGeometry(number*(size+padding)+(window->width()-allWidth)/2 ,5*window->height()/7+rowIndex*(size+padding), 1.5*size, size);
    }
}

void Keyboard::handleLetterClick(char letter) {
    if (gameplay)
        gameplay->update(letter);
}
void Keyboard::handleEraseClick(){
    if (gameplay)
        gameplay->erase();
}

void Keyboard::handleEnterClick(){
    if(gameplay)
        gameplay->check();
}
void Keyboard::setEnabled(char letter, bool status){
    for(size_t i =0; i<26; ++i){
        if(buttonLetters[i]->getLetter()==toupper(letter)){
            buttonLetters[i]->setEnabled(status);
        }
    }
}

Keyboard::~Keyboard(){
    delete [] buttonLetters;
    delete enter;
    delete erase;
 }
