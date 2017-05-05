# -*- coding: utf-8 -*-
# s0 1 1 2 3 5 8 13 21 34 55 89

def digaOi():
	print "Oizinho :3"
	# isso aqui é da função
	
def fibonacci(n):
	if n <= 1:
		return n
	# else:	
	return fibonacci(n-1) + fibonacci(n-2)

def euclides(a, b): # MDC
	if b == 0:
		return a
	return euclides(b, a % b)

x = int(raw_input())
y = int(raw_input())

print "MDC(%d, %d) = %d" % (x, y, euclides(x, y))