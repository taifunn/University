def prefix(lista_slow):
    def pref(a, b):
        i=0
        while i<len(a) and i<len(b) and a[i] == b[i]:
            i += 1
        return i
    s = sorted(s.lower() for s in lista_slow)
    best = ""
    for i in range(len(s)-2):
        l = min(pref(s[i], s[i+1]), pref(s[i+1], s[i+2]))
        if l>len(best): 
            best = s[i][:l]
    return best

print(prefix(["Cyprian","cyberotoman","cynik","ceniąc","czule"]))

