// Copyright 2024 UNN-IASR
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <string>
#include <iostream>
#include <vector>

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
 private:
  int cash;
  std::vector<std::string> menu;
  std::vector<int> prices;
  STATES state;

 public:
  Automata();

  void on();
  void off();
  void coin(int amount);
  void getMenu() const;
  std::string getState() const;
  void choice(int index);
  void check(int index);
  void cancel();
  void cook(int index);
  void finish();
};

#endif // INCLUDE_AUTOMATA_H_