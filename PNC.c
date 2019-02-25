#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

mpz_t b1,b2,b3,b4,at,max,l,d;
unsigned long  n,k,m;
char cont_prog = 'n';
 int main()
 {
     putchar ('\n');
     printf("                  ***** PNC - prime number calculator *****\n\n\n");

do {
    /* main program in here */
   //int main()
   printf("Please enter the ordinal number : ");
   scanf("%lu",&n);
   mpz_init_set_ui(b1,6);
   mpz_init_set_ui(b2,6);
   mpz_init_set_ui(b3,6);
   if(n==1)
   {
   mpz_init_set_ui(max,2);
   }
   else
   {
   mpz_init_set_ui(max,3);
   }
   mpz_init(b4);
   mpz_init(at);
   mpz_init(l);
   mpz_init(d);
   k=4;
   m=3;
   
	while(m<=n)
	{
		mpz_lcm_ui(l,b1,k-2);
		mpz_add(b4,b1,l);
		mpz_cdiv_q(d,b4,b1);
		mpz_sub_ui(at,d,1);
		k=k+1;
		mpz_set(b1,b2);
		mpz_set(b2,b3);
		mpz_set(b3,b4);
		if(mpz_cmp(max,at)<0)
		{
			mpz_set(max,at);
			m=m+1;
		}
	}
	mpz_clear(l);mpz_clear(d);mpz_clear(b1);
	mpz_clear(b2);mpz_clear(b3);mpz_clear(b4);mpz_clear(at);
	if(n%10==1 && n%100 != 11)
    {
     printf("The %lust prime number is : ",n);
    }
    else
    {
        if(n%10==2 && n%100 != 12)
        {
         printf("The %lund prime number is : ",n);
        }
        else
        {
            if(n%10==3 && n%100 != 13)
            {
              printf("The %lurd prime number is : ",n);
            }
            else
            {
             printf("The %luth prime number is : ",n);
            }
         }
    }
	mpz_out_str(stdout, 10, max);
	putchar ('\n');
	mpz_clear(max);
	//printf("Press ENTER to terminate the program");
    fflush(stdout);
    getchar();//getchar();
    //return 0;
    printf("Do you want to start again? (y/n) : ");
    cont_prog = getchar();

}
while (cont_prog == 'y' || cont_prog == 'Y');
return 0;
}