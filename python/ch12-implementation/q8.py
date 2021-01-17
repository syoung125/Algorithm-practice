# -*- coding: utf-8 -*-
# 문자열 재졍렬

s = list(input())
alphabet_array = []
hasNum, num_sum = False, 0  # hasNum: 숫자가 없는 경우 0도 붙이면 안되므로 필요한 변수
for c in s:
    # 알파벳 대문자인 경우 그냥 결과 문자열에 붙임
    if ord(c) >= ord('A') and ord(c) <= ord('Z'):
        alphabet_array.append(c)
    # 숫자인 경우 합산
    else:
        if hasNum == False:
            hasNum = True
        num_sum += int(c)

alphabet_array.sort()
result = ''.join(alphabet_array)

if hasNum:
    result += str(num_sum)

print(result)
