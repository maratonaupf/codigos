# -*- coding: utf-8 -*-

def fatorial(n):
    if n == 1 or n == 0:
        print('Caso base, retornando 1')
        return 1
    # print('We need to go deeper:')
    print('Retornando {} * fatorial({})'.format(
        n, n-1))
    return n * fatorial(n-1)

def fibonacci_iterativo(n):
    fib = [0, 1]
    for i in range(2, n+1):
        fib.append(fib[i-2] + fib[i-1])
    return fib[n]

memo = [None] * 1123

def fibonacci(n):
    if memo[n] == None:
        if n <= 1:
            memo[n] = n
        else:
            memo[n] = fibonacci(n-1) + fibonacci(n-2)
    return memo[n]

def main():
    n = int(input())
    memo[0] = 0
    memo[1] = 1
    print(fibonacci(n))

main()
