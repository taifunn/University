from abc import ABC, abstractmethod
from typing import Dict, Set
import itertools

class Formula(ABC):
    @abstractmethod
    def oblicz(self, zmienne):
        pass

    @abstractmethod
    def vars(self):
        pass

    @abstractmethod
    def __str__(self):
        pass

    def __add__(self, other):
        return Or(self, other)

    def __mul__(self, other):
        return And(self, other)

    def __invert__(self):
        return Not(self)

    def tautologia(self):
        V = sorted(self.vars())
        for vals in itertools.product([False, True], repeat=len(V)):
            env = dict(zip(V, vals))
            if not self.oblicz(env):
                return False
        return True

    def simplify(self):
        return _simplify(self)

class Stala(Formula):
    def __init__(self, val):
        self.val = bool(val)
    def oblicz(self, zmienne):
        return self.val
    def vars(self):
        return set()
    def __str__(self):
        return "true" if self.val else "false"
    def __eq__(self, other):
        return isinstance(other, Stala) and self.val == other.val


class Zmienna(Formula):
    def __init__(self, name):
        self.name = name
    def oblicz(self, zmienne):
        return bool(zmienne[self.name])
    def vars(self):
        return {self.name}
    def __str__(self):
        return self.name
    def __eq__(self, other):
        return isinstance(other, Zmienna) and self.name == other.name

class Not(Formula):
    def __init__(self, p):
        self.p = p
    def oblicz(self, zmienne):
        return not self.p.oblicz(zmienne)
    def vars(self):
        return self.p.vars()
    def __str__(self):
        return f"¬{_paren(self.p)}" if isinstance(self.p, (And, Or)) else f"¬{self.p}"
    def __eq__(self, other):
        return isinstance(other, Not) and self.p == other.p

class And(Formula):
    def __init__(self, l, r):
        self.l, self.r = l, r
    def oblicz(self, zmienne):
        return self.l.oblicz(zmienne) and self.r.oblicz(zmienne)
    def vars(self):
        return self.l.vars() | self.r.vars()
    def __str__(self):
        return f"{_paren(self.l)} ∧ {_paren(self.r)}"
    def __eq__(self, other):
        return isinstance(other, And) and self.l == other.l and self.r == other.r


class Or(Formula):
    def __init__(self, l, r):
        self.l, self.r = l, r
    def oblicz(self, zmienne):
        return self.l.oblicz(zmienne) or self.r.oblicz(zmienne)
    def vars(self):
        return self.l.vars() | self.r.vars()
    def __str__(self):
        return f"{_paren(self.l)} v {_paren(self.r)}"
    def __eq__(self, other):
        return isinstance(other, Or) and self.l == other.l and self.r == other.r


def _simplify(f):
    if isinstance(f, (Stala, Zmienna)):
        return f

    if isinstance(f, Not):
        p = _simplify(f.p)
        if isinstance(p, Stala):
            return Stala(not p.val)
        if isinstance(p, Not):
            return _simplify(p.p)
        return Not(p)

    if isinstance(f, And):
        a, b = _simplify(f.l), _simplify(f.r)
        if isinstance(a, Stala) and not a.val: 
            return Stala(False)
        if isinstance(b, Stala) and not b.val: 
            return Stala(False)
        if isinstance(a, Stala) and a.val:     
            return b
        if isinstance(b, Stala) and b.val:     
            return a
        if a == b:                             
            return a
        return And(a, b)

    if isinstance(f, Or):
        a, b = _simplify(f.l), _simplify(f.r)
        if isinstance(a, Stala) and a.val:     
            return Stala(True)
        if isinstance(b, Stala) and b.val:     
            return Stala(True)
        if isinstance(a, Stala) and not a.val: 
            return b
        if isinstance(b, Stala) and not b.val: 
            return a
        if a == b:
            return a
        return Or(a, b)
    return f

def _paren(x):
    return f"({x})" if isinstance(x, (And, Or)) else str(x)

if __name__ == "__main__":
    x, y, z = Zmienna("x"), Zmienna("y"), Zmienna("z")

    f = Or(Not(x), And(y, z))     
    g = ~x + (y * z)
    h = Or(Stala(True), x)

    print("f=", f)
    print("uproszczone f =", f.simplify())
    print("g= ", g)
    print("uproszczone g =", g.simplify())
    print("h=", h)
    print("uproszczone h =", h.simplify())
    print("vars(f) =", f.vars())

    env1 = {"x": False, "y": False, "z": False}
    env2 = {"x": False, "y": True,  "z": False}
    env3 = {"x": True,  "y": True,  "z": False}
    env4 = {"x": True,  "y": True,  "z": True}

    print(env1, "-> f:", f.oblicz(env1), "g:", g.oblicz(env1))
    print(env2, "-> f:", f.oblicz(env2), "g:", g.oblicz(env2))
    print(env3, "-> f:", f.oblicz(env3), "g:", g.oblicz(env3))
    print(env4, "-> f:", f.oblicz(env4), "g:", g.oblicz(env4))
    print("tautologia (x v ¬x)?", Or(x, Not(x)).tautologia())
