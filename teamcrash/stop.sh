#!/bin/bash

echo "=========================="
echo "Stopping App teamcrash"

systemctl stop rosnodeChecker
systemctl stop teamcrash
