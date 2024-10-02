punctuations = ['.', ',', '?','!', ':', ';', "'", '"', '(', ')', '[', ']', '{', '}', '-', '—', '/', '&', '*', '$', '%' ,'#', '@', '+', '=', '~', '^', '\\', '|', '•', '†', '‡', '“', '’', '”']

with open('story.txt') as file:
    data = file.read()

with open('test.txt', 'w') as file:

    for char in data:

        if char not in punctuations:
            file.write(char)

with open('test.txt') as file:
    data = file.read()
    
# Unigram Probability
unigram_probability = {}
total_words = 0

for word in data.split():
    
    if word in unigram_probability:
        unigram_probability[word] += 1
        
    else:
        unigram_probability[word] = 1
        
    total_words += 1
    
for key in unigram_probability:
    unigram_probability[key] /= total_words
    
print(unigram_probability)


# Bigram Probability
bigram_probability = {}

for i in range(len(data.split()) - 1):
    
    two_words = f'{data.split()[i]} {data.split()[i + 1]}'
    two_Words_count = data.count(two_words)
    
    first_word = data.split()[i]
    first_word_count = data.count(data.split()[i])
     
    if two_Words_count != 0 and first_word_count != 0:
        bigram_probability[two_words] = two_Words_count / first_word_count
    
print(bigram_probability)

# Trigram Probability
trigram_probability = {}

for i in range(len(data.split()) - 2):
    
    three_words = f'{data.split()[i]} {data.split()[i + 1]} {data.split()[i + 2]}'
    three_words_count = data.count(three_words)
    
    two_words = f'{data.split()[i]} {data.split()[i + 1]}'
    two_Words_count = data.count(two_words)
    
    if two_Words_count != 0 and three_words_count != 0:
        trigram_probability[three_words] = three_words_count / two_Words_count
        
print(trigram_probability)
