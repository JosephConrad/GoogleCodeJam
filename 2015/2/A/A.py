directions = ['^', '<', '>', 'v'] 
        
def calc(grid, size1, size2, row):
    result = []
    for i in range(size2):
        s = 0
        for j in range(size1):
            if row:
                r, c = i, j
            else:
                r, c = j, i
            if grid[r][c] in directions:
                s+=1
        result.append(s)
    return result

def hasNext(p, grid, column, row):
    posR, posC, direction = p
    if direction in ['<', '^']:
        decR, decC = [(0, -1),(-1, 0)][['<', '^'].index(direction)]
        while posR >= 0 and posC >=0:
            posR += decR
            posC += decC
            if grid[posR][posC] in directions:  
                return True
        return False
    incR, incC = [(1, 0),(0, 1)][['v', '>'].index(direction)]
    while posR < row and posC < column:
         posR += incR
         posC += incC
         if grid[posR][posC] in directions:
             return True
    return False

T = int(raw_input())
for t in range(T):
    points = []
    row, column = map(int, raw_input().split(' '))
    grid = [[0 for x in range(120)] for x in range(120)] 
    for r in range(row):
        rowString = raw_input()
        for c, elt in enumerate(rowString):
            if elt in directions:
                points.append((r, c, elt))
            grid[r][c] = elt
    
    ile = 0
    for p in points:
        if not hasNext(p, grid, column, row):
            ile+=1
    rowIle = calc(grid, column, row, True)
    colIle =  calc(grid, row, column, False)

    bad = False 
    for r in range(row):
        for c in range(column):
            if grid[r][c] in directions and rowIle[r] == 1 and colIle[c] == 1:
                bad = True
        
    if bad: 
        print "Case #%d: %s"  % (t+1, "IMPOSSIBLE")
    else:
        print "Case #%d: %d" % (t+1, ile)
