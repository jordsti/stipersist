import sys
import os
import shutil

build_name = sys.argv[1]

files = os.listdir('bin')

fp = open('dll.log', 'w')

for f in files:

    src = os.path.join('bin', f)
    dst = os.path.join('test', 'bin', build_name, f)
    dst2 = os.path.join('Samples', 'bin', build_name, f)
	
    line = 'Copying %s -> %s \n' % (src, dst)

    fp.write(line)
	
    line = 'Copying %s -> %s \n' % (src, dst2)
    fp.write(line)
	
    shutil.copy(src, dst)
    shutil.copy(src, dst2)

fp.close()
