# -*- coding: utf-8 -*-
# 만들 수 없는 금액

from itertools import combinations

n = int(input())
coins = list(map(int, input().split()))
coins.sort()

storage = set()

expectValue = 1
for i in range(1, len(coins)+1):
    print("i", i)
    for nCi in combinations(coins, i):
        sum = 0
        for num in nCi:
            sum += num
        print("sum", sum)
        print("expectValue", expectValue)
        if (expectValue == sum) | (expectValue in storage):
            expectValue += 1
        elif expectValue < sum:
            storage.add(sum)

print(expectValue)
