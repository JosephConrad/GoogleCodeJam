T = int(raw_input())
for t in range(T):
    N = int(raw_input())
    array = map(int, raw_input( ).split( ))
    result = 0
    while array != []:
        index = array.index(min(array))
        result += index if index < len(array) / 2 else len(array) - (index + 1)
        array.pop(index)
    print "Case #%d: %d" % (t+1, result)