

import re
# #findall:匹配字符串中所有的符合正则的内容
# lst = re.findall("\d+","我的电话好号是：10086,test = 101010101")
# print(lst)

# #finditer : 匹配字符串中所有的内容【返回一个迭代器】,在迭代器中拿到内容需要.group()
# it = re.finditer("\d+","我的电话好号是：10086,test = 101010101")
# for i in it:
#     print(i.group())

#search 找到一个结果就返回，返回的结果为match对象,拿数据需要.group()
# s = re.search("\d+","我的电话好号是：10086,test = 101010101")
# print(s.group())

# #match 从头匹配
# s = re.match("\d+","我的电话好号是：10086,test = 101010101")
# print(s.group())

#预加载正则表达式
obj = re.compile("\d+")
ret = obj.finditer("我的电话好号是：10086,test = 101010101")
for it in ret:
    print(it.group())
print("check")