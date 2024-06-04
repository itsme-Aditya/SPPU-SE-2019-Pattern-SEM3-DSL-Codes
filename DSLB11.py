def sentinelsearch(list, x):
    n = len(list)
    last = list[n - 1]
    list[n - 1] = x

    i = 0
    while list[i] != x:
        i += 1
    
    list[n - 1] = last

    if i < n - 1 or list[n - 1] == x:
        return i
    return -1