#include<stdio.h>
#include<conio.h>
struct employee
{
int n;
char name[10];
int salery;
}e;
void main()
{
FILE *fp ,*ft;
int recz,num=0,st=0,choice;
char ans;
clrscr();
recz=sizeof(e);
fp=fopen("emp dat","rb+");

if(fp==NULL)
{
fp=fopen("emp dat","wb+");

if(fp==NULL)
{
printf("its empty");
exit(1);
}
}
while(1)

{
printf("enter u choise");
printf("\n[1].add");
printf("\n[2].list");
printf("\n[3].modify");
printf("\n[4].delete");
printf("\n[0].exit");
gotoxy(56,10);
scanf("%d",&choice);
switch(choice)
{
case 1:
{

fseek(fp,0,SEEK_END);

 do{
 printf("enter employee no");
 scanf("%d",&e.n);
 fflush(stdin);
 printf("enter employee name");
 scanf("%s",e.name);
 fflush(stdin);
 printf("enter employee salery");
 scanf("%d",&e.salery);
 fwrite(&e,recz,1,fp);
 printf("want to enter more[y\n]:");
 fflush(stdin);
 scanf("%c",&ans);
 }
 while(ans=='y'||ans=='Y');
 break;
 }
 case 2:
 {
 clrscr();
 rewind(fp);
 st=0;
 while(fread(&e,recz,1,fp)==1)
 {
 printf("%d  %s  %d",e.n,e.name,e.salery);
 st++;
 }
 if(st==0)
 {
 printf("no data");
 }
 getch();
 break;
 }
 case 3:
 {
 do
 {
 printf("enter employee number");
 scanf("%d",&num);
 rewind(fp);
 st=0;
 while(fread(&e,recz,1,fp)==1)
 {
 if(num==e.n)
 {
 printf("enter employee number,name,salery");
 scanf("%d%s%d",&e.n,e.name,&e.salery);
 fseek(fp,-recz,SEEK_CUR);
 fwrite(&e,recz,1,fp);
 st++;
 break;
 }
 }
 if(st==0)
 {
 printf("no data");
 getch();
 }
 printf("another record[y\n]");
 fflush(stdin);
 scanf("%c",&ans);
 }while(ans=='y'||ans=='Y');
 break;
 }
 case 4:
 {
 clrscr();
 do
 {
 printf("enter code of employee");
 scanf("%d",&num);

 ft=fopen("temp","wb");
 rewind(fp);
 st=0;

 while(fread(&e,recz,1,fp)==1)
 {
 if(num!=e.n)
 {
 fwrite(&e,recz,1,ft);
 }
 else
 {
 st++;
 }
 }
 if(st==0)
 {
 printf("record not found");
 getch();
 }
 fclose(ft);
 fclose(fp);
 remove("emp dat");
 rename("temp","emp dat");
 fp=fopen("emp dat","rb+");
 printf("want tp delete more record[y\n]");
 fflush(stdin);
 scanf("%c",&ans);
 }
 while(ans=='y'||ans=='Y');
 break;
 }
 case 0:
 {
 fclose(fp);
 exit(1);
 }
 default:
 {
 printf("wrong choice");
 getch();
 break;
 }
 }
 }
// fclose(fp);
 }




