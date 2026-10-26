class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


def reverse_list(head):
    prev = None
    curr = head

    while curr is not None:
        nxt = curr.next
        curr.next = prev
        prev = curr
        curr = nxt

    return prev


a = Node(10)
b = Node(20)
c = Node(30)
a.next = b
b.next = c

new_head = reverse_list(a)
print(new_head.val)
print(new_head.next.val)
print(new_head.next.next.val)
print(new_head.next.next.next)

print("same_nodes:", new_head is c,
      new_head.next is b, new_head.next.next is a)

print("empty:", reverse_list(None))

single = Node(10)
result = reverse_list(single)
print("single:", result is single, result.val, result.next)

x = Node(10)
y = Node(10)
z = Node(20)
x.next = y
y.next = z

result = reverse_list(x)
print("duplicates:", result.val, result.next.val,
      result.next.next.val, result.next.next.next)
print("duplicate_nodes:", result is z,
      result.next is y, result.next.next is x)