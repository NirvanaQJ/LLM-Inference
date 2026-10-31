"""本机连接教学辅助：只建立并关闭 TCP 连接，尚不发送数据。

接口来源：https://docs.python.org/3.14/library/socket.html#socket.create_connection
"""

import socket

with socket.create_connection(("127.0.0.1", 39031), timeout=3) as client:
    print("connected to 127.0.0.1:39031")
    print(f"client_fd={client.fileno()}")

print("client closed")
