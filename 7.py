def initDp(dp:list,n:int,value:list):
    for i in range(2,n):
        dp[i][0] = dp[i-1][0] + abs(value[i]-value[i-1])
        dp[i][i-1] = dp[i-1][i-2] + abs(value[i-1]-value[i-2])

def fillDp(dp:list,n:int,value:list):
    for i in range(2,n):
        for j in range(0,i-1):
            dp[i][j] = dp[i-1][j] + abs(value[i]-value[i-1])
            dp[i][i-1] = min(dp[i][i-1],dp[i-1][j] + abs(value[j]-value[i]))
if __name__ == '__main__':
    n = int(input())
    value = [int(i) for i in input().strip().split(" ")]
    dp = [([0]*n) for _ in range(n)]
    initDp(dp,n,value)
    fillDp(dp,n,value)
    minNum = dp[-1][0]
    for i in dp[-1][:-1]:
        if (i<minNum):
            minNum = i
    print(minNum)