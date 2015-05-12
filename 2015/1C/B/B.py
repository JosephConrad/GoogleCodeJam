import sys
from itertools import product

def strongPrefixSuffix(x):
    strongP = [-1]
    t = -1
    m = len(x)
    for j in range(0, m):
        while t >=0 and x[t] != x[j]:
            t = strongP[t]
        t += 1
        
        if j == m-1 or x[j+1] != x[t]:
            nextElem = t
        else:
            nextElem = strongP[t]
            
        strongP.append(nextElem)
    return strongP

def onlineKMP(pattern, text):
    x = pattern
    m = len(pattern)
    
    result = 0
    strongP = strongPrefixSuffix(pattern)
    j = 0 
    for sym in text:    
        while j >=0  and x[j] != sym: j = strongP[j]
        j += 1
        if j == m:
            result += 1
            j = strongP[m] 
        else:
            pass
    return result


T = int(raw_input())
for i in range(T):
    K, L, S  = map(int, raw_input().split(" "))
    keyboard = raw_input()
    targetWord = raw_input()
    result = 0
    dem = len(list(product(keyboard, repeat=S)))
    maks = 0
    
    for x in product(keyboard, repeat=S):
        w = ''.join(x)
        kmp = onlineKMP(targetWord, w)
        result += kmp
        maks = max(maks, kmp)
    wyn = maks - result/(dem *1.0)
    printing = "{0:.6f}".format(round(wyn,6))
    if printing[-1] == "0":
        print "Case #" + str(i+1) + ": " + "{0:.6f}".format(round(wyn,6)).rstrip("0")+"0"
    else:     
        print "Case #" + str(i+1) + ": " + "{0:.6f}".format(round(wyn,6))
