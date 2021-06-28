def greedy(meeting):
    cnt=0
    l=0
    ans=[]
    for item in meeting:
        if item[1]>=l:
            l=item[2]
            ans.append(item[0])
            cnt+=1
    print(cnt)
    print(ans)

num=int(input(""))
meeting=[]
for i in range(num):
    num,start,end=map(int,input().split())
    meeting.append((num,start,end))

meeting=sorted(meeting, key=lambda item:item[1])
meeting=sorted(meeting, key=lambda item:item[2])
greedy(meeting)