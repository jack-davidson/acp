/* Author: Jack Davidson
 *
 * World Data Lab - Read/Write CSV
 *
 * 	- Create an ordered list by longest lived rate from 2000-2005 year group.
 * 	- Where does the United States rank in the list by more developed regions
 * 		(comprised of Europe, Northern America, Australia/New Zealand and Japan)?
 * 	- Where is it ranked overall?
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

/* One csv row of mortality rate data. (Non-(2000-20005) rates are ignored).  */
struct rate {
	int index;
	string region;  /* Area/Region/Country */
	float rate;  /* 2000-2005 */
};

int main (int argc, char *argv[])
{
	string r, re;  /* row, row element.  */
	stringstream row;
	ifstream f;
	int i;  /* Column number.  */
	int ri; /* rate index */

	f.open("mortality_rates.csv");

	struct rate rates[241];
	ri = 0;

	/* Every row in csv.  */
	while(getline(f, r)) {
		/* Convert string(r) to stringstream(row) for
		 * use with a columnar getline() call.  */
		row = stringstream(r);  
		if (r[0] == ',' || r[0] == '"') continue;

		struct rate *p = &rates[ri++];

		i = 0; /* Reset element number.  */
		while(getline(row, re, ',')) {
			switch(i) {
			case 0: /* index header */
				p->index = atoi(re.c_str());
			case 2:
				p->region = re;
			case 15:
				p->rate = atof(re.c_str());
			}
			i++;
		}
	}
	
	int j;
	for (i = 0; i < sizeof(rates)/sizeof(rates[0]) - 1; i++) {
		for (j = 0; j < sizeof(rates)/sizeof(rates[0]) - i - 1; j++) {
		    if (rates[j].rate > rates[j + 1].rate) {
			struct rate tmp = rates[j];
			rates[j] = rates[j+1];
			rates[j+1] = tmp;
		    }
		}
	}

	int no = sizeof(rates)/sizeof(rates[0])-1;
	int wrank;
	int dvrank;
	for (struct rate p: rates) {
		if (p.index == 223) {
			wrank = no;
			dvrank = no/2;
		}
		no--;
		//cout << "[" << no++ << "]: index=" << p.index << ", region=" << p.region << ", rate=" << p.rate << endl;
	}
	cout << "Throughout World USA ranks at " << wrank << endl;
	cout << "Throughout developed nations, USA ranks at " << dvrank << endl;

	f.close();
	return 0;
}
