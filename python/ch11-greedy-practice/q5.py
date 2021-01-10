# -*- coding: utf-8 -*-
# 볼링공 고르기
from itertools import combinations

n, m = map(int, input().split())
ballWeights = list(map(int, input().split()))

result = 0
for nC2 in combinations(ballWeights, 2):
    if nC2[0] != nC2[1]:
        result += 1

print(result)
