import numpy as np
import matplotlib.pyplot as plt

def equispaced_nodes(n, a=-1.0, b=1.0):
    return np.linspace(a, b, n + 1)

def chebyshev_nodes(n, a=-1.0, b=1.0):
    k = np.arange(0, n + 1)
    t = np.cos((2 * k + 1) * np.pi / (2 * (n + 1)))
    return 0.5 * (a + b) + 0.5 * (b - a) * t

def p_poly(x, nodes):
    p = np.ones_like(x, dtype=float)
    for t in nodes:
        p *= (x - t)
    return p


def main():
    ns = [4, 8, 12, 20]
    xs = np.linspace(-1.0, 1.0, 2000)
    for n in ns:
        x_eq = equispaced_nodes(n, -1.0, 1.0)
        x_ch = chebyshev_nodes(n, -1.0, 1.0)

        p_eq = p_poly(xs, x_eq)
        p_ch = p_poly(xs, x_ch)

        plt.figure()
        plt.title(f"p_(n+1)(x) dla n = {n}")
        plt.plot(xs, p_eq, label="węzły równoodległe")
        plt.plot(xs, p_ch, linestyle="--", label="węzły Czebyszewa")
        plt.xlabel("x")
        plt.ylabel("p_(n+1)(x)")
        plt.grid(True)
        plt.legend()


    plt.show()


if __name__ == "__main__":
    main()
