DAYS=(Mon Tue Wed Thurs Fri Sat Sun)

select DAY in ${DAYS[*]}; do
	echo $DAY
	exit 1
done
