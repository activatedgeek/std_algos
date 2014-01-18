import math,sys
def nck(n,k):
	res=1
	for i in range(1,k+1):
		res*= n-k+i
		res/=i
	return res%1000000007

test=-1
for line in sys.stdin:
	if test!=-1:
		num = line.split(' ')
		m = int(num[0])
		n = int(num[1])
		print nck(m+n-2,min(m,n)-1)
	else:
		test = int(line)