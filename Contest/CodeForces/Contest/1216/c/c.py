# -*- coding: utf-8 -*-
# @Author: apikdech
# @Date:   14:54:18 21-09-2019
# @Last Modified by:   apikdech
# @Last Modified time: 15:20:14 21-09-2019

class Line:
	def _init__(x1, y1, x2, y2):
		dy = y2 - y1
		dx = x2 - x1
		# bottom
		self.x1 = x1
		self.y1 = y1
		# top
		self.x2 = x2
		self.y2 = y2
		self.a = dy
		self.b = -dx
		self.c = y1 * dx - x1 * dy

		self.is_tegak = (x1 == x2)
		self.is_datar = (y1 == y2)

	def posisi_h(self, x, y):
		if y == self.y1:
			return 'pas'
		elif y > self.y1:
			return 'di atas'
		else:
			return 'di bawah'

	def posisi_v(self, x, y):
		if x == self.x1:
			return 'pas'
		elif x > self.x1:
			return 'di kanan'
		else:
			return 'di kiri'

class Rectangle:
	def __init__(x1, y1, x2, y2):
		# bottom
		self.x1 = x1
		self.y1 = y1
		# top
		self.x2 = x2
		self.y2 = y2

	def is_inside(self, x, y):
		ans = True
		ans = (ans and (Line(x1, y1, x2, y1).posisi_v == 'di atas'))
		ans = (ans and (Line(x1, y2, x2, y2).posisi_v == 'di bawah'))
		ans = (ans and (Line(x1, y2, x1, y1).posisi_h == 'di kanan'))
		ans = (ans and (Line(x2, y2, x2, y1).posisi_h == 'di kiri'))
		return ans

class Polygon:
	def __init__(x_arr, y_arr):
		self.x_arr = x_arr
		self.y_arr = y_arr

P = Rectangle(map(int, input().strip().split()))
H1 = Rectangle(map(int, input().strip().split()))
H2 = Rectangle(map(int, input().strip().split()))

ans = True
ans = (ans and H1.is_inside(P.x1, P.y1))
ans = (ans and H1.is_inside(P.x1, P.y2))
ans = (ans and H1.is_inside(P.x2, P.y2))
ans = (ans and H1.is_inside(P.x2, P.y1))
if ans:
	print('YES')
else:
	