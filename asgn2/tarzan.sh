#!/bin/bash
#260854650 kuba nowosielski
if [[ ! $# -eq 2 ]]
then
        echo "Usage ./tarzan.sh filename tarfile"
        exit 1
fi

if [[ ! -f $2 ]]
then
        echo "Error cannot find tar file $2"
        exit 1
else
        if [[ `tar --list --file=$2 | grep "$1"` ]]
        then
                echo "$1 exists in $2"
        else
                echo "$1 does not exist in $2"
        fi
fi

