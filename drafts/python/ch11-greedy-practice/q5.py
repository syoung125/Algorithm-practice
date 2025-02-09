# -*- coding: utf-8 -*-
# 볼링공 고르기

# 조합 사용
# from itertools import combinations

# n, m = map(int, input().split())
# ballWeights = list(map(int, input().split()))

# result = 0
# for nC2 in combinations(ballWeights, 2):
#     if nC2[0] != nC2[1]:
#         result += 1

# print(result)

# 조합 미사용
n, m = map(int, input().split())
ballWeights = list(map(int, input().split()))

result = 0
for ball1Idx in range(n - 1):
    for ball2Idx in range(ball1Idx, n):
        if ballWeights[ball1Idx] != ballWeights[ball2Idx]:
            result += 1

print(result)
