def ideal_substring(string: str, substring_size: int = 3) -> None:
    for character in range(len(string) - substring_size + 1):

        window = string[character: character + substring_size]

        if len(set(window)) == len(window):
            print(window, end=' ')


ideal_substring("aababcabc")