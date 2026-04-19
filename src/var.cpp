#include <iostream>
#include <random>
#include <fstream>

int qntArch(std::string nome) {
    std::ifstream arq;
    std::string line;
    int indice = 0;

    if (nome == "Null") {
        return 100;
    }

    arq.open(nome);
        if (arq.is_open() == true) {
            while (getline(arq, line)) {
                indice++;
            }
            return indice;
        }
        else {
            std::cout << "Could not open the archive.\n";
        }
    arq.close();
    return 0;
}

bool sortWord(std::string &_word, int selection, std::string pkgN) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, qntArch(pkgN));

    std::ifstream arq;
    std::string which_arq;
    switch (selection) {
        case (1): which_arq = "../data/words-package-01.txt"; break;
        case (2): which_arq = "../data/words-package-02.txt"; break;
        case (3): which_arq = "../data/words-package-03.txt"; break;
        case (4): which_arq = "../data/words-package-04.txt"; break;
        case (5): which_arq = "../data/words-package-05.txt"; break;
        case (6): which_arq = "../data/words-package-06.txt"; break;
    }

    if (selection == 7) {
        which_arq = pkgN;
    }

    arq.open(which_arq);
        if (arq.is_open() == true) {
            for (int i = 0; i <= dist(gen); i++) {
                std::getline(arq, _word);
            }
            return true;
        }
        else {
            std::cout << "Could not open the archive.\n";
            return false;
        }
    arq.close();
    return false;
}


