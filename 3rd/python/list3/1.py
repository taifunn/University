def pierwsze_imperatywna(n):
    l = []
    for i in range(2, n+1):
        pierwsza = True
        for j in range(2, int(i**0.5)+1):
            if i % j == 0:
                pierwsza = False
                break
        if pierwsza:
            l.append(i)
    return l

def pierwsze_skladana(n):
    return [i for i in range(2, n+1) if all(i%d !=0 for d in range(2, int(i**0.5)+1))]

def pierwsze_funkcyjna(n):
    return list(filter(lambda i: all(i%d !=0 for d in range(2, int(i**0.5)+1)), range(2, n+1)))

n=100
print(pierwsze_imperatywna(n))
print(pierwsze_skladana(n))
print(pierwsze_funkcyjna(n))

from timeit import Timer

vals = [10, 20, 30, 40, 50, 75, 100]

print(" n    skladana  imperatywna  funkcyjna (ms)")
for n in vals:
    n1, t1 = Timer(lambda: pierwsze_skladana(n)).autorange()
    n2, t2 = Timer(lambda: pierwsze_imperatywna(n)).autorange()
    n3, t3 = Timer(lambda: pierwsze_funkcyjna(n)).autorange()
    print(f"{n:3d}: {t1/n1*1000:9.3f} {t2/n2*1000:12.3f} {t3/n3*1000:10.3f}")