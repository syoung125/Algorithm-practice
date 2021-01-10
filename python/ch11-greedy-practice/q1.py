# # -*- coding: utf-8 -*-
# # 모험가 길드

n = int(input())
adventurerFears = list(map(int, input().split()))
adventurerFears.sort(reverse=True)

result, maxValue = 0, 0

for adventurerFear in adventurerFears:
    if maxValue == 0:
        result += 1
        maxValue = adventurerFear
    maxValue -= 1

if maxValue > 0:
    result -= 1

print(result)
