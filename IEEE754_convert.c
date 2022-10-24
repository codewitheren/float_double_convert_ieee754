#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *ft_strrev(char *str)
{
 int i = 0;
 int size = strlen(str);
 char tmp;
 size = size - 1;
 while(i < size)
 {
 tmp = str[size];
 str[size] = str[i];
 str[i] = tmp;
 i++;
 size--;
 }
 return(str);
}
void ft_float(long double sayi)
{

 int t, g, i;
 double o;
 char *a, *b, *a2, *s, *f;
 int size, j, ex, hey = 0;

 if(sayi < 0)
 {
 hey = 1;
 sayi = sayi * -1;
 }

 a = malloc(1000);
 b = malloc(1000);
 a2 = malloc(1000);
 s = malloc(1000);
 f = malloc(1000);

 t = sayi;
 o = sayi - t;

 i = 0;
 while(t)
 {
 g = t % 2;
 if(g == 1)
 a[i] = '1';
 else
 a[i] = '0';
 t = t / 2;
 i++;
 }
 a[i] = '\0';
 a = ft_strrev(a);// tam sayı kısım binary

 i = 0;
 while(i < 32)
 {
 o = o * 2;
 g = o;
 if(g == 1)
 b[i] = '1';
 else
 b[i] = '0';
 o = o - g;
 i++;
 }
 b[i] = '\0';//ondalıklı kısım binary

 i = 0;
 while(a[i])
 {
 a2[i] = a[i + 1];
 i++;
 }
 a2[i] = '\0';//1 basamak kaydırılmış hali

 size = strlen(a2);

 i = 0;
 while(a2[i])
 {
 s[i] = a2[i];
 i++;
 }

 j = 0;
 while(b[j])
 {
 s[i] = b[j];
 i++;
 j++;
 }
 s[i] = '\0';//mantis kısım

 ex = 127 + size;
 i = 0;
 while(ex)
 {
 g = ex % 2;
 if(g == 1)
 f[i] = '1';
 else
 f[i] = '0';
 i++;
 ex = ex / 2;
 }
 f = ft_strrev(f);//exponent kısım
 i = 0;
 if(hey == 0)
 {
 printf("0 %s ",f);
 while(i < 23)
 {
 printf("%c", s[i]);
 i++;
 }
 }
 else
 {
 printf("1 %s ",f);
 while(i < 23)
 {
 printf("%c", s[i]);
 i++;
 }
 }
}
void ft_double(long double sayi)
{

 int t, g, i;
 long double o;
 char *a, *b, *a2, *s, *f;
 int size, j, ex, hey = 0;

 if(sayi < 0)
 {
 hey = 1;
 sayi = sayi * -1;
 }

 a = malloc(1000);
 b = malloc(1000);
 a2 = malloc(1000);
 s = malloc(1000);
 f = malloc(1000);

 t = sayi;
 o = sayi - t;

 i = 0;
 while(t)
 {
 g = t % 2;
 if(g == 1)
 a[i] = '1';
 else
 a[i] = '0';
 t = t / 2;
 i++;
 }
 a[i] = '\0';
 a = ft_strrev(a);// tam sayı binary
 i = 0;
 while(i < 52)
 {
 o = o * 2;
 g = o;
 if(g == 1)
 b[i] = '1';
 else
 b[i] = '0';
 o = o - g;
 i++;
 }
 b[i] = '\0';
 i = 0;
 while(a[i])
 {
 a2[i] = a[i + 1];
 i++;
 }
 a2[i] = '\0';
 size = strlen(a2);
 i = 0;
 while(a2[i])
 {
 s[i] = a2[i];
 i++;
 }
 j = 0;
 while(b[j])
 {
 s[i] = b[j];
 i++;
 j++;
 }
 s[i] = '\0';
 ex = 1023 + size;
 i = 0;
 while(ex)
 {
 g = ex % 2;
 if(g == 1)
 f[i] = '1';
 else
 f[i] = '0';
 i++;
 ex = ex / 2;
 }
 f = ft_strrev(f);
 i = 0;
 if(hey == 0)
 {
 printf("0 %s ",f);
 while(i < 52)
 {
 printf("%c", s[i]);
 i++;
 }
 }
 else
 {
 printf("1 %s ",f);
 while(i < 52)
 {
 printf("%c", s[i]);
 i++;
 }
 }

}
int main()
{
 long double sayi;
 int islem;
 printf("Lütfen bir sayı giriniz :");
 scanf("%Lf", &sayi);
 printf("(1) Float için\n(2) Double için\n==>");
 scanf("%d", &islem);
 switch(islem)
 {
 case 1:
 ft_float(sayi);
 break;
 case 2:
 ft_double(sayi);
 break;
 default:
 printf("Hatali islem !");
 break;
 }
}