import heapq

class Node:

    def __init__(self, char: str, frequency: int):
        self.char = char
        self.freq = frequency
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq

def get_freq(text: str) -> dict[str:int]:

    freq = {}

    for char in text:
        if char in freq:
            freq[char] += 1
            continue

        freq[char] = 1

    return freq

def build_tree(text: str) -> Node:

    freq_map = get_freq(text)
    nodes = [Node(char, freq) for char, freq in freq_map.items()]

    heapq.heapify(nodes)

    while len(nodes) > 1:

        left = heapq.heappop(nodes)
        right = heapq.heappop(nodes)

        merged = Node(None, left.freq + right.freq)
        merged.left = left
        merged.right = right

        heapq.heappush(nodes, merged)

    return nodes[0]

def generate_codes(root: Node, code_prefix: str = '', result: dict[str:str] = {}) -> None:

    if root is None:
        return

    if root.char is not None:
        result[root.char] = code_prefix

    generate_codes(root.left, code_prefix + '0', result)
    generate_codes(root.right, code_prefix + '1', result)

    return result

def encode(text: str, root: None) -> str:

    char_map = generate_codes(root)
    return ''.join(char_map[char] for char in text)

def decode(encoded_text: str, root: None) -> str:

    answer = ''
    current: Node = root

    for bit in encoded_text:

        if bit == '0':
            current = current.left
        else:
            current = current.right

        if current.char is not None:
            answer += current.char
            current = root

    return answer


text = input('Enter: ')
root = build_tree(text)
encoded_text = encode(text, root)
decoded_text = decode(encoded_text, root)

print('Encoded Text:', encoded_text)
print('Decoded Text:', decoded_text)
