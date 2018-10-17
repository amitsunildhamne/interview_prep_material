

def flatten_string(str):
    if str=="" :
        return str
    num_stack=[]
    str_stack=[]
    res = ""
    for i in xrange(0,len(str)):
        if str[i].isdigit():
            num_stack.append(int(str[i]))
        elif str[i]=="[" or str[i].isalpha():
            str_stack.append(str[i])
        elif str[i]=="]":
            s = ""
            while str_stack[-1]!="[":
                s += str_stack.pop()
            s = s[::-1]
            s = num_stack.pop()*s
            res+=s
    print "str_stack: "+ "".join(str_stack)
    print "int_stack"+ "".join(num_stack)
    return res



def main():
    str="3[b2[ca]]"
    print flatten_string(str)

if __name__=="__main__":
    main()
