#!/bin/bash

LEMIN="./lem-in";
DIR="test_maps/";
nm -u ./lem-in;
# norminette -RCheckForbiddenSourceHeader;
# cat -e author
ERROR_DIR='map_error/';
ERROR_MAPS=`ls $DIR$ERROR_DIR`
SIMPLE_DIR='map_simple';
SIMPLE_MAPS=`ls $DIR$SIMPLE_DIR`;

for MAP in $ERROR_MAPS
do
    echo "\n\033[33mMAP NAME : $MAP\033[37m\n"
    $LEMIN $DIR$ERROR_DIR$MAP;
done

echo "\n\n\033[32m/dev/urandom/\033[37m"
$LEMIN /dev/urandom | leaks lem-in;

echo "\n\n\033[32m/dev/null/\033[37m"
$LEMIN /dev/null | leaks lem-in;

#echo -e "\n\n\033[32m/dev/zero/\033[37m"
#$LEMIN /dev/zero | leaks lem-in;

echo "\n\n\033[32mNothing\033[37m"
echo "" | $LEMIN | leaks lem-in;