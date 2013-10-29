import simplejson as json
import requests
url = "https://api.riskive.com/v2/profile"
payload = {"profile": { "userid": "1234567890", "network":"twitter" } }
headers = {"Content-Type": "application/json"}
r = requests.post(url, data=json.dumps(payload),headers=headers)
r.json(){'score': 17, 'userid': '1234567890', 'network': 'twitter'}
