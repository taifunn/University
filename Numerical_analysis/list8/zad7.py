import numpy as np
import matplotlib.pyplot as plt
def compute_moments(t, y):
    n = len(t) - 1            # węzły od 0 do n
    h = np.diff(t)            # h[k] to t[k+1]-t[k]

    lam = np.zeros(n+1)
    for k in range(1, n):
        lam[k] = h[k-1] / (h[k-1] + h[k]) #liczymy lambdy

    # prawa strona d_k = 6 * f[x_{k-1}, x_k, x_{k+1}]  dla k=1..n-1
    d = np.zeros(n-1)
    for k in range(1, n): #ilorazy różnicowe
        f1 = (y[k]   - y[k-1]) / (t[k]   - t[k-1]) 
        f2 = (y[k+1] - y[k])   / (t[k+1] - t[k])
        sec = (f2 - f1) / (t[k+1] - t[k-1])
        d[k-1] = 6 * sec

    m = n - 1
    A = np.zeros((m, m))
    b = d.copy() #A*tablica M[1..n-1] = b

    # Wiersz k (1..n-1) -> indeks r = k-1
    for k in range(1, n):
        r = k - 1
        A[r, r] = 2.0               # współczynnik przy M[k]

        if k > 1:                   # współczynnik przy M[k-1]
            A[r, r-1] = lam[k]

        if k < n-1:                 # współczynnik przy M[k+1]
            A[r, r+1] = 1.0 - lam[k]

    # eliminacja Gaussa

    # forward elimination
    for i in range(m):
        # wybór pivota w kolumnie i (w wierszach i..m-1)
        pivot_row = i + np.argmax(np.abs(A[i:, i]))
        if abs(A[pivot_row, i]) < 1e-14:
            raise ValueError("Układ osobliwy (pivot ~ 0)")

        # zamiana wierszy
        if pivot_row != i:
            A[[i, pivot_row]] = A[[pivot_row, i]]
            b[i], b[pivot_row] = b[pivot_row], b[i]

        # eliminacja wierszy poniżej
        for j in range(i + 1, m):
            factor = A[j, i] / A[i, i]
            A[j, i:] -= factor * A[i, i:]
            b[j] -= factor   * b[i]

    # back substitution
    M_inner = np.zeros(m)
    for i in range(m - 1, -1, -1):
        M_inner[i] = (b[i] - np.dot(A[i, i+1:], M_inner[i+1:])) / A[i, i]

    # Składamy pełny wektor momentów M_0..M_n z M_0 = M_n = 0
    M = np.zeros(n + 1)
    M[1:n] = M_inner
    return M

class NaturalCubicSpline:
    def __init__(self, t, y):
        self.t = np.array(t, dtype=float)
        self.y = np.array(y, dtype=float)
        self.M = compute_moments(self.t, self.y)
        self.h = np.diff(self.t)

    def __call__(self, u):
        u = np.asarray(u, dtype=float)
        idx = np.searchsorted(self.t, u) - 1
        idx = np.clip(idx, 0, len(self.t)-2)

        t = self.t
        y = self.y
        M = self.M
        h = self.h

        tk = t[idx]
        tk1 = t[idx+1]
        hk = h[idx]

        A = (tk1 - u) / hk
        B = (u - tk) / hk

        val = (
            A * y[idx] + B * y[idx+1]
            + ((A**3 - A) * M[idx] + (B**3 - B) * M[idx+1]) * (hk**2 / 6.0)
        )
        return val

# ====== Dane ======
t = np.linspace(0.0, 1.0, 96)
x = np.array( [5.5, 8.5, 10.5, 13, 17, 20.5, 24.5, 28, 32.5, 37.5, 40.5, 42.5, 45, 47,
49.5, 50.5, 51, 51.5, 52.5, 53, 52.8, 52, 51.5, 53, 54, 55, 56, 55.5, 54.5, 54, 55, 57, 58.5,
59, 61.5, 62.5, 63.5, 63, 61.5, 59, 55, 53.5, 52.5, 50.5, 49.5, 50, 51, 50.5, 49, 47.5, 46,
45.5, 45.5, 45.5, 46, 47.5, 47.5, 46, 43, 41, 41.5, 41.5, 41, 39.5, 37.5, 34.5, 31.5, 28, 24,
21, 18.5, 17.5, 16.5, 15, 13, 10, 8, 6, 6, 6, 5.5, 3.5, 1, 0, 0, 0.5, 1.5, 3.5, 5, 5, 4.5, 4.5, 5.5,
6.5, 6.5, 5.5])
y = np.array([41, 40.5, 40, 40.5, 41.5, 41.5, 42, 42.5, 43.5, 45, 47, 49.5, 53, 57, 59,
59.5, 61.5, 63, 64, 64.5, 63, 61.5, 60.5, 61, 62, 63, 62.5, 61.5, 60.5, 60, 59.5, 59, 58.5,
57.5, 55.5, 54, 53, 51.5, 50, 50, 50.5, 51, 50.5, 47.5, 44, 40.5, 36, 30.5, 28, 25.5, 21.5,
18, 14.5, 10.5, 7.50, 4, 2.50, 1.50, 2, 3.50, 7, 12.5, 17.5, 22.5, 25, 25, 25, 25.5, 26.5,
27.5, 27.5, 26.5, 23.5, 21, 19, 17, 14.5, 11.5, 8, 4, 1, 0, 0.5, 3, 6.50, 10, 13, 16.5, 20.5,
25.5, 29, 33, 35, 36.5, 39, 41])
sx = NaturalCubicSpline(t, x)
sy = NaturalCubicSpline(t, y)

M = 1000
u = np.linspace(0.0, 1.0, M+1)
X = sx(u)
Y = sy(u)

plt.plot(X, Y, '-')
plt.axis('equal')
plt.show()
