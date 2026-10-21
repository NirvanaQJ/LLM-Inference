def two_sum_hash(nums,target):
    num_to_index = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in num_to_index:
            return (num_to_index[complement], i)
        num_to_index[num] = i
    return None

print("ordinary:", two_sum_hash([2, 7, 11, 15], 9))  # 预期 (0, 1)
print("single:", two_sum_hash([2], 9))                # 预期 None
print("empty:", two_sum_hash([], 6))                 # 预期 None