def move_zeros(nums):
    write=0
    for read in range(len(nums)):
        if nums[read]!=0:
            nums[write]=nums[read]
            write+=1
    for i in range(write,len(nums)):
        nums[i]=0

    return None

nums = [0, 6, 0, -3, 6, 0]
result = move_zeros(nums)
print("nums:", nums)
print("return:", result)

empty = []
empty_result = move_zeros(empty)
print("empty:", empty, "return:", empty_result)

all_zero = [0, 0, 0]
all_zero_result = move_zeros(all_zero)
print("all_zero:", all_zero, "return:", all_zero_result)
