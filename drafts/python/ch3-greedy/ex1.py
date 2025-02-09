# -*- coding: utf-8 -*-
# 예제 3-1 거스름돈
input = 1260


def calculateChange(n):
    change = 0
    list = [500, 100, 50, 10]
    for coin in list:
        change += n // coin
        n %= coin

    return change


output = calculateChange(input)

print(output)
