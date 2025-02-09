# -*- coding: utf-8 -*-
# 왕실의 나이트

input_data = input()
x = int(ord(input_data[0])) - int(ord('a')) + 1
y = int(input_data[1])

available_cases = [
    (-2, -1), (-2, 1), (2, -1), (2, 1), (1, 2), (-1, 2), (-1, -2), (1, -2)
]

result = 0
for case in available_cases:
    # 말을 이동해본 좌표
    nx = x + case[0]
    ny = y + case[1]
    # 체스판을 벗어나지 않은 경우
    if nx >= 1 and ny >= 1 and nx <= 8 and ny <= 8:
        result += 1  # 경우의 수를 1 증가시킨다

print(result)
