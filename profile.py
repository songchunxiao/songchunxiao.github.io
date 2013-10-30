#!/usr/bin/python
import simplejson as json
import requests
url = "http://api.riskive.com/v2/link"
urlCheck = "http://api.riskive.com/v2/linkcheck/%s"
#payload = { "profile": { "userid": "717397076", "network":"twitter"} }

payload = {"link": {"uri": "http://google.com", "threshold": 75}}
headers = {"Content-Type": "application/json", "App_id":"df4821e7", 
	"APP_KEY":"437c48648632b112ab09b6700b89a816" }
r = requests.post(url, data=json.dumps(payload),headers=headers)
request_id = r.json()['request_id']
urlTemp = urlCheck % request_id[1:]
print urlTemp
#r = requests.post(urlTemp, data=json.dumps(payload),headers=headers)
r = requests.get(urlTemp, headers=headers)
print r.json()
#{'score': 17, 'userid': '1234567890', 'network': 'twitter'}




