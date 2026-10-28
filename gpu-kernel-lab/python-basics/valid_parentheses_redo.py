def is_valid_parentheses(text):
    par={")":"(","]":"[","}":"{"}
    ch=[]

    for s in text:
        if s in "({[":
            ch.append(s)
        else:
            if not ch:
                return False
            if ch.pop() !=par[s]:
                return False
    return not ch

cases = [
    ("", True),
    (")", False),
    ("([])", True),
    ("([)]", False),
    ("(", False),
]

for text, expected in cases:
    actual = is_valid_parentheses(text)
    print(repr(text), actual)
    assert type(actual) is bool
    assert actual == expected

print("5 cases passed")