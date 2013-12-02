#!/usr/bin/perl
use String::Util 'trim';
$tempFile = "statistic";
$insecure = "insecure";
`cat scoreFile | cut -f2 > $tempFile`;
`grep False scoreFile > $insecure`;
$numOfInsecure = `wc $insecure`;
$wc = `wc $tempFile`;
$tempS = trim($wc);
@tempSArray = split(/\ +/, $tempS);
$numOfRows = @tempSArray[1];
$totalScore = `cat $tempFile | paste -sd+ | bc`;
print "number of scores whe have got is :" . $numOfRows . "\n";
print "The average score is :" . $totalScore / 1.0 / $numOfRows . "\n";
print "The number of insecure urls is :" . $numOfInsecure . "\n";
