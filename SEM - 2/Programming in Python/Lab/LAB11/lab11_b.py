dictionary_word = {}
dictionary_char = {}

with open('data.txt') as file:

    data = file.readlines()
    lines = words = characters = 0


    for line in data:

        for word in line.split():
            
            if word in dictionary_word:
                dictionary_word[word] += 1

            else:
                dictionary_word[word] = 1
            
            words += 1
            
            for char in word:
                
                if char in dictionary_char:
                    dictionary_char[char] += 1

                else:
                    dictionary_char[char] = 1

                characters += 1

        lines += 1

print(f'Total number of lines: {lines}')
print(f'Total number of words: {words}')
print(f'Total number of characters: {characters}')
print(f'Frequency of words: {dictionary_word}')
print(f'Frequency of characters: {dictionary_char}')
