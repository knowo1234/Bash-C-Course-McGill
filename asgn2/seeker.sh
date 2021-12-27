#!/bin/bash

#initialize global variables
a=$1
b=$2
c=$3
d=$4

#Helper function that throws an exception
error_missing_args() {
	echo "Error not the correct arguments"
	echo "Usage ./seeker.sh [-c] [-a] pattern [path]"
	exit 1
}

dir_check() {
	if [ ! -d $1 ]
	then
		echo "Error $1 is not a valid directory"
		exit 1
	fi
}


#C_flag prints to the screen a file in the directory, takes four inputs (-c -a pattern and path) 
#it gets the file by piping the list of the directory(in question) into grep to sort for the pattern wanted
# then that is stored in a file. 
#a file name is extracted from the file and stored in a variable to then be shown in the header
#and later printed
#if the $d is empty then initilize it with PWD
C_flag() {
	path=$4
	if [[ $path = "" ]]
        then
               path=$PWD
        fi
	
	dir_check $path

	first=""

	ls $path | grep $3 > matching_files
	first=`cat matching_files | head -1`
	if [[ ! $first = "" ]]
	then
		echo "==== Contents of: $path/$first ===="
		cat $path/$first
	fi	

	if [[ $first = "" ]]
        then
                echo "unable to locate any file that has pattern $3 in its name in $path"
        fi

	
}

#check how many files are match the PATTERN and initizialize a variable to that
#run a for loop that many times and print the contents of everything
A_flag() {
	#check if we have a path given, if not assign it pwd
	path=$4
	if [[ $path = "" ]]
	then
		path=$PWD
	fi

	dir_check $path
	
	#declare the variables that will be used for looping
	ls $path | grep $3 > matching_files2
	n=`wc -l matching_files2 | cut -d " " -f1`
	l=0
	first=""
	
	#if its 2args and -a is first with non-existent file
	if [[ $2 = "-a" ]] && [[ $# -eq 2 ]]
	then	
		echo "I am in the new if"
		for (( c=1; c<=n; c++))
                do
                        ((l++))
                        first=`cat matching_files2 | head -$l | tail -1`
                        echo "$path/$first"
                done
                if [[ $first = "" ]]
                then
                        echo "unable to locate any file that has pattern $3 in its name in $path"
                fi

	fi



	#if just -a is passed different print format
	if [[ ! $1 = "-c" ]] && [[ $2 = "-a" ]]
	then
		for (( c=1; c<=n; c++))
        	do
                	((l++))
                	first=`cat matching_files2 | head -$l | tail -1`
                	echo "$path/$first"
		done
		if [[ $first = "" ]]
        	then
                	echo "unable to locate any file that has pattern $3 in its name in $path"
        	fi
			
	exit 0
	fi

	#loop for when its c and a
	for (( c=1; c<=n; c++))
	do
			
		((l++))
		first=`cat matching_files2 | head -$l | tail -1`
        	echo "==== Contents of: $path/$first ===="
		#only print the contents if -c flag is raised
		if [[ $1 = "-c" ]]
	       	then
        		cat $path/$first
		fi

	done

	if [[ $first = "" ]]
	then
		echo "unable to locate any file that has pattern $3 in its name in $path"
	fi
}

#check if the number of arguments is less than 1 or greater than 4
if [ $# -lt 1 ] || [ $# -gt 4 ]
then
	error_missing_args
fi

#case if 4 arguments are passed into the script
if [ $# -eq 4 ]
then	
	#check if $1 and $2 are not -c and -a and that the path starts with the root "/" 
	if [ ! $a = "-c" ] || [ ! $b = "-a" ] || [[ ! $d = /* ]]
	then
		error_missing_args	
	else
 		A_flag $a $b $c $d	
		exit 0
	fi
fi

#case if 3 arguments are passed into the script
if [ $# -eq 3 ]
then

	#case for (-c arg path) 
	if [[ $a = "-c" ]] && [[ $c = /* ]]
	then
		C_flag $a "" $b $c
		exit 0
	fi

	#check for (-c -a arg) case and assign path to 0 to later be initialized to pwd in A_flag method
	if [[ $a = "-c" ]] && [[ $b = "-a" ]]
	then
		A_flag $a $b $c ""
		exit 0
	fi

	#case when (-a arg path)
	if [[ $a = "-a" ]] && [[ $c = /* ]]
        then
                A_flag "" $a $b $c
                exit 0
        fi
fi

#case if 2 arguments are passed into the script
if [ $# -eq 2 ]
then
	#if the first argument is -c
	if [[ $a = "-c" ]] && [[ ! $b = "-a" ]]
	then
		C_flag $a "" $b " " 
		exit 0
	elif [[ $a = "-c" ]] && [[ $b = "-a" ]]
	then
		error_missing_args
	fi

	#check if the input is (pattern, path)
	if [[ $b = /* ]]
	then
		dir_check $b

		first=""
		#just printing the first element from the list
		first=`cat matching_files2 | head -1 | tail -1`
		if [[ $first = "" ]]
	        then
                	echo "unable to locate any file that has pattern $a in its name in $b"
		else
                	echo "$b/$first"
		fi
		exit 0
	fi


	#if the first arg is -a
	if [[ $a = "-a" ]]
	then
		A_flag "" $a $b ""
	fi

fi

#case if 1 argument is passed into the script
if [ $# -eq 1 ]
then
	if [ $a = "-c" ] || [ $a = "-a" ] 
	then
		error_missing_args
	else
		#just printing the first element from the list
                first=`cat matching_files2 | head -1 | tail -1`
                echo "`pwd`/$first"
                exit 0
	fi
fi

