def is_anagram(s, t):
    count_s = {}
    count_t = {}

    for ch in s:
        count_s[ch] = count_s.get(ch, 0) + 1

    for ch in t:
        count_t[ch] = count_t.get(ch, 0) + 1

    return count_s == count_t


print("ordinary:", is_anagram("tea", "eat"))
print("different_counts:", is_anagram("aab", "abb"))

print("repeated:", is_anagram("aabb", "baba"))       # 预期 True
print("both_empty:", is_anagram("", ""))            # 预期 True
print("one_empty:", is_anagram("", "a"))             # 预期 False
print("different_lengths:", is_anagram("ab", "aab")) # 预期 False
print("different_letters:", is_anagram("ab", "ac"))  # 预期 False
print("identical:", is_anagram("abc", "abc"))        # 预期 True