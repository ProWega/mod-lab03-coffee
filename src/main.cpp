// Copyright 2024 UNN-IASR
#include <iostream>
#include "Automata.h"

int main() {
    setlocale(LC_ALL, "Russian");
    Automata automata;
    int choice;
    int amount;

    do {
        std::cout << "\nТекущее состояние: "
            << automata.getState() << std::endl;
        std::cout << "1. Включить" << std::endl;
        std::cout << "2. Выключить" << std::endl;
        std::cout << "3. Внести деньги" << std::endl;
        std::cout << "4. Показать меню" << std::endl;
        std::cout << "5. Выбрать напиток" << std::endl;
        std::cout << "6. Отмена" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            automata.on();
            break;
        case 2:
            automata.off();
            break;
        case 3:
            std::cout << "Введите сумму: ";
            std::cin >> amount;
            automata.coin(amount);
            break;
        case 4:
            automata.getMenu();
            break;
        case 5:
            int drinkChoice;
            std::cout << "Введите номер напитка: ";
            std::cin >> drinkChoice;
            automata.choice(drinkChoice - 1);
            break;
        case 6:
            automata.cancel();
            break;
        case 0:
            std::cout << "Выход..." << std::endl;
            break;
        default:
            std::cout <<
                "Неверный выбор. Пожалуйста, попробуйте снова."
                << std::endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
