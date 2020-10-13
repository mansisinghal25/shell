default: shell
	./a.out

cat: 
	gcc cat.c -o cat

date: 
	gcc date.c -o date

ls: 
	gcc ls.c -o ls

mymkdir: 
	gcc mkdir.c -o mkdir

rm: 
	gcc rm.c -o rm

shell: cat date ls mymkdir rm
	gcc shell.c
