#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<Windows.h>
#include<conio.h>

char arr[1000][1000];

int main(){
 int jmlr=10,jmlc=10;
 int step=0;
 int bp,kp;
 int bm=8,km=2;
 int posx=1,posy=1;//posx = kolom sekarang , posy = baris sekarang
 char b[10];
 //inisialisasi map
 for(int r=1;r<=10;r++){
 for(int c=1;c<=10;c++){
  arr[r][c]='.';
 }
 }
 arr[1][5]='#';
 int st=0;
 int countdown=1;
 //splash
 for(int i=0;i<25;i++){
  puts("");
 }
 printf("\t\t\t\tMAZE RUNNER");
 Sleep(1000);
 for(int i=0;i<24;i++){
  puts("");
  Sleep(50);
 }
 printf("\t\t\t");
 system("pause");
 while(1){
  Sleep(100);
  system("cls");
  for(int r=1;r<=10;r++){
   for(int c=1;c<=10;c++){
    if(c==posx && r==posy)printf("O"); //DI POSISI KARAKTER
 else if(c==km && r==bm)printf("M");
    else printf("%c",arr[r][c]);
   }
   printf("\n");
  }
  if(posy==bm && posx==km){
   //game selesai
   step++;
   printf("Game Selesai! Skor anda %d\n",step);
   system("pause");
   break;
  }
  printf("Jumlah Langkah : %d\n",step);
  if(st!=0){
   //lagi jalan
   switch(st){
   case 1 : b[0]='w'; break;
   case 2 : b[0]='a'; break;
   case 3 : b[0]='s'; break;
   case 4 : b[0]='d'; break;
   }
  }
  else{
   //lagi diem
  printf("Masukkan Pergerakan [wasd, t untuk tambah pagar] : ");
  gets(b);
  }
  switch(b[0]){
  case 'w': if(posy!=1 && arr[posy-1][posx]!='#')
    {
     st=1;
     posy--;
     //step++;
   }
   else{
    if(st!=0)step++;
    st=0;
   }
   break;

  case 'a': if(posx!=1 && arr[posy][posx-1]!='#')
    {
     st=2;
     posx--;
     //step++;
    }
   else
   {
    if(st!=0)step++;
    st=0;
   }
   break;
  case 's':
   if(posy!=10 && arr[posy+1][posx]!='#')
  {
   st=3;
   posy++;
   //step++;
  }
   else 
  {
    if(st!=0)step++;
    st=0;
  }
   break;
  case 'd':
   if(posx!=10 && arr[posy][posx+1]!='#'){
    st=4; //lagi jalan ke kanan
    posx++;
    //step++;
   }
   else
  {
    if(st!=0)step++;
    st=0;
  }
    break;
  case 't':
   printf("Masukkan baris dari pagar : "); scanf("%d",&bp);
   printf("Masukkan kolom dari pagar : "); scanf("%d",&kp);
   arr[bp][kp]='#';
   break;
  }
}
 return 0;
}