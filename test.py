def gcd(a,b):
	if(a%b==0):
		return b
	x = b
	b = a%b
	a = x
	return gcd(a,b)

N = int(input(''))
i=0;
for i in range(0,N):
	L= raw_input('').split()
	a=int(L[0]); b = int(L[1]);
	j = gcd(a,b)if (a>=b) else gcd(b,a)
	print j,a*b/j
