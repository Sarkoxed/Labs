#! /usr/bin/python3

import os
import sys
import random
from string import printable

def gen(l):
    return "".join(random.choices(printable[:-6]+' ', k=l))

os.system('touch '+sys.argv[1])
f = open(sys.argv[1], "w")

string_count = random.randint(3,10)
lo = []

for i in range(string_count):
    new = " ".join([gen(random.randint(1, 20)) for _ in range(random.randint(1, 3))])
    lo.append(new)

test = "\n".join(lo)
f.write(test)
