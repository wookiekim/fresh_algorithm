# -*- coding: utf-8 -*-

###########################################################
# KAKAO 1 #################################################
# N진수 게임                                              #
# 2 <= n <= 16 진법 					  #
# 0 < t <= 1000 미리 구해놓을 수의 개수			  #
# 2 <= ㅡ <= 100 참가인원				  #
# 1 <= p <= m 튜브의 순서				  #
###########################################################
# OUTLINE: ################################################
# p + (t - 1) * m 이하의 모든 숫자를 저장하는 배열 생성   #
# 빈 리스트에 위 리스트를 n진수로 변환한 버전을 넣음      #
# 위 리스트를 str으로 concat한다			  #
# 각 턴에 해당하는 부분만 이어붙인다			  #
###########################################################

def convert_to_nary(num, n):
  if num < n:
    return over_ten(num)
  else:
    return convert_to_nary(num / n ,n) + over_ten(num % n)

def over_ten(num):
  if num > 9:
    offset = num - 10
    sub = ['A','B','C','D','E','F']
    return sub[offset]
  return str(num)

n = input()
t = input()
m = input()
p = input()

base_list = [i for i in range(p + m * (t-1))]

converted_list = [convert_to_nary(i, n) for i in base_list]

full_string = ''.join(converted_list)

turns = [p]

for i in range(t - 1):
  turns.append(p + (i+1) * m)

result = []

for i in turns:
  result.append(full_string[i - 1])

result = ''.join(result)
print result
