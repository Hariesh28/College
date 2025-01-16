import re

string = 'A37_as909'
expression = '^A[B-G]*[2-8]+[_\.][a-z]+'
a = re.findall(expression, string)
print(a)

# d = {1:2, 3:4}
# d.update(([3,7], [9, 5]))
# print(d)