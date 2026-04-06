import numpy as np
import sys
# ____________________CREATING ARRAY___________________________

a=np.array([1,2,3])
print(a)

b=np.array([(1,2,3),(2,3,4)])
print("size of array :",b.size)
print("shape of array:" ,b.shape)
print("dimensions of array: ",b.ndim)
print("size of each element: ",b.itemsize)
print(b)

c=np.zeros((2,4),dtype=int)
print(c)

d=np.ones((2,2))
print(d)
d=np.ones((3,3),dtype=complex)
print(d)
print("size of each element :",d.itemsize)

e=np.empty((3,3),dtype=np.int16)
print(" data type of e: ",e.dtype)
print(e)

f=np.arange(0,9).reshape(3,3)
print(f)
print(f[1,1])

l=np.linspace(1,10,5,dtype=np.int16)
print(l)

print(np.arange(10000))
#np.set_printoptions(threshold=sys.maxsize)

print(np.arange(10000))

arr=[[1,2,3],[4,5,6],[7,8,9]]

#print(arr[1,1])#in list this gives error it works only for numpy array

# ______________________________Basic Operations________________________
a=np.array([10,20,30,90])

b=np.arange(4)

c=a-b

print(c)

print(a>25)

"""a=([10,20,30,40])
print(a)
b=[0,1,2,3]
c=a-b   # in regular list we cant substract lists like np array
print(c)"""

print(b**2)
angles=np.array([0,np.pi/6,np.pi/4,np.pi/3,np.pi/2,np.pi])
print(np.sin(angles))

A=np.array([[1,2],[3,4]])
B=np.array([[0,1],[2,3]]
           )
#regular martrix multiplication
print(A*B)

#mathematical matrix multiplication
print(A@B)
print(A.dot(B))
import numpy as np

rg1 = np.random.default_rng(1)
rg2 = np.random.default_rng(2)

generator1=rg1.integers(0, 10, 5)
generator2=rg2.integers(0, 10, 5)
generator3=rg1.integers(0,10,5)
generator4=rg2.integers(0,10,5)
print(generator1)
print(generator2)
print(generator3)
print(generator4)