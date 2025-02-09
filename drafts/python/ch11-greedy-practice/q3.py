# -*- coding: utf-8 -*-
# 문자열 뒤집기

s = list(map(int, input().split()))

prevNum = s[0]
result = 1
for num in s[1:]:
    if prevNum != num:
        prevNum = num
        result += 1
result //= 2

print(result)
