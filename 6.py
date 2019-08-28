def getSubString(string:str,index:int)->str:
    if(index==0):
        return str[1:]
    if(index==len(str)-1):
        return str[:-1]
    return str[:index] + str[index+1:]
def insertChar2String(string:str,insert:str,index:int)->str:
    if(index==0):
        return insert+string
    if(index == len(string)):
        return string + insert
    return string[:index] + insert + string[index:]
def isLegal(string:str)->bool:
    n = 0
    for char in string:
        if(char == "("):
            n+=1
        elif(char == ")"):
            n-=1
            if(n<0):return False
    return n==0

if __name__ == '__main__':
    str = input()
    # str = "(())"
    dict = {}
    for i in range(len(str)):
        temp = getSubString(str,i)
        for j in range(len(temp)+1):
            insertString = insertChar2String(temp,str[i],j)
            if(insertString!=str and isLegal(insertString)):
                dict[insertString] = 0
    print(len(dict))
