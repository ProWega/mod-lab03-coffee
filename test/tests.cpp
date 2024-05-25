// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

// Тест включения автомата
TEST(AutomataTest, TurnOn) {
    Automata automata;
    automata.on();
    EXPECT_EQ(automata.getState(), "WAIT");
}

// Тест выключения автомата
TEST(AutomataTest, TurnOff) {
    Automata automata;
    automata.on();
    automata.off();
    EXPECT_EQ(automata.getState(), "OFF");
}

// Тест внесения денег в автомат
TEST(AutomataTest, InsertCoin) {
    Automata automata;
    automata.on();
    automata.coin(10);
    EXPECT_EQ(automata.getState(), "ACCEPT");
}

// Тест показа меню
TEST(AutomataTest, ShowMenu) {
    Automata automata;
    automata.on();
    testing::internal::CaptureStdout();
    automata.getMenu();
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected_output = "Меню:\n1. Чай - 10 копеек\n2."
    "Кофе - 15 копеек\n3. Молоко - 20 копеек\n";
    EXPECT_EQ(output, expected_output);
}

// Тест выбора напитка с достаточными средствами
TEST(AutomataTest, ChooseDrinkSufficientFunds) {
    Automata automata;
    automata.on();
    automata.coin(20);
    automata.choice(1);
    EXPECT_EQ(automata.getState(), "WAIT");
}

// Тест выбора напитка с недостаточными средствами
TEST(AutomataTest, ChooseDrinkInsufficientFunds) {
    Automata automata;
    automata.on();
    automata.coin(10);
    automata.choice(1);
    EXPECT_EQ(automata.getState(), "ACCEPT");
}

// Тест отмены операции
TEST(AutomataTest, CancelOperation) {
    Automata automata;
    automata.on();
    automata.coin(10);
    automata.cancel();
    EXPECT_EQ(automata.getState(), "WAIT");
}

// Тест приготовления напитка
TEST(AutomataTest, CookDrink) {
    Automata automata;
    automata.on();
    automata.coin(20);
    automata.choice(1);
    EXPECT_EQ(automata.getState(), "WAIT");
}

// Тест состояния после завершения приготовления напитка
TEST(AutomataTest, FinishCooking) {
    Automata automata;
    automata.on();
    automata.coin(20);
    automata.choice(1);
    automata.finish();
    EXPECT_EQ(automata.getState(), "WAIT");
}

// Тест состояния после повторного включения автомата
TEST(AutomataTest, RepeatedTurnOn) {
    Automata automata;
    automata.on();
    automata.off();
    automata.on();
    EXPECT_EQ(automata.getState(), "WAIT");
}
