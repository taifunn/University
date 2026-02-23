import math

def romberg(f, a, b, N=20):
    # metoda trapezow
    T0 = []
    h = b - a
    t = 0.5 * h * (f(a) + f(b))
    T0.append(t)

    for k in range(1, N + 1):
        h *= 0.5
        s = 0.0
        for i in range(1, 2**(k-1) + 1):
            s += f(a + (2*i - 1) * h)   # nowe punkty
        t = 0.5 * t + h * s
        T0.append(t)

    # ekstrapolacja
    T = [T0]
    for m in range(1, N + 1):
        row = []
        fact = 4**m
        for k in range(0, N - m + 1):
            licz = fact * T[m-1][k+1] - T[m-1][k]
            mian = fact - 1

            val = licz / mian
            row.append(val)
        T.append(row)

    return T[N][0]

# a)
fa = lambda x: 2026*x**8 + 1977*x**6 - 1410*x**3 - 1791*x + 1
print("a) T[20,0] =", romberg(fa, -1, 7))

# b)
fb = lambda x: 1/(1 + 25*x*x)
print("b) T[20,0] =", romberg(fb, -1, 1))

# c)
fc = lambda x: math.log(x+1)
print("c) T[20,0] =", romberg(fc, 0, 5))
