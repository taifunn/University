def solve(grid):
    G = [row[:] for row in grid]

    def find_empty():
        for row in range(9):
            for col in range(9):
                if G[row][col] == 0:
                    return row, col
        return None
    
    def ok(row, col, v):
        if any(G[row][i] == v for i in range(9)): return False
        if any(G[i][col] == v for i in range(9)): return False

        br, bc = 3*(row//3), 3*(col//3)

        for rr in range(br, br + 3):
            for cc in range(bc, bc + 3):
                if G[rr][cc] == v:
                    return False
        return True
    
    def dfs():
        em = find_empty()
        if em is None:
            yield [row[:] for row in G]
            return
        row, col = em
        for v in range(1,10):
            if ok(row, col, v):
                G[row][col] = v
                yield from dfs()
                G[row][col] = 0
    
    return dfs()
    
def show(G):
    for row in range(9):
        print(" ".join(str(x) for x in G[row]))
    
#jedno rozwiazanie
ex = [
    [5,3,0, 0,7,0, 0,0,0],
    [6,0,0, 1,9,5, 0,0,0],
    [0,9,8, 0,0,0, 0,6,0],
    [8,0,0, 0,6,0, 0,0,3],
    [4,0,0, 8,0,3, 0,0,1],
    [7,0,0, 0,2,0, 0,0,6],
    [0,6,0, 0,0,0, 2,8,0],
    [0,0,0, 4,1,9, 0,0,5],
    [0,0,0, 0,8,0, 0,7,9],
]

#dwa rozwiazania
ex2 = [
    [5,3,0, 6,7,0, 9,1,2],
    [6,0,2, 1,9,0, 3,4,0],
    [1,0,0, 3,4,0, 5,6,0],
    [0,5,0, 7,0,0, 0,2,0],
    [0,2,0, 8,0,0, 7,9,0],
    [0,1,0, 9,2,4, 0,5,6],
    [0,6,1, 0,3,0, 0,8,4],
    [2,8,7, 0,0,0, 6,3,0],
    [0,4,5, 0,0,0, 0,7,0],
] 

#duzooo rozwiazan
ex3 = [
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
]

for rozw in solve(ex3):
    show(rozw)
    print()
 
#show(next(solve(ex)))
