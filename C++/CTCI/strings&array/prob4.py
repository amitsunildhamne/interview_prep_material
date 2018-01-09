string = raw_input('Enter the string: ')
d = {}
i=0
while i<len(string):
    d[string[i]] =0
    i+=1
i=0
while i<len(string):
    d[string[i]]=not(d[string[i]])
    i+=1

sum_o=0
i=0
while i<len(string):
    if(d[string[i]]==1):
        sum_o+=1;
    i+=1
if sum_o>1:
    print 'Is not a palindrome'
else:
    print 'Is palindrome'
