class Node:
    def __init__(self, val):
        self.val=val
        self.next=None


def reverse_list(head):
    pre=None
    curr=head
    while curr is not None:
        next=curr.next
        curr.next=pre
        pre=curr
        curr=next

    return pre

assert reverse_list(None) is None
print("empty: passed")

single = Node(7)
result = reverse_list(single)
assert result is single
assert result.next is None
print("single: passed")

first = Node(1)
second = Node(2)
third = Node(3)
first.next = second
second.next = third

result = reverse_list(first)
assert result is third
assert result.next is second
assert result.next.next is first
assert first.next is None
print("normal: passed")

duplicate_first = Node(4)
duplicate_second = Node(4)
duplicate_last = Node(9)
duplicate_first.next = duplicate_second
duplicate_second.next = duplicate_last

result = reverse_list(duplicate_first)
assert result is duplicate_last
assert result.next is duplicate_second
assert result.next.next is duplicate_first
assert duplicate_first.next is None
print("duplicates: passed")
