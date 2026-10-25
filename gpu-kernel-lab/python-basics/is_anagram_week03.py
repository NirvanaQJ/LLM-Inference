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
print("both_empty:", is_anagram("", ""))
print("one_empty:", is_anagram("", "a"))
print("repeated:", is_anagram("aabb", "baba"))
print("different_lengths:", is_anagram("ab", "aab"))
print("different_letters:", is_anagram("ab", "ac"))
print("identical:", is_anagram("abc", "abc"))
