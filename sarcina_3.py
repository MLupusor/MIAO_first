from itertools import permutations

with open("originale.txt", "r") as f:
    originale = []
    for line in f.readlines():
        originale.append(line.strip())

with open("really_shuffled.txt", "r") as f:
    shuffled = []
    for line in f.readlines():
        shuffled.append(line.strip())


# print(originale)
# print(shuffled)
found = []

for word in shuffled:
    perm = permutations(word)
    for p in set(perm):
        word = "".join(p)
        if word in originale:
            found.append(word)

print(f"Cuvintele gasite: {found}")
key = "".join(found)
print(f"Cheia este: {key}")