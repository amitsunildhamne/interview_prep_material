
def max_op(ls):
    op=ls[0]
    for i in xrange(1,len(ls)):
        if op==0 or op==1 or ls[i]==1 or ls[i]==0:
            op+=ls[i]
        else:
            op*=ls[i]
    return op

def convert_to_list(ls,s):
    for i in xrange(0,len(s)):
        ls.append(int(s[i]))
    return ls

def main():
    s = "891"
    ls = []
    convert_to_list(ls,s)
    print max_op(ls)
if __name__=="__main__":
    main()
