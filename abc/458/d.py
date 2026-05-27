import heapq

heap = []
# heapq.heappush(heap, 30)
# heapq.heappush(heap, 20)

# リストなのでインデックスでランダムアクセス可能（O(1)）
# print(heap[0])  # 先頭要素にアクセス (常に最小値)
x=int(input())
q=int(input())

for i in range(q):
    
    a,b=map(int,input().split())
    heapq.heappush(heap, a)

    heapq.heappush(heap, b)
    print(heap[1+i])


