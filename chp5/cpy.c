#include <stdio.h>

/* copy t to s; array subscript version */
void strcpy2(char *s, char *t)
{
    int i = 0;
    for(i = 0; t[i] != 0; i++)
    {
        s[i] = t[i];
    }
    s[i] = 0;
}

/* pointers version */
void strcpy3(char *s, char *t)
{
    while(*t)
    {
        *s = *t;
        t++;
        s++;
    }
    *s = 0;
}

/** pointers -> practical version by "experienced" engineers */
void strcpy4(char *s, char *t)
{
    while(*s++ = *t++)
    {}
}

int main()
{
    char s[] = "Meme";
    char t[] = "Cry";
    strcpy3(s, t);
    printf("S is %s\n", s);

    // char *ps = s;
    // char *pt = t;
    // *(ps + 1) = 'J';
    // printf("S is %s\n", s);
    // pt = ps;
    // *(pt + 2) = 'D';
    // printf("pt is %s\n", pt);
}

//  is CDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~⌂ÇüéâäàåçêëèïîìÄÅÉæÆôöòûùÿÖÜ¢£¥₧ƒáíóúñÑªº¿⌐¬½¼¡«»░▒▓│┤╡╢╖╕╣║╗╝╜╛┐└┴┬├─┼╞╟╚╔╩╦╠═╬╧╨╤╥╙╘╒╓╫╪┘┌█▄▌▐▀αßΓπΣσµτΦΘΩδ∞φε∩≡±≥≤⌠⌡÷≈°∙·√ⁿ²■ 
// ☺☻♥♦♣♠
// ♫☼►◄↕‼¶§▬↨↑↓→∟↔▲▼123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~⌂ÇüéâäàåçêëèïîìÄÅÉæÆôöòûùÿÖÜ¢£¥₧ƒáíóúñÑªº¿⌐¬½¼¡«»░▒▓│┤╡╢╖╕╣║╗╝╜╛┐└┴┬├─┼╞╟╚╔╩╦╠═╬╧╨╤╥╙╘╒╓╫╪┘┌█▄▌▐▀αßΓπΣσµτΦΘΩδ∞φε∩≡±≥≤⌠⌡÷≈°∙·√ⁿ²■ 