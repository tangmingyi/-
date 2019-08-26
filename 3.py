if __name__ == '__main__':
    strings = input()
    current = strings[0]
    kind = 1.0
    for i in strings:
        if(i!=current):
            kind += 1
            current = i
    length = float(len(strings))
    print("%.2f"%(length/kind))