import socket
import sys

t_host = str(sys.argv[1])
t_ports = str(sys.argv[2])
t_ports = [int(port) for port in t_ports.split(':')]
t_ip = socket.gethostbyname(t_host)

def parse_ports(ports):
    print(ports)
    match = {
        1: lambda x: (x, x+1, 1),
        2: lambda x,y: (x, y , 1),
        3: lambda x,y,z: (x,y,z),
    }
    return match[len(ports)](*ports)

for port in range(*parse_ports(t_ports)):
    try:
        sock = socket.socket()
        res = sock.connect((t_ip, port))
        print(f"Port {port}: Open")
        sock.close()
    except:
        print(f"Port {port}: Closed")


