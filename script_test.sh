#!/bin/bash

LEMIN="./lem-in"
DIR="maps/"
nm -u ./lem-in;
# norminette -RCheckForbiddenSourceHeader;
# cat -e author
ERROR_DIR='error/'
ERROR_MAPS=`ls $DIR$ERROR_DIR`
SIMPLE_DIR='simple/'
SIMPLE_MAPS=`ls $DIR$SIMPLE_DIR`
LAST_DIR='last/'
CHOICE=0
MAP=0
let "REPETITION = 1"

echo -e "Choice :\n1 - Error\n2 - Simple"
echo -e "3 - flow-one\n4 - flow-ten\n5 - flow-thousand"
echo -e "6 - big\n7 - big-superposition"
read -e -p "What do you want to test ? " CHOICE

case $CHOICE in
		"1")
				for ERRMAP in $ERROR_MAPS
				do
					echo -e "\n\033[33mMAP NAME : $ERRMAP\033[37m\n"
					time $LEMIN $DIR$ERROR_DIR$ERRMAP
					#$LEMIN $DIR$ERROR_DIR$MAP | leaks lem-in;
				done
				;;
		"2")
				for SIMMAP in $SIMPLE_MAPS
				do
					echo -e "\n\033[33mMAP NAME : $SIMMAP\033[37m\n"
					time $LEMIN $DIR$SIMPLE_DIR$SIMMAP
					#$LEMIN $DIR$SIMPLE_DIR$MAP | leaks lem-in;
				done
				;;
		"3")
				MAP="--flow-one"
				;;
		"4")
				MAP="--flow-ten"
				;;
		"5")
				MAP="--flow-thousand"
				;;
		"6")
				MAP="--big"
				;;
		"7")
				MAP="--big-superposition"
				;;
		*)
				echo "Wrong command"
				;;
esac

if [ $MAP != "0" ]; then
	read -e -p "How many times ? " REPETITION
	echo -e "\n\033[33mMAP NAME : $MAP\033[37m\n"
	if [ $REPETITION -eq 1 ]; then
		time ./generator $MAP | $LEMIN
		#./generator $MAP | $LEMIN | leaks lem-in;
	elif [ $REPETITION -gt 1 ]; then
		rm -rf maps/last
		mkdir maps/last
		while [ $REPETITION -ne 0 ]
		do
			echo -e "\n\033[35mMAP number $REPETITION\033[37m\n"
			./generator $MAP > $DIR$LAST_DIR$REPETITION
			head $DIR$LAST_DIR$REPETITION | grep "lines required" | cut -d ' ' -f 6-8 | tr '\n' ' '
			echo -e "   lem_in: \c"
			time $LEMIN $DIR$LAST_DIR$REPETITION | grep "NBR LINE" | cut -d ' ' -f 4
			let "REPETITION = REPETITION - 1"
			sleep 1
		done
	else
		echo -e "\nPlease put a number greater than 0.\n"
	fi
fi

if [ $CHOICE -eq 1 ]; then
	echo -e "\n\n\033[32m/dev/urandom/\033[37m"
	#$LEMIN /dev/urandom;
	$LEMIN /dev/urandom | leaks lem-in;

	echo -e "\n\n\033[32m/dev/null/\033[37m"
	#$LEMIN /dev/null;
	$LEMIN /dev/null | leaks lem-in;

	#echo -e "\n\n\033[32m/dev/zero/\033[37m"
	#$LEMIN /dev/zero;
	#$LEMIN /dev/zero | leaks lem-in;

	echo -e "\n\n\033[32mNothing\033[37m"
	#echo "" | $LEMIN;
	echo "" | $LEMIN | leaks lem-in;
fi