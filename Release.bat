@echo on

set BUILDER="C:\Program Files\Microsoft eMbedded Tools\Common\EVC\Bin\EVC.EXE"
set CABBUILDER="\Windows CE Tools\wce211\MS HPC Pro\support\appinst\bin\cabwiz.exe"

set cabdir="STWeaker 2004_cab"

mkdir CabFiles

%BUILDER% "STWeaker 2004.vcw" /make "STweaker 2004 - Win32 (WCE SH3) Release" /rebuild
%BUILDER% "STWeaker 2004.vcw" /make "STweaker 2004 - Win32 (WCE SH4) Release" /rebuild
%BUILDER% "STWeaker 2004.vcw" /make "STweaker 2004 - Win32 (WCE ARM) Release" /rebuild
%BUILDER% "STWeaker 2004.vcw" /make "STweaker 2004 - Win32 (WCE MIPS) Release" /rebuild

mkdir arm
mkdir mips
mkdir sh3
mkdir sh4
 
copy SH3Rel\"STWeaker 2004.exe" sh3\
copy SH4Rel\"STWeaker 2004.exe" sh4\
copy MIPSRel\"STWeaker 2004.exe" mips\
copy ARMRel\"STWeaker 2004.exe" arm\

rmdir /s /q .\armrel
rmdir /s /q .\mipsrel
rmdir /s /q .\sh3rel
rmdir /s /q .\sh4rel
rmdir /s /q .\x86emrel
rmdir /s /q .\armdbg
rmdir /s /q .\mipsdbg
rmdir /s /q .\sh3dbg
rmdir /s /q .\sh4dbg
rmdir /s /q .\x86emdbg

%cabbuilder% "STweaker 2004.inf" /err tmp.log /cpu ARM MIPS SH3 SH4
type tmp.log

del .\%TARGET%.arm.dat
del .\%TARGET%.mips.dat
del .\%TARGET%.sh3.dat
del .\%TARGET%.sh4.dat


rmdir /s /q .\mips
rmdir /s /q .\sh3
rmdir /s /q .\sh4
rmdir /s /q .\arm

copy *.cab CabFiles
del *.cab

del *.exe
del *.vcl
del *.vcb
del *.ilk
del *.aps
del *.lzh
del *.dat

