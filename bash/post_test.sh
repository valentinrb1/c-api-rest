#!/bin/bash


FRAMEWORK_URL="http://localhost:8537"

IP="127.0.0.1"

send_post_request() {
  local buffer="POST /increment HTTP/1.1\r\n"
  buffer+="Host: $IP\r\n"
  buffer+="Content-Length: 0\r\n"
  buffer+="\r\n"

  for ((i=1; i<=100; i++)); do
    curl -X POST "$FRAMEWORK_URL/increment" -d "$buffer"

    sleep 0.3
  done
}

for ((i=1; i<=10; i++)); do
  echo "Sending POST $i..."
  
  send_post_request &

  sleep 0.3
done

wait