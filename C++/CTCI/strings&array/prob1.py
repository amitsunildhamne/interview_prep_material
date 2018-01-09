string = raw_input('Enter a string: ')
i=0
flag = False
hashmap = {}
while i<len(string):
    hashmap[string[i]] =0
    i+=1
i=0
while i<len(string):
    hashmap[string[i]] +=1 
    i+=1
i=0
while i<len(string):
    if hashmap[string[i]]>1:
        flag =True
        break
    i+=1
if flag:
    print 'Not unique'
else:
    print "Unique"
