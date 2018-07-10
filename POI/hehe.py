import random

lst = []

for i in range(100):
    lst.append(i + 1)

random.shuffle(lst)

lst = [0] + lst
rev = lst[:]

print("Urutan awal: ", end='')
for i in range(1, 101):
    print(i, lst[i], sep='. ')
    rev[lst[i]] = i
print('\n')

print("====swapping====\n")

vis = lst[:]
for i in range(101):
    vis[i] = 0

swapnum = 0


def pecah(awal, vertex, panjang):
    vis[vertex] = 1
    if vertex == awal:
        return
    if panjang == 9 and lst[vertex] != awal:
        global swapnum
        swapnum += 1
        a = awal
        b = vertex
        c = lst[vertex]
        d = rev[awal]
        rev[a] = b
        lst[b] = a
        rev[c] = d
        lst[d] = c
        print('tukar kartu di indeks {} dengan kartu di indeks {}'.format(b, d))
        return
    pecah(awal, lst[vertex], panjang + 1)


for i in range(1, 101):
    if not vis[i]:
        pecah(i, lst[i], 1)

assert(swapnum <= 10)
print('ditukar sebanyak {} kali'.format(swapnum))

for i in range(1, 101):
    print(i, lst[i], sep='. ')
    assert(rev[lst[i]] == i)
print('\n')


def ambil(expec, idx):
    print('ambil indeks {}, dapet ini {}'.format(idx, lst[idx]))
    if(lst[idx] == expec):
        return
    ambil(expec, lst[idx])


num = int(input('mau ambil no berapa? '))
ambil(num, num)
