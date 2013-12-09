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
sudo apt-get install vim vim-gnome tomboy \
    git expect gparted \
    artha dict goldendict goldendict-wordnet \
    vlc-nox apt-file\
    texlive-full

#Developing
sudo apt-get install cmake bzr build-dep unity nux gnome-common libibus-1.0-dev libgtest-dev google-mock libxtst-dev libmrss0
#Lamp
sudo apt-get install tasksel 
sudo tasksel install lamp-server
sudo apt-get install php5-cgi
