
def sumUptoZero(ls):
    list_of_results = []
    for i in xrange(0,len(ls)):
        for j in xrange(i+1, len(ls)):
            if -(i+ls[j]) in ls[j+1:]:
                list_of_results.append([i,ls[j],-(i+ls[j])])
    return list_of_results

def remove_dups(ls):
    for i in xrange(0,len(ls)):
        ls[i].sort()
        print ls[i]
    for i in xrange(0,len(ls)):
        if ls[i] in ls[i+1:]:
            ls.pop(i)
    return ls

ls = [0, -1, 2, -3 , 1]
l=sumUptoZero(ls)
print l
