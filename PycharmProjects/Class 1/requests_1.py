'''

    requests包下载：
        pip install requests

'''
import requests
# coding=utf-8
'''
    Point_1:
        resp这个对象的属性里包含json、test等响应格式内容
        resp.text：响应的页面源码
'''
# url ='https://www.sogou.com/web?query=周杰伦'
# resp = requests.get(url) #返回一个响应状态
# print(resp.text)

'''
    Point_2: 使用请求头的 User-Agent伪装成普通用户登录。 
        
'''
url ='https://www.sogou.com/web?query=周杰伦'
dic = {
    "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/94.0.4606.54 Safari/537.36"
}
resp = requests.get(url,headers=dic)
# resp.text = resp.text.replace(u'\xa0',u' ')

print(resp.text)



