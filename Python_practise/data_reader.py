

with open("data1.txt","r") as f:
    rf = f.readline()
    rf = f.readline()
    while rf:
        l=rf.split("  ")
        i=0
        sum=0
        for i in xrange(0,len(l)):
            sum+=int(l[i])
        rf = f.readline()


#to write the lines:
with open("output.txt","w+") as wf:
    with open("input.txt", "r") as rf:
        wf.writelines(rf.readlines())
