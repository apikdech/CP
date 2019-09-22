from math import gcd

for tc in range(1, int(input()) + 1):
	n, l = map(int, input().split())
	a = list(map(int, input().split()))
	tmp = []
	b = [None]*(l+1)
	w = {}
	ptr = 0
	while a[ptr] == a[ptr+1]: ptr += 1
	g = gcd(a[ptr], a[ptr+1])
	w[a[ptr]//g] = 1
	tmp.append(a[ptr]//g)
	b[ptr] = a[ptr]//g
	if g not in w: 
		tmp.append(g)
		w[g] = 1
	b[ptr+1] = g
	for i in range(ptr+1, l):
		if ((a[i] % b[i]) == 0):
			g = a[i]//b[i]
		else:
			g = a[i]//(a[i-1]//b[i])
		if g not in w:
			w[g] = 1
			tmp.append(g)
		b[i+1] = g
	for i in range(ptr-1, -1, -1):
		if ((a[i] % b[i+1]) == 0):
			g = a[i]//b[i+1]
		else:
			g = a[i]//(a[i+1]/b[i+1])
		if g not in w:
			w[g] = 1
			tmp.append(g)
		b[i] = g
	tmp.sort()
	for i in range(len(tmp)):
		w[tmp[i]] = i
	ans = ""
	for i in range(len(b)):
		ans += chr(w[b[i]] + ord('A'))
	print("Case #%d: " % tc + ans)