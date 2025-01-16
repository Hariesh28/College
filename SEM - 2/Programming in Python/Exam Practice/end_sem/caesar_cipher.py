def caesar_cipher(word : str, num: int = 3):

    result = ''

    for letter in word:

        if letter.isalpha():
            value = ord(letter) + num

            if(value > ord('z')):
                difference = ord(letter) + num - ord('z')
                value = ord('a') - 1 + difference

            value = chr(value)
            result += value

        else:
            result += letter

    return result

print(caesar_cipher('abcx3'))