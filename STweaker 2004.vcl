<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: STweaker 2004 - Win32 (WCE x86em) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating temporary file "C:\DOCUME~1\Snoogie\LOCALS~1\Temp\RSP866.tmp" with contents
[
/nologo /W3 /D "i486" /D UNDER_CE=211 /D _WIN32_WCE=211 /D "WIN32" /D "STRICT" /D "_WIN32_WCE_EMULATION" /D "INTERNATIONAL" /D "USA" /D "INTLMSG_CODEPAGE" /D "WIN32_PLATFORM_HPCPRO" /D "UNICODE" /D "_UNICODE" /D "_X86_" /D "x86" /D "NDEBUG" /D "_AFXDLL" /Fp"X86EMRel/STweaker 2004.pch" /Yu"stdafx.h" /Fo"X86EMRel/" /Gz /Oxs /c 
"C:\Documents and Settings\Snoogie\Bureau\HPCCoding\STweaker 2004\Startup.cpp"
]
Creating command line "cl.exe @C:\DOCUME~1\Snoogie\LOCALS~1\Temp\RSP866.tmp" 
Creating temporary file "C:\DOCUME~1\Snoogie\LOCALS~1\Temp\RSP867.tmp" with contents
[
/nologo /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /incremental:no /pdb:"X86EMRel/STweaker 2004.pdb" /out:"X86EMRel/STweaker 2004.exe" /windowsce:emulation /MACHINE:IX86 
".\X86EMRel\Animation.obj"
".\X86EMRel\ChildView.obj"
".\X86EMRel\CleanAddress.obj"
".\X86EMRel\CleanRun.obj"
".\X86EMRel\Hide.obj"
".\X86EMRel\IEAmelioration.obj"
".\X86EMRel\Infos.obj"
".\X86EMRel\MainFrm.obj"
".\X86EMRel\Power.obj"
".\X86EMRel\Rename.obj"
".\X86EMRel\ShellSwaper.obj"
".\X86EMRel\SpeedIE.obj"
".\X86EMRel\Startup.obj"
".\X86EMRel\StdAfx.obj"
".\X86EMRel\STweaker 2004.obj"
".\X86EMRel\STweaker 2004.res"
]
Creating command line "link.exe @C:\DOCUME~1\Snoogie\LOCALS~1\Temp\RSP867.tmp"
<h3>Output Window</h3>
Compiling...
Startup.cpp
C:\Documents and Settings\Snoogie\Bureau\HPCCoding\STweaker 2004\Startup.cpp(131) : error C2065: 'IShellLink' : undeclared identifier
C:\Documents and Settings\Snoogie\Bureau\HPCCoding\STweaker 2004\Startup.cpp(131) : error C2955: 'CComPtr' : use of class template requires template argument list
        C:\Windows CE Tools\wce211\MS HPC PRO\atl\include\Atlbase.h(638) : see declaration of 'CComPtr'
C:\Documents and Settings\Snoogie\Bureau\HPCCoding\STweaker 2004\Startup.cpp(131) : error C2133: 'ipShellLink' : unknown size
C:\Documents and Settings\Snoogie\Bureau\HPCCoding\STweaker 2004\Startup.cpp(131) : error C2512: 'CComPtr' : no appropriate default constructor available
C:\Documents and Settings\Snoogie\Bureau\HPCCoding\STweaker 2004\Startup.cpp(131) : error C2262: 'ipShellLink' : cannot be destroyed
C:\Documents and Settings\Snoogie\Bureau\HPCCoding\STweaker 2004\Startup.cpp(135) : error C2065: 'GetFullPathName' : undeclared identifier
C:\Documents and Settings\Snoogie\Bureau\HPCCoding\STweaker 2004\Startup.cpp(140) : error C2065: 'CLSID_ShellLink' : undeclared identifier
C:\Documents and Settings\Snoogie\Bureau\HPCCoding\STweaker 2004\Startup.cpp(143) : error C2065: 'IID_IShellLink' : undeclared identifier
C:\Windows CE Tools\wce211\MS HPC PRO\atl\include\Atlbase.h(641) : error C2787: 'IPersistFile' : no GUID has been associated with this object
C:\Documents and Settings\Snoogie\Bureau\HPCCoding\STweaker 2004\Startup.cpp(147) : error C2664: '__thiscall ATL::CComQIPtr<struct IPersistFile,NULL>::ATL::CComQIPtr<struct IPersistFile,NULL>(struct IPersistFile *)' : cannot convert parameter 1 from 'class ATL::CComPtr' to 'struct IPersistFile *'
        No user-defined-conversion operator available that can perform this conversion, or the operator cannot be called
C:\Documents and Settings\Snoogie\Bureau\HPCCoding\STweaker 2004\Startup.cpp(148) : error C2678: binary '->' : no operator defined which takes a left-hand operand of type 'class ATL::CComPtr' (or there is no acceptable conversion)
C:\Documents and Settings\Snoogie\Bureau\HPCCoding\STweaker 2004\Startup.cpp(148) : error C2039: 'SetPath' : is not a member of 'CComPtr'
        C:\Windows CE Tools\wce211\MS HPC PRO\atl\include\Atlbase.h(638) : see declaration of 'CComPtr'
C:\Documents and Settings\Snoogie\Bureau\HPCCoding\STweaker 2004\Startup.cpp(151) : error C2678: binary '->' : no operator defined which takes a left-hand operand of type 'class ATL::CComPtr' (or there is no acceptable conversion)
C:\Documents and Settings\Snoogie\Bureau\HPCCoding\STweaker 2004\Startup.cpp(151) : error C2039: 'SetDescription' : is not a member of 'CComPtr'
        C:\Windows CE Tools\wce211\MS HPC PRO\atl\include\Atlbase.h(638) : see declaration of 'CComPtr'
C:\Documents and Settings\Snoogie\Bureau\HPCCoding\STweaker 2004\Startup.cpp(155) : error C2664: 'MultiByteToWideChar' : cannot convert parameter 3 from 'const unsigned short *' to 'const char *'
        Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or function-style cast
Error executing cl.exe.



<h3>Results</h3>
STweaker 2004.exe - 15 error(s), 0 warning(s)
</pre>
</body>
</html>
