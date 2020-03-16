# -*- coding: utf-8 -*-
# @Author: apikdech
# @Date:   09:26:36 31-08-2019
# @Last Modified by:   apikdech
# @Last Modified time: 09:39:55 31-08-2019
import random
t = 8000
print(t)
for tc in range(t):
	n = 1
	print(n)
	a = []
	for i in range(n):
		a.append(random.randint(1, 10000))
	s = " ".join(map(str, a))
	print(s)
