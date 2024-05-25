// Copyright 2024 UNN-IASR
#include <iostream>
#include "Automata.h"

void demo() {
    Automata automata;

    // Включение автомата
    std::cout << "\nДемонстрация работы автомата"
        << std::endl;
    automata.on();
    std::cout << "Текущее состояние: "
        << automata.getState() << std::endl;

    // Показать меню
    automata.getMenu();

    // Внесение денег
    std::cout << "Внесение 10 копеек..."
        << std::endl;
    automata.coin(10);
    std::cout << "Текущее состояние: "
        << automata.getState() << std::endl;

    std::cout << "Внесение еще 10 копеек..."
        << std::endl;
    automata.coin(10);
    std::cout << "Текущее состояние: "
        << automata.getState() << std::endl;

    // Выбор напитка
    std::cout << "Выбор напитка: Кофе" << std::endl;
    automata.choice(1);  // Выбираем кофе (индекс 1)
    std::cout << "Текущее состояние: "
        << automata.getState() << std::endl;

    // Завершение приготовления
    automata.finish();
    std::cout << "Текущее состояние: "
        << automata.getState() << std::endl;

    // Выключение автомата
    automata.off();
    std::cout << "Текущее состояние: "
        << automata.getState() << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    demo();
    return 0;
}
