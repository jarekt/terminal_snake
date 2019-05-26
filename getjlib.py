#simple script for downloading github repos easily
import requests
import zipfile
import os

url = 'https://github.com/jarekt/jlib/archive/v1.0.zip'
folder = 'jlib'
#zip conents into this ^ folder

r = requests.get(url)
if not r:
    print('download failed, try again or download %s manually' % url)
    exit()
open('temp.zip', 'wb').write(r.content)

zipfile.ZipFile('temp.zip').extractall()
os.rename(zipfile.ZipFile('temp.zip').namelist()[0], folder)
os.remove('temp.zip')
