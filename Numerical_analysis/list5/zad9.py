import mpmath as mp

mp.mp.dps = 128
def olver(f, fp, fpp, x):
    fx, fpx, fppx = f(x), fp(x), fpp(x)
    return x - fx/fpx - mp.mpf('0.5')*(fppx/fpx)*(fx/fpx)**2

def acoc(xs):
    deltas = [abs(xs[i+1] - xs[i]) for i in range(len(xs)-1)]
    p_vals = []
    for k in range(2, len(deltas)):
        a, b, c = deltas[k], deltas[k-1], deltas[k-2]
        if a > 0 and b > 0 and c > 0 and a != b and b != c:
            p_vals.append(mp.log(a/b) / mp.log(b/c))
    return p_vals

def run_test(name, f, fp, fpp, x0, N=7):
    print(f"\nTEST: {name} ")
    xs = [mp.mpf(x0)]
    for _ in range(N):
        xs.append(olver(f, fp, fpp, xs[-1]))

    print("Iteraty x_k:")
    for k, x in enumerate(xs):
        print(f"k={k:2d}  x={x}")

    p_list = acoc(xs)
    print("\nSzacunki p:")
    print(p_list)
    if p_list:
        print("Ostatne przyblizenie ~", p_list[-1])
        
def f1(x):   return x**2 - 2
def f1p(x):  return 2*x
def f1pp(x): return 2
def f2(x):   return mp.cos(x) - x
def f2p(x):  return -mp.sin(x) - 1
def f2pp(x): return -mp.cos(x)

if __name__ == "__main__":
    run_test("x^2 - 2", f1, f1p, f1pp, x0=mp.mpf('1.2'), N=7)
    run_test("cos(x) - x", f2, f2p, f2pp, x0=mp.mpf('1.0'), N=7)
