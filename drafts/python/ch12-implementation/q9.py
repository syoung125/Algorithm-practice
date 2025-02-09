# -*- coding: utf-8 -*-
# 문자열 압축

def solution(s):
    minLength = len(s)
    for unit in range(1, len(s)//2 + 1):
        # unit개의 단위로 잘라 압축한다
        result = ""
        count = 1
        prev_str = s[:unit]
        # 압축한 문자열 생성
        for curr_idx in range(unit, len(s) + unit, unit):
            curr_str = s[curr_idx:curr_idx+unit]
            if prev_str == curr_str:
                count += 1
            else:
                if count > 1:
                    result += str(count)
                result += prev_str
                count = 1
                prev_str = curr_str
        # minLength 갱신
        if len(result) < minLength:
            minLength = len(result)
    return minLength
