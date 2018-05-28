
def find_split_point(l):
    leftSum=0
    i=0
    while(i<len(l)):
        leftSum+=l[i]
        i+=1
    i=0
    rightSum=0
    while(i<len(l)):
        leftSum-=l[i]
        rightSum+=l[i]
        if(leftSum==rightSum):
            return i
        elif (leftSum<rightSum):
            break
        i+=1
    return -1

def split_array(l):
    print "Entered split array"
    p = find_split_point(l)
    if (p==-1 or p==len(l)):
        print "No split point"
    else:
        i=0
        while i<=p:
            print str(l[i])+" "
            i+=1
        print "\n"
        while i<len(l):
            print str(l[i])+" "
            i+=1

l = [1,2,5]
split_array(l)
