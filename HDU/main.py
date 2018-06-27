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
reg = {}
reg[0] = r"<td align=center><h1 style='color:#1A5CC8'>.*?[\s\S]</h1>"# Problem Title
reg[1] = r"Time Limit.*?[\s\S]*?(Java/Others)" # Time limit
reg[2] = r"Memory Limit:.*?[\s\S]*?(Java/Others)" # Memery limit
reg[3] = r"<div class=panel_title align=left>Problem Description.*?[\s\S]*?<div class=panel_bottom>" # problem description
reg[4] =r"<div class=panel_title align=left>Input.*?[\s\S]*?<div class=panel_bottom>" #Input desc
reg[5] =r"<div class=panel_title align=left>Output.*?[\s\S]*?<div class=panel_bottom>" #Output desc
reg[6] = r'Sample Input.*?[\s\S]*?</div></pre></div>'
reg[7] = r'Sample Output.*?[\s\S]*?</div></pre></div>'
while num<=1013:
    t = open("hdu题库\hdu%s.txt"%num,"w")
    for j in range (0,8):
        print (reg[j])
        imgre=re.compile(reg[j]) #
        list = zhenghe(Url,str(num),imgre)
        if(list=="a"):
            continue

        for i in list:
            dr = re.compile(r'<[^>]+>',re.S)
            dd = dr.sub('',i)
            dr = re.compile(r'Input',re.S)
            dd = dr.sub('Input\n',dd)
            dr = re.compile(r'Output',re.S)
            dd = dr.sub('Output\n',dd)
            t.write(dd)
            t.write("\n\n")
    t.close()
    num=num+1
