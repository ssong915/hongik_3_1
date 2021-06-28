def partition(arr,l,r):
    pivot=arr[l]
    i=l+1
    j =r
    while True:
        while i<=r and arr[i]<=pivot:
            i+=1
        while l<=j and arr[j]>pivot:
            j-=1
        if j>=i:
            arr[i],arr[j]=arr[j],arr[i]
        else:
            break
    arr[l],arr[j]=arr[j],arr[l]
    return j

def quicksort(arr,l,r):
    if l<r:
        pivot=partition(arr,l,r)
        quicksort(arr,l,pivot-1)
        quicksort(arr,pivot+1,r)

n=list(map(int,input().split()))
quicksort(n,0,len(n)-1)
print(n)