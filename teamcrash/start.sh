#!/bin/bash

echo "=========================="
echo "Starting App teamcrash for {APP_PRETTY_NAME}"


systemctl start teamcrash
systemctl start rosnodeChecker
