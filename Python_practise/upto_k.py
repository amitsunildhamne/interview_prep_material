

def add_upto_k(l,k):
    l.sort()
    while l[0]<k:
        l[1]+=l[0]
        l.pop(0)
        l.sort()
    return l

l = [2,2,3,7,5,6]
k=5
print add_upto_k(l,k)
