import sys
import os

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print('usage: {:s} file'.format(sys.argv[0]))
        exit(os.EX_USAGE)
    with open(sys.argv[1]) as f:
        lines = f.readlines()
    f = open('clean_' + sys.argv[1], 'w')
    for line in lines:
        line = line.strip()
        if line.startswith('f'):
            letter, *field = line.split(' ')
            clean = lambda x: x.split('/')[0]
            line = letter + ' ' + ' '.join(map(clean, field))
        print(line, file = f)
