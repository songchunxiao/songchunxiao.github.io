#!/bin/bash 

if [ -z $1 ]
then
    sudo add-apt-repository ppa:noobslab/mint
    sudo apt-get update
    sudo apt-get install nemo
    sudo apt-get install nemo-compare nemo-dropbox nemo-fileroller nemo-pastebin nemo-seahorse nemo-share nemo-rabbitvcs nemo-terminal
    sudo apt-get install nemo-compare nemo-dropbox nemo-fileroller nemo-pastebin nemo-seahorse nemo-share nemo-rabbitvcs nemo-terminal
    sudo apt-get install nemo-preview
elif [ $1 == "rm" ]
then 
    sudo apt-get autoremove nemo nemo-*
    sudo apt-get install ppa-purge
    sudo ppa-purge ppa:noobslab/mint
    sudo apt-get update
elif [ $1 == "conf" ]
then
    gsettings set org.nemo.desktop home-icon-visible false; gsettings set org.nemo.desktop trash-icon-visible false; gsettings set org.nemo.desktop computer-icon-visible false; gsettings set org.nemo.desktop volumes-visible false

elif [ $1 == "sound" ]
then 
    echo "meow"
fi
