data = {'Student1': {'Marks': [50, 45, 36, 48, 50]},
        'Student 2': {'Marks': [43, 44, 48, 30, 37]},
        'Student4': {'Marks': [50, 48, 36, 45, 50]},
        'Student3': {'Marks': [50, 46, 50, 50, 50]}}

for key, value in data.items():
    data[key]['Average'] = sum(data[key]['Marks']) / len(data[key]['Marks'])

print(data)

averages = []

for key, value in data.items():
    averages.append(data[key]['Average'])
averages = list(set(averages))
print(averages)
averages.sort(reverse=True)
print(averages)
for i in range(len(averages)):
    for key, value in data.items():
        if data[key]['Average'] == averages[i]:
            data[key]['Rank'] = i+1

print(data)