# Devang Sharma-MAIT Delhi

from itertools import imap

def join_the_ranks():
    R, S = map(int, raw_input().strip().split())
    return "{}\n{}".format(((S-1)*R+1)//2, "\n".join(imap(lambda x: "{} {}".format(x[0]+x[1], x[2]-(x[0]+x[1])),
                           ((i//R+1, (i+1)//R+1 if i+1 != (S-1)*R else 0, R+1+i) for i in xrange(0, (S-1)*R, 2)))))

for case in xrange(input()):
    print 'Case #%d: %s' % (case+1, join_the_ranks())