rem SET PATH=%PATH%;c:\c51\bin

SET tmp=c:\
SET c51inc=c:\c51\inc
SET c51lib=c:\c51\lib
del log
c:\c51\bin\A51 %1.a51   >log
c:\c51\bin\l51 %1.obj to %1.abs >>log
c:\c51\bin\oh51 %1.abs     >>log
copy log tlog
exit