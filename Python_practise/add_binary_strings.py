
def strToDec(x):
    res = 0
    for i in xrange(0, len(x)):
        if x[i]:
            res+= 2**i
    return res

def add_binary(a,b):
    a = a[::-1]
    b = b[::-1]
    bVal = strToDec(b)
    aVal = strToDec(a)
    return bin(aVal+bVal)

def main():
    a = "11"
    b = "1"
    print str(add_binary(a,b))[2:]

if __name__=="__main__":
    main()
