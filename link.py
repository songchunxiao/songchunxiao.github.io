#!/usr/bin/python
import simplejson as json
import requests
import pprint
import time
import threading
import urllib2 


class ScoreUrl(threading.Thread):
	timeLimit = 30
	ddTick = 2
	threadTotalNum = 100
	threadPool = [0] * threadTotalNum
	threadNum = 0

	def __init__(self, lock, uri, resultAll, scoreFile, pointFile, points, i, tNum):
		threading.Thread.__init__(self)
		self.lock = lock
		self.uri = uri
		self.resultAll = resultAll
		self.scoreFile = scoreFile
		self.pointFile = pointFile
		self.tNum = tNum
		self.i = i

	@staticmethod
	def getNextThreadNum():
		while (True):
			ScoreUrl.threadNum = (ScoreUrl.threadNum + 1) % ScoreUrl.threadTotalNum
			if (ScoreUrl.threadPool[ScoreUrl.threadNum] == 0):
				ScoreUrl.threadPool[ScoreUrl.threadNum] = 1
				return ScoreUrl.threadNum

	def writeStuff(self, res):
		self.lock.acquire()

		if (res != None):
			self.scoreFile.write( "%-50s\t%s\t%r\n" %
				(self.uri.rstrip('\n'), res['response']['info']['score'], 
				 res['response']['safe']))
			self.resultAll.write(json.dumps(res)+"\n")
			self.scoreFile.flush()
			self.resultAll.flush()

		self.pointFile.write("%d\n" % self.i)
		self.pointFile.flush()
		self.lock.release()

	def httpExists(self, location):
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

	def run(self):
		if (not self.httpExists(self.uri)):
			self.writeStuff(None)
			return

		uriLink = "http://api.riskive.com/v2/link"
		uriCheck = "http://api.riskive.com/v2/linkcheck/%s"
		payload = {"link": {"uri": self.uri, "threshold": 75}}
		headers = {"Content-Type": "application/json", "App_id":"df4821e7", 
			"APP_KEY":"437c48648632b112ab09b6700b89a816" }

		r = requests.post(uriLink, data=json.dumps(payload), headers=headers)
		print r.json()
		return
		request_id = r.json()['request_id']
		uriTemp = uriCheck % request_id

		tics = 0
		while (True):
			r = requests.get(uriTemp, headers=headers)
			res = r.json()
			time.sleep(1)
			tics = tics + ScoreUrl.addTick

			if res['done']:
				self.writeStuff(res)
				break

			if (tics >= ScoreUrl.timeLimit):
				self.writeStuff(None)
				break
		ScoreUrl.threadPool[self.tNum] = 0

#pprint.pprint(res, width = 8)
def loadPoints(points):
	f =  open("points", "r")
	for numStr in f:
		points[int(numStr)] = 1
	f.close()

def main():
	uris = open("/home/john/hello/work/uriUnique", "r").readlines()
	points = [0] * len(uris)
	loadPoints(points)
	for i in range(0,len(points)):
		if (points[i] == 1):
			print i
	resultAll = open("resultAll", "a")
	scoreFile = open("scoreFile", "a")
	pointFile = open("points", "a")

	lock = threading.Lock()
	
	for i in range(0, len(uris)):
		if (points[i] == 1):
			continue
		tNum = ScoreUrl.getNextThreadNum()
		ScoreUrl(lock, uris[i], resultAll, scoreFile, pointFile, points, i, tNum).start()
	resultAll.close()
	scoreFile.close()

if __name__ == "__main__":
	main()
#pprint.pprint(r.json(), width = 8)

