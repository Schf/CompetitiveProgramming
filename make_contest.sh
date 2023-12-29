mkdir -p $1
AVALUE=$(printf "%d" \'a)
for ((i=0;i<$2;i++))
do
	LETTERVALUE=`expr "$i" + "$AVALUE"`
	FILENAME=$1/$(printf "\x$(printf %x $LETTERVALUE)").cpp
	cat template.cpp > $FILENAME
done
