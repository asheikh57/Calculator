#ifndef STACK_H
#define STACK_H

#include <memory>

template<typename T>
class Stack {
    public:
      T pop() {
        // TODO
        T TODO;
        return TODO;
      }

      void push(T val) {
        // TODO
      }

      bool is_empty() {
        // TODO
        return true;
      }

    private:
     struct Node {
        T val;
        std::unique_ptr<T> next;
     };
     size_t size;
      
};

#endif