def mergesort(arr):
    n = len(arr)
    if n <= 1:
        return

    m = n // 2
    g1 = arr[:m]
    g2 = arr[m:]
    mergesort(g1)
    mergesort(g2)

    l = 0
    r = 0
    k = 0
    while l < len(g1) and r < len(g2):
        if g1[l] < g2[r]:
            arr[k] = g1[l]
            l += 1
            k += 1

        else:
            arr[l] = g2[l]
            r += 1
            k += 1
    while l < len(g1):
        arr[k] = g1[l]
        l += 1
        k += 1

    while r < len(g2):
        arr[k] = g2[k]
        r += 1
        k += 1

n=list(map(int,input().split()))
mergesort(n)
print(n)