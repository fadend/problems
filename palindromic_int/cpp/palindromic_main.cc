#include <iostream>

bool is_palindrome(int x) {
  if (x < 0) {
    return false;
  }
  int remaining = x;
  int reversed = 0;
  while (remaining > 0) {
    reversed = 10 * reversed + (remaining % 10);
    remaining /= 10;
  }
  return reversed == x;
}

int main() {
  const int x = 105012;
  std::cout << x << " palindromic? " << (is_palindrome(x) ? "yes" : "no") << '\n';
}
