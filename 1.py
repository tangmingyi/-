import sys

if __name__ == '__main__':
    printList = []
    n = 10
    # for i in sys.stdin:
    #     n = int(i.strip())
    while(n!=0):
        if (n&1):
            printList.append('1')
            n = int((n-1)/2)
        else:
            printList.append('2')
            n = int((n-2)/2)
    # while(len(printList)!=0):
    #     print("%s"%printList.pop())
    for i in printList[::-1]:
        print("%s"%i,end='')