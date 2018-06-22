import urllib.request
i=1000
up=1010
while i<=up:
    i=i+1
    file=urllib.request.urlopen("http://acm.hdu.edu.cn/showproblem.php?pid="+str(1000))
    data=file.read();
    fhandle=open("./HDU/"+str(i)+".html","wb");
    fhandle.write(data);
    fhandle.close();
