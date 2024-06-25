import re


def parse_url(url):
    protocol, rest = re.split('://', url, 1)
    hostname, params = re.split('/\?|/$', rest, 1)
    handle, params = re.split('\?|/$', params, 1)
    params = dict(re.split('=|&', params))

    hostname = hostname.trim('/')
    handle = handle.trim('/')
    return (protocol, hostname, handle, params)


url = input()

protocol, hostname, handle, params = parse_url(url)

print("Proto:", protocol)
print("Host:", hostname)
if handle:
    print("Handle:", handle)
if params:
    for k, v in params.items():
        if k and v:
            print(f"{k} -> {v}")
