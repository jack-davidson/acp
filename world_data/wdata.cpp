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
#include <string>

/* One csv row of mortality rate data. (Non-(2000-20005) populations are ignored).  */
struct population {
	int index;
	std::string region;  /* Area/Region/Country */
	int population;  /* 2000-2005 */
};

int main (int argc, char *argv[])
{
	return 0;
}
