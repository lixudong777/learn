#!/bin/bash
# case-menu: a menu driven system information program
show_menu() {
clear
echo "
Please Select:
1. Display System Information
2. Display Disk Space
3. Display Home Space Utilization
0. Quit
"
return
}
wait_key() {
  read -p "press any key to return..." -n 1
  return
}

while true; do
  show_menu
  read -p "Enter selection [0-3] > "
  case "$REPLY" in
    0) echo "Quit."
       exit
       ;;
    1) echo "Hostname: $HOSTNAME"
       uptime
       wait_key
       ;;
    2) df -h
      wait_key
      ;;
    3) if [[ "$(id -u)" -eq 0 ]]; then
        echo "Home Space Utilization (All Users)"
        du -sh /home/*
       else
        echo "Home Space Utilization ($USER)"
        du -sh "$HOME"
       fi
      wait_key
     ;;
    *) echo "Invalid entry" >&2
       exit 1
      ;; 
  esac
done

