def binary_search(nums, target):
    left = 0
    right = len(nums) - 1

    while left <= right:
        mid = (left + right) // 2

        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            left = mid + 1   # 中间值太小，排除左半边和中点
        else:
            right = mid - 1  # 中间值太大，排除右半边和中点

    return -1


if __name__ == "__main__":
    # 导师提供的测试：expected 下标按输入手工确定，重复值允许任一匹配。
    cases = [
        ("ordinary", [2, 5, 8, 12, 16, 23, 38], 16, (4,)),
        ("not_found", [2, 5, 8, 12, 16, 23, 38], 9, (-1,)),
        ("empty", [], 5, (-1,)),
        ("single_found", [5], 5, (0,)),
        ("single_missing", [5], 4, (-1,)),
        ("first", [2, 5, 8], 2, (0,)),
        ("last", [2, 5, 8], 8, (2,)),
        ("duplicate", [2, 5, 5, 8], 5, (1, 2)),
    ]

    for name, nums, target, expected in cases:
        before = nums.copy()
        actual = binary_search(nums, target)
        assert type(actual) is int, f"{name}: expected int, got {type(actual)}"
        assert actual in expected, f"{name}: expected={expected}, actual={actual}"
        assert nums == before, f"{name}: input was modified"
        print(f"{name}: expected={expected}, actual={actual} passed")

    print(f"{len(cases)} cases passed")
