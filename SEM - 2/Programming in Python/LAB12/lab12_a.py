import sys

l = sys.argv[1:]
sentence = ''
result = 1

for word in l:
    sentence += word + ' '

for i in range(len(sentence.split()) - 1):
    result *= sentence.count(f'{sentence.split()[i]} {sentence.split()[i + 1]}') / sentence.count(sentence.split()[i])

result *= sentence.count(sentence.split()[0]) / len(sentence.split())

print(result)