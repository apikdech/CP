# -*- coding: utf-8 -*-
# @Author: apikdech
# @Date:   22:57:59 17-07-2019
# @Last Modified by:   apikdech
# @Last Modified time: 23:06:15 17-07-2019
def f(x):
	i = 10
	res = 0
	while(x > 0):
		res += ((int(x % 10)) * i)
		x /= 10
		i *= 100
	return int(res)

n = int(input())
a = list(map(int, input().split()))
ans = 0
mod = 998244353


for x in a:
	tmp = f(x)
	ans += tmp + tmp//10

ans *= n
print(ans % mod)