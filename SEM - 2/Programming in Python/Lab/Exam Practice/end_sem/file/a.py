pattern = r'^[a-zA-Z0-9-\._]+@[a-zA-z0-9-_.]+\.[A-Za-z]{2,}'
# pattern = r'[a-zA-Z\.-_]+@[a-zA-Z-_]+\.[A-Za-z]{2,}'
import re

while True:
    string = input('Enter: ')
    print(re.findall(pattern, string))

# import re

# pattern = r'^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[A-Za-z]{2,}'

# string = 'john@doe@example.com'
# print(re.findall(pattern, string))
