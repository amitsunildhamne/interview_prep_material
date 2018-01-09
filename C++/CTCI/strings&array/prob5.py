def replace(string_1,string_2):
    idx = 0
    s=0
    while(idx<len(string_1)):
        if string_1[idx]!=string_2[idx]:
            s+=1
        idx+=1

    if s>1:
        return False
    else:
        return True


def insert(string_1,string_2):
    idx1 = 0
    idx2 = 0
    while(idx1<len(string_1) and idx2<len(string_2)):
        if string_1[idx1]!=string_2[idx2] :
            if idx1 != idx2:
                return False
            idx2+=1
        else:
            idx1+=1
            idx2+=2
    return True

def main():
    string_1 = raw_input('Add 1st string: ')
    string_2 = raw_input('Add 2nd string: ')
    n1 = len(string_1)
    n2 = len(string_2)
    if n1==n2:
        flag = replace(string_1,string_2)
    elif n2 ==n1+1:
        flag = insert(string_1,string_2)
    elif n1-1==n2:
        flag = insert(string_2,string_1)
    print flag
if __name__ == "__main__":main()
