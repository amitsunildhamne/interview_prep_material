fibo_ls={}
def creat_fibo_ls(a,b,max):
    if a+b>max:
        return
    elif a+b == max:
        fibo_ls[a+b]=True
        return
    else:
        print a+b
        fibo_ls[a+b]=True
        creat_fibo_ls(b,a+b,max)

def largest_subarray(fibo_ls,ls):
    res = []
    for i in ls:
        if i in fibo_ls:
            res.append(i)
    return res

ls = [1, 4, 3, 9, 10, 13, 7]
max = max(ls)
fibo_ls[1]=True
creat_fibo_ls(1,1,max)
print (largest_subarray(fibo_ls,ls))
