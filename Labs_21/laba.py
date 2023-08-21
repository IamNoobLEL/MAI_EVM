import os

rootDir = input('')
for dirName, subdirList, fileList in os.walk(rootDir):
    print('Found directory: %s' % dirName)