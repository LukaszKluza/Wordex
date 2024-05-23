#include "wordloarder.h"
#include "QDebug"

WordLoarder::WordLoarder()
{
    loadWordsFromFile("C:/Users/Lenovo/Desktop/Studia/Semestr4/C++_2024/Wordex-Project/Wordex/Words/5-letter-words.txt");
}
WordLoarder& WordLoarder::instance(){
    static WordLoarder instance;
    return instance;
}

void WordLoarder::loadWordsFromFile(const QString &filename){
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
          qDebug() << "Opening error!" << file.errorString();
          return;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString word = in.readLine().trimmed();
        if(!word.isEmpty()){
            wordSet.insert(word.toStdString());
        }
    }
    file.close();
}

const std::unordered_set<std::string>& WordLoarder::getWord() const{
    return wordSet;
}
