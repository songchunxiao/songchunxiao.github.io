#!/usr/bin/python
import urllib2
import httplib
import urlparse

def httpExists(location):
	print location
	request = urllib2.Request(location)
	request.get_method = lambda : 'HEAD'
	try:
		response = urllib2.urlopen(request)
		return True
	except urllib2.HTTPError:
		return False
	except urllib2.URLError:
		return False
	except:
		return False

def checkUrl(uri):
	req = Request(uri) #urilib2
	try:
		res = uriopen(req)
	except HTTPError, e:
		print "HTTP Error"
		return False
	except URLError, e:
		print "URL Error"
		return False
	except:
		#print "HTTP is not correct"
		return False
	return True

outFile =  open("/home/john/hello/work/uriUniqueValid", "a")
i = 0
with open("/home/john/hello/work/uriUnique", "r") as f:
	for uri in f:
		i += 1
		if (httpExists(uri)):
			print uri
			outFile.write(uri)
		if (i > 100):
			break

outFile.close()

