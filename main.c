#include<stdio.h>
#include<string.h>

static int count=0;
struct tele{
  char name[20];
  long int num;
};

int main()
{
  struct tele a[10];//for save the list of numbers.
  char temp_name[20];
  int checker,i,n= 0;

 while(n!=5)
  {  
  printf("**Welcome in Telephone Diary.**");
  printf("\n\n1.Show the list of diary.\n2.Find a Number.\n3.Add the Number.\n4.Delete the Number.\n5.Exit from the Diary.\n");
  
  printf("Enter your choice:");
  scanf("%d",&n);

  switch(n)
  {
    case 1:{
            if(count==0)
             printf("No Number is in Telephone Diary.");
            
            else 
             for(i=0;i<count;i++)
              {
                printf("%d.%[\n]s",i+1,a[i].name);
                printf("\n  %ld\n",a[i].num);
              }
              break;
           }
  
    case 2:{  if(count==0)
             printf("No Number is in Telephone Diary.");
            
            else 
              {
              printf("Please Fill Every Details in Capital.\n");
              printf("Enter a Name"); 
              scanf("%[\n]s",temp_name);
        
              for(i=0;i<count;i++)
               {
                 checker=strcmp(a[i].name,temp_name);
                 if(checker>0)
                  {
                   printf("Your Enter Number is this:\n");
                   printf("\n %s\n",a[i].name);
                   printf("  %ld",a[i].num);
                   break;
                  }
               }
               if(i=10)
                printf("Your Entered Number is not in List");
               }
               break;
           }        
  
    case 3:{
            if(count==0)
            {
              printf("\nPlease Fill Every Details in Capital.\n");
              printf("Enter a Name:");
              scanf("%s",&a[count].name);
              printf("Enter a Number:");
              scanf("%ld",&a[count].num);
              count=count+2;
             }
            else 
            {
             printf("Please Fill Every Details in Capital.\n");
             printf("Enter a Name:");
             scanf("%[^\n]s",&a[count-1].name);
             printf("Enter a Number:");
             scanf("%ld",&a[count-1].num);
             count++;
            }  
            break;
           } 
   }
  }
  return 0;
  
}