#include "Stack.h"
#include <iostream>
#include <string_view>
#include <format>

// Only looks at INTS from 0 to 9
class BasicRpnCalculator {
    public:
      void readExpression(const char * expr) {
        int num = 1;
        for(char ch : std::string_view(expr)) {
            if (isNum(ch)) {
                num = ch - '0';
                nums.push(num);
                debugMsg("readExpression", std::format("pushed char '{}' as int {} to stack", ch, num));
            } else if (isBinop(ch)) {
                debugMsg("readExpression", std::format("read '{}' binop", ch));
                doBinop(ch);
            }
        }
        // TODO: deal with bad inputs better, if I care enough to do so.

        auto num = nums.pop();
        std::cout << "Calculation finished output: " << num << std::endl;
        if (!isPersistent) nums.clear();
        else if (isPersistent) nums.push(num);
      }

      void debugMsg(const char * func, const char * msg) {
        if(debug) std::clog << "BasicRpnCalc: " << func << ": " << msg << "\n";
      }

      void debugMsg(const char * func, const std::string msg) {
        if(debug) std::clog << "BasicRpnCalc: " << func << ": " << msg << "\n";
      }

      void debugMsg(const char * msg) {
        if(debug) std::clog << "BasicRpnCalc: " << msg << "\n";
      }

      void setDebug(bool flag) { debug = flag; }
      void setPersistence(bool flag) { isPersistent = flag; }

    private:
      void doBinop(const char &ch) {
        int num2 = nums.pop(), num1 = nums.pop();
        debugMsg("doBinop", std::format("popped {}, {} from stack", num1, num2));
        int ret;
        switch(ch) {
            case '+' :
              ret = num1 + num2;
              break;
            case '-' : 
              ret = num1 - num2;
              break;
            case '*' : 
              ret = num1 * num2;
              break;
            case '/' : 
              ret = num1 / num2;
              break;
        }
        nums.push(ret);
        debugMsg("doBinop", std::format("pushed ({}{}{}=){} onto stack", num1, ch, num2, ret));
      }

      [[nodiscard]] bool isBinop(const char &c) {
        return (c == '+' || c == '-' || c == '/' || c == '*');
      }

      [[nodiscard]] bool isNum(const char &c) {
        return (c >= '0' && c <= '9');
      }

      bool debug = false;
      bool isPersistent = false;
      Stack<int> nums;
};

void repl() {
    BasicRpnCalculator rpn;
    rpn.setDebug(true);
    rpn.setPersistence(true);
    std::string line;
    while( std::getline(std::cin, line)) {
        if (line == "exit" || line == "stop" || line == "exit()" || line == "") break;
        rpn.readExpression(line.c_str());
    }
}


int main() {
    /*
    Stack<char> st;
    const char * expr = "2 3 + 4 * 1 / 5 *";
    //for(char c: expr) st.push(c);
    //for(auto c: expr) std::cout << st.pop() << std::endl;

    BasicRpnCalculator rpn;
    rpn.setDebug(true);
    rpn.readExpression(expr);
    */
    repl();
    return 0;
}