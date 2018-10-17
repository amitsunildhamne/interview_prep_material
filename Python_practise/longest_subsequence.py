def lcs(X, Y, m, n):
    

def iskpal(str, k):
    revstr = str[::-1]
    n = len(str)
    lps = lcs(str,revstr,n,n)
    return n-lps<=2

def main():
    str = "abcdeca"
    k = 2
    print iskpal(str,k)

if __name__=="__main__":
    main()
