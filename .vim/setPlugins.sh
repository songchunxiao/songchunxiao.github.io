#!/bin/bash - 
#===============================================================================
#
#          FILE: setPlugins.sh
# 
#         USAGE: ./setPlugins.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 02/14/2014 17:26
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error
cd bundle/
git clone https://github.com/tpope/vim-surround

