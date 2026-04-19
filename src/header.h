#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <conio.h>
#include <cctype>
#include <vector>

class Termo {
    private:
        int qtyVogal(std::string _word);
        int qtyCons(std::string _word);
        std::vector<std::string> howM;
        bool status{false};

    public:

        void scoreReader();
        void scoreLogger(std::string _word);
        void printTry(std::string _word, std::string _wordTry);
        bool compareWords(std::string _word, std::string _wordTry, int _i);
        void wordInfo(std::string _word);
        void printRules();
        void printStarter();
        void printDifficulty();

};

void Termo::scoreReader() {
    std::ifstream score;
    std::string line;
    int i = 0;

    score.open("../data/score.txt");
            if (score.is_open() == true) {
                while (getline(score, line)) {
                    std::cout << line << std::endl;
                }
            }
            else {
                std::cout << "Missing Files.\n";
            }
    score.close();
}

void Termo::scoreLogger(std::string _word) {
    {
        std::ofstream arq;
        int j = 0;
        arq.open("../data/score.txt");
            arq << "------------ SCORE -------------\n";
            arq << "Tentativas:\n";
            for (std::string i : howM) {
                arq << j+1 << "a: " << i << "\n";
                j++;
            }
            if (status == true) {
                arq << "\nStatus de Jogo: GANHADOR\n";
            }
            else if (status == false) {
                arq << "\nStatus de Jogo: PERDEDOR\n";
            }
            arq << "Palavra Correta: " << _word << "\n";
            arq << "--------------------------------\n\n";
        arq.close();

        arq.open("../data/AllPlays.txt", std::ios::app);
            arq << "------------ SCORE -------------\n";
            arq << "Tentativas:\n";
            for (std::string i : howM) {
                arq << j+1 << "a: " << i << "\n";
                j++;
            }
            if (status == true) {
                arq << "\nStatus de Jogo: GANHADOR\n";
            }
            else if (status == false) {
                arq << "\nStatus de Jogo: PERDEDOR\n";
            }
            arq << "Palavra Correta: " << _word << "\n";
            arq << "--------------------------------\n\n";
        arq.close();
    }
};

void Termo::printTry(std::string _word, std::string _wordTry) {
    //compareWords(_word, _wordTry);
    int *i =new int{0};

    for (auto it = howM.begin(); it != howM.end(); it++) {
        (*i)++;

        std::cout << (*i) << "a Tentativa: " << (*it) << std::endl;
    }
    delete i;
};

void Termo::wordInfo(std::string _word) {
    std::cout << "--------- INFO ---------\n";
    std::cout << "Tamanho: " << _word.size() << std::endl;
    std::cout << "Qtde Vogal: " << qtyVogal(_word) << std::endl;
    std::cout << "Qtde Consoante: " << qtyCons(_word) << std::endl;
}

int Termo::qtyCons(std::string _word) {
    int cons{0};
    for (int i = 0; i < _word.size(); i++) {
        switch (toupper(_word[i])) {
            case 'B': case 'C': case 'D': case 'F': case 'G':
            case 'H': case 'J': case 'K': case 'L': case 'M':
            case 'N': case 'P': case 'Q': case 'R': case 'S':
            case 'T': case 'V': case 'W': case 'X': case 'Y':
            case 'Z':
                cons++;
                break;
        }
    }
    return cons;
}

int Termo::qtyVogal(std::string _word) {
    int vgl{0};
    for (int i = 0; i < _word.size(); i++) {
        switch (toupper(_word[i])) {
            case ('A'):
            case ('E'):
            case ('I'):
            case ('O'):
            case ('U'):
                vgl++;
                break;
        }
    }
    return vgl;
}

bool Termo::compareWords(std::string _word, std::string _wordTry, int _i) {
    howM.push_back(_wordTry);

    if (_i < howM.size()) {
        for (int j = 0; j < _word.size(); j++) {
            if (_wordTry == _word) {
                status = true;
                return true;
            }
            if (_wordTry[j] == _word[j]) {
                howM.at(_i)[j] = toupper(_wordTry[j]);
            }
        }
    }

    return false;
}

void Termo::printRules() {
std::ifstream rules;
std::string line;

rules.open("../data/rules.txt");
    if (rules.is_open() == true) {
        while (getline(rules, line)) {
            std::cout << line << std::endl;
        }
    }
    else {
        std::cout << "Missing Files.\n";
    }
rules.close();
}

void Termo::printStarter() {
std::ifstream starter;
std::string line;

starter.open("../data/starter.txt");
    if (starter.is_open() == true) {
        while (getline(starter, line)) {
            std::cout << line << std::endl;
        }
    }
    else {
        std::cout << "Missing Files.\n";
    }
starter.close();
}

void Termo::printDifficulty() {
std::ifstream diff;
std::string line;

diff.open("../data/diff.txt");
    if (diff.is_open() == true) {
        while (getline(diff, line)) {
            std::cout << line << std::endl;
        }
    }
    else {
        std::cout << "Missing Files.\n";
    }
diff.close();
}



#endif // HEADER_H_INCLUDED
