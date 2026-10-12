def two_sum_sorted(nums, target):
    left = 0
    right = len(nums) - 1

    while left < right:
        current = nums[left] + nums[right]

        if current == target:
            return (left, right)
        elif current < target:
            left += 1;  # 总和太小
        else:
            right -= 1;  # 总和太大

    return None
print(two_sum_sorted([1, 2, 4, 7, 11], 9))
print("empty:", two_sum_sorted([], 9))
print("single:", two_sum_sorted([4], 8))
print("duplicate:", two_sum_sorted([4, 4], 8))
print("no_solution:", two_sum_sorted([1, 2, 4], 10))
print("negative:", two_sum_sorted([-5, -1, 2, 7], 1))