import sys
A=input()
N=int(input())

left=[]
right=[]

for i in A:
    left.append(i)
for i in range(N):
    temp=[]
    temp=sys.stdin.readline().split()

    if temp[0]=='P':
        left.append(temp[1])
    elif temp[0]=='L':
        if left:
            right.append(left.pop())
    elif temp[0]=='D':
        if right:
            left.append(right.pop())
    elif temp[0]=='B':
        if left:
            left.pop()
print(''.join(left),''.join(reversed(right)),sep='')