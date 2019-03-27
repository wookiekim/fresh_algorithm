# Dynamic Programming

### 기본적인 재귀를 더욱 최적화하는 방안
**같은** 인풋(parameter)에 대해 function call이 일어나는 재귀함수인 경우, \
**Dynamic Programming**을 통해 최적화할 수 있다.

### High-level Idea
Subproblem의 결과를 **저장**해둠으로서, 나중에 같은 계산을 반복 할 필요가 없도록 한다.
* 이 간단한 optimization이 Exponential (O(2<sup>n</sup>)) 을 Linear (O(n))으로 줄일 수 있다.

예시: Fibonacci

```c
/* Recursion: Exponential */

int fib(int n)
{
  if (n <=1)
    return n;
  return fib(n-1) + fib(n-2);
}
```
```c
/* Dynamic Programming: Linear */

f[0] = 0;
f[1] = 1;

for (i=2; i <=n; i ++)
{
  f[i] = f[i-1] + f[i-2];
}
```

물론 이렇게 단적인 예시만으로 종결되는 Dynamic Programming 기법은 아니다.

## Basic Concepts
### [DP문제를 푸는 방법](https://www.geeksforgeeks.org/solve-dynamic-programming-problem/)
우선 2가지를 알아야 한다:

1. Overlapping Subproblems (겹치는 소문제)
2. Optimal Substructure Property (최적의 substructure의 성질)

DP문제를 푸는 단계:

1. DP문제인지 확인한다
* 흔한 DP문제들..
  * 특정 값을 **최대화(maximize)/최소화(minimize)** 하는 문제나,
  * 특정 조건 하에 arrangement 를 count하는 문제나,
  * 특정 확률 문제는 DP로 풀 수 있다.
* 모든 DP문제는 **overlapping subproblems property**를 만족한다
  * 대부분의 클래식한 DP문제들은 Optimal Substructure Property도 만족한다.

2. Decide a state expression with least parameters 
* DP문제는 **state**와 **state들의 transition** 과 관련한 문제다.
  * state: set of parameters that can uniquely identify a certain position or standing in the given problem.
  * state space를 줄이기 위해 해당 'set of parameters'는 적을수록 좋음
  * Fibonacci의 경우 'n번째'가 state
  - 해당 n만 가지고 subproblem을 만들 수 있음(n - m번째 fibonacci숫자를 찾는다...)
3. Formulate state relationship
* DP문제를 푸는 과정 중 가장 어려운 부분
* 많은 연습과 직관, 관찰을 필요로 함

예시 문제:
```
Given 3 numbers {1, 3, 5}, we need to tell \
the total number of ways we can form a number 'N' \
using the sum of the given three numbers. \
(allowing repetitions and different arrangements).

Total number of ways to form 6 is: 8 \
1+1+1+1+1+1 \
1+1+1+3 \
1+1+3+1 \
1+3+1+1 \
3+1+1+1 \
3+3 \
1+5 \
5+1 \
```
위 문제에서의 상태: state(n) :: 1,3,5를 사용하여 숫자 N(위 예시에서 6)을 만들 수 있는 경우(arrangement) \
우리의 목적은 state(n)을 얻는 것!

예시로 N = 7일 때의 경우를 알고싶다고 하자. \

* n = 1~6일 때의 결과를 안다고 '가정'한다.
* 1,3,5 만 더할 수 있음 (주어진 숫자들이 1,3,5임)
* 고로 7을 얻기 위해선 3가지 방법이 있다:
  * state(6)의 모든 경우에 1을 더하기
  * state(4)의 모든 경우에 3을 더하기
  * state(2)의 모든 경우에 5를 더하기
* state(7) = state(7-1) + state(7-3) + state(7-5)

따라서 우리의 코드는 다음과 같아진다:

```c
int solve(int n) 
{  
   // base case 
   if (n < 0)  
      return 0; 
   if (n == 0)   
      return 1;   
  
   return solve(n-1) + solve(n-3) + solve(n-5); 
}
```
하지만 위의 코드는 단순 recursion으로, 같은 단계를 여러 번 계산하는 구조다.
* Memoization을 추가해주면 된다.

4. Do tabulation (or add memoization)
각 state의 값을 미리 저장해놔서 해당 state가 다음에 필요할 때 굳이 계산하지 않아도 되도록 하는 것.

```c
// initialize to -1 
int dp[MAXN]; //-1로 초기화됐다고 가정 
  
// this function returns the number of  
// arrangements to form 'n'  
int solve(int n) 
{  
  // base case 
  if (n < 0)   
      return 0; 
  if (n == 0)   
      return 1; 
  
  // checking if already calculated 
  if (dp[n]!=-1)  
      return dp[n]; 
  
  // storing the result and returning 
  return dp[n] = solve(n-1) + solve(n-3) + solve(n-5); 
} 
```

Tabulation은 그럼 뭔가요?
* 나중에 나옵니다.

### [Overlapping Subproblem Property](https://www.geeksforgeeks.org/overlapping-subproblems-property-in-dynamic-programming-dp-1/)
* 분할정복과 비슷하게, Subproblem에 대한 해답을 사용하여 Conquer(정복)하는 구조
* DP는 같은 Subproblem의 해답이 **여러번** 필요할 때 주로 사용된다.
  * 똑같은 값이 여러 번 계산 될 필요가 없도록 하는 방안.
  * 예시로 Binary Search는 Divide and Conquer지만, **같은** Subproblem은 없음 (항상 다른 범위에서 비교연산)
  * 그러나 Fibonacci와 같은 경우, 여러번 연산되는 Subproblem들이 있다.

```
                          fib(5)
                     /             \
               fib(4)                fib(3)
             /      \                /     \
         fib(3)      fib(2)         fib(2)    fib(1)
        /     \        /    \       /    \
  fib(2)   fib(1)  fib(1) fib(0) fib(1) fib(0)
  /    \
fib(1) fib(0)
```
따라서 연산이 한 번만 진행되고, 이후에는 이미 연산된 값을 바탕으로 불러오기만 하면 되는 두 가지 방법이 있다:
1. Tabulation (Bottom Up)
2. Memoization (Top Down)

나중에 나옵니다

### [Optimal Substructure Property](https://www.geeksforgeeks.org/optimal-substructure-property-in-dynamic-programming-dp-2/)
* 주어진 문제의 최적해가 subproblem들의 최적해를 사용하여 구해질 수 있다면

ex) Shortest Path (graph) 문제
```
If a node x lies in the shortest path \
from a source node u to destination node v \
then the shortest path from u to v is \
combination of shortest path from u to x and shortest path from x to v.
``` 
* Floyd-Warshall과 Bellman-Ford 또한 Dynamic Programming 사용

### Tabulation vs Memoization
**Tabulation**: Bottom Up \
**Memoization**: Top Down

문장 1:
* 나는 스터디를 통해 DP를 공부하고, DP 예제를 풀어본 뒤 DP를 마스터할거야!

문장 2:
* DP를 마스터하기 위해, 나는 DP 예제를 풀어야할거야 - 우선 스터디를 통해 DP를 공부해야겠어!

> 두 문장이 의미는 같으나 내용의 순서만 다르듯, \
Tabulation과 Memoization 또한 결과는 같으나 순서만 다르다.

Tabulation: state[0]에서 시작하여 state[n]까지 가는 것


```c
// Tabulated version to find factorial x.
int dp[MAXN];

// base case
int dp[0] = 1;
for (int i = 1; i< =n; i++)
{
    dp[i] = dp[i-1] * i;
}
```

Memoization: state[n]에서 시작하여 state[0]까지 가는 것
```c
// Memoized version to find factorial x.
// To speed up we store the values
// of calculated states

// initialized to -1
int dp[MAXN]

// return fact x!
int solve(int x)
{
    if (x==0)
        return 1;
    if (dp[x]!=-1)
        return dp[x];
    return (dp[x] = x * solve(x-1));
}
```


Tabulation과 Memoization 비교:

|-|Tabulation|Memoization|
|-|----------|-----------|
|State|State transition 관계를 구상하기 어려움| 쉬움|
|Code|조건이 많아질수록 코드가 복잡해짐|비교적 덜 복잡함|
|Speed|직전 state에 직접적으로 access하는 것이라 빠름| Recursion과 Return이 많아서 느림|
|Subproblem solving|모든 Subproblem이 풀려야하는 경우 더 빠름|몇 개의 Subproblem이 풀릴 필요가 없는 경우 더 빠름|

## Advanced Concepts
* [Bitmasking DP](https://www.geeksforgeeks.org/bitmasking-and-dynamic-programming-set-1-count-ways-to-assign-unique-cap-to-every-person/)
* [Digit DP](https://www.geeksforgeeks.org/digit-dp-introduction/)
