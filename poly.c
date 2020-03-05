/***********************************
* EECS2031 - Assignment 1
* Filename: poly.c
* Author: Zhao,Yixi
* Email: frankzyx@my.yorku.ca
* Login ID: frankzyx
************************************/

#include "poly.h"
void help_method1(int integer, char a[]);

/*
  Initialize all coefficients and exponents of the polynomial to zero.
 */
void init_polynom( int coeff[ ], int exp[ ] )
{
    int i;
    for (i=0; i <ASIZE ; ++i) {
        *coeff++=0;
        *exp++=0;
    }
    /* ADD YOUR CODE HERE */

}  /* end init_polynom */


/*
  Get inputs from user using scanf() and store them in the polynomial.
 */
void get_polynom( int coeff[ ], int exp[ ] )
{
    int i=0; // save the input position;
    int j=0; // save the position on coeff;
    int k=0;  // save the position on exp;
    int num;  // save how many input will be save;
    while(1)
    {
        //printf("Plz type your input:\n");
        scanf("%d",&num);
        if(num>0)
        {
            num *=2;
            do
            {
                if(i%2==0)
                {
                    scanf(" %d", &coeff[j++]);
                }

                if(i%2==1)
                {
                    scanf(" %d", &exp[k++]);
                }

                i++;
            }while (i<num);
        }
        break;
    }
    /* ADD YOUR CODE HERE */

}  /* end get_polynom */


/*
  Convert the polynomial to a string s.
 */
void polynom_to_string( int coeff[ ], int exp[ ], char s[ ] )
{
    int tmp =0;
    int tmp1=0;
    while(tmp<ASIZE)
    {
        s[tmp++]='\0';
    }
    tmp=0;

    if(coeff[tmp]!=0)    // print first input ,coefficient is zero will not be appear;
    {
        char ex1[20];
        char co1[20];
        int l;
        if(exp[tmp]!=0)
        {
            if(coeff[tmp]==1)      // when coefficient is 1, x wont appear;
            {
                l=0;
                s[tmp1++]='x';
                s[tmp1++]='^';
                help_method1(exp[tmp],ex1);
                while(ex1[l]!='\0')
                {
                    s[tmp1++]=ex1[l++];
                }
                //s[tmp1++]=(char)exp[tmp];
            } else if(coeff[tmp]==-1){
                s[tmp1++]='-';
                s[tmp1++]='x';
                s[tmp1++]='^';
                l=0;
                help_method1(exp[tmp],ex1);
                while(ex1[l]!='\0')
                {
                    s[tmp1++]=ex1[l++];
                }
                //s[tmp1++]=(char)exp[tmp];
            } else if(coeff[tmp]>1){
                l=0;
                help_method1(coeff[tmp],co1);
                while(co1[l]!='\0')
                {
                    s[tmp1++]=co1[l++];
                }
               // s[tmp1++]=(char)coeff[tmp];
               l=0;
                s[tmp1++]='x';
                s[tmp1++]='^';
                help_method1(exp[tmp],ex1);
                while(ex1[l]!='\0')
                {
                    s[tmp1++]=ex1[l++];
                }
            } else{
                s[tmp1++]='-';
                l=0;
                help_method1((coeff[tmp]*-1),co1);
                while (co1[l]!='\0')
                {

                    s[tmp1++]=co1[l++];
                }
                //s[tmp1++]=(char)coeff[tmp];
                s[tmp1++]='x';
                s[tmp1++]='^';
                l=0;
                help_method1(exp[tmp],ex1);
                while(ex1[l]!='\0')
                {
                    s[tmp1++]=ex1[l++];
                }
                //s[tmp1++]=(char)exp[tmp];
            }

        }else{
            if(coeff[tmp]>0)
            {
               // s[tmp1++]=(char)coeff[tmp];
               l=0;
                help_method1(coeff[tmp],co1);
                while(co1[l]!='\0')
                {
                    s[tmp1++]=co1[l++];
                }
            }
            else
            {
              //  s[tmp1++]='-';
               // s[tmp1++]= (char)coeff[tmp];
                s[tmp1++]='-';
                l=0;
                help_method1((coeff[tmp]*-1),co1);
                while (co1[l]!='\0')
                {
                    s[tmp1++]=co1[l++];
                }
            }

        }

        tmp++;

    } else{
        s[tmp1++]='0';
    }


    while(coeff[tmp]!=0)  // print after first input, coefficient is zero will not be appear;
    {
        char ex[50];
        char co[50];
        int l;
        if(exp[tmp]!=0 && exp[tmp]!=1)
        {
            if(coeff[tmp]>0)
                if(coeff[tmp]==1)    // when coefficient is 1, x wont appear
                {
                    s[tmp1++]='+';
                    s[tmp1++]='x';
                    s[tmp1++]='^';
                  //  s[tmp1++]=(char)exp[tmp];
                  l=0;
                    help_method1(exp[tmp],ex);
                    while(ex[l]!='\0')
                    {
                        s[tmp1++]=ex[l++];
                    }
                } else{
                    s[tmp1++]='+';
                  //  s[tmp1++]=(char)coeff[tmp];
                  l=0;
                    help_method1(coeff[tmp],co);
                    while(co[l]!='\0')
                    {
                        s[tmp1++]=co[l++];
                    }
                    s[tmp1++]='x';
                    s[tmp1++]='^';
                   // s[tmp1++]=(char)exp[tmp];
                   l=0;
                    help_method1(exp[tmp],ex);
                    while(ex[l]!='\0')
                    {
                        s[tmp1++]=ex[l++];
                    }
                }

            else{
                if(coeff[tmp]==-1)  // when coefficient is -1, x wont appear
                {
                    s[tmp1++]='-';
                    s[tmp1++]='x';
                    s[tmp1++]='^';
                  //  s[tmp1++]=(char)exp[tmp];
                  l=0;
                    help_method1(exp[tmp],ex);
                    while(ex[l]!='\0')
                    {
                        s[tmp1++]=ex[l++];
                    }
                }
                else{
                    s[tmp1++]='-';
                    //s[tmp1++]=(char)(coeff[tmp] * -1);
                    l=0;
                    help_method1((coeff[tmp]*-1),co);
                    while (co[l]!='\0')
                    {
                        s[tmp1++]=co[l++];
                    }
                    s[tmp1++]='x';
                    s[tmp1++]='^';
                  //  s[tmp1++]=(char)exp[tmp];
                  l=0;
                    help_method1(exp[tmp],ex);
                    while(ex[l]!='\0')
                    {
                        s[tmp1++]=ex[l++];
                    }
                }
            }

        } else if(exp[tmp]==1)
        {
            if(coeff[tmp]>0)
            {
                s[tmp1++]='+';
                if(coeff[tmp]!=1)
                {
                    l=0;
                    help_method1(coeff[tmp],co);
                    while(co[l]!='\0')
                    {
                        s[tmp1++]=co[l++];
                    }

                }
                s[tmp1++]='x';

            } else
            {
                s[tmp1++]='-';
               if(coeff[tmp]!=-1)
               {
                   l=0;
                   help_method1((coeff[tmp]*-1),co);
                   while (co[l]!='\0')
                   {
                       s[tmp1++]=co[l++];
                   }
               }
                s[tmp1++]='x';
            }
        }

        else
        {
            if(coeff[tmp]>0)
            {
                s[tmp1++]='+';
               // s[tmp1++]=(char)coeff[tmp];

                   l=0;
                   help_method1(coeff[tmp],co);
                   while(co[l]!='\0')
                   {
                       s[tmp1++]=co[l++];
                   }

            } else
            {
                s[tmp1++]='-';
               // s[tmp1++]= (char)(coeff[tmp] * -1);

                   l=0;
                   help_method1((coeff[tmp]*-1),co);
                   while (co[l]!='\0')
                   {
                       s[tmp1++]=co[l++];
                   }


            }
        }
        tmp++;
    }
    s[tmp1]='\0';

    /* ADD YOUR CODE HERE */

}  /* end polynom_to_string */



/*
  Evaluate the polynomial for the value of x and store the result p(x) in variable result.
 */
void eval_polynom( int coeff[ ], int exp[ ], double x, double *result )
{

    /* ADD YOUR CODE HERE */
    int num =0;   // num is to help track the position on coeff and exp;
    int i;
    double tmp=1;
    *result=0;
    while(coeff[num]!=0)
    {
        if(exp[num]!=0)
        {
            for(i=0;i<exp[num];i++)
            {
                tmp = tmp * x;
            }
            *result = *result + (tmp * coeff[num]);
        } else{
            *result = *result + coeff[num];
        }
        num++;
        tmp=1;
    }


}  /* end eval_polynom */



/*
  Add two polynomials and the result is stored in the first polynomial (arrays co1[] and ex1[]).
 */
void add_polynom( int co1[ ], int ex1[ ], int co2[ ], int ex2[ ] )
{

    /* ADD YOUR CODE HERE */
    int num =0;
    int num1 =0;
    int num2 =0;
    int tmp_co[ASIZE];
    int tmp_ex[ASIZE];
    init_polynom(tmp_co,tmp_ex);
    int signal=0;
    while(co1[num1]!=0 && co2[num2]!=0)
    {
        if(ex1[num1]==ex2[num2])
        {
            if((co1[num1]+co2[num2])==0)
            {
                num1++;
                num2++;
            } else{
                tmp_ex[num]= ex1[num1];
                tmp_co[num]= co1[num1] + co2[num2];
                num++;
                num1++;
                num2++;
                signal=1;
            }

        } else if(ex1[num1] > ex2[num2])
        {
            tmp_ex[num]= ex1[num1];
            tmp_co[num]= co1[num1];
            num++;
            num1++;
            signal=1;
        } else{
            tmp_ex[num]=ex2[num2];
            tmp_co[num]=co2[num2];
            num++;
            num2++;
            signal=1;
        }
    }
    while(co1[num1]!=0)
    {
        tmp_co[num]=ex1[num1];
        tmp_ex[num++]=co1[num1++];
        signal=1;
    }
    while(co2[num2]!=0)
    {
        tmp_co[num]=co2[num2];
        tmp_ex[num++] = ex2[num2++];
        signal=1;
    }
    num=0;
    init_polynom(co1,ex1);
    if(signal==1)
    {
        while(tmp_co[num]!=0)
        {
            co1[num]=tmp_co[num];
            ex1[num]=tmp_ex[num];
            num++;
        }
    }




}  /* end add_ polynom */

void help_method1(int integer, char a[])
{
    int i,j,k;
    k=0;
    int count=0;
    int tmp= integer;
    int exp;
        while(tmp>=10)
        {
            tmp = tmp/10;
            count++;
        }
        tmp = integer;
        for(i=0;i<count;i++)
        {
            exp=1;
            for (j = i; j < count; j++) {
                exp = exp *10;
            }
            int tmp1 = tmp / exp;
            tmp = tmp % exp;
            a[k]=tmp1+'0';
            k++;

        }
        a[k]=tmp+'0';
        k++;
        a[k]='\0';

}


/************************** END OF FILE ***************************/




