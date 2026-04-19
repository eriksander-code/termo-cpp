#include <iostream>
#include "header.h"

bool sortWord(std::string &_word, int selection, std::string pkgN);

int main() {
    //termo
    bool looper = true;

    do {
        {
            std::string word;
            std::string wordTry;
            Termo *game =new Termo;
            int l{0};
            char key;

            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif



            do {
                game->printStarter();
                std::cin >> key;

                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif

                if (key == '1') {
                    game->printDifficulty();
                    std::cin >> key;
                    switch (key) {
                        case ('1'): sortWord(word, 1, "Null"); looper = false; break;
                        case ('2'): sortWord(word, 2, "Null"); looper = false; break;
                        case ('3'): sortWord(word, 3, "Null"); looper = false; break;
                        case ('4'): sortWord(word, 4, "Null"); looper = false; break;
                        case ('5'): sortWord(word, 5, "Null"); looper = false; break;
                        case ('6'): sortWord(word, 6, "Null"); looper = false; break;
                    }
                }
                else if (key == '2') {
                    game->printRules();
                    std::cin >> key;
                }
                else if (key == '3') {
                    std::string nome;
                    do {
                        std::cout << "Digite o nome EXATO (incluindo\nextensao) do seu pacote:\n";
                        std::cin >> nome;
                        if (sortWord(word, 7, "../data/" + nome) == false) {
                            std::cout << "Nome Invalido.\n";

                        }
                    } while (looper == true);
                    looper = false;
                }
                else if (key == '4') {
                    game->scoreReader();
                    std::cin >> key;
                }

                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif

            } while (looper == true);

            looper = false;
            int i = 0;

            do {
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif

                game->wordInfo(word);
                std::cout << "Tentativas Restantes: " << i+1 << "\n";

                if (l >= 1) {
                    game->printTry(word, wordTry);
                } l++;


                std::cin >> wordTry;

                if (game->compareWords(word, wordTry, i) == true) {
                    break;
                }

                i++;
            } while (i < 6);

            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif

            game->scoreLogger(word);
            game->scoreReader();

            std::cout << "Veja em 'data/score.txt' sua pontuacao.\n";
            std::cout << "Veja em 'data/AllPlay.txt' todas pontuacoes.\n";

            delete game;

            std::cout << "Deseja Jogar Novamente? [1/0]: ";
            std::cin >> looper;
            if ((looper != 0) && (looper != 1)) {
                looper = 0;
            }
        }
    } while (looper == true);

    return 0;
}
