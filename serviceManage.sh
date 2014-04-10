#!/bin/bash - 
#===============================================================================
#
#          FILE: serviceManage.sh
# 
#         USAGE: ./serviceManage.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 04/07/2014 23:34
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error
sudo service apache2 stop
sudo service mysql stop


