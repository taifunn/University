from functools import lru_cache
import time

def sudan(n, x, y):
    if n==0:
        return x+y
    if y == 0:
        return x
    else:
        a = sudan(n, x, y-1)
        return sudan(n-1, a, a + y)

@lru_cache(maxsize=None)
def sudan_snd(n, x, y):
    if n==0:
        return x+y
    if y == 0:
        return x
    else:
        a = sudan_snd(n, x, y-1)
        return sudan_snd(n-1, a, a + y)

print(sudan(0, 1, 3))
print(sudan(1, 1, 3))
print(sudan(2, 1, 1))
print(sudan(2, 2, 1))
print(sudan(2, 2, 2))
#print(sudan(2, 1, 40))
#print(sudan(2, 1, 3)) tu juz za duzo

print(sudan_snd(0, 1, 3))
print(sudan_snd(1, 1, 3))
print(sudan_snd(2, 1, 1))
print(sudan_snd(2, 2, 2))
#print(sudan_snd(2, 1, 40))
#print(sudan_snd(2, 1, 3)) tez za duzo

t=time.perf_counter()
v=sudan(1,1,3)
print(v, "czas:", time.perf_counter()-t, "s")

t=time.perf_counter()
v=sudan_snd(1,1,3)
print(v, "czas:", time.perf_counter()-t, "s")

t=time.perf_counter()
v=sudan(2,2,2)
print(v, "czas:", time.perf_counter()-t, "s")

t=time.perf_counter()
v=sudan_snd(2,2,2)
print(v, "czas:", time.perf_counter()-t, "s")

#dla 2,2,2 oba działają ale z memoizacją jest szybciej