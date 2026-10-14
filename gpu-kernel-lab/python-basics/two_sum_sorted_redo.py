def two_sum_sorted(nums, target):
    left = 0
    right = len(nums)-1

    while left<right:
        current=nums[left]+nums[right]
        if current==target:
            return (left, right)
        elif current<target:
            left+=1
        else:
            right-=1
    return None

print(two_sum_sorted([1, 3, 4, 6, 10], 9))
print("empty:", two_sum_sorted([], 9))
print("single:", two_sum_sorted([5], 10))
print("duplicate:", two_sum_sorted([5, 5], 10))
print("no_solution:", two_sum_sorted([1, 2, 4], 20))
print("negative:", two_sum_sorted([-6, -2, 3, 9], 1))