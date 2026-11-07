#pragma once
#include "Calulator.h"
#include "Stack.h"

class BasicRpnCalculator : public Calculator {
    void evalExpression(const char *) override;

    private:
      bool debug = false;
      bool isPersistent = false;
      Stack<int> nums_;
}