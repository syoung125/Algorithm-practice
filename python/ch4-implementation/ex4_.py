# -*- coding: utf-8 -*-
# 게임 개발 (다시)

# n, m 입력받음
n, m = map(int, input().split())

# 방문한 유무를 저장하기 위한 맵을 생성하여 0으로 초기화
d = [[0] * m for _ in range(n)]
# 현재 캐릭터의 위치와 방향 입력받기
x, y, direction = map(int, input().split())
# 주의: x - 북쪽으로부터 떨어진 칸의 개수, y - 서쪽으로부터 떨어진 칸의 개수
d[x][y] = 1  # 현재 좌표 방문처리

# 전체 맵 정보 입력받기
array = []
for i in range(n):
    array.append(list(map(int, input().split())))

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


def turn_left():
    global direction
    direction += 1
    if direction == 3:
        direction = 0


# 시뮬레이션 시작
count = 1
turn_time = 0
while True:
    turn_left()
    nx = x + dx[direction]
    ny = y + dy[direction]
    if d[nx][ny] == 0 and array[nx][ny] == 0:
        x, y = nx, ny  # 방문
        d[x][y] = 1  # 방문 표시
        count += 1
        turn_time = 0
        continue
    else:
        turn_time += 1
    # 4방향 모두 탐색한 경우
    if turn_time == 4:
        # 뒤로가기
        nx = x - dx[direction]
        ny = y - dy[direction]
        if array[nx][ny] == 0:
            x, y = nx, ny  # 뒤로 갈수 있으면 이동
        else:
            break  # 바다로 막힌 경우
        turn_time = 0

# 정답 출력
print(count)
