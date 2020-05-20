# Time:  O(ClogC + D)
# Space: O(C)
# Language: Python 2

from itertools import imap

def security_update():
    C, D = map(int, raw_input().strip().split())
    R, T = [], []
    for i, x in enumerate(imap(int, raw_input().strip().split()), 1):
        if x < 0:
            R.append((-x, i)) 
        else:
            T.append((x, i))
    assigned_T, last_merged = {0:0}, (0, 0, 0)
    R.sort(), T.sort()  # Time: O(ClogC)
    i, j = 0, 0
    while i != len(R) or j != len(T):
        if j == len(T) or (i != len(R) and R[i][0] <= len(assigned_T)):
            last_merged = (R[i][0], last_merged[1] if R[i][0] == last_merged[0] else last_merged[1]+1)
            assigned_T[R[i][1]] = last_merged[1]
            i += 1
        else:
            last_merged = (last_merged[0] if T[j][0] == last_merged[1] else len(assigned_T), T[j][0])
            assigned_T[T[j][1]] = last_merged[1]
            j += 1
    result = []
    for _ in xrange(D):  # Time: O(D)
        U, V = map(int, raw_input().strip().split())
        result.append(max(abs(assigned_T[U-1]-assigned_T[V-1]), 1))
    return " ".join(map(str, result))
    
for case in xrange(input()):
    print 'Case #%d: %s' % (case+1, security_update())
