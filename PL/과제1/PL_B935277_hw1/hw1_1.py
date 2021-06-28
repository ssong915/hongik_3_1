def binary_search(left, right):
    while left <= right:
        mid = (left + right) // 2
        if n[mid] == ans:
            return mid
        elif n[mid] > ans:
            right = mid - 1
        elif n[mid] < ans:
            left = mid + 1
    return -1

n=list(map(int,input().split()))

ans=input()

l=len(n)

n.sort()
left = 0
right = l-1
if binary_search(left,right) == -1 :
    print("None")
else :
    num=binary_search(left,right)
    print(str(num+1))




