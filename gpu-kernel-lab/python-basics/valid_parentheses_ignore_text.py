def is_valid_parentheses_ignore_text(text):
    par={")":"(","]":"[","}":"{"}
    ch=[]

    for s in text:
        if s in "({[":
            ch.append(s)
        else:
            if s in ")}]":
              if not ch:
                return False
              if ch.pop()!=par[s]:
                return False
    return not ch

cases = [
    ("", True),
    ("hello", True),
    ("a(b[c]d)e", True),
    ("a([)]b", False),
    ("(abc", False),
    ("abc]", False),
    ("a{}b[]c()", True),
    ("a{b[c(d)e]f}g", True),
]

for text, expected in cases:
    actual = is_valid_parentheses_ignore_text(text)
    print(repr(text), actual)

    assert type(actual) is bool  # 检查返回类型
    assert actual == expected    # 检查结果

print("8 cases passed")