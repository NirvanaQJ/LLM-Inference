def two_sum_hash(nums, target):
    seen = {}

    for i, x in enumerate(nums):
        need = target - x

        if need in seen:
            return (seen[need],i)


        # TODO 2：把当前数字 x 和下标 i 记录到 seen
        seen[x] = i
    return None


print(two_sum_hash([8, 3, 6, 2], 9))
print("empty:", two_sum_hash([], 9))                  # 预期 None
print("single:", two_sum_hash([4], 8))                # 预期 None
print("duplicate:", two_sum_hash([4, 4], 8))          # 预期 (0, 1)
print("no_solution:", two_sum_hash([1, 2, 4], 10))     # 预期 None
print("negative:", two_sum_hash([-3, 7, 2, 9], 4))    # 预期 (0, 1)
print("zero:", two_sum_hash([0, 5, 0], 0))            # 预期 (0, 2)
