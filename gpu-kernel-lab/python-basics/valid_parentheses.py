def is_valid_parentheses(s):
    pairs = {")": "(", "]": "[", "}": "{"}
    stack = []

    for ch in s:
        if ch in "([{":
            stack.append(ch)
        else:
            if not stack:
                return False
            if stack.pop() != pairs[ch]:
                return False

    return not stack

cases = [
    ("", True),
    ("()", True),
    ("()[]{}", True),
    ("([])", True),
    ("{[()]}", True),
    ("(]", False),
    ("([)]", False),
    (")(", False),
    ("(", False),
    (")", False),
    ("(()", False),
    ("())", False),
]

for text, expected in cases:
    actual = is_valid_parentheses(text)
    print(repr(text), actual)
    assert type(actual) is bool
    assert actual == expected

print("12 cases passed")