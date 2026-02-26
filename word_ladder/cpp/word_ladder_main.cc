#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

struct Possibility {
  std::string head;
  std::unordered_set<std::string> predecessors;
};

int find_lower_ascii_word_ladder_len(const std::unordered_set<std::string>& words, std::string start, std::string stop) {
  std::vector<Possibility> possibilities = {{.head = start}};
  while (!possibilities.empty()) {
    std::vector<Possibility> new_possibilities;
    for (const Possibility& p : possibilities) {
      auto new_predecessors = p.predecessors;
      new_predecessors.insert(p.head);
      const int n = p.head.size();
      std::string new_head = p.head;
      for (int i = 0; i < n; ++i) {
        const char old_c = new_head[i];
        for (char c = 'a'; c <= 'z'; ++c) {
          if (old_c == c) {
            continue;
          }
          new_head[i] = c;
          if (new_head == stop) {
            return new_predecessors.size() + 1;
          } else if (words.count(new_head) > 0 && new_predecessors.count(new_head) == 0) {
            new_possibilities.emplace_back(new_head, new_predecessors);
          }
        }
        // Restore the original value.
        new_head[i] = old_c;
      }
    }
    possibilities.swap(new_possibilities);
  }
  return -1;
}

int main() {
  std::cout << find_lower_ascii_word_ladder_len({"dog", "cog", "cot", "cat", "rob"}, "dog", "cog") << '\n';
}
