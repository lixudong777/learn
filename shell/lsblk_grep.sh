#!/bin/bash
# grep some info
blk=$(lsblk)
echo "$blk" | grep -v "loop"
