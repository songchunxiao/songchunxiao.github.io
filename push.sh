#!/usr/bin/expect
set timeout -1

spawn git push

expect "Username" {
    send "jokerfeng2010@gmail.com\r"
}
expect "Password*" {
    send "FJqq1314\r"
}
expect eof
