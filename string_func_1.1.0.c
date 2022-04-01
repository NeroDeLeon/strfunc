#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/types.h>


char* mystrlwr (char *string);
char* mystrupr (char *string);
char* mystrrev (char *string);
char *uplow (char *string);
char *chr_such(register char *s,	register char c);
char *getlaufzeit(time_t t_start, time_t t_stop);

int main(int argc, char **argv)
{
    time_t t_start;
    int i,j;
    char str1[]="Das ist langer ein sehr langer ein sehr sehr langer langer string!";
    char str2[]="langer";
    char *in;
    char *out;
    char *cs;
    char *lz;

  if(i=strstr_count(str1, str2))
    {
        in=(str1);
        out=(str2);
        printf("String: %s\n", (in));
        printf("mystrlwr: %s\n", mystrlwr(in));
        printf("mystrupr: %s\n", mystrupr(in));
        printf("mystrrev: %s\n", mystrrev(in));
        mystrrev (in);
        printf("uplow: %s\n", uplow(in));
        printf("Vorkommen von \"%s\" im String: %d mal\n",out, i);
        if(!chr_such(str1, "s")){
        j=chr_such(str1, "s");
        printf("chr_such: %d\n", (j));
        }else{
        printf("geht net!\n");
        }
    }
    else
    {
        printf("strstr_count hat nix gefunden!");
    }
    time_t t_stop;
    lz=getlaufzeit(t_start, t_stop);
        printf("%s\n", lz);
return 0;
}
int strstr_count(const char *string, const char *substring) {
    int i, j, k, count=0;
    for(i = 0; string[i]; i++)
        for(j = i, k = 0; string[j] == substring[k]; j++, k++)
            if(!substring[k+1])
                count++;
    return(count);
}
char* mystrlwr (char *string) {
    char *p=string;
    for (p=string; *p; p++)
        *p = tolower(*p);
    return string;
}
char* mystrupr (char *string) {
    char *p=string;
    for (p=string; *p; p++)
        *p = toupper(*p);
    return string;
}
char* mystrrev(char *string) {
int i,len;
char c;
   len=strlen(string);
   for (i=0; i<len/2; i++) {
      c=string[i];
      string[i]=string[len-1-i];
      string[len-1-i]=c;
   }
   return string;
}
char *uplow(char *string) {
   char *ptr=string;
   char schalter=0;
   mystrrev(string);
   while(*ptr++) {
      while((*ptr) && (*ptr != 0x20)) {
         *ptr=(!schalter) ? tolower(*ptr) : toupper(*ptr);
         ptr++;
      }
      schalter=(!schalter) ? 1 : 0;
   }
   mystrrev(string);
   while(*ptr++) {
      while((*ptr) && (*ptr != 0x20)) {
         *ptr=(!schalter) ? tolower(*ptr) : toupper(*ptr);
         ptr++;
      }
      schalter=(!schalter) ? 1 : 0;
   }
   return(string);
}
/*-------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------*/
/* sucht character c in String s                                           */
/* Im Unterschied zur Standardfunktion strchr wird                         */
/* die den String begrenzende NUL nicht als zum String                     */
/* zugehoerig gezaehlt.                                                    */

char *chr_such(register char *s,	register char c) {
   while (*s) {
      if (*s == c) {
			return(s);
		}
		s++;
	}
	return((char *)0);
}
/*----------------------------------------*/
char *getlaufzeit(time_t t_start, time_t t_stop) {
#define MAXLEN 50
int lzeit_st, lzeit_min, lzeit_sec, lzeit_ms, test;
div_t erg;
static char lzeit[MAXLEN];

   memset(lzeit, 0x00, sizeof(lzeit));
   erg = div((int)(t_stop - t_start), 3600);
   lzeit_st = erg.quot;
   erg = div(erg.rem, 60);
   lzeit_min = erg.quot;
   lzeit_sec = erg.rem;
   erg = div(erg.rem, 100);
   lzeit_ms = erg.quot;
   test = sprintf (lzeit, "%d St %d Min %d Sek %d ms", lzeit_st, lzeit_min, lzeit_sec, lzeit_ms);
   if ( test <= 0 || test > (MAXLEN-1)) {
      lzeit[0] = '\0';
   }
   return(lzeit);
}
