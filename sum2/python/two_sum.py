import sys
from typing import Sequence


def find_two_sum_pair(target: int, values: Sequence[int]) -> tuple[int, int] | None:
    to_index = {}
    for i, value in enumerate(values):
        needed = target - value
        if (index := to_index.get(needed, None)) is not None:
            return (index, i)
        to_index.setdefault(value, i)
    return None


if __name__ == "__main__":
    args = list(map(int, sys.argv[1:]))
    if len(args) > 0:
        print(find_two_sum_pair(args[0], args[1:]))
