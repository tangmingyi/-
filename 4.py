if __name__ == '__main__':
    #通过率为70%，报语法错误,没有返回测试用例
    n,l = map(int,input().strip().split(" "))
    parent_lt = [int(i) for i in input().strip().split(" ")]
    nodeLength = [0]*n
    for i in range(1,n):
        nodeLength[i] = nodeLength[parent_lt[i-1]] +1
    max_length = max(nodeLength)
    if(l<=max_length):
        print("%d"%l+1)
    else:
        print("%d"%(min(n,int((l-max_length)/2) + max_length + 1)))

