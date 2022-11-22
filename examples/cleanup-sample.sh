#!/bin/bash
cp -n $1 $1.bak
TMPFILE=`mktemp`

sed source_subtask.pmk -e 's/\*\*\*\*\*\*\*\*\*/\*\*\*\*\*/g;s/----------/------/g;s/                      \*\*\*/\*\*\*\*/g' > $TMPFILE
cat $TMPFILE > $1
