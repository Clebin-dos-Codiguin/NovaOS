@echo off
setlocal

netsh advfirewall firewall add rule name="Bloquear ICMP" protocol=icmpv4:8,any dir=in action=block

netsh advfirewall firewall show rule name=all

echo Regras de firewall atualizadas.
pause
