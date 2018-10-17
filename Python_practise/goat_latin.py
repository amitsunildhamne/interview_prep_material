
vowelList = ['a','e','i','o','u','A','E','I','O','U']

def convertToGoatLatin(str):
    ls = str.split(" ")
    for i in xrange(len(ls)):
        if ls[i][0] not in vowelList:
            ls[i] = ls[i][1:]
        ls[i]+="ma"
        ls[i]+="a"*(i+1)
    print ls
    return " ".join(ls)


def main():
    str = "I speak goat Latin"
    print convertToGoatLatin(str)

if __name__=="__main__":
    main()
