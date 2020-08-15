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




length_wise=[0,10,19]

for i in range(3,19):
    length_wise.append(9*(10**(i-2))+length_wise[-1])

# print(length_wise)

def operate(x):
    if(x==-1): return 0
    x=str(x)
    if(len(x)==1): return int(x)+1
    
    ans=length_wise[len(x)-1]

    key=min(int(x[0]),int(x[-1]))
    key1=max(int(x[0]),int(x[-1]))

    if(key==int(x[0])): type=1
    else: type=2

    # print(key,ans)

    x=x[1:-1]
    ans1=0
    try:ans1=int(x)
    except:pass
    
    if(type==2):
        ans+=(key1-1)*(10**len(x))
    else:
        ans+=(key-1)*(10**len(x))
        ans1+=1

    # print(ans,ans1,x)

    return ans+ans1





l,r=value()

# print(operate(l-1))
# print(operate(r))

print(operate(r)-operate(l-1))


# BruteForce
# ans=0
#
# for i in range(l,r+1):
#     x=str(i)
#     if(x[0]==x[-1]):
#         # print(x)
#         ans+=1
    
# print(ans)  
    

        





                

    









    
