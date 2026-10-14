def move_zeros(nums):
    write = 0
    for read in range(len(nums)):
        if nums[read]!=0:
            nums[write]=nums[read]
            write +=1
    for index in range(write,len(nums)):
        nums[index]=0

nums = [0, 4, 0, -1, 4]
result = move_zeros(nums)
print(nums)
print(result)

empty = []
result = move_zeros(empty)
print("empty:", empty, "return:", result)

all_zero = [0, 0, 0]
result = move_zeros(all_zero)
print("all_zero:", all_zero, "return:", result)