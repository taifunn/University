def kompresja(text):
    i = 0
    res = []
    count = 1
    for i in range(1, len(text)):
        if(text[i] == text[i-1]):
            count +=1
        else: 
            res.append((count, text[i-1]))
            count = 1
    res.append(text[len(text)-1])
    return res

def dekompresja(list):
    s = ''
    for tup in list:
        liczba = 1
        znak = tup[0]
        if(isinstance(tup[0], int)):
            liczba = tup[0]
            znak = tup[1]

        for i in range(liczba):
            s += znak

    return s

print(kompresja('aaabbbc'))
print(dekompresja([(3, 'a'), (3, 'b'), 'c']))

with open('text.txt', "r") as f: #link : https://literat.ug.edu.pl/lalka/0020.htm
    text = f.read()
    encoded = kompresja(text)
    print(encoded)
    decoded = dekompresja(encoded)
    print(decoded)
