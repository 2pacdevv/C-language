#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define maxcaracter 50
struct product{
char name[maxcaracter];
int price;
int sell_price;
int profit;
int sold_amoud;
};
typedef struct product product;

float avarege_calculate(){
float numconsiderate;
float avarage;
scanf("%d", &numconsiderate);
float valors;
float sumofall = 0; 
for(int i = 0; i < numconsiderate; i++){
   printf("type the %d valor: ", i + 1);
   scanf("%f", &valors);
   sumofall += valors;
}
avarage = sumofall / numconsiderate;
return avarage;
}


int profit_calculate(int price, int sell_price, int sold_amoud){
    int profit = 0;
   for(int i = 0; i < sold_amoud; i++)
     profit += sell_price - price;
   return profit;
}

void string_tiny(char products[]){
   int letters = strlen(products);
   for(int i = 0; i < letters; i++){
       products[i] = tolower((unsigned char)products[i]);
   }
}

int main(void){
   int NumberOfProducts;
   float avarege;
printf("Hello, This program calculate your profit in some thing\n");
printf("Look, now you need write how many product you need see your profit, please, type it in number: \n");
scanf("%d", &NumberOfProducts);
if (NumberOfProducts < 1){
printf("Please, type one number bigger 0, try again: \n");
}
product *products;
products = (product *)malloc(NumberOfProducts * sizeof(product));
printf("Nice, now you need talk, what is name of this product, actually, this code is just a test, the name will not be used, please, type name of ALL products: \n");
for(int i = 0; i <= NumberOfProducts; i++){
   fgets(products[i].name, 50, stdin);
   string_tiny(products[i].name);
}
printf("Now, This code go make some question about the product, read and answer:\n");
for(int i = 1; i <= NumberOfProducts; i++){
   printf("The next three question is about %s", &products[i].name);
   printf("How much YOY pay in this product? in cust: ");
   scanf("%d", &products[i].price);
   printf("Now, how much you custom sell it, if you want calculate the avarage, please type \"0\" ");
   scanf("%d", &products[i].sell_price);
   if(products[i].sell_price == 0){
      printf("So, you select calculate avarege mode, now you need tell-me how many sales you want considerate for this average? ");
      printf("your avarage of sell sales is %.2f", avarege_calculate());
   }
}
    return 0;
}