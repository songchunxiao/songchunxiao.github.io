#!/usr/bin/python
import simplejson as json
import requests
import pprint
import time

with open("~/hello/work/urlUnique", "r") as f:
	for line in f:
		uri = "http://shipin1.yezhao.com/tuiguang/mj/a/tz.html?uid=7545&sid=0"
		urlLink = "http://api.riskive.com/v2/link"
		urlCheck = "http://api.riskive.com/v2/linkcheck/%s"
		payload = {"link": {"uri": uri, "threshold": 75}}
		headers = {"Content-Type": "application/json", "App_id":"df4821e7", 
			"APP_KEY":"437c48648632b112ab09b6700b89a816" }
		r = requests.post(urlLink, data=json.dumps(payload),headers=headers)
		request_id = r.json()['request_id']
		urlTemp = urlCheck % request_id
		print urlTemp
		r = requests.get(urlTemp, headers=headers)
		done = False
		while (not done):
			res = r.json()
			pprint.pprint(res, width = 8)
			done = res['done']
			time.sleep(1)
			if done:
				print res['response']['info']['score']
				print res['response']['safe']

#pprint.pprint(r.json(), width = 8)




