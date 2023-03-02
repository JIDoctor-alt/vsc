安装Microsoft.Build.UnGAC




I had same problem after install VS 2022. The cause of problem was antivirus program can't trust dotnet-host-path.ps1 script for me.  

I opened my antivirups program and click trust this project button in blocked processes page.  

It's fixed my problem. I hope it will be helpfull for you too.  

By the way this is the full path of that script. 

C:\ProgramData\Microsoft\VisualStudio\Packages\Microsoft.NetCore.HostPath,version=17.0.32002.160,language=neutral,machinearch=x64\dotnet-host-path.ps1
