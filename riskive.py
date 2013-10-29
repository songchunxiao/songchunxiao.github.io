import simplejson as json
import requests
url = "http://api.riskive.com/v2/profile"
payload = { "profile": { "userid": "717397076", "network":"twitter"} }

#payload = {"link": {"uri": "http://google.com", "threshold": 75}}
headers = {"Content-Type": "application/json", "App_id":"df4821e7", 
	"APP_KEY":"437c48648632b112ab09b6700b89a816" }
r = requests.post(url, data=json.dumps(payload),headers=headers)
print r.json()

#{'score': 17, 'userid': '1234567890', 'network': 'twitter'}




