@echo off
setlocal
cd /d "%~dp0"

start conhost.exe "%~dp0argendino.exe"

endlocal
exit