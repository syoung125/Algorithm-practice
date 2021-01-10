# -*- coding: utf-8 -*-
# 큰 수의 법칙

# test input
# n, m, k = 5, 8, 3
# data = [2, 4, 5, 4, 6]

n, m, k = map(int, input().split())  # input은 string이어야 함 ex) "5 8 3"
data = list(map(int, input().split()))

data.sort(reverse=True)  # 정렬 (reverse True: 내림차순)
first = data[0]
second = data[1]

result = (first * k) * (m // k) + second * (m % k)

print(result)
