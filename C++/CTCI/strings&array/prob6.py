string1 = raw_input('Enter a string to compress: ')
i=0
count=0
s = ''
while (i<len(string1)):
    count+=1
    try:
        if string1[i]!=string1[i+1]:
            s += string1[i]+str(count)
            count=0
    except:
        s+=string1[i]+str(count)
    i+=1
if string1 !=s:
    print s
else:
    print string1
