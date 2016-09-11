from collections import defaultdict
import random
alpha = "abcdefghijklmnopqrstuvwxyz"
ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"


def choice(n):
    if len(n) > 0:
        return random.choice(n)
    else:
        return None


def getTokens(file_, seperators={" ", "\n"}, tokens={".", ",", "!", "?"}):
    with open(file_) as f:
        data = f.read()
        word = []
        for letter in data:
            if letter in seperators:
                if len(word) != 0:
                    yield "".join(word)
                    word = []
            elif letter in tokens:
                yield "".join(word)
                yield letter
                word = []
            else:
                word.append(letter)


def makeChain(tokens, ngrams):
    chain = defaultdict(list)
    prev = [None for _ in range(ngrams)]
    for word in tokens:
        chain[tuple(prev)].append(word)
        prev = prev[1:]
        prev.append(word)
    return chain


class Chain:
    def __init__(self, tokens, ngramsize=1):
        self.chain = makeChain(tokens, ngramsize)

    def walk(self, seed = None):
        if seed is None:
            seed = choice(list(self.chain.keys()))
        prev = list(seed)
        while True:
            state = choice(self.chain[tuple(prev)])
            yield state
            prev = prev[1:]
            prev.append(state)

    def get(self, length, seed=None):
        ans = []
        for i, ngram in zip(range(length), self.walk(seed)):
            ans.append(ngram)
        return ans

    def debug(self):
        print(self.chain.keys())
        print(len(self.chain.keys()))

if __name__ == "__main__":
    t = getTokens("test.txt")
    a = Chain(t, 3)
    a.debug()
    print(a.get(20))



