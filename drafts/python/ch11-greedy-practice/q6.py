def solution(food_times, k):
    answer = 0
    lastIndex = len(food_times) - 1
    i, time = 0, 0

    # 더 섭취할 음식이 없는 경우 확인
    if sum(food_times) <= k:
        return -1

    while time <= k:
        if food_times[i] > 0:
            if time == k:  # 통신이 끊긴 후 음식을 먹으면 안되므로 break
                break
            food_times[i] -= 1
            time += 1
        if i == lastIndex:
            i = 0
        else:
            i += 1

    answer = i + 1

    return answer
