

def count_up_k(l,k):
    res=[]
    for i in xrange(0,len(l)-1):
        for j in xrange(i+1,len(l)):
            if abs(l[i]-l[j])==k:
                res.append([l[i],l[j]])
    return res

def remove_dups(ls):
    for x in xrange(0,len(ls)):
        ls[x].sort()
    for i in xrange(0,len(ls)-1):
        for j in xrange(i+1,len(ls)):
            if ls[i]==ls[j]:
                ls.pop(j)
    return len(ls)

def main():
    l = [8, 12, 16, 4, 0, 20]
    k=4
    ls = count_up_k(l,k)
    print remove_dups(ls)

if __name__=="__main__":
    main()
