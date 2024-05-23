#ifndef WORDLOARDER_H
#define WORDLOARDER_H
#include <unordered_set>
#include <QString>
#include <string>
#include <QFile>
#include <QTextStream>

class WordLoarder
{
public:
    static WordLoarder& instance();
    const std::unordered_set<std::string>& getWord() const;
private:
    WordLoarder();
    void loadWordsFromFile(const QString& filename);
    std::unordered_set<std::string> wordSet;
};

#endif // WORDLOARDER_H
