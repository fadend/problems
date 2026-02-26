#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>

std::string find_longest_no_repeat(std::string input) {
  std::unordered_map<char, int> last_occurrence;
  int max_start = 0;
  int max_len = 0;
  int current_len = 0;
  const int n = input.size();
  for (int i = 0; i < n; ++i) {
    const char c = input[i];
    auto last_it = last_occurrence.find(c);
    if (last_it != last_occurrence.end()) {
      current_len = std::min(i - last_it->second + 1, current_len);
    } else {
      ++current_len;
    }
    if (current_len > max_len) {
      max_len = current_len;
      max_start = i - max_len + 1;
    }
    last_occurrence[c] = i;
  }
  return input.substr(max_start, max_len);
}

auto main() -> int {
  std::cout << "<<" << find_longest_no_repeat("abcxyzabcdef") << ">>\n";
}
