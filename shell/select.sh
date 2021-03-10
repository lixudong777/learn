#!/bin/bash
# example for "select"
menu="one \
      two there four five"
foo_1() {
  local fname
  select fname in *; do
    echo you picked $fname \($REPLY\)
    break;
    done
  return 
}

# more example:
foo_2() {
  local i
  select i in $menu; do
    echo "you select: $i"
    break;
    done
  return
}
echo "select file from list: "
foo_1
echo "one more example, select:"
foo_2
