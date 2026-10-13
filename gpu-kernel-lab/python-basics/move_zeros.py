def move_zeros(nums):
    write = 0

    for read in range(len(nums)):
        if nums[read] != 0:
            nums[write] = nums[read]
            write += 1

    for index in range(write, len(nums)):
        nums[index] = 0


nums = [0, 1, 0, 3, 12]
move_zeros(nums)
print(nums)

cases = [
    ("empty", []),
    ("single_zero", [0]),
    ("single_nonzero", [5]),
    ("all_zero", [0, 0, 0]),
    ("no_zero", [1, 2, 3]),
    ("negative_duplicate", [0, -1, 0, -1, 2]),
]

for name, values in cases:
    result = move_zeros(values)
    print(name, values, "return:", result)