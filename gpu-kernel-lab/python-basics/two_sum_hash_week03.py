def two_sum_hash(nums, target):
    num_to_index = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in num_to_index:
            return (num_to_index[complement], i)
        num_to_index[num] = i
    return None


print("ordinary:", two_sum_hash([8, 3, 6, 2], 9))
print("empty:", two_sum_hash([], 9))
print("single:", two_sum_hash([4], 8))
print("duplicate:", two_sum_hash([4, 4], 8))
print("no_solution:", two_sum_hash([1, 2, 4], 10))
print("negative:", two_sum_hash([-3, 7, 2, 9], 4))
print("zero:", two_sum_hash([0, 5, 0], 0))
