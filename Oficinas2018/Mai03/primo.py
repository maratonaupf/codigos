def ehPrimo(n):
    for i in range(2, int(n**(1/2)) + 1):
        if n % i == 0:
            return False
    return n >= 2

def main():
    P = int(input())
    for i in range(P):
        N = int(input())
        if ehPrimo(N):
            print('Eh primo')
        else:
            print('Nao eh primo')

if __name__ == '__main__':
    main()
