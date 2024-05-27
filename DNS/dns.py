# Write a program for DNS lookup. Given an IP address input, it should return URL and viceversa.

import socket
print 'welcome to DNS LOOKUP'
print 'select option 1)get IP address 2) get DOMAIN name'
op=input('enter option')
if (op==1):
	print 'ENTER THE DOMAIN NAME'
	var=raw_input('HOSTNAME: ')
	addr1 = socket.gethostbyname(var)
	print('IP ADDRESS FOR GIVE HOST NAME IS :')
	print(addr1)
else:
	print 'ENTER THE IP ADDRESS'
	var=raw_input('IP ADDRESS :')
	addr2 = socket.gethostbyaddr(var)
	print(addr2)
