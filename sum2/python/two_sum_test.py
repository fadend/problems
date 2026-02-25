import two_sum


def test_two_sum_empty():
    assert None == two_sum.find_two_sum_pair(33, [])


def test_two_sum_positive():
    assert (0, 2) == two_sum.find_two_sum_pair(5, [2, 6, 3, 7])


def test_two_sum_first_only():
    assert (1, 4) == two_sum.find_two_sum_pair(0, [1, 2, 2, 2, -2, 3])


def test_two_sum_not_there():
    assert None == two_sum.find_two_sum_pair(9, [1, 2, 3])
