find * -name "*.*~" | while read a
do
rm "$a"
done
