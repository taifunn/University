import random

def uprosc_zdanie(zdanie, dl_slowa, liczba_slow):
    slowa = []
    for w in zdanie.split():
        base = w.rstrip(".,;:!?…\"'”’)")
        if len(base) <= dl_slowa:
            slowa.append(base)

    while len(slowa) > liczba_slow:
        i = random.randrange(len(slowa))
        del slowa[i]

    if not slowa:
        return ""
    res = " ".join(slowa)
    if res[-1] not in ".!?":
        res += "."
    return res 

t = ("Podział peryklinalny inicjałów wrzecionowatych kambium "
         "charakteryzuje się ścianą podziałową inicjowaną "
         "w płaszczyźnie maksymalnej.")

print(uprosc_zdanie(t,10,5))

with open('text.txt', "r") as f: #link : https://literat.ug.edu.pl/lalka/0020.htm
    text = f.read()
    print(uprosc_zdanie(text, 8, 300))
