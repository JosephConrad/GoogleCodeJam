T = int(raw_input())
for t in range(T):
    N, X = map(int, raw_input().split( ))
    sizes = map(int, raw_input().split( ))
    sizes.sort()
    sizes.reverse() 
    used = 0

    # can be done using binsearch
    for i in range(0, len(sizes)):
        for j in range(i+1, len(sizes)): 
            if sizes[i] + sizes[j] <= X:
                sizes[i] = X+1
                sizes[j] = X+1
                used += 1
    remaining = filter(lambda x: x < X + 1, sizes)
    used += len(remaining)
    print "Case #%d: %d" % (t+1, used) 
