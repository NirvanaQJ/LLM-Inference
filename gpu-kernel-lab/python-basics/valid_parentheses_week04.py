"""2026-11-01 W04 有效括号复做；函数体由本人保存，测试由导师追加。"""


def is_valid_parentheses(text):
    par={")":"(","]":"[","}":"{"}
    stack=[]
    for i in text:
        if i in "([{":
            stack.append(i)
        else:
            if not stack:
                return False
            if stack.pop()!=par[i]:
                return False
    return not stack


# 以下八组预期在本次实现前已按题目规则确定，测试由导师追加。
cases = [
    ("", True),
    (")", False),
    ("(", False),
    ("([])", True),
    ("([)]", False),
    ("{[]}", True),
    ("(]", False),
    ("()[]{}", True),
]

for text, expected in cases:
    actual = is_valid_parentheses(text)
    print(repr(text), actual)
    assert type(actual) is bool
    assert actual == expected

print("8 cases passed")
