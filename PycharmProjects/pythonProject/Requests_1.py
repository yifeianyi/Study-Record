'''
    主要用到了get方法
'''

import requests
query = input("input someting:")
url = f"https://www.sogou.com/web?query={query}"


dic = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/94.0.4606.54 Safari/537.36"
}

resp = requests.get(url,headers=dic)#处理一个小小的反爬
print(resp)
print(resp.text) #拿到网页源码





