#pragma once

class Calculator {
    public:
      virtual void evalExpression(const char * expr)  = 0;
      virtual ~Calculator() = default;
}