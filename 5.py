def result():
    num_lt = [int(i) for i in input().strip().split(" ")]
    num4 = 0
    num2 = 0
    num3 = 0
    for i in num_lt:
        if(i%4==0):
            num4+=1
        elif(i%2==0):
            num2+=1
        else:
            num3+=1
    if(num2):
        num3+=1
    return num3-num4<=1

if __name__ == '__main__':
    rows = int(input())
    for _ in range(rows):
        n = int(input())
        if(result()):
            print("Yes")
        else:
            print("No")
