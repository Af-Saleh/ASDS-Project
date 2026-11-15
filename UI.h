#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED
#define reset   "\033[0m"
#define bold    "\033[1m"
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void clear_page(){
    system("cls");
}

void colored_char(char character , char color[] , int BOLD){
    if (BOLD) printf(bold);
    printf("%s%c%s" , color , character , reset);
}

void colored_word(char word[] , char color[] , int BOLD){
    if(BOLD) printf(bold);
    printf("%s%s%s" , color , word , reset);
}

char* line(int length , char plus_color[] , char minus_color[] , int pBOLD , int mBOLD)
{
    static char ln[200];
    colored_char('+' , plus_color , pBOLD);
    ln[0] = '+';
    for (int i = 0 ; i < length; i++) {colored_char('-' , minus_color , mBOLD); strcat(ln , "-");}
    colored_char('+' , plus_color , pBOLD);
    strcat(ln , "+");
    printf("\n");
    strcat(ln , "\n");
    return ln;
}

char* separated_line(int lengths[] , int total , char* plus_color[]  , char* minus_color[] , int pBOLD[] , int mBOLD[])
{
    static char ln[200];
    colored_char('+' , plus_color[0] , pBOLD[0]);
    ln[0] = '+';
    for (int i = 0 ; i < total ; i++){
        for (int j = 0 ; j < lengths[i] ; j++) 
        {
            colored_char('-' , minus_color[i] , mBOLD[i]);
            strcat(ln , "-");
        }
        colored_char('+' , plus_color[i+1] , pBOLD[i+1]);
        strcat(ln , "+");
    }
    printf("\n");
    strcat(ln , "\n");
    return ln;
}

char* table_line(int lengths[] ,char* elements[] ,int total , char* word_color[] , char* pillar_color[] , int BOLD[] , int pBOLD[])
{
    static char ln[200];
    ln[0] = '|';
    colored_char('|' , pillar_color[0] , pBOLD[0]);
    for (int i = 0 ; i < total ; i++){
        int element_len = strlen(elements[i]) , length = lengths[i];
        int left_space = (length-element_len)/2 , right_space = length - (element_len + left_space);
        for(int j = 0 ; j < left_space ; j++) {printf(" ");strcat(ln," ");}
        colored_word(elements[i] , word_color[i] , BOLD[i]);
        strcat(ln , elements[i]);
        for (int j = 0 ; j < right_space ; j++) {printf(" ");strcat(ln , " ");}
        colored_char('|' , pillar_color[i+1] , pBOLD[i+1]);
        strcat(ln , "|");
    }
    printf("\n");
    strcat(ln , "\n");
    return ln;
}

void boxed(int length, int left_space , char word[] , char pillar_color[] , char word_color[] , int BOLD , int pBOLD){
    colored_char('|' , pillar_color , pBOLD);
    int right_space = length - (strlen(word) + left_space);
    for (int i = 0 ; i < left_space ; i++) printf(" ");
    colored_word(word , word_color , BOLD);
    for (int i = 0 ; i < right_space ; i++) printf(" ");
    colored_char('|' , pillar_color , pBOLD);
    printf("\n");
}

void centered(int length , char word[] , char pillar_color[] , char word_color[] , int BOLD , int pBOLD){
    int left_space = (length-strlen(word))/2, right_space = length - (left_space + strlen(word));
    colored_char('|' , pillar_color , pBOLD);
    for (int i = 0 ; i < left_space ; i++) printf(" ");
    colored_word(word , word_color , BOLD);
    for (int i = 0 ; i < right_space ; i++) printf(" ");
    colored_char('|' , pillar_color , pBOLD);
    printf("\n");
}

void menu_display(int select , int width, char *menu[] ,int total , char menu_name[] , char selected_color[] , char non_selected_color[]  , char menu_name_color[] , char menu_color[]){
    char selected[200] = "> ";
    clear_page();
    line(width , menu_color , menu_color , 1 , 1);
    centered(width , menu_name , menu_color , menu_name_color , 1 , 1);
    line(width , menu_color , menu_color , 1 , 1);
    for (int i = 0 ; i < total ; i++){
        if (i == select){
            strcat(selected , menu[i]);
            centered(width , selected , menu_color , selected_color , 1 , 1);
        } 
        else{
            centered(width, menu[i] , menu_color , non_selected_color , 0 , 1);
        }
    }
    line(width , menu_color , menu_color , 1 , 1);
}

int menus(int width, char *menu[] ,int total , char menu_name[] , char selected_color[] , char non_selected_color[]  , char menu_name_color[] , char menu_color[])
{
    int selected = 0;
    int key;
    while (1)
    {
        menu_display(selected , width, menu , total , menu_name , selected_color , non_selected_color , menu_name_color , menu_color);
        // get key (char) without enter needed
        key = getch();
        // common return up/down for getch
        if (key == 224)
        {
            key = getch();
            if (key == 80) // down
            {
                selected += 1;
                selected %= total;
            }
            else if (key == 72) // up
            {
                selected += total-1;
                selected %= total;              
            }
        }
        else if (key == ' ' || key == 13) // space or enter
        {
            return selected;
        }
    }
}

char** bill(char bill_color[] , char** values , char date[]){
    static char bl[14][200];
    line(10);
}

#endif