'''
    目标：
        1、定位到2020必看片
        2、
'''

import requests
import re

#拿到页面源代码
domain = "https://www.dytt89.com/"
resp = requests.get(domain,verify=False) #verify = False ：去掉安全验证
resp.encoding = "gb2312"
print(resp.text)

#拿到ul里面的li
obj1 = re.compile("2020必看热片.*?<ul>(?P<ul>.*?)</ul>",re,S)
obj2 = re.compile("<a href>'(?P<href>.*?)'",reS)
# obj3 = re.compile()






