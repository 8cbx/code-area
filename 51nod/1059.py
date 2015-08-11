a=input()
ans=1
for i in range (1,a+1):
	ans=ans*i
ans2='%d'%ans
#print ans2
for i in range (1,int(len(ans2)/1000)+1):
	print ans2[(i-1)*1000:i*1000]
print ans2[int(len(ans2)/1000)*1000:]
