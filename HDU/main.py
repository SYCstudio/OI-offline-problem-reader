import webbrowser
import urllib
import requests
import re
import codecs

def getHtml(url):
    page = urllib.request.urlopen(url)
    html = page.read()
    try:
        unicodehtml = html.decode("gbk")
    except:
        print("%s had not been install\n"%url)
        return "a"
    return unicodehtml

def zhenghe(str1,id,imgre):
    html=getHtml( str1+id )
    return re.findall(imgre,html)

headers = {'User-Agent':
    'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) '
    'Chrome/51.0.2704.63 Safari/537.36'}
num =1013;
Url = "http://acm.hdu.edu.cn/showproblem.php?pid="
reg = {}
reg[0] = r"<td align=center><h1 style='color:#1A5CC8'>.*?[\s\S]</h1>"
reg[1] = r"<br><br><div class=panel_title align=left>.*?[\s\S]*?</div> <div class=panel_content>"
reg[2] = r"</div> <div class=panel_content>.*?[\s\S]*?<br></div><div class=panel_bottom>"
reg[3] = r'Sample Input</div><div class=panel_content><pre><div style="font-family:Courier New,Courier,monospace;">.*?[\s\S]*?</div>'
reg[4] = r'Sample Output</div><div class=panel_content><pre><div style="font-family:Courier New,Courier,monospace;">.*?[\s\S]*?</div>'

while num<=1013:
    #t = open("hdu题库\hdu%s.txt"%num,"a")
    html=getHtml(Url+str(num))
    print (html)
    #t.close()
    num=num+1
"""
    for j in range (0,5):
        imgre=re.compile(reg[j])
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
"""

"""
import webbrowser
import urllib
import requests
import re
import codecs
def getHtml(url):
    page = urllib.request.urlopen(url)
    html = page.read()
    try:
        unicodehtml = html.decode("gbk")
    except:
        print("%s had not been install\n"%url)
        return "a"
    return unicodehtml

def zhenghe(str1,id,imgre):
    html=getHtml( str1+id )
    return re.findall(imgre,html)
headers = {'User-Agent':
    'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) '
    'Chrome/51.0.2704.63 Safari/537.36'}
num =1013;
Url = "http://acm.hdu.edu.cn/showproblem.php?pid="
reg = {}
reg[0] = r"<td align=center><h1 style='color:#1A5CC8'>.*?[\s\S]</h1>"
reg[1] = r"<br><br><div class=panel_title align=left>.*?[\s\S]*?</div> <div class=panel_content>"
reg[2] = r"</div> <div class=panel_content>.*?[\s\S]*?<br></div><div class=panel_bottom>"
reg[3] = r'Sample Input</div><div class=panel_content><pre><div style="font-family:Courier New,Courier,monospace;">.*?[\s\S]*?</div>'
reg[4] = r'Sample Output</div><div class=panel_content><pre><div style="font-family:Courier New,Courier,monospace;">.*?[\s\S]*?</div>'
while num<=1013:
    t = open("hdu题库\hdu%s.txt"%num,"a")
    for j in range (0,5):
        imgre=re.compile(reg[j])
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
"""
