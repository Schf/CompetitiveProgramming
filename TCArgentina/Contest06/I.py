pasc_size = 1000
pasc = [[1,],[1,1,],]
for i in range (2, pasc_size):
    pasc.append ([1,])
    for j in range (1, i):
        pasc[i].append (pasc[i - 1][j] + pasc[i - 1][j - 1])
    pasc[i].append (1)

for i in range (len (pasc)):
    for j in range (len (pasc[i])):
        if pasc[i][j]%7 == 0: pasc[i][j] = 1
        else: pasc[i][j] = 0

'''
for i in range (0, 10):
    for e in pasc[i]:
        print (e, end=' ')
    print ('')
'''

tot_summ = [0,]
line_summ = [0,]
for v in pasc[1:]:
    tot_summ.append (tot_summ[-1])
    line_summ.append (0)
    for e in v:
        tot_summ[-1] += e
        line_summ[-1] += e

for i in range (0, 1000//7):
    for j in range (0, 7):
        print ('%d' % tot_summ[i*7 + j], end=' ')
    print ('')

'''tc = int (input ())
for qq in range (1, tc + 1):
    n = int (input ())
    print ('Case %d: %d' % (qq, tot_summ[n]))
'''
