


#1.拿到页面源码
#2.使用bs4进行解析，拿到数据
import requests
from bs4 import BeautifulSoup

url = ""
resp = requests.get(url)

#解析数据
#1、把页面源代码交给BeautifulSoup进行处理，生成bs对象
page= BeautifulSoup(resp.text,"html.parser") #指定html解析器

#2.从bs对象中查找数据
#find(标签，属性= 值)
