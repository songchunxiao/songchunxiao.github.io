#!/bin/sh
~/install/installVim.sh

#For push.sh
gpg --output push.sh  --decrypt push.sh.gpg 
chmod a+x push.sh

#For git setup
git config --global core.excludesfile ~/.gitignore_global
git config --global user.email "jokerfeng2010@gmail.com"
git config --global user.name "Jie Feng"

#Install softwares
sudo apt-get install ccrypt vim vim-gnome git expect

