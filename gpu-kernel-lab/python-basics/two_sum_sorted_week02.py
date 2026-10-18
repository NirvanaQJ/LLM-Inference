def two_sum_sorted(nums,target):
    left=0
    right=len(nums)-1
    while left<right:
        total=nums[left]+nums[right]
        if total==target:
            return(left,right)
        elif total<target:
            left+=1
        else:
            right-=1
    return None

print(two_sum_sorted([2, 4, 5, 9, 13], 14))

print("empty:", two_sum_sorted([], 14))              # 预期 None
print("single:", two_sum_sorted([7], 14))            # 预期 None
print("duplicate:", two_sum_sorted([7, 7], 14))      # 预期 (0, 1)
print("no_solution:", two_sum_sorted([1, 2, 3], 9))  # 预期 None
print("negative:", two_sum_sorted([-7, -2, 4, 10], 2))  # 预期 (1, 2)