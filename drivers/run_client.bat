echo off
cd C:\Users\crisc\CLionProjects\TestClient\cmake-build-debug

.\TestClient.exe 127.0.0.2 
timeout /t 1 /nobreak
.\TestClient.exe 127.0.0.3
timeout /t 3 /nobreak 
.\TestClient.exe 127.0.0.10
timeout /t 2 /nobreak 
.\TestClient.exe 127.0.0.50
timeout /t 2 /nobreak
.\TestClient.exe 127.0.0.2
