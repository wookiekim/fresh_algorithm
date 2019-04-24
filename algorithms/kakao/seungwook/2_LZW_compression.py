# -*- coding: utf-8 -*-

###########################################################
# KAKAO 2 #################################################
# 압축    	                                          #
# INPUT       	 					  #
# 영문 대문자로만 이루어진 msg // 1 < len(msg) <= 1000	  #
###########################################################

import string

msg = raw_input()

indexes = {ch: n + 1 for n, ch in enumerate(string.ascii_uppercase)}

s = 0
index = 0
result = []
e = 1

while e <= len(msg):
  if msg[s:e] in indexes:
    index = indexes[msg[s:e]]
    e += 1
    continue
  else:
    result.append(index)
    indexes[msg[s:e]] = len(indexes) + 1
    s += e - s - 1

result.append(index)

print result
