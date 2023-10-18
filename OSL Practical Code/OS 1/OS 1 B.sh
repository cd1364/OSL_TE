clear

c=0
while test $c != 7

do
echo "1-> Create 2-> View 3-> Insert 4-> Delete 5->Modify 6->Search 7-> Exit"
echo "Enter your Choice : "
read c

case "$c" in
"1")
echo "Enter file name"
read file_name
touch $file_name
echo -e "ID \t\t Name \t\tEmail \t\t\t Phone Number">>
$file_name
echo "File created successfully"
;;

"2")
echo "Enter the file name to be viewed"
read file_name
cat $file_name
;;

"3")
echo "Enter the file name to be viewed"
read file_name

echo "Enter id"
read id
echo "Enter name"
read name
patn="^[A-Za-z]"
while [[ ! "$name" =~ $patn ]]
do
echo "enter valid Name:"
read name
done

echo "Enter email"
read email
patem="^[a-z0-9._%-+]+@[a-z]+\.[a-z]{2,4}$"
while [[ ! $email =~ $patem ]]
do

echo "please enter valid email address"
read email

done

echo "Enter Phone number"
read ph_no

pat_num="^[0-9]{10}$"
while [[ ! $ph_no =~ $pat_num ]]
do

echo "please enter valid phone number"
read ph_no

done

echo -e " $id \t\t $name \t\t $email \t\t $ph_no" >>
$file_name
echo "Successfully inserted the record"

;;
"4")
echo "Enter the file name to be viewed"
read file_name
echo "Enter the Name/ID of the record you want to delete"
read id
sed -i "/$id/d" $file_name

;;
"5")
echo "Enter the file name to be viewed"
read file_name
echo "Enter the Name you want to modify"
read old_name
echo "Enter the new name you want to replace"
read new_name
sed -i "s/$old_name/$new_name/" $file_name
;;
"6")

echo "Enter the file name to be viewed"
read file_name
echo "Enter the Name/ID of the record you want to delete"
read id

if grep -i "$id" $file_name ;
then
echo "Record Found"
else
echo "Record Not Found";
fi

;;
"7")
echo "Exit"
exit
;;

esac

done
exit