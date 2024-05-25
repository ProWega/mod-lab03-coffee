// Copyright 2024 UNN-IASR
#include "Automata.h"
#include "windows.h"

Automata::Automata() : cash(0), state(OFF) {
    menu = { "���", "����", "������" };
    prices = { 10, 15, 20 };
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        std::cout << "������� �������." << std::endl;
    }
}

void Automata::off() {
    if (state != OFF) {
        state = OFF;
        cash = 0;
        std::cout << "������� ��������." << std::endl;
    }
}

void Automata::coin(int amount) {
    if (state == WAIT || state == ACCEPT) {
        cash += amount;
        state = ACCEPT;
        std::cout << "������� " <<
            amount <<
            " ������. ����� �����: " <<
            cash << " ������."
            << std::endl;
    }
}

void Automata::getMenu() const {
    std::cout << "����:" << std::endl;
    for (size_t i = 0; i < menu.size(); ++i) {
        std::cout << i + 1 << ". "
            << menu[i] << " - "
            << prices[i] <<
            " ������" << std::endl;
    }
}

std::string Automata::getState() const {
    switch (state) {
    case OFF: return "OFF";
    case WAIT: return "WAIT";
    case ACCEPT: return "ACCEPT";
    case CHECK: return "CHECK";
    case COOK: return "COOK";
    }
    return "UNKNOWN";
}

void Automata::choice(int index) {
    if (state == ACCEPT &&
        index >= 0 &&
        static_cast<size_t>(index) < menu.size()) {
        std::cout << "�������: "
            << menu[index] << std::endl;
        state = CHECK;
        check(index);
    }
    else {
        std::cout <<
            "�������� ����� ��� ������������ ���������."
            << std::endl;
    }
}

void Automata::check(int index) {
    if (state == CHECK) {
        if (cash >= prices[index]) {
            std::cout << "���������� �������." << std::endl;
            state = COOK;
            cook(index);
        }
        else {
            std::cout << "������������ �������." << std::endl;
            state = ACCEPT;
        }
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        std::cout << "�������� ��������. ���������� " <<
            cash << " ������." << std::endl;
        cash = 0;
        state = WAIT;
    }
}

void Automata::cook(int index) {
    if (state == COOK) {
        std::cout << "������������� " << menu[index] << "..." << std::endl;
        Sleep(3); // �������� ������� �������������
        std::cout << menu[index] << " �����!" << std::endl;
        cash -= prices[index];
        state = WAIT;
    }
}

void Automata::finish() {
    if (state == COOK) {
        std::cout << "����������..." << std::endl;
        state = WAIT;
    }
}
