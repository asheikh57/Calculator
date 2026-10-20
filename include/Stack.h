#ifndef STACK_H
#define STACK_H

#include <memory>
#include <stdexcept>
#include <utility>

template<typename T>
class Stack {
    public:
      [[nodiscard]] T pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack.h : pop() : Empty, stack underflow");
        }
        // Transfer ownership to local variables
        std::unique_ptr<Node> old = std::move(head_);
        T ret = std::move(old->val);

        // Set new head and update params
        head_ = std::move(old->next);
        size_--;
        return ret;
      }

      void push(T val) {
        std::unique_ptr<Node> new_head = std::make_unique<Node>(std::move(val));
        new_head->next = std::move(head_);
        head_ = std::move(new_head);
        size_++;
      }

      [[nodiscard]] bool isEmpty() {
        return size_ == 0;
      }

      [[nodiscard]] size_t size() {
        return size_;
      }

    private:
     struct Node {
        T val;
        std::unique_ptr<Node> next;
        Node(T data) : val(data), next(nullptr) {};
     };

     std::size_t size_;
     std::unique_ptr<Node> head_;
      
};

#endif