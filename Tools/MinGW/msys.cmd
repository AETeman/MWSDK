@echo off

SET WD=msys\1.0\bin

IF NOT EXIST %WD%\bash.exe GOTO _Err
%WD%\bash -l
EXIT

:_Err
echo PLEASE RUN ON MSYS TOP DIRECTORY...
PAUSE
EXIT