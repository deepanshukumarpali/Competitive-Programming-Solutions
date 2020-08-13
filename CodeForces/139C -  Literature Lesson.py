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

ACCEPTED={'aaaa','aabb','abba','abab'}
vowels='aeiou'
nul='abcd'
nu=0

def operate(s):
    global nu
    c=0
    for i in range(len(s)-1,-1,-1):
        if(s[i] in vowels):
            c+=1
        if(c==k):
            return s[i:]
    nu=(nu+1)%4
    return nul[nu]

def rhymes(a):
    a=[operate(i) for i in a]
    # print(a)

    ID={}
    id=0
    ans=''

    for i in a:
        if(i not in ID):
            ID[i]=nul[id]
            id+=1
        ans+=ID[i]

    return ans



n,k=value()
scheme=set()

for i in range(n):
    a=[]
    for j in range(4):
        a.append(input())
    scheme.add(rhymes(a))
        

# print(scheme)

for i in scheme:
    if(i not in ACCEPTED):
        print("NO")
        exit()

if(len(scheme)>2):
    print("NO")
elif(len(scheme)==2):
    if('aaaa' not in scheme):
        print("NO")
    else:
        for i in scheme:
            if(i!='aaaa'):
                print(i)
else:
    print(*scheme)



    








    




    




    













                

    









    
