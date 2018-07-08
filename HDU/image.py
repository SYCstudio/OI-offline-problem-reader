import urllib
import urllib.request

url="http://acm.hdu.edu.cn/data/images/";
local="./data/images/"

name=(str)(input())
urllib.request.urlretrieve(url+name,local+name)
