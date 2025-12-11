def res(e2, e3, e4, e5, c, s, exp_s):
    m = (16 + 8*e2 + 4*e3 + 2*e4 + e5)/32
    k = 2**(c * exp_s)
    return s * m * k 

#maximum 
print(res(1,1,1,1,1,1,1))
#minimum
print(res(1,1,1,1,1,-1,1))

import matplotlib.pyplot as plt

S = set()
for e2 in (0,1):
    for e3 in (0,1):
        for e4 in (0,1):
            for e5 in (0,1):
                for c in (0,1):
                    for s in (-1,1):
                        for exp_s in (-1,1):
                            S.add(res(e2, e3, e4, e5, c, s, exp_s))
vals = sorted(S)
A, B = vals[0], vals[-1]
print("liczba punktow: ", len(vals))
print("przedzial [A,B]: ", (A, B))

plt.figure(figsize=(10, 2))
plt.plot(vals, [0]*len(vals), "|", markersize=14)
plt.yticks([])
plt.xlabel("x")
plt.title("Rozkład: ±(0.1 e2 e3 e4 e5)_2 · 2^(±c)")
plt.xlim(-2.05, 2.05)
plt.tight_layout()
plt.show()