#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *load_map_node(const char *filename){
	Node *node_head;
	Node *next_node;
	Node *current_node;
	int n=0;
	next_node=(Node*)malloc(sizeof(Node));
	node_head=next_node;
	current_node=next_node;
	node_head->next=NULL;
	FILE *file=fopen(filename,"r");
	if(file==NULL){
		printf("fail to load file!");
		return NULL;
	}
	char str[50];
	while(!feof(file)){
		next_node=(Node*)malloc(sizeof(Node));
		fgetc(file);
		fscanf(file,"%[^\n]s",str);
		if(str=="<node"){
			sscanf(file,"id=%d lat=%f lon=%f /node>",&next_node->id,&next_node->lat,&next_node->lon);
		}
		else{
			fgetc(file);
		}
		current_node->next=next_node;
		current_node=next_node;
		n++;
	}
}

Link *load_map_link(const char *filename){
	Link *link_head;
	Link *next_link;
	Link *current_link;
	int x=0;
	next_link=(Link*)malloc(sizeof(Link));
	link_head=next_link;
	current_link=next_link;
	link_head->next=NULL;
	FILE *file=fopen(filename,"r");
	if(file==NULL){
		printf("fail to load file!");
		return NULL;
	}
	char str[50];
	while(!feof(file)){
		next_node=(Link*)malloc(sizeof(Link));
		fgetc(file);
		fscanf(file,"%[^\n]s",str);
		if(str=="<link"){
			sscanf(file,"id=%d node=%d node=%d way=%d length=%f veg=%f arch=%f land=%f POI=;/link>",&next_link->id,&next_link->node1,&next_link->node2,&next_link->way,&next_link->length,&next_link->veg,&next_link->arch,&next_link->land);
		}
		fgetc(file);
		current_link->next=next_link;
		current_link=next_link;
		x++;
	}
}