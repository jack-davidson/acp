/* Author: Jack Davidson
 *
 * World Data Lab - Read/Write CSV
 *
 * 	- Create an ordered list by longest lived population from 2000-2005 year group.
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

/* One csv row of mortality rate data. (Non-(2000-20005) populations are ignored).  */
struct population {
	int index;
	string region;  /* Area/Region/Country */
	float population;  /* 2000-2005 */
};

int main (int argc, char *argv[])
{
	string r, re;  /* row, row element.  */
	stringstream row;
	ifstream f;
	int i;  /* Column number.  */

	f.open("mortality_rates.csv");

	/* Every row in csv.  */
	while(getline(f, r)) {
		/* Convert string(r) to stringstream(row) for
		 * use with a columnar getline() call.  */
		row = stringstream(r);  

		struct population p;

		i = 0; /* Reset element number.  */
		while(getline(row, re, ',')) {
			switch(i) {
			case 0: /* index header */
				p.index = atoi(re.c_str());
			case 2:
				p.region = re;
			case 15:
				p.population = atof(re.c_str());
			}
			i++;
		}
		cout << "index=" << p.index << ", region=" << p.region << ", population=" << p.population << endl;
	}

	f.close();
	return 0;
}
