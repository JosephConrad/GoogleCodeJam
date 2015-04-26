N_MAX = pow(10,18)

r = 0

def value(v):
    return (2*v*v + 2 * v * r + 3 * v) + 2 * r + 1


def bin_search(down, top, search):
    while (True):
        if down + 1 >= top:
            return down
        mid = (down + top) / 2
        if value(mid) == search:
            return mid
        elif value(mid) > search:
            top = mid
        else:
            down = mid


T = int(raw_input())

for i in range(1, T+1):
    r, n = map(int, raw_input().split(" "))
    print "Case #" + str(i) + ": " + str(bin_search(0, N_MAX, n) + 1)
