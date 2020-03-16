# -*- coding: utf-8 -*-
# @Author: apikdech
# @Date:   16:56:52 16-06-2019
# @Last Modified by:   apikdech
# @Last Modified time: 20:07:47 16-06-2019
l = (int)(input())
tmp = input()

a = 0
b = 0
c = 0
d = 0
ans = 0
ok = 0
idx = 0

if (l % 2 == 0):
	if (tmp[l//2] == '0'):
		x = l//2
		y = l//2
		while(x >= 0 and tmp[x] == '0'):
			x -= 1
		while(y < l and tmp[y] == '0'):
			y += 1
		if (x == 0):
			for i in range(0, y):
				a *= 10
				a += int(tmp[i])
			for i in range(y, l):
				b *= 10
				b += int(tmp[i])
			ans = a + b
		else:
			for i in range(0, x):
				a *= 10
				a += int(tmp[i])
			for i in range(x, l):
				b *= 10
				b += int(tmp[i])
			ans = a + b
	else:
		for i in range(0, l//2):
			a *= 10
			a += int(tmp[i])
		for i in range(l//2, l):
			b *= 10
			b += int(tmp[i])
else:
	if (tmp[l//2] == '0' and tmp[l//2+1] == '0'):
		x = l//2
		y = l//2
		while(x >= 0 and tmp[x] == '0'):
			x -= 1
		while(y < l and tmp[y] == '0'):
			y += 1
		if (x == 0):
			for i in range(0, y):
				a *= 10
				a += int(tmp[i])
			for i in range(y, l):
				b *= 10
				b += int(tmp[i])
			ans = a + b
		else:
			for i in range(0, x):
				a *= 10
				a += int(tmp[i])
			for i in range(x, l):
				b *= 10
				b += int(tmp[i])
			ans = a + b
	elif (tmp[l//2] == '0'):
		for i in range(0, l//2):
			a *= 10
			a += int(tmp[i])
		for i in range(l//2, l):
			b *= 10
			b += int(tmp[i])
		ans = a+b
	elif (tmp[l//2+1] == '0'):
		for i in range(0, l//2+1):
			a *= 10
			a += int(tmp[i])
		for i in range(l//2+1, l):
			b *= 10
			b += int(tmp[i])
		ans = a+b
	else:
		for i in range(0, l//2):
			a *= 10
			a += int(tmp[i])
		for i in range(l//2, l):
			b *= 10
			b += int(tmp[i])
		for i in range(0, l//2+1):
			c *= 10
			c += int(tmp[i])
		for i in range(l//2+1, l):
			d *= 10
			d += int(tmp[i])
		ans = min(a+b, c+d)

print(ans)

# SALAH COX