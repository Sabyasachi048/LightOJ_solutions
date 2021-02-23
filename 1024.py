import sys,io,os,math


def sieve():
	MX=10005
	global mark
	mark=[False]*MX
	global primes
	primes=[]
	for i in range(4,MX,2):
		mark[i]=True
	for i in range(3,int(math.sqrt(MX)),2):
		if mark[i]==False:
			for j in range(i*i,MX,2*i):
				mark[j]=True
	primes.append(2)
	for i in range(3,MX,2):
		if mark[i]==False:
			primes.append(i)

def gcd(a,b):
	if(a==0):
		return b
	return gcd(b%a,a)

def lcm(a):
	if(len(a)==1):
		return a[0]
	ans=1
	pdict={}
	for num in a:
		i=0
		x=num
		while i<len(primes) and primes[i]<=int(math.sqrt(num)):
			cnt=0
			while x%primes[i]==0 and x>0:
				x=x//primes[i]
				cnt+=1
			if(cnt>0):
				if(primes[i] in pdict):
					pdict[primes[i]]=max(pdict[primes[i]],cnt)
				else:
					pdict[primes[i]]=cnt
			i+=1
		if(x>=2):
			if(x not in pdict):
				pdict[x]=1
	for k in pdict.keys():
		ans*=int(math.pow(k,pdict[k]))
	return ans




if __name__	==	"__main__":
	sieve()
	ts=int(sys.stdin.readline())
	cs=0
	while ts>0:
		n=int(sys.stdin.readline())
		ara=list(map(int,sys.stdin.readline().split()))
		cs+=1
		ans=lcm(ara)
		sys.stdout.write("Case %d: "%(cs))
		sys.stdout.write(str(int(ans))+'\n')
		ts-=1



	