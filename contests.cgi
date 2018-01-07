#!/usr/bin/python
print "Content-type:text/html\r\n\r\n"
import cgitb;
cgitb.enable()

import requests
from bs4 import BeautifulSoup
import re

print "<html>"
print "<body>"
r = requests.get("https://www.codechef.com/contests");
html_doc = r.content;
soup = BeautifulSoup(html_doc,'html.parser')
contest_table = soup.find_all("table",{"class":"dataTable"})
raw_contest_name = contest_table[0].find_all("a");
contest_name = [];
reserved = ["CODE","NAME","START","END"]
print "<center>"
for i in range(len(raw_contest_name)):
    newSoup = BeautifulSoup(str(raw_contest_name[i]),'html.parser');
    data = newSoup.a.string;
    data = str(data);
    dummy = re.sub("\s+","",data,len((data)),re.I|re.M);
    if dummy not in reserved:
        print "<h1>",data,"</h1>";
print "</body>"
print "</html>"
