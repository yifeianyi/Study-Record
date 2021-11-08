'''
    1、服务器渲染：在服务器把数据 和 html整合，统一发送给浏览器
    2、客户端渲染：发两次请求
        第一次：返回html骨架
        第二次：返回数据并显示


    http协议：
        请求：
            1、请求行 ->请求方式 请求url地址 协议
            2、请求头 -> 服务器要用的附加信息
            3、请求体 -> 请求的参数

        响应：
            1、状态行：协议 状态码
            2、响应头：客户端需要的附加信息
            3、响应体：服务器返回的真正客户端要用的内容（HTML，json）
'''



from urllib.request import urlopen
url = "http://www.baidu.com"
resp = urlopen(url)

# resp.read()

# print(resp.read().decode("utf-8"))

with open("mybaidu.html",mode="w") as f:
    f.write(resp.read().decode("utf-8"))
print("over!")
