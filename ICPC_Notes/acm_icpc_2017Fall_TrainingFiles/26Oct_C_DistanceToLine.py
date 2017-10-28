import sys
import math

FNAME = "A"
FNAME = "distance"
###########
fin, fout = open(FNAME + ".in", "r"), open(FNAME + ".out", "w")
sys.stdin = fin
sys.stdout = fout
###########

def intersection(a1, b1, c1, a2, b2, c2):

    c1, c2 = -c1, -c2

    if b1 == 0:
        x = c1/a1
        y = (c2 - a2*x)/b2

    if b2 == 0:
        x = c2/a2
        y = (c1 - a1*x)/b1

    if b1 != 0 and b2 != 0:
        num = c2/b2 - c1/b1
        den = a2/b2 - a1/b1
        x = num/den
        y = (c1 - a1*x)/b1

    return (x,y)


x1, y1, a1, b1, c1 = [int(i) for i in input().split()]
if a1 != 0:
    # derived from point-slope form
    m = b1/a1
    a2 = -m
    b2 = 1
    c2 = m*x1 - y1
else:
    a2 = 1
    b2 = 0
    c2 = -x1

tx, ty = intersection(a1, b1, c1, a2, b2, c2)
ans = math.sqrt(math.pow(x1-tx, 2) + math.pow(y1-ty, 2))
print(ans)
