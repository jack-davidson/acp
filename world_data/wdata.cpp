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
	int population;  /* 2000-2005 */
};

int main (int argc, char *argv[])
{
	string r, column;
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

		i = 0; /* Reset column number.  */
		while(getline(row, column, ',')) {
			cout << column;
			switch(i) {
			case 0: /* index header */
				p.index = atoi(column.c_str());
			}
			/* Append struct to list.  */
			i++;
		}
		cout << endl;
	}

	f.close();
	return 0;
}
