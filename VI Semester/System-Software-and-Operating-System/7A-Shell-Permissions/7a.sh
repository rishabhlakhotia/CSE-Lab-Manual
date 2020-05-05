#Write a $hell script that accepts two file names as arguments, 
#checks if the permissions for both the files are identical and 
#if the permissions are identical,
#outputs the common permissions; otherwise outputs each file name
#followed by its permissions.

clear
if  [  $#  !=  2  ]
then
echo  “Invalid input!!!”
else
p1=`ls -l $1 | cut -d “  “ -f  1`
p2=`ls -l $2 | cut -d “  “ -f  1`
if   [  $p1  ==  $p2  ]
then
echo “the file permissions are same and it is : “
echo “$p1”
else
echo “The file permissions are different”
echo “$1 : $p1”
echo “$2 : $p2”
fi
fi

#How to run above program
#$  sh 7a.sh file1 file2
#Input & Output:
#             $  sh 7a.sh file1 file2
#The permissions are different
#Filename: aaa   permission: drwxr-xr-x
#Filename: tem   permission: -rw-r--r--
#[root@localhost]# sh 8a.sh tem temp
#The permissions are same
#-rw-r—r—



