#!/bin/sh
#Tool Name:- temp-folder
#Author :- Rani Giro
#Date :- 15/12/2023
DIR="$( cd "$( dirname "$0" )" && pwd )"

sudo cp -r ${DIR} /usr/local/bin

echo 'export PATH=$PATH:/usr/local/bin/temp-folder' >> ~/.zshrc
exit
