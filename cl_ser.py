import socket,argparse,sys
def client(host,port,bytecount):
    s = socket.socket()
    bytecount = (bytecount+15)
    message   = b'capitalize this!'
    print("sending",bytecount,"bytes of data, in chuncksuf 16 bytes") 
    s.connect((host,port))
    sent =0
    while sent < bytecount:
       s.sendall(message)
       sent+=len(message)
       print('\r %d bytes sent' % (sent,),end=' ')
    print() 
    s.shutdown(socket.SHUT_WR)

    print('Receiving all the data the server sends back')

    received = 0 
    while True: 
       data = s.recv(48) 
       if not received: 
          print(' The first data received says\n', repr(data))

       if not data: 
         break 
       received += len(data) 
       print('\r %d bytes received' % (received,), end=' ')
    print()
    s.close()

   

def server(host,port,bytecount):
    addr = (host,port)
    s    = socket.socket()
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    s.bind(addr)
    s.listen(1)
    print('Listening at', s.getsockname())
    while True:
       connection,sockname = s.accept()
       print(f'Processing up to 1024 bytes at a time from >>> {sockname}')
       n=0
       while True: 
        data = connection.recv(1024)
        if not data:
            break
        output = data.decode('ascii').upper().encode('ascii')
        connection.sendall(output)
        n+=len(data)
        print('\r %d bytes processed so far' % (n,), end=' ')
        sys.stdout.flush()
       print() 
       connection.close()
       print(f"socket closed.....")     




















if __name__ == "__main__":
    choice = {"client":client,"server":server}
    parser = argparse.ArgumentParser(description="GET DEADLOCKED OVER TCP")
    parser.add_argument("role",choices=choice,help="which role to play")
    parser.add_argument("host",help='interface the server listens at;' 'host the client sends to')
    parser.add_argument('bytecount', type=int, nargs='?', default=16, help='number of bytes for client to send (default 16)')
    parser.add_argument('-p', metavar='PORT', type=int, default=1060, help='TCP port (default 1060) ')
    args = parser.parse_args()
    function = choice[args.role] 
    function(args.host, args.p, args.bytecount)


# from pprint import pprint
# import socket,argparse
# import dns.resolver
# print(dns.resolver.resolve)
# give = socket.getaddrinfo("google.com","www")
# pprint(give)
# def lookup(name):
#      for dnstype in 'A', 'AAAA', 'CNAME', 'MX', 'NS':
#           answer = dns.resolver.query(name, dnstype, raise_on_no_answer=False) 
#           if answer.rrset is not None: 
#               print (answer.rrset)
          
# if __name__ == "__main__":
#      parser =  argparse.ArgumentParser(description="dns tests....")
#      parser.add_argument("name",help="resolve aname using dns")
#      lookup(parser.parse_args().name)