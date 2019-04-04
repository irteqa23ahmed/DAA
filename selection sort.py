def select(l):
    for i in range(0, len(l)):
        mn = i
        for j in range(i, len(l)):
            if l[j] < l[mn]:
                mn = j
        if mn != i:
            t = l[mn]
            l[mn] = l[i]
            l[i] = t
    return l


n = int(input("Size of array: "))
a = []
for i in range(0,n):
    a.append(int(input()))
print(select(a))
