a = 'awewaa'

for i in range(len(a)):
    for j in range(i, len(a)):
        if a[i:j+1] == a[i:j+1][::-1] and a[i:j+1] != '':
            print(a[i:j+1])