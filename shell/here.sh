#!/bin/bash
# This is "here document"
# demostrate redirection << & <<-
cat << _EOF_
echo 1
echo 12
echo 123
ls
_EOF_
