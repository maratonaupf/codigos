# -*- coding: utf-8 -*-
# Leonardo Deliyannis Constantin
# https://codeforces.com/contest/1337/problem/A

def isTriangle(x, y, z):
    return x+y > z and x+z > y and y+z > x
    # return not(x+y <= z or x+z <= y or y+z <= x)

def printIfRight(x, y, z):
    if isTriangle(x, y, z):
        print("%d %d %d" % (x, y, z))
        return True
    return False

def main():
    t = int(input())
    while t > 0:
        t -= 1
        a, b, c, d = map(int, input().split())
        arr = [
            [a, b, c], [a, b, d], [a, c, d], [b, c, d],
            [a, c, c], [b, c, c], [b, b, c], [b, b, d]
        ]
        ans = False
        for x in arr:
            if printIfRight(x[0], x[1], x[2]):
                ans = True
                break
        if not ans:
            exit(1)

# if __name__ == '__main__':
main()
