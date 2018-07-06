import webbrowser
import urllib
import requests
import re
import codecs
def getHtml(url): # 得到一个网页并转码为gbk
    page = urllib.request.urlopen(url)
    html = page.read()
    try:
        unicodehtml = html.decode("gbk")
    except:
        print("%s had not been install\n"%url)
        return "a"
    return unicodehtml

def zhenghe(str1,id,imgre):# 整合?作用是调用上面的函数得到网页+转码，然后返回所有的匹配项
    html=getHtml( str1+id )
    return re.findall(imgre,html)

headers = {'User-Agent':
    'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) '
    'Chrome/51.0.2704.63 Safari/537.36'} # 浏览器伪装
num =1013;
Url = "http://acm.hdu.edu.cn/showproblem.php?pid="
while num<=1013:
    t = open("HDU%s.txt"%num,"w")
    html=getHtml(Url+(str)(num));
    t.write(html);
    t.close()
    num=num+1
