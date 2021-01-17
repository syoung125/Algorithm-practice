# -*- coding: utf-8 -*-
# 럭키 스트레이트

n = str(input())
half_idx = len(n)//2

l_sum, r_sum = 0, 0
for num in range(half_idx):
    l_sum += int(n[num])
    r_sum += int(n[num + half_idx])

if l_sum == r_sum:
    print("LUCKY")
else:
    print("READY")
