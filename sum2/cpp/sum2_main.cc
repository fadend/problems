#include <iostream>
#include <unordered_map>
#include <optional>
#include <span>
#include <utility>
#include <vector>

typedef std::optional<std::pair<int, int>> Result;

auto find_sum2(int target, std::span<int> values) -> Result {
  std::unordered_map<int, int> to_index;
  int n = values.size();
  for (int i = 0; i < n; ++i) {
    const int value = values[i];
    const int needed = target - value;
    auto it = to_index.find(needed);
    if (it != to_index.end()) {
      return std::make_pair(it->second, i);
    }
    to_index.emplace(value, i);
  }
  return std::nullopt;
}

void print_result(Result result) {
  if (result) {
    std::cout << result->first << ", " << result->second << '\n';
  } else {
    std::cout << "None\n";
  }
}

auto main() -> int {
  std::vector<int> values = {1, 1, 2, 3};
  auto result = find_sum2(3, values);
  print_result(result);
}
