count=[1.5]
total=0
flag=False
for i in count:
    if type(i)!=int:
        flag=True
        break
    if i<0:
        flag=True
        break
    total+=i
if flag==True:
    print("wrong input")
else:
  print(total)
