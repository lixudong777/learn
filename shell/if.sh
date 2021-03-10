#!/bin/bash
# This is a example for loop sentense
foo () {
    local x
    x=4
    if [ "$x" -eq 5 ]; then
        echo "x equals 5"
    else
         echo "x does not equal 5"
    fi
    return
}
foo
