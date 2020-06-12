#!/bin/bash

LEMIN="./lem-in";
DIR="test_maps/";
nm -u ./lem-in;
# norminette -RCheckForbiddenSourceHeader;
# cat -e author
ERROR_DIR='map_error/';
ERROR_MAPS=`ls $DIR$ERROR_DIR`
SIMPLE_DIR='map_simple/';
SIMPLE_MAPS=`ls $DIR$SIMPLE_DIR`;
CHOICE=0

echo -e "Choice :\n0 - ALL\n1 - Error\n2 - Simple"
echo -e "3 - flow-one\n4 - flow-ten\n5 - flow-thousand"
echo -e "6 - big\n7 - big-superposition"
read -e -p "What do you want to test ? " CHOICE

if [ $CHOICE -eq 0 ] || [ $CHOICE -eq 1 ]; then
    for MAP in $ERROR_MAPS
    do
        echo -e "\n\033[33mMAP NAME : $MAP\033[37m\n"
        time $LEMIN $DIR$ERROR_DIR$MAP;
        #$LEMIN $DIR$ERROR_DIR$MAP | leaks lem-in;
    done
fi

if [ $CHOICE -eq 0 ] || [ $CHOICE -eq 2 ]; then
    for MAP in $SIMPLE_MAPS
    do
        echo -e "\n\033[33mMAP NAME : $MAP\033[37m\n"
        time $LEMIN $DIR$SIMPLE_DIR$MAP;
        #$LEMIN $DIR$SIMPLE_DIR$MAP | leaks lem-in;
    done
fi

if [ $CHOICE -eq 0 ] || [ $CHOICE -eq 3 ]; then
    echo -e "\n\033[33mMAP NAME : flow-one\033[37m\n"
    time ./generator --flow-one | $LEMIN;
    #./generator --flow-one | $LEMIN | leaks lem-in;
fi

if [ $CHOICE -eq 0 ] || [ $CHOICE -eq 4 ]; then
    echo -e "\n\033[33mMAP NAME : flow-ten\033[37m\n"
    time ./generator --flow-ten | $LEMIN;
    #./generator --flow-ten | $LEMIN | leaks lem-in;
fi

if [ $CHOICE -eq 0 ] || [ $CHOICE -eq 5 ]; then
    echo -e "\n\033[33mMAP NAME : flow-thousand\033[37m\n"
    time ./generator --flow-thousand | $LEMIN;
    #./generator --flow-thousand | $LEMIN | leaks lem-in;
fi

if [ $CHOICE -eq 0 ] || [ $CHOICE -eq 6 ]; then
    echo -e "\n\033[33mMAP NAME : big\033[37m\n"
    time ./generator --big | $LEMIN;
    #./generator --big | $LEMIN | leaks lem-in;
fi

if [ $CHOICE -eq 0 ] || [ $CHOICE -eq 7 ]; then
    echo -e "\n\033[33mMAP NAME : big-superposition\033[37m\n"
    time ./generator --big-superposition | $LEMIN
    #./generator --big-superposition | $LEMIN | leaks lem-in;
fi

if [ $CHOICE -eq 0 ]; then
    echo -e "\n\n\033[32m/dev/urandom/\033[37m"
    $LEMIN /dev/urandom;
    #$LEMIN /dev/urandom | leaks lem-in;

    echo -e "\n\n\033[32m/dev/null/\033[37m"
    $LEMIN /dev/null;
    #$LEMIN /dev/null | leaks lem-in;

    #echo -e "\n\n\033[32m/dev/zero/\033[37m"
    #$LEMIN /dev/zero;
    #$LEMIN /dev/zero | leaks lem-in;

    echo -e "\n\n\033[32mNothing\033[37m"
    echo "" | $LEMIN;
    #echo "" | $LEMIN | leaks lem-in;
fi