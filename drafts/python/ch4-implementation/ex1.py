# -*- coding: utf-8 -*-
# 상하좌우

n = int(input())
plan = input().split()

# L, R, U, D에 따른 이동 방향
direction = {
    'L': [0, -1],
    'R': [0, 1],
    'U': [-1, 0],
    'D': [1, 0]
}

x, y = 1, 1
for d in plan:
    # 이동 후 좌표 구하기
    nx = x + direction[d][0]
    ny = y + direction[d][1]
    # 공간을 벗어 난 경우 무시
    if nx <= 0 or nx > n or ny <= 0 or ny > n:
        continue
    # 이동 수행
    x, y = nx, ny

print(x, y)
