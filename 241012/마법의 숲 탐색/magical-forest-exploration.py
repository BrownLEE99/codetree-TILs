R, C, K = map(int,input().split())
golem =  [[0]+list(map(int,input().split())) for _ in range(K)]

arr = [[-1]+[0]*C +[-1] for _ in range(R+2)] + [[-1]*(C+2)]
exit_1 = []
di = [-1, 0, 1, 0]
dj = [ 0, 1, 0,-1]

from collections import deque


def bfs (si,sj):
    v = [[0]*(C+2) for _ in range(R+3)]
    q = deque()
    q.append((si,sj))
    v[si][sj] = 1
    mx = 0
    while q:
        ci,cj = q.popleft()
        mx = max(ci,mx)
        for i in range(4):
            ni,nj = ci + di[i], cj+dj[i]
            if v[ni][nj] == 0 and (arr[ci][cj] == arr[ni][nj] or ([ci,cj] in exit_1 and arr[ni][nj]>1)):
                q.append((ni,nj))
                v[ni][nj] = 1
                
    return mx - 1
        

            # 현재 좌표가 출구라면 갈수 있다 그리고 
    
ans = 0
num = 0
for _ in range(K):
    
    while True:
        mi, mj ,d = golem[num][0] ,golem[num][1], golem[num][2]
        # 아래로 진행
        if arr[mi+1][mj-1] == 0 and arr[mi+2][mj] == 0 and arr[mi+1][mj+1] ==0:
            ni,nj = mi+1,mj
            golem[num][0] ,golem[num][1] = ni,nj
        # 왼쪽 아래로 진행
        elif arr[mi-1][mj-1] == 0 and arr[mi][mj-2] == 0 and arr[mi+1][mj-1] == 0 and arr[mi+1][mj-2] == 0 and arr[mi+2][mj-1] == 0:
            ni,nj = mi+1,mj-1
            d = (d-1) % 4
            golem[num][0] ,golem[num][1] = ni,nj
            golem[num][2] = d
        # 오른쪽 아래로 진행
        elif arr[mi-1][mj+1] == 0 and arr[mi][mj+2] == 0 and arr[mi+1][mj+1] == 0 and arr[mi+1][mj+2] == 0 and arr[mi+2][mj+1] == 0:
            ni,nj = mi+1,mj+1
            d = (d+1) % 4
            golem[num][0] ,golem[num][1] = ni,nj
            golem[num][2] = d
        else : 
            break
    ci, cj = golem[num][0] ,golem[num][1]
    if ci < 3:
        arr = [[-1]+[0]*C +[-1] for _ in range(R+2)] + [[-1]*(C+2)]
        exit_1 = []
        num += 1
    else:
        nn = num+2
        dr = golem[num][2]
        arr[ci+1][cj]=arr[ci-1][cj]=nn
        arr[ci][cj-1:cj+2]=[nn]*3
        exit_1.append([ci+di[dr],cj +dj[dr]])
        num += 1
        ans += bfs(ci,cj)
    
print(ans)