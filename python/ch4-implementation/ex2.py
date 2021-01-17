# -*- coding: utf-8 -*-
# 4-2 시각

h = int(input())

count = 0
for i in range(h+1):
    if '3' in str(i):
        count += 3600
        continue
    for j in range(60):
        if '3' in str(j):
            count += 60
            continue
        for k in range(60):
            if '3' in str(k):
                count += 1

print(count)
