/*Copyright 2015 Aman Joshi

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mini.h"

/* for save */
#include <fcntl.h>
#include <errno.h>


	/* Sold Product */

/* Initialises the sold product list */
void binit(lt *bl) {
	bl->hd = bl->tl = NULL;
	bl->lgt = 0;
}	

/* Taking the inf about the sold product */
void bogus(node *t, int u) {
	prd *bmed;
	bmed = (prd *)malloc(sizeof(prd));
	bmed->qnt = u;
	strcpy(bmed->name,t->str->name);
	strcpy(bmed->company,t->str->company);
	bmed->dom,t->str->dom;
	bmed->doe,t->str->doe;
	bmed->cp = t->str->cp;
	bmed->sp = t->str->sp;
	bmed->discnt = t->str->discnt;
	bappend(&bp, bmed);
	
}

/* Adding the sold product to the list */
void bappend(lt *bl, prd *bmed) {
	nd *tp = (nd *)malloc(sizeof(nd));
	tp->st = (prd*)malloc(sizeof(prd));
	tp->st = bmed;
	if(bl->hd) {
		tp->nxt = bl->hd;
		tp->prv = bl->tl;
		bl->hd->prv = tp;
		bl->tl->nxt = tp;
	} else {
		tp->nxt = tp->prv = bl->hd
			= tp;
	}
	bl->tl = tp;	
	bl->lgt++;
}

/* Traverses the sold product list */
void btraverse(lt *bl) {
	nd *t = bl->hd;
	printf("Sold Products are:\n");
	while(t != bl->tl) {
		printf(" [ ");
		printf("%d  %s %s ", 
				 t->st->qnt,
		 		 t->st->name,
		 		 t->st->company);
		t = t->nxt;
		printf(" ]\n");
	}
	if(t) {
		printf(" [ ");
		printf("%d  %s %s", 
				 t->st->qnt,
		 		 t->st->name,
		 		 t->st->company);
		
		printf(" ]\n");
	}
	
}


	/* Product */

/* Initialises the Product List */
void init(list *l) {
	l->head = l->tail = NULL;
	l->length = 0;
}

/* Traverses the Product List */
void traverse(list *l) {
	node *p = l->head;
	while(p != l->tail) {
		printf(" [ ");
		printf("%d  %s %s ", 
				 p->str->qnt,
		 		 p->str->name,
		 		 p->str->company);
		p = p->next;
		printf(" ]\n");
	}
	if(p) {
		printf(" [ ");
		printf("%d  %s %s", 
				 p->str->qnt,
		 		 p->str->name,
		 		 p->str->company);
		
		printf(" ]\n");
	}
	
}

/* Adds product to the List */
void append(list *l, prd *med) {
	node *tmp = (node *)malloc(sizeof(node));
	tmp->str = (prd*)malloc(sizeof(prd));
	tmp->str = med;
	if(l->head) {
		tmp->next = l->head;
		tmp->prev = l->tail;
		l->head->prev = tmp;
		l->tail->next = tmp;
	} else {
		tmp->next = tmp->prev = l->head
			= tmp;
	}
	l->tail = tmp;	
	l->length++;

}

int length(list *l) {
	return l->length;	
}

/* Sells the product & tells total bill */
void sell(list *l) {
	float netbill = 0.00;
	int x = 1;
	while(x) {
		printf("Enter the name & quantity of product ");
		char prdname[128];
		int prdqnt;
		scanf("%s %d", prdname, &prdqnt);
		int a, state = 0;
		float b, c, d, bill ;
		node *p = l->head;
		while(p != l->tail) {
			a = strcmp(p->str->name, prdname);
			if(a == 0) {
				if(p->str->qnt >= prdqnt) {
					p->str->qnt = p->str->qnt - prdqnt;
					d = p->str->discnt / 100.00;
					b = 1.00 - d;
					c = p->str->sp * b;
					bill = prdqnt * c;
					printf("Bill : %f\n",bill);
					state = 1;
					bogus(p, prdqnt);
					netbill = netbill + bill;
					break;
				}
				else {
					printf("Insufficient quantity!\n");
					state = 1;
					break;
				}
				
			}
			else
				p = p->next;
			
		}
		
		if(state == 0) {
			a = strcmp(p->str->name, prdname);
			if(a == 0) {
				if(p->str->qnt >= prdqnt) {
					p->str->qnt = p->str->qnt - prdqnt;
					d = p->str->discnt / 100.00;
					b = 1.00 - d;
					c = p->str->sp * b;
					bill = prdqnt * c;
					printf("Bill : %f\n",bill);
					bogus(p, prdqnt);
					netbill = netbill + bill;
				}
				else {
					printf("Insufficient quantity!\n");
				}
				state = 1;
			}
			
		}
		if(state == 0) 
			printf("Item not available!\n");
		
		x = buymore();
	}
	printf("Total bill is : %f\n",netbill);

}

int buymore() {
	int choice;
	printf("If you want to continue shopping press 1 else 0 ");
	scanf("%d",&choice);
	return choice;
}

/* Tells 1 month in advance about products expiry */
void expiry(list *l, int date) {
	node *p = l->head;
	printf("Products are about to expire:\n");
	while(p != l->tail) {
		if((p->str->doe - date) < 1000) {
			printf("  [ ");
			printf("%d  %s %s %d %d %f %f %f", 
				 p->str->qnt,
		 		 p->str->name,
		 		 p->str->company,
		 		 p->str->dom,
		 		 p->str->doe,
		 		 p->str->cp,
		 		 p->str->sp,
		 		 p->str->discnt);
			p = p->next;
			printf(" ]\n");
		}
	}
	if(p) {
		if((p->str->doe - date) < 1000) {
			printf(" [ ");
			printf("%d  %s %s %d %d %f %f %f", 
				 p->str->qnt,
		 		 p->str->name,
		 		 p->str->company,
		 		 p->str->dom,
		 		 p->str->doe,
		 		 p->str->cp,
		 		 p->str->sp,
		 		 p->str->discnt);
		
			printf(" ]\n");
		}
	}
}


	/* Expired Product */

/* Initialises the expired product list */
void expinit(explist *expl) {
	expl->exphead = expl->exptail = NULL;
	expl->explength = 0;
}

/* Taking the inf about the expired product */
void expbogus(node *p) {
	prd *expmed;
	expmed = (prd *)malloc(sizeof(prd));
	expmed->qnt = p->str->qnt;
	strcpy(expmed->name,p->str->name);
	strcpy(expmed->company, p->str->company);
	expmed->dom = p->str->dom;
	expmed->doe = p->str->doe;
	expmed->cp = p->str->cp;
	expmed->sp = p->str->sp;
	expmed->discnt = p->str->discnt;
	expappend(&expp, expmed);
	
}

/* Adding the expired product to the list */
void expappend(explist *expl, prd *expmed) {
	exp *exptemp = (exp *)malloc(sizeof(exp));
	exptemp->expst = (prd*)malloc(sizeof(prd));
	exptemp->expst = expmed;
	if(expl->exphead) {
		exptemp->expnext = expl->exphead;
		exptemp->expprev = expl->exptail;
		expl->exphead->expprev = exptemp;
		expl->exptail->expnext = exptemp;
	} else {
		exptemp->expnext = exptemp->expprev = expl->exphead
			= exptemp;
	}
	expl->exptail = exptemp;	
	expl->explength++;
}

/* Traverses the expired product list */
void exptraverse(explist *expl) {
	exp *exptemp = expl->exphead;
	printf("Expired Products are:\n");
	while(exptemp != expl->exptail) {
		printf(" [ ");
		printf("%d  %s %s ", 
				 exptemp->expst->qnt,
		 		 exptemp->expst->name,
		 		 exptemp->expst->company);
		exptemp = exptemp->expnext;
		printf(" ]\n");
	}
	if(exptemp) {
		printf(" [ ");
		printf("%d  %s %s", 
				 exptemp->expst->qnt,
		 		 exptemp->expst->name,
		 		 exptemp->expst->company);
		
		printf(" ]\n");
	}
	
}

/* Gives a list of expired products */
void expired(list *l, int date) {
	node *p = l->head;
	printf("Expired products are:\n");
	while(p != l->tail) {
		if((p->str->doe - date) < 0) {
			printf("  [ ");
			printf("%d  %s %s %d %d %f %f %f", 
				 p->str->qnt,
		 		 p->str->name,
		 		 p->str->company,
		 		 p->str->dom,
		 		 p->str->doe,
		 		 p->str->cp,
		 		 p->str->sp,
		 		 p->str->discnt);
			expbogus(p);
			p = p->next;
			printf(" ]\n");
		}
	}
	if(p) {
		if((p->str->doe - date) < 0) {
			printf(" [ ");
			printf("%d  %s %s %d %d %f %f %f", 
				 p->str->qnt,
		 		 p->str->name,
		 		 p->str->company,
		 		 p->str->dom,
		 		 p->str->doe,
		 		 p->str->cp,
		 		 p->str->sp,
		 		 p->str->discnt);
			expbogus(p);
			printf(" ]\n");
		}
	}
}

/* Remove the expired product from list */
void expremov(list *l, int date) {
	node *p = l->head;
	while(p != l->tail) {
		if(p->str->doe - date < 0) {
			node *tmp;
			tmp = p;
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			if(p == l->head) {
				l->head = l->head->next;
				p = l->tail;
			}
			l->length--;
			free(tmp);
		}
		p = p->next;
	}
	if(p->str->doe - date < 0) {
			node *tmp;
			tmp = p;
			if(l->head == l->tail) {
				l->head = l->tail = p = NULL;
				free(tmp);				
			}
			else {
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				l->tail = l->tail->prev;
				l->length--;
				free(tmp);
			}
		}
}


	/* Product */ /* Continued */

/* Saves the product data in a file */
int save(list *l) {
	FILE *fp= fopen("Data.txt", "w");
	if(fp == NULL) {
		perror("open failed:");
		return errno;
	}
	node *p = l->head;
	while(p->next != l->head) {
		fwrite(p->str,sizeof(prd),1,fp);
		p = p->next;
	}	
	if(p) {
		fwrite(p->str,sizeof(prd),1,fp);
	}
	fclose(fp);
	return 0;
	
}

/* Reterives the product data from a file */
int ret(list *l) {
	FILE *fp= fopen("Data.txt", "r");	
	if(fp == NULL) {
		perror("read failed:");
		return errno;
	}
	int w = 1;
	node *tmp;
	while(w) {
		tmp = (node *)malloc(sizeof(node));
		tmp->str = (prd*)malloc(sizeof(prd));
		w = fread(tmp->str,sizeof(prd),1,fp);
		if(w == 0) 
			break;
		if(l->head) {
			tmp->next = l->head;
			tmp->prev = l->tail;
			l->head->prev = tmp;
			l->tail->next = tmp;
		} 
		else {
			tmp->next = tmp->prev = l->head
				= tmp;
		}
		l->tail = tmp;	
		l->length++;

	}
	return 0;
}

/* Remove the product from list */
void remov(list *l) {
	node *p = l->head;
	while(p != l->tail) {
		if(p->str->qnt == 0) {
			/* rechain */
			node *tmp;
			tmp = p;
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			if(p == l->head) {
				l->head = l->head->next;
				p = l->tail;
			}
			l->length--;
			free(tmp);
		}
		p = p->next;
	}
	if(p->str->qnt == 0) {
			/* rechain */
			node *tmp;
			tmp = p;
			if(l->head == l->tail) {
				l->head = l->tail = p = NULL;
				free(tmp);				
			}
			else {
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				l->tail = l->tail->prev;
				l->length--;
				free(tmp);
			}
		}
}


	/* Special Product */

/* Initialises the sp product list */
void sinit(slist *sl) {
	sl->shead = sl->stail = NULL;
	sl->slength = 0;
}

/* Traverses the special product list */
void straverse(slist *sl) {
	snode *spp = sl->shead;
	while(spp != sl->stail) {
		printf(" [ ");
		printf("%d  %s %s", 
				 spp->sstr->sqnt,
		 		 spp->sstr->sname,
		 		 spp->sstr->scompany);
		spp = spp->snext;
		printf(" ]\n");
	}
	if(spp) {
		printf(" [ ");
		printf("%d  %s %s", 
				 spp->sstr->sqnt,
		 		 spp->sstr->sname,
		 		 spp->sstr->scompany);
		
		printf(" ]\n");
	}
}

/* Appends the special product list */
void sappend(slist *sl, sprd *smed) {
	snode *stmp = (snode *)malloc(sizeof(snode));
	stmp->sstr = (sprd*)malloc(sizeof(sprd));
	stmp->sstr = smed;
	if(sl->shead) {
		stmp->snext = sl->shead;
		stmp->sprev = sl->stail;
		sl->shead->sprev = stmp;
		sl->stail->snext = stmp;
	} 
	else {
		stmp->snext = stmp->sprev = sl->shead
			= stmp;
	}
	sl->stail = stmp;	
	sl->slength++;
}



	




















