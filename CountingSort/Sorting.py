

def CountingSort(A,B,k):
    C = [ 0 for  i in xrange(0,k+1)]
    for j in xrange(0,len(A)):
        C[A[j]] = C[A[j]]+1
    for i in range(1,k+1):
        C[i]=C[i]+C[i-1]
    for j in xrange(len(A)-1,-1,-1):
        B[C[A[j]]-1]=A[j]
        C[A[j]] = C[A[j]]-1
    return B
    

B = [0,0,0,0,0,0,0,0,0,0]
A = [10,9,9,6,6,5,5,1,1,1]

k = 10

B = CountingSort(A,B,k)

print A
print B