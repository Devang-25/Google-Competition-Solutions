# Devang Sharma-MAIT DELHI
#Simple Py2 Solution

from collections import defaultdict

def overrandomized():
    U = input()
    result, count = set(), defaultdict(int)
    for _ in xrange(L):
        _, R = raw_input().strip().split()
        result.add(R[-1])
        if len(R) == U:
            count[R[0]] += 1
    count[(result-set(count.iterkeys())).pop()] = L-sum(count.itervalues())
    return "".join(sorted(count.iterkeys(), key=lambda x:count[x], reverse=True))

L = 10**4
for case in xrange(input()):
    print 'Case #%d: %s' % (case+1, overrandomized())