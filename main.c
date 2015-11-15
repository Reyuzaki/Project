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
#include <limits.h>
#include "mini.h"

int printmenu() {
	int choice;
	printf("1. Add Product\n");
	printf("2. Sell Product\n");
	printf("3. Save Data\n");
	printf("4. Retrive Data\n");
	printf("5. About to Expire\n");
	printf("6. Expired\n");
	printf("7. Expired Products\n");
	printf("8. Special Orders\n");
	printf("9. Sold Products\n");
	printf("10. exit\n");
	scanf("%d", &choice);	
	return choice;
}

int main() {
	
	/* Product */
	list p;
	prd *med;
	init(&p);	
	
	/* Special Product */
	slist spp;
	sprd *smed;
	sinit(&spp);
		
	/* Sold Product */
	
	prd *bmed;
	binit(&bp);	

	/* Expired Product */
	
	prd *expmed;
	expinit(&expp);	

	/* Operations */
	int choice;
	while(1) {
		printf("Available Products are:\n");
		traverse(&p);
		choice = printmenu();
		switch(choice) {
		
		case 1:/* Add Product */ 
			med = (prd*)malloc(sizeof(prd));
			printf("Enter the quantity of product\n");
			scanf("%d", &med->qnt);
			printf("Enter the name of product\n");
			scanf("%s", med->name);
			printf("Enter the of company product\n");
			scanf("%s", med->company);
			printf("Enter the  date of manufacture(yyyymmdd) of product\n");
			scanf("%d", &med->dom);
			printf("Enter the date of expiry(yyyymmdd) of product\n");
			scanf("%d", &med->doe);
			printf("Enter the Cost Price of product\n");
			scanf("%f", &med->cp);
			printf("Enter the Selling Price of product\n");
			scanf("%f", &med->sp);
			printf("Enter the discount percentage on product\n");
			scanf("%f", &med->discnt);
			append(&p, med);
			break;
		
		case 2:/* Sell Product*/
			sell(&p);
			remov(&p);
			break;
		
		case 3:/* Save today's Data */
			save(&p);
			break;
		
		case 4:/* Retrive yesterday's Data */
			ret(&p);
			break;
		
		case 5:/*About to Expire*/
			printf("Enter today,s date:");
			int date;
			scanf("%d", &date);
			expiry(&p, date);
			break;
		
		case 6:/* Expired Products*/
			printf("Enter today,s date(yyyymmdd):");
			int toddate;
			scanf("%d", &toddate);
			expired(&p, toddate);
			expremov(&p, toddate);
			break;
		
		case 7:/* Expired Product */		
			exptraverse(&expp);			
			break;
 
		case 8:/* Special Orders*/
			straverse(&spp);
			smed = (sprd*)malloc(sizeof(sprd));
			printf("Enter the quantity of product\n");
			scanf("%d", &smed->sqnt);
			printf("Enter the name of product\n");
			scanf("%s", smed->sname);
			printf("Enter the of company product\n");
			scanf("%s", smed->scompany);
			sappend(&spp, smed);
			break;
		
		case 9:/* Sold Product */
			btraverse(&bp);			
			break;
			
		case 10:/*exit */
			exit(0);
			break;
		}	
	}
	return 0;
}
