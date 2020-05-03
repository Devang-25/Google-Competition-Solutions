#Devang Sharma- MAIT Delhi

import sys
from collections import defaultdict

def lowerBsearch(nums, target):
    left = 0
    right = len(nums)
    while left < right:
        mid = (left + right)/2
        if target <= nums[mid]:
            right = mid
        else:
            left = mid + 1
    return left

def f(X, Y, M):

    dirs = {
        'N': (0, 1),
        'S': (0, -1),
        'E': (1, 0),
        'W': (-1, 0),
    }

    ht = defaultdict(list)
    cur = (X, Y)
    curSteps = 0
    ht[cur].append(curSteps)
    for m in M:
        dx, dy = dirs[m]
        x = cur[0] + dx
        y = cur[1] + dy
        cur = (x, y)
        curSteps += 1
        ht[(x, y)].append(curSteps)

    res = sys.maxsize

    for key in ht:
        x, y = key
        arr = ht[key]
        stepsFromFan = abs(x) + abs(y)
        idx = lowerBsearch(arr, stepsFromFan)
        if idx < len(arr):
            res = min(res, arr[idx])

    return 'IMPOSSIBLE' if res == sys.maxsize else res

T = int(raw_input())  
for t in range(1, T + 1):
    X, Y, M = [s for s in raw_input().split(" ")]
    res = f(int(X), int(Y), M)
    print("Case #{}: {}".format(t, res))
