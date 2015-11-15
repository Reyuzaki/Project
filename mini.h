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
/* Daily Product */

typedef struct prd {
	int qnt;
	char name[128];
	char company[128];
	int dom;
	int doe;
	float cp;
	float sp;
	float discnt;

}prd;

typedef struct node {
	prd *str;
	struct node *next, *prev;
}node;

typedef struct list {
	struct node *head, *tail;
	int length;
}list;

void init(list *l);
void traverse(list *l);
void append(list *l, prd *med);
int length(list *l);
void sell(list *l);
void expiry(list *l, int date);
void expired(list *l, int date);
int save(list *l);
int ret(list *l);
void remov(list *l);


/* Special Product */

typedef struct sprd {
	int sqnt;
	char sname[128];
	char scompany[128];
}sprd;

typedef struct snode {
	sprd *sstr;
	struct snode *snext, *sprev;
}snode;

typedef struct slist {
	struct snode *shead, *stail;
	int slength;
}slist;

void sinit(slist *sl);
void straverse(slist *sl);
void sappend(slist *sl, sprd *smed);
int slength(slist *sl);


/* Sold Product */

typedef struct nd{
		prd *st;
		struct nd *nxt, *prv;
}nd;

typedef struct lt {
	struct nd *hd, *tl;
	int lgt;
}lt;

lt bp;

void binit(lt *bl);
void bogus(node *t, int u);
void bappend(lt *bl, prd *bmed);
void btraverse(lt *bl);


/* Expired Product */

typedef struct exp{
	prd *expst;
	struct exp *expnext, *expprev;
}exp;

typedef struct explist {
	struct exp *exphead, *exptail;
	int explength;
}explist;

explist expp;

void expinit(explist *expl);
void expbogus(node *exptemp);
void expappend(explist *expl, prd *expmed);
void exptraverse(explist *expl);
void expremov(list *l, int date);
