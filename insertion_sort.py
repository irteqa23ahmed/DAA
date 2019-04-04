def ins(l):
    for i in range(1,len(l)):
        key = l[i]
        j = i-1
        while(j>=0 and l[j]>key):
            l[j+1] = l[j]
            j -= 1
        l[j+1] = key
    return l

print(ins([12,1,21,16,2,39,24]))