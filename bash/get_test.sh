#!/bin/bash

FRAMEWORK_URL="http://localhost:8537"

IP="127.0.0.1"

send_get_request() {
  local buffer="GET /print HTTP/1.1\r\n"
  buffer+="Host: $IP\r\n"
  buffer+="\r\n"

  curl -X GET "$FRAMEWORK_URL/print" -d "$buffer"
}

for ((i=1; i<=100; i++)); do
  echo "Sending GET $i..."
  
  send_get_request &
  
  sleep 0.3
done

wait