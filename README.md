# data_backup
A data backup software with UI.  
Supported operations: backup | restore | pack | unpack | compress | decompress | encrypt | decrypt.  
Supported file types: hard-link | soft-link | pipe | directory  
# environment
OS: Ubuntu-24.04  
Qt: 6.5.3  
# how to run
Run script files as follows:  
  bash makefile.sh //This file will generate an executable program backup and run it once.  
Also you can generate backup as follows:  
  qmake backup.pro  
  make -j$(nproc)  
Then type "./backup" to start it.  
