#!/usr/bin/env python3

import socket
import sys
import time
import argparse

def test_server(host='127.0.0.1', port=8080):
    print(f"Connecting to {host}:{port}...")
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.settimeout(2.0)
            s.connect((host, port))
            
            # Test 1: SET command
            key = "hello"
            value = "world"
            print(f"> SET {key} {value}")
            # Ensure proper newline termination for the protocol
            s.sendall(f"SET {key} {value}\n".encode('utf-8'))
            
            # Server should probably respond (e.g., "OK\n"), but let's assume
            # a simple fire-and-forget or check response if implemented.
            # For this lab, let's assume we just proceed to GET.
            # If your protocol sends "+OK\r\n", read it here:
            # response = s.recv(1024)
            # print(f"< {response.decode().strip()}")

            # Test 2: GET command
            print(f"> GET {key}")
            s.sendall(f"GET {key}\n".encode('utf-8'))
            
            response = s.recv(1024).decode('utf-8').strip()
            print(f"< {response}")
            
            if response == value:
                print("PASS: Retrieved value matches set value.")
                return True
            else:
                print(f"FAIL: Expected '{value}', got '{response}'")
                return False
                
    except ConnectionRefusedError:
        print("FAIL: Connection refused. Is the server running?")
        return False
    except Exception as e:
        print(f"FAIL: {e}")
        return False

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Test networking model server.')
    parser.add_argument('--port', type=int, default=8080, help='Port to connect to')
    args = parser.parse_args()
    
    if test_server(port=args.port):
        sys.exit(0)
    else:
        sys.exit(1)