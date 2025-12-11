def vat_faktura(lista):
    return sum(lista)*0.23

def vat_paragon(lista):
    s = 0
    for el in lista:
        s += el * 0.23
    return s

from decimal import Decimal

def vat_faktura_dec(lista):
    s = sum(Decimal(str(x)) for x in lista)
    return s * Decimal('0.23')

def vat_paragon_dec(lista):
    s = Decimal('0')
    for el in lista:
        s += Decimal(str(el)) * Decimal('0.23')
    return s

lista = [0.11, 0.22, 0.33]
print(vat_faktura(lista) == vat_paragon(lista))
print(vat_faktura_dec(lista) == vat_paragon_dec(lista))

