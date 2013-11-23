#!/usr/bin/python
import urllib2
import sys
args = sys.argv
url = args[1]
content = urllib2.urlopen(url).read()
print content
