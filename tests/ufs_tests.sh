#! /bin/bash

failedTests=0
failedFiles=()

pushd ./tests > /dev/null 2>&1

if [ $? -ne 0 ]
then
    echo "Could not navigate to tests directory."
    exit 1
fi


for i in *
do
    if [ -x $i ]
    then
        echo "Running test $i"
        ./$i

        res=$?

        failedTests=$(( $failedTests + $res ))

        if [ $res -ne 0 ]
        then
            failedFiles+=($i)
        fi

    fi
done

echo "There are $failedTests failed tests in total"

if [ $failedTests -gt 0 ]
then
    echo "Failed tests are in:"
    echo $failedFiles
fi

popd > /dev/null 2>&1
