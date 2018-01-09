string = raw_input("Enter the string: ")
ls = []
data = string.split(' ')
for temp in data:
    ls.append(temp)
n=0
for n in xrange(len(ls)-1):
    ls[n] = ls[n]+'%20'
n=0
ans = ''
for n in xrange(len(ls)):
    ans+= ls[n]
print ans
