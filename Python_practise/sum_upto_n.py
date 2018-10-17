
def generate_subarray(l, total):
    for i in xrange(0, len(l)):
        curr_sum = l[i]
        if curr_sum == total:
            return (i,i)
        elif curr_sum<total:
            for j in xrange(i+1, len(l)):
                curr_sum+=l[j]
                if curr_sum==total:
                    return (i,j)
                elif curr_sum>total:
                    break
                

def main():
    l = [1, 4, 20, 3, 10, 5]
    total = 33
    print generate_subarray(l,total)

if __name__=="__main__":
    main()
