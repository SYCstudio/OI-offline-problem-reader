import urllib.request
file=urllib.request.urlopen("https://vjudge.net/problem/POJ-1568")
data=file.read();
fhandle=open("./1.html","wb");
fhandle.write(data);
fhandle.close();
