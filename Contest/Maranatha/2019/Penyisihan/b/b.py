def f(v):
	if (v == p[v]):
		return v
	else:
		p[v] = f(p[v])
		return p[v]

def unite(u, v, par):
	u = f(u)
	v = f(v)
	p[v] = u
	if (par == 0):
		sz[u] = (min(sz[u][0], sz[v][0]), max(sz[u][1], sz[v][1]))
	elif (par == 1):
		sz[u] = (sz[u][0], sz[v][1])
	elif(par == 2):
		sz[u] = (max(sz[u][0], sz[v][0]), max(sz[u][1], sz[v][1]))

S = input().strip()
S = S[1:-1]
A = S.split(',')
A = [s.replace('(', '').replace(')', '') for s in A]
A = [int(s) for s in A]
 
L = A[::2]
R = A[1::2]
A = [(L[i], R[i]) for i in range(len(L))]

sz = [(A[i][0], A[i][1]) for i in range(len(A))]
p = [i for i in range(len(A))]

for (i, x) in enumerate(A):
	for (j, y) in enumerate(A):
		if (j <= i):
			continue
		if (x[0] <= x[1] and x[1] >= y[0] and y[0] <= y[1]):
			unite(i, j, 0)
		elif(x[0] <= x[1] and x[1] >= y[0] and y[0] >= y[1]):
			unite(i, j, 1)
		elif(y[0] >= y[1] and x[0] <= x[1] and y[1] >= x[0]):
			unite(i, j, 2)
		elif(x[0] >= x[1] and y[0] >= y[1] and x[0] <= y[1]):
			unite(i, j, 2)


ans = []

for i in range(len(A)):
	if (i == p[i]):
		ans.append(sz[i])

ans.sort(key = lambda tup: tup[0])
print(ans)
