"""2026-11-01 W04 链表反转复做；Node/测试由导师提供，函数体由本人保存。"""


class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


def reverse_list(head):
    prev=None
    current=head
    while current:
        next_code=current.next
        current.next=prev
        prev=current
        current=next_code
    return prev


# 以下测试由导师追加；使用 is 核对是否保留原来的节点对象。
assert reverse_list(None) is None
print("empty: passed")

a = Node(7)
result = reverse_list(a)
assert result is a
assert a.next is None
print("single: passed")

a = Node(1)
b = Node(2)
c = Node(3)
a.next = b
b.next = c
result = reverse_list(a)
assert result is c
assert c.next is b
assert b.next is a
assert a.next is None
print("normal: passed")

d = Node(4)
e = Node(4)
f = Node(9)
d.next = e
e.next = f
result = reverse_list(d)
assert result is f
assert f.next is e
assert e.next is d
assert d.next is None
print("duplicates: passed")
