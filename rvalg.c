#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define NUM_LETTERS (int)26


typedef struct Node{
char letter;
int count; //counts the number of this word node
struct Node* child[NUM_LETTERS];
bool isCreat[NUM_LETTERS];
struct Node* father;
}Node;

//checks if the char is letter
//if it is -> returns the letter to low
//else -> return 0   
char isCorrect(char c){
if (c>=65 && c<=90){
	c =c+32;
	return c;
}
if (c>=97 && c <= 122){
	return c;
}
if(c==' ' || c=='\t' || c=='\n') return ' ';
return 0;
}



void revers(char* c, int length){
int i;
for(i=0;i<length/2;i++){
  char temp = c[i];
  c[i] = c[length-i-1];
  c[length-i-1] = temp;
}}

void recPrint(Node* p){
int i;
for(i=26;i>=0;i--){
    if(p -> isCreat[i] == true){
    	recPrint(p -> child[i]);
    }
}
if(p -> count > 0 && p -> father != NULL){
	Node* t = p;
	char* word = (char*)malloc(sizeof(char));
	int size=0;
	while(t -> father != NULL){
		size++;
		word = (char*)realloc(word, size*sizeof(char));
		word[size-1] = t -> letter;
		t = t -> father;
	}
	revers(word,size);
	printf("%s %d\n", word, p ->count);
	free(word);
}
}





Node* creatNode(char c){
Node *p = (Node*)malloc(sizeof(Node));
p -> letter = c;
p -> count = 0;
int i;
    for(i=0;i<NUM_LETTERS;i++){
	p -> isCreat[i] = false;
    }
return p;
}


void recFree(Node* p){
int i;
for(i=0;i<26;i++){
    if(p -> isCreat[i] == true){
    	recFree(p -> child[i]);
    }
}
free(p);
}


int main(){
printf("revers fun");
Node* first = creatNode('F');
first -> father = NULL;
Node* p = first;
char c;

while(scanf("%c",&c)!=EOF && c!='0'){
    c = isCorrect(c);
    if(c){//only " " splits words! (not another char as "." "," "1")
    	if(c==' '){
    	  p -> count++;
    	  p = first;
    	}else{
    	if(p -> isCreat[c-97]){
    	  p = p -> child[c-97];
    	}
    	else{
    	  int index = c-97;
    	  p -> child[index] = creatNode(c);
    	  p -> child[index] -> father = p;//
    	  p -> isCreat[index] = true;
    	  p = p -> child[index];
    	}
    	}
    }
}
p -> count++;//for the last word

recPrint(first);
recFree(first);//free allocs

return 0;
}
