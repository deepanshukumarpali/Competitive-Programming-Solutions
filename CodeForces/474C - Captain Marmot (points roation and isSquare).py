#------------------------template--------------------------#
import os
import sys
from math import *
from collections import *
from fractions import *
from bisect import *
from heapq import*
from io import BytesIO, IOBase
def vsInput():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
BUFSIZE = 8192
class FastIO(IOBase):
    newlines = 0
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
ALPHA='abcdefghijklmnopqrstuvwxyz'
M=10**9+7
EPS=1e-6
def value():return tuple(map(int,input().split()))
def array():return [int(i) for i in input().split()]
def Int():return int(input())
def Str():return input()
def arrayS():return [i for i in input().split()]


#-------------------------code---------------------------#
# vsInput()

def RotateAntiClockBy90(P,H):
    x,y=P
    a,b=H

    x-=a
    y-=b

    X=-y+a
    Y=x+b
    return (X,Y)

def Dist(p1,p2):
    return (p2[1]-p1[1])**2 + (p2[0]-p1[0])**2

def isSquare(P):

    p1,p2,p3,p4=P
    # print(p1,p2,p3,p4)

    d2 = Dist(p1,p2)
    d3 = Dist(p1,p3)
    d4 = Dist(p1,p4)
  
    if(d2==0 or d3==0 or d4==0):   
        return False
    if(d2==d3 and 2*d2==d4 and 2*Dist(p2,p4)==Dist(p2,p3)):
        return True
    if(d3==d4 and 2*d3==d2 and 2*Dist(p3,p2)==Dist(p3,p4)): 
        return True 
    if(d2==d4 and 2*d2==d3 and 2*Dist(p2,p3)==Dist(p2,p4)): 
        return True 
    return False

for _ in range(Int()):

    home=[]
    point=[]
    for i in range(4):
        V=value()
        point.append((V[0],V[1]))
        home.append((V[2],V[3]))
    ans=[inf]
    heapify(ans)

    # print(point)
    # print(home)
    # print()

    for i in range(4):

        point[0]=RotateAntiClockBy90(point[0],home[0])
        cost1=(i+1)%4
        for j in range(4):

            cost2=(j+1)%4
            point[1]=RotateAntiClockBy90(point[1],home[1])
            for k in range(4):

                cost3=(k+1)%4
                point[2]=RotateAntiClockBy90(point[2],home[2])
                for l in range(4):

                    cost4=(l+1)%4
                    point[3]=RotateAntiClockBy90(point[3],home[3])

                    if(isSquare(point)):
                        # print(point,cost1+cost2+cost3+cost4)
                        heappush(ans,cost1+cost2+cost3+cost4)

    ans=heappop(ans)
    if(ans==inf):ans=-1
    print(ans)













                

    









    
