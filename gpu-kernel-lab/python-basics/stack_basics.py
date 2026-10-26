def pop_or_none(stack):
   if len(stack) ==0:
      return None
   else:
        return stack.pop()


stack = []
print("empty:", pop_or_none(stack))

stack.append(10)
stack.append(20)
print("pop1:", pop_or_none(stack))
print("left1:", stack)

stack.append(30)
print("pop2:", pop_or_none(stack))
print("pop3:", pop_or_none(stack))
print("empty_again:", pop_or_none(stack))
print("left2:", stack)

zero_stack = [0]
print("zero:", pop_or_none(zero_stack))
print("zero_left:", zero_stack)