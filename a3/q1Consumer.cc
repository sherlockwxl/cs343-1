#ifndef Q1_CONSUMER_CC
#define Q1_CONSUMER_CC

#include <uC++.h>
#include <cstdlib>
#include <iostream>

#include "q1BoundedBuffer.cc"

using namespace std;

_Task Consumer {
 public:
  Consumer(BoundedBuffer<int32_t>& buffer,
           const int32_t delay,
           const int32_t sentinel,
           int32_t& sum)
    : buffer_(buffer),
      delay_(delay),
      sentinel_(sentinel),
      sum_(sum) { }
 private:
  BoundedBuffer<int32_t>& buffer_;
  const int32_t delay_;
  const int32_t sentinel_;
  int32_t& sum_;
  void main() {
    sum_ = 0;
    while (true) {
      yield(rand() % delay_);
      int32_t value = buffer_.remove();
      if (value == sentinel_) {
        cout << "received sentinel" << endl;
        break;
      }
      sum_ += value;
    }
  }
};

#endif // Q1_CONSUMER_CC
