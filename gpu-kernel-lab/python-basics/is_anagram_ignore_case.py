def is_anagram_ignore_case(s, t):
    # Convert both strings to lowercase

    s = s.lower()
    t = t.lower()

    # Check if the sorted characters of both strings are equal
    return sorted(s) == sorted(t)

print(is_anagram_ignore_case("Tea", "eAt"))  # Output: True
print(is_anagram_ignore_case("AaB", "abA"))    # Output: True
print(is_anagram_ignore_case("Aab", "abb"))  # Output: False
print(is_anagram_ignore_case("", ""))  # Output: True
print(is_anagram_ignore_case("", "A"))  # Output: False
print(is_anagram_ignore_case("ab", "AAB"))  # Output: False
