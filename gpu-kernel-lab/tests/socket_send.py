"""本机接收循环教学辅助：发送指定 ASCII 数据并结束发送方向。

当前只验证服务端接收；尚不接收或验证回显。
接口来源：https://docs.python.org/3.14/library/socket.html
"""

import socket
import sys

if len(sys.argv) != 2:
    raise SystemExit("usage: socket_send.py <ASCII payload>")

payload = sys.argv[1].encode("ascii")
print(f"expected_payload={payload!r}")
print(f"expected_bytes={len(payload)}")

with socket.create_connection(("127.0.0.1", 39031), timeout=3) as client:
    client.sendall(payload)
    print(f"sent_bytes={len(payload)}")
    client.shutdown(socket.SHUT_WR)
    print("send direction closed")

print("client closed")
