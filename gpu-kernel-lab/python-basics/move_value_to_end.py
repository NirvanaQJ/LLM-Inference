def move_value_to_end(nums, target):
    write=0
    for read in range(len(nums)):
        if nums[read]!=target:
            nums[write]=nums[read]
            write+=1
    for index in range(write,len(nums)):
        nums[index]=target



nums = [3, 0, 3, -2, 5, 3]
result = move_value_to_end(nums, 3)

print(nums)
print(result)

empty = []
result = move_value_to_end(empty, 3)
print("empty:", empty, "return:", result)

all_target = [3, 3, 3]
result = move_value_to_end(all_target, 3)
print("all_target:", all_target, "return:", result)