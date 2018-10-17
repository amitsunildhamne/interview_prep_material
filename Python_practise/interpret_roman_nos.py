def convert_from_roman(str):
    dict = {}
    dict['I'] = 1
    dict['V'] = 5
    dict['X'] = 10
    dict['L'] = 50
    dict['C'] = 100
    dict['D'] = 500
    dict['M'] = 1000
    if str=="":
        return 0
    str = str[::-1]
    res=dict[str[0]]
    for i in xrange(1,len(str)):
        if dict[str[i]] < dict[str[i-1]]:
            res-= dict[str[i]]
        else:
            res+=dict[str[i]]
    return res


def main():
    str = "MCMIX"
    print convert_from_roman(str)

if __name__=="__main__":
    main()
