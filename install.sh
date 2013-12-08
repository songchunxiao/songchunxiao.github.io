#!/bin/sh
~/install/installVim.sh
mkdir ~/generated

#push.sh setup
gpg --output ~/generated/push.sh  --decrypt ~/install/push.sh.gpg
chmod a+x ~/generated/push.sh

#Git setup
git config --global core.excludesfile ~/.gitignore_global
git config --global user.email "jokerfeng2010@gmail.com"
git config --global user.name "Jie Feng"

#Python setup
sudo apt-get install python-pip
sudo pip install urllib2

#Install softwares
sudo apt-get install vim vim-gnome git expect tomboy gparted
sudo apt-get install texlive-full
