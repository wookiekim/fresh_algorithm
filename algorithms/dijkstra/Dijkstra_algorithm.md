# [Dijkstra algorithm](https://ko.wikipedia.org/wiki/데이크스트라_알고리즘)

도로 교통망 같은 곳에서 나타날 수 있는 그래프에서 꼭짓점 간의 최단 경로를 찾는 너비우선탐색(BFS)를 기본으로 하는 알고리즘이다. 더 일반적인 변형은 한 꼭짓점을 '소스'꼭짓점으로 고정하고 그래프의 다른 모든 꼭짓점 까지의 최단경로를 찾는 알고리즘으로 최단 경로 트리를 만드는 것이다.

## 1. [Dijkstra의 기본 로직](https://hsp1116.tistory.com/42)
첫 정점을 기준으로 연결되어 있는 정점들을 추가해가며, 최단 거리를 갱신하는 것이다. 정점을 잇기 전까지는 시작점을 제외한 정점
들은 모두 무한대 값을 가진다. (링크를 통해 예시 보기!)

## 2. 우선순위 큐(힙구조) 사용
배열을 매번 탐색해서 가장 짧은 거리를 찾기에는 시간이 너무 걸린다. 이때 힙 구조를 이용하면 더욱 빠른 시간 내에 구현이 가능하다. add_with_priority(), decrease_priority(), extract_min()을 사용한다.

```
1  function Dijkstra(Graph, source):
2      dist[source] ← 0                                    // 초기화
3
4      create vertex set Q
5
6      for each vertex v in Graph:
7          if v ≠ source
8              dist[v] ← INFINITY                          // 소스에서 v까지의 아직 모르는 길이
9          prev[v] ← UNDEFINED                             // v의 이전 노드
10
11         Q.add_with_priority(v, dist[v])
12
13
14     while Q is not empty:                          // 메인 루프
15         u ← Q.extract_min()                         // 최고의 꼭짓점을 제거하고 반환한다
16         for each neighbor v of u:              // Q에 여전히 남아 있는 v에 대해서만
17             alt ← dist[u] + length(u, v)
18             if alt < dist[v]
19                 dist[v] ← alt
20                 prev[v] ← u
21                 Q.decrease_priority(v, alt)
22
23     return dist, prev
```

## [Time complexity](https://blog.naver.com/uuuu118/221430383952)
하나의 노드에 대해 다익스트라 알고리즘을 수행하는 경우를 따져보면, 미방문노드 가운데 거리가 가장 작은 노드에 BFS를 적용한다. 거리를 가장 작은 미방문노드를 가려내려면 최악의 경우 노드 전체를 모두 따져봐야 하므로 O(|V|)
이다. 선택된 노드의 모든 이웃노드들에 대해 최단경로 정보를 업데이트한다. 한 노드당 엣지의 기대값은 |E|/|V|이다.

다익스트라 알고리즘은 이러한 연산을 전체 노드 수만큼 반복하므로 전체적인 계산복잡성은 O(|V|^2+|E|)가 된다. 보통의 dense graph는 엣지의 수가 노드 수의 제곱만큼 있으므로 간략하게 시간복잡도를 적으면 O(|V|^2)이 된다.

하지만! 우선순위 큐(priority queue)를 사용하여 이를 개선할 수 있다.
시간 복잡도에 영향을 주는 작업은 두 가지인데
하나는 각 정점마다 인접한 간선들을 모두 검사하는 작업이고,
다른 하나는 우선순위 큐에 원소를 넣고 삭제하는 작업이다.

모든 간선이 한 번씩 검사된다는 점에서 첫 번째 작업이 O(E),
각 간선마다 우선순위 큐에 자료가 삽입 연산이 일어난다는 점에서 O(E log V)이며
이 둘을 합쳤을 때(E + E log V) time complexity는 O(E log V)이다.
이 둘을 합쳤을 때(E + E log V) time complexity는 O(E log V)이다.

## 단점
가중치가 음수인 경우 작동하지 않는다. 이때 벨만-포드 알고리즘을 사용해야 한다.
