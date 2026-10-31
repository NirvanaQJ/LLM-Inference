"""本机 echo 验收辅助：原输入作为独立预期，核对完整回显。

接口来源：https://docs.python.org/3.14/library/socket.html
"""

import socket
import sys

if len(sys.argv) != 2:
    raise SystemExit("usage: socket_echo.py <ASCII payload>")

expected = sys.argv[1].encode("ascii")
print(f"expected_payload={expected!r}")
print(f"expected_bytes={len(expected)}")
actual = bytearray()

with socket.create_connection(("127.0.0.1", 39031), timeout=3) as client:
    client.sendall(expected)
    client.shutdown(socket.SHUT_WR)  # 发送结束，接收方向仍可用
    while True:
        chunk = client.recv(4096)
        if not chunk:
            break
        actual.extend(chunk)

print(f"actual_payload={bytes(actual)!r}")
print(f"actual_bytes={len(actual)}")
matched = bytes(actual) == expected
print(f"echo_match={matched}")
raise SystemExit(0 if matched else 1)
