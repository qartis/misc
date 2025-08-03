#!/bin/sh

if [ "$0" = "/config/rf_command.sh" ]; then
	exec >> /config/shell_command_log.txt 2>&1
fi
echo "Running: $0 $@"

if [ $# -ne 1 ]; then
    echo "Usage: $0 <text>"
    exit 4
fi

CMD="$1"

case "$CMD" in
    kitchen_*)
        HOST="192.168.1.190" # esp32c6-B6F244  e4:b3:23:b6:f2:44
        ;;
    master_bath_*)
        HOST="192.168.1.191" # esp32c6-B5BF54  e4:b3:23:b5:bf:54
        ;;
    bedroom_*)
        HOST="192.168.1.192" # esp32c6-F706C0  60:55:f9:f7:06:c0
        ;;
    *)
        echo "Unknown command prefix: $CMD"
        exit 4
        ;;
esac

PORT=23
CONNECT_TIMEOUT_S=3
RESPONSE_TIMEOUT_S=6

RESPONSE=$(echo "$CMD" | timeout $RESPONSE_TIMEOUT_S socat -x stdio,ignoreeof\!\!exec:'head -n 1' TCP:$HOST:$PORT,connect-timeout=$CONNECT_TIMEOUT_S)
NC_STATUS=$?

if [ "$NC_STATUS" -eq 1 ]; then
    echo "connection failed or timed out"
    exit 5
fi

if [ "$NC_STATUS" -eq 124 ]; then
    echo "connected but timed out waiting for response"
    exit 2
fi

if [ "$RESPONSE" != "ok" ]; then
    echo "response not ok: '$RESPONSE'"
    exit 1
fi

echo ok
