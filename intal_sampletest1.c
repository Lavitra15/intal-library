#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intal.h"

int main(int argc, char const *argv[]) {
	int n = 12;
	char **a = (char**) malloc(n * sizeof(char*));
	for(int i = 0; i < n; i++) {
		a[i] = (char*) malloc(1001 * sizeof(char));
	}
	
	strcpy(a[0], "1234512345123451234512345");
	strcpy(a[1], "543215432154321543215432154321");
	strcpy(a[2], "0");
	strcpy(a[3], "1234512345123451234512345");
	strcpy(a[4], "1234512345123451234512344");
	strcpy(a[5], "12");
	strcpy(a[6], "265252859812191058636308480000000");
	strcpy(a[7], "265252859812191058636308480000000");
	strcpy(a[8], "5432154321543215432154321");
	strcpy(a[9], "3");
	strcpy(a[10], "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
	strcpy(a[11], "1230231922161117176931558813276752514640713895736833715766118029160058800614672948775360067838593459582429649254051804908512884180898236823585082482065348331234959350355845017413023320111360666922624728239756880416434478315693675013413090757208690376793296658810662941824493488451726505303712916005346747908623702673480919353936813105736620402352744776903840477883651100322409301983488363802930540482487909763484098253940728685132044408863734754271212592471778643949486688511721051561970432780747454823776808464180697103083861812184348565522740195796682622205511845512080552010310050255801589349645928001133745474220715013683413907542779063759833876101354235184245096670042160720629411581502371248008430447184842098610320580417992206662247328722122088513643683907670360209162653670641130936997002170500675501374723998766005827579300723253474890612250135171889174899079911291512399773872178519018229989376");
	// strcpy(a[12], "1000");
	char *result1;
	int index1;

	result1 = intal_add(a[0], a[1]);
	if(!result1) {
		printf("Test intal_add FAILED.\n");
	} else {
		if(0 == strcmp(result1, "543216666666666666666666666666")) {
			printf("Generic Case : Test intal_add PASSED\n");
		} else {
			printf("Generic Case : Test intal_add FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "543216666666666666666666666666");
		}
		free(result1);
	}

	result1 = intal_add("9999", "9999");
	if(!result1) {
		printf("Test intal_add FAILED.\n");
	} else {
		if(0 == strcmp(result1, "19998")) {
			printf("New digit : Test intal_add PASSED\n");
		} else {
			printf("New digit : Test intal_add FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "19998");
		}
		free(result1);
	}

	result1 = intal_add("13", "8");
	if(!result1) {
		printf("Test intal_add FAILED.\n");
	} else {
		if(0 == strcmp(result1, "21")) {
			printf("Carry without : Test intal_add PASSED\n");
		} else {
			printf("Carry without : Test intal_add FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "21");
		}
		free(result1);
	}

	result1 = intal_add("897", "8");
	if(!result1) {
		printf("Test intal_add FAILED.\n");
	} else {
		if(0 == strcmp(result1, "905")) {
			printf("Losing carry Last digit : Test intal_add PASSED\n");
		} else {
			printf("Losing carry Last digit : Test intal_add FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "905");
		}
		free(result1);
	}

	result1 = intal_add("2346", "0");
	if(!result1) {
		printf("Test intal_add FAILED.\n");
	} else {
		if(0 == strcmp(result1, "2346")) {
			printf("Zero + number : Test intal_add PASSED\n");
		} else {
			printf("Zero + number : Test intal_add FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "2346");
		}
		free(result1);
	}

	result1 = intal_add("0", "0");
	if(!result1) {
		printf("Test intal_add FAILED.\n");
	} else {
		if(0 == strcmp(result1, "0")) {
			printf("Zero + Zero : Test intal_add PASSED\n");
		} else {
			printf("Zero + Zero : Test intal_add FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "0");
		}
		free(result1);
	}

	printf("\n");

	index1 = intal_compare(a[1], a[0]);
	if(1 == index1) {
		printf("First number greater : Test intal_compare PASSED\n");
	} else {
		printf("First number greater : Test intal_compare FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, -1);
	}

	index1 = intal_compare(a[0], a[1]);
	if(-1 == index1) {
		printf("Second number greater : Test intal_compare PASSED\n");
	} else {
		printf("Second number greater : Test intal_compare FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, -1);
	}

	index1 = intal_compare(a[0], a[3]);
	if(0 == index1) {
		printf("Equal numbers : Test intal_compare PASSED\n");
	} else {
		printf("Equal numbers : Test intal_compare FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 0);
	}

	printf("\n");

	result1 = intal_diff(a[0], a[1]);
	if(!result1) {
		printf("Test intal_diff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "543214197641976419764197641976")) {
			printf("Original Test : Test intal_diff PASSED\n");
		} else {
			printf("Test intal_diff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "543214197641976419764197641976");
		}
		free(result1);
	}

	result1 = intal_diff(a[1], a[0]);
	if(!result1) {
		printf("Test intal_diff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "543214197641976419764197641976")) {
			printf("Changed Order : Test intal_diff PASSED\n");
		} else {
			printf("Changed Order : Test intal_diff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "543214197641976419764197641976");
		}
		free(result1);
	}

	result1 = intal_diff("3", "1000");
	if(!result1) {
		printf("Test intal_diff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "997")) {
			printf("Losing a digit abs(3 - 1000) : Test intal_diff PASSED\n");
		} else {
			printf("Losing a digit abs(3 - 1000) : Test intal_diff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "997");
		}
		free(result1);
	}

	//Losing multiple digits
	result1 = intal_diff("1000", "999");
	if(!result1) {
		printf("Test intal_diff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1")) {
			printf("Losing Multiple Digits (1000-999) : Test intal_diff PASSED\n");
		} else {
			printf("Losing Multiple Digits (1000-999) : Test intal_diff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1");
		}
		free(result1);
	}

	//Equal numbers
	result1 = intal_diff("845672", "845672");
	if(!result1) {
		printf("Test intal_diff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "0")) {
			printf("Equal Numbers : Test intal_diff PASSED\n");
		} else {
			printf("Equal Numbers : Test intal_diff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "0");
		}
		free(result1);
	}

	printf("\n");

	result1 = intal_multiply(a[8], a[5]);
	if(!result1) {
		printf("Test intal_multiply FAILED.\n");
	} else {
		if(0 == strcmp(result1, "65185851858518585185851852")) {
			printf("Generic Case : Test intal_multiply PASSED\n");
		} else {
			printf("Generic Case : Test intal_multiply FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "65185851858518585185851852");
		}
		free(result1);
	}


	//Zero mult
	result1 = intal_multiply("0", "696969");
	if(!result1) {
		printf("Test intal_multiply FAILED.\n");
	} else {
		if(0 == strcmp(result1, "0")) {
			printf("Multiply by 0 : Test intal_multiply PASSED\n");
		} else {
			printf("Multiply by 0 : Test intal_multiply FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "0");
		}
		free(result1);
	}

	//Squaring
	result1 = intal_multiply("999", "999");
	if(!result1) {
		printf("Test intal_multiply FAILED.\n");
	} else {
		if(0 == strcmp(result1, "998001")) {
			printf("Squaring a number : Test intal_multiply PASSED\n");
		} else {
			printf("Squaring a number : Test intal_multiply FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "998001");
		}
		free(result1);
	}

	// Multiple zeros in one number
	result1 = intal_multiply("897649235", "10001010");
	if(!result1) {
		printf("Test intal_multiply FAILED.\n");
	} else {
		if(0 == strcmp(result1, "8977398975727350")) {
			printf("Many zeros in a number : Test intal_multiply PASSED\n");
		} else {
			printf("Many zeros in a number : Test intal_multiply FAILED.\nYour answer:     %s\nExpected answer: %s\n", result1, "8977398975727350");
		}
		free(result1);
	}

		result1 = intal_multiply("18446744073709551616", "18446744073709551616");
	if(!result1) {
		printf("Test intal_multiply FAILED.\n");
	} else {
		if(0 == strcmp(result1, "340282366920938463463374607431768211456")) {
			printf("2 ^ 64 squared : Test intal_multiply PASSED\n");
		} else {
			printf("2 ^ 64 squared : Test intal_multiply FAILED.\nYour answer:     %s\nExpected answer: %s\n", result1, "340282366920938463463374607431768211456");
		}
		free(result1);
	}

	result1 = intal_multiply("4294967296", "4294967296");
	if(!result1) {
		printf("Test intal_multiply FAILED.\n");
	} else {
		if(0 == strcmp(result1, "18446744073709551616")) {
			printf("Squaring a Small number : Test intal_multiply PASSED\n");
		} else {
			printf("Squaring a Small number : Test intal_multiply FAILED.\nYour answer:     %s\nExpected answer: %s\n", result1, "18446744073709551616");
		}
		free(result1);
	}

	result1 = intal_multiply("1", "1");
	if(!result1) {
		printf("Test intal_multiply FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1")) {
			printf("1 x 1 : Test intal_multiply PASSED\n");
		} else {
			printf("1 x 1 : Test intal_multiply FAILED.\nYour answer:     %s\nExpected answer: %s\n", result1, "1");
		}
		free(result1);
	}

	result1 = intal_multiply("3433683820292512484657849089281", "3433683820292512484657849089281");
	if(!result1) {
		printf("Test intal_multiply FAILED.\n");
	} else {
		if(0 == strcmp(result1, "11790184577738583171520872861412518665678211592275841109096961")) {
			printf("3 ^ 64 squared : Test intal_multiply PASSED\n");
		} else {
			printf("3 ^ 64 squared : Test intal_multiply FAILED.\nYour answer:     %s\nExpected answer: %s\n", result1, "11790184577738583171520872861412518665678211592275841109096961");
		}
		free(result1);
	}

	printf("\n");

	

	result1 = intal_mod(a[3], a[4]);
	if(!result1) {
		printf("Test intal_mod FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1")) {
			printf("Single Subtraction : Test intal_mod PASSED\n");
		} else {
			printf("Single Subtraction : Test intal_mod FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1");
		}
		free(result1);
	}

	result1 = intal_mod("978", "5");
	if(!result1) {
		printf("Test intal_mod FAILED.\n");
	} else {
		if(0 == strcmp(result1, "3")) {
			printf("Multiple Subtractions : Test intal_mod PASSED\n");
		} else {
			printf("Multiple Subtractions : Test intal_mod FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "3");
		}
		free(result1);
	}

	result1 = intal_mod(a[0], a[5]);
	if(!result1) {
		printf("Test intal_mod FAILED.\n");
	} else {
		if(0 == strcmp(result1, "9")) {
			printf("Several Subtractions : Test intal_mod PASSED\n");
		} else {
			printf("Several Subtractions : Test intal_mod FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "9");
		}
		free(result1);
	}

	result1 = intal_mod("23176523", "23176523");
	if(!result1) {
		printf("Test intal_mod FAILED.\n");
	} else {
		if(0 == strcmp(result1, "0")) {
			printf("Equal Numbers : Test intal_mod PASSED\n");
		} else {
			printf("Equal Numbers : Test intal_mod FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "0");
		}
		free(result1);
	}

	result1 = intal_mod("23", "231");
	if(!result1) {
		printf("Test intal_mod FAILED.\n");
	} else {
		if(0 == strcmp(result1, "23")) {
			printf("First number smaller : Test intal_mod PASSED\n");
		} else {
			printf("First number smaller : Test intal_mod FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "23");
		}
		free(result1);
	}

	result1 = intal_mod("0", "235235");
	if(!result1) {
		printf("Test intal_mod FAILED.\n");
	} else {
		if(0 == strcmp(result1, "0")) {
			printf("0 mod number : Test intal_mod PASSED\n");
		} else {
			printf("0 mod number : Test intal_mod FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "0");
		}
		free(result1);
	}

	result1 = intal_mod("1943805738985792340875902378590238745890237589023759023759087238490570293845790894572089345702983470289345789475298347908243705928752890570934827590824375908274059872309458720398745902874890234575290872349087259082347585", "1");
	if(!result1) {
		printf("Test intal_mod FAILED.\n");
	} else {
		if(0 == strcmp(result1, "0")) {
			printf("Large number mod 1 : Test intal_mod PASSED\n");
		} else {
			printf("Large number mod 1 : Test intal_mod FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "0");
		}
		free(result1);
	}


	printf("\nNot sure about 0^0, whether we need to handle it or not\nHence not included here\n");

	result1 = intal_pow(a[5], 3);
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1728")) {
			printf("Regular Case : Test intal_pow PASSED\n");
		} else {
			printf("Regular Case : Test intal_pow FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1728");
		}
		free(result1);
	}

	result1 = intal_pow("10", 999);
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, a[10])) {
			printf("10 ^ 999 Digit Limit : Test intal_pow PASSED\n");
		} else {
			printf("10 ^ 999 Digit Limit : Test intal_pow FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, a[10]);
		}
		free(result1);
	}

	result1 = intal_pow("2", 3000);
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, a[11])) {
			printf("2 ^ 3000 Worst case scenario : Test intal_pow PASSED\n");
		} else {
			printf("2 ^ 3000 Worst case scenario : Test intal_pow FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, a[11]);
		}
		free(result1);
	}

	result1 = intal_pow("8723467823964238947623694823764923", 0);
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1")) {
			printf("Large Number ^ 0 : Test intal_pow PASSED\n");
		} else {
			printf("Large Number ^ 0 : Test intal_pow FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1");
		}
		free(result1);
	}

	result1 = intal_pow("8723467823964238947623694823764923", 3);
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, "663846225993878236590565240604356687447916771116535229243713805189057299645488558997487454878332598467")) {
			printf("Large Number ^ 3 : Test intal_pow PASSED\n");
		} else {
			printf("Large Number ^ 3 : Test intal_pow FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "663846225993878236590565240604356687447916771116535229243713805189057299645488558997487454878332598467");
		}
		free(result1);
	}


	printf("\n");

	
	result1 = intal_gcd(a[0], a[5]);
	if(!result1) {
		printf("Test intal_gcd FAILED.\n");
	} else {
		if(0 == strcmp(result1, "3")) {
			printf("Large number and 12 : Test intal_gcd PASSED\n");
		} else {
			printf("Large number and 12 : Test intal_gcd FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "3");
		}
		free(result1);
	}
	
	result1 = intal_gcd(a[5], a[0]);
	if(!result1) {
		printf("Test intal_gcd FAILED.\n");
	} else {
		if(0 == strcmp(result1, "3")) {
			printf("12 and Large number : Test intal_gcd PASSED\n");
		} else {
			printf("12 and Large number : Test intal_gcd FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "3");
		}
		free(result1);
	}

	result1 = intal_gcd("0", "0");
	if(!result1) {
		printf("Test intal_gcd FAILED.\n");
	} else {
		if(0 == strcmp(result1, "0")) {
			printf("Zero and zero : Test intal_gcd PASSED\n");
		} else {
			printf("Zero and zero : Test intal_gcd FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "0");
		}
		free(result1);
	}

	result1 = intal_gcd("23478962348976", "23478962348976");
	if(!result1) {
		printf("Test intal_gcd FAILED.\n");
	} else {
		if(0 == strcmp(result1, "23478962348976")) {
			printf("Equal Large numbers : Test intal_gcd PASSED\n");
		} else {
			printf("Equal Large numbers : Test intal_gcd FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "23478962348976");
		}
		free(result1);
	}

	result1 = intal_gcd("0", "23478962348976");
	if(!result1) {
		printf("Test intal_gcd FAILED.\n");
	} else {
		if(0 == strcmp(result1, "23478962348976")) {
			printf("Zero in the first position : Test intal_gcd PASSED\n");
		} else {
			printf("Zero in the first position : Test intal_gcd FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "23478962348976");
		}
		free(result1);
	}



	printf("\n");

	result1 = intal_fibonacci(3);
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "2")) {
			printf("Small number : Test intal_fibonacci PASSED\n");
		} else {
			printf("Small number : Test intal_fibonacci FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "2");
		}
		free(result1);
	}

	result1 = intal_fibonacci(1000);
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "43466557686937456435688527675040625802564660517371780402481729089536555417949051890403879840079255169295922593080322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875")) {
			printf("Large number : Test intal_fibonacci PASSED\n");
		} else {
			printf("Large number : Test intal_fibonacci FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "43466557686937456435688527675040625802564660517371780402481729089536555417949051890403879840079255169295922593080322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875");
		}
		free(result1);
	}

	result1 = intal_fibonacci(0);
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "0")) {
			printf("Base case n = 0 : Test intal_fibonacci PASSED\n");
		} else {
			printf("Base case n = 0 : Test intal_fibonacci FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "0");
		}
		free(result1);
	}

	result1 = intal_fibonacci(1);
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1")) {
			printf("Base case n = 1 : Test intal_fibonacci PASSED\n");
		} else {
			printf("Base case n = 1 : Test intal_fibonacci FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1");
		}
		free(result1);
	}

	printf("\n");

	result1 = intal_factorial(30);
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, a[6])) {
			printf("Intermediate number : Test intal_factorial PASSED\n");
		} else {
			printf("Intermediate number : Test intal_factorial FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, a[6]);
		}
		free(result1);
	}

	result1 = intal_factorial(0);
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1")) {
			printf("Base Case with 0 : Test intal_factorial PASSED\n");
		} else {
			printf("Base Case with 0 : Test intal_factorial FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1");
		}
		free(result1);
	}

	result1 = intal_factorial(1);
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1")) {
			printf("Base Case with 1 : Test intal_factorial PASSED\n");
		} else {
			printf("Base Case with 1 : Test intal_factorial FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1");
		}
		free(result1);
	}

	result1 = intal_factorial(100);
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000")) {
			printf("Large number : Test intal_factorial PASSED\n");
		} else {
			printf("Large number : Test intal_factorial FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000");
		}
		free(result1);
	}

	printf("\n");

	result1 = intal_bincoeff(10, 8);
	if(!result1) {
		printf("Test intal_bincoeff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "45")) {
			printf("10C8 : Test intal_bincoeff PASSED\n");
		} else {
			printf("10C8 : Test intal_bincoeff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "45");
		}
		free(result1);
	}

	result1 = intal_bincoeff(10, 1);
	if(!result1) {
		printf("Test intal_bincoeff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "10")) {
			printf("10C1 : Test intal_bincoeff PASSED\n");
		} else {
			printf("10C1 : Test intal_bincoeff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "10");
		}
		free(result1);
	}

	result1 = intal_bincoeff(1000, 900);
	if(!result1) {
		printf("Test intal_bincoeff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "63850511926305130236698511142022274281262900693853331776286816221524376994750901948920974351797699894319420811933446197797592213357065053890")) {
			printf("1000C900 : Test intal_bincoeff PASSED\n");
		} else {
			printf("1000C900 : Test intal_bincoeff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "63850511926305130236698511142022274281262900693853331776286816221524376994750901948920974351797699894319420811933446197797592213357065053890");
		}
		free(result1);
	}

	printf("\n");
	// char newTestCase[6][30] = {
	// 	"4", "5", "6", "9", "4", "9"
	// };
	
	int newLen = 6;
	char **newTestCase = (char **)malloc(sizeof(char *) * newLen);
	for (int i = 0; i < newLen; i++)
	{
		newTestCase[i] = (char *)malloc(sizeof(char) * 100);
	}
	strcpy(newTestCase[0], "4");
	strcpy(newTestCase[1], "5");
	strcpy(newTestCase[2], "6");
	strcpy(newTestCase[3], "9");
	strcpy(newTestCase[4], "4");
	strcpy(newTestCase[5], "9");
	

	index1 = intal_max(a, n);
	if(10 == index1) {
		printf("Given Test : Test intal_max PASSED\n");
	} else {
		printf("Given Test : Test intal_max FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 10);
	}

	index1 = intal_max(newTestCase, 6);
	if(3 == index1) {
		printf("First occurrence with repeated max : Test intal_max PASSED\n");
	} else {
		printf("First occurrence with repeated max : Test intal_max FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 3);
	}

	printf("\n");

	index1 = intal_min(a, n);
	if(2 == index1) {
		printf("Test intal_min PASSED\n");
	} else {
		printf("Test intal_min FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 2);
	}

	index1 = intal_min(newTestCase, 6);
	if(0 == index1) {
		printf("First occurence with repeated min : Test intal_min PASSED\n");
	} else {
		printf("First occurence with repeated min : Test intal_min FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 0);
	}

	printf("\n");

	index1 = intal_search(a, n, a[7]);
	if(6 == index1) {
		printf("Test intal_search PASSED\n");
	} else {
		printf("Test intal_search FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 6);
	}

	index1 = intal_search(newTestCase, 6, "82379469238746892376423894689237648923674");
	if(-1 == index1) {
		printf("Element not in array : Test intal_search PASSED\n");
	} else {
		printf("Element not in array : Test intal_search FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, -1);
	}

	printf("\n");

	result1 = coin_row_problem(a, n);
	if(!result1) {
		printf("Test coin_row_problem FAILED.\n");
	} else {
		if(0 == strcmp("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000265796081911012046846190578820987", result1)) {
			printf("Given test case : Test coin_row_problem PASSED\n");
		} else {
			printf("Given test case : Test coin_row_problem FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000265796081911012046846190578820987");
		}
		free(result1);
	}

	result1 = coin_row_problem(newTestCase, 6);
	if(!result1) {
		printf("Test coin_row_problem FAILED.\n");
	} else {
		if(0 == strcmp("23", result1)) {
			printf("Just another test case : Test coin_row_problem PASSED\n");
		} else {
			printf("Just another test case : Test coin_row_problem FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "23");
		}
		free(result1);
	}

	printf("\n");
	
	intal_sort(a, n);
	printf("\nTest intal_sort PASSED only if the following sequence of %d intals are sorted in nondecreasing order.\n", n);
	for (int i = 0; i < n; i++) {
		printf("%s\n", a[i]);
	}

	intal_sort(newTestCase, 6);
	printf("\nTest intal_sort PASSED only if the following sequence of %d intals are sorted in nondecreasing order.\n", n);
	for (int i = 0; i < newLen; i++) {
		printf("%s\n", newTestCase[i]);
	}

	printf("\n");



	index1 = intal_binsearch(a, n, "3");
	if(1 == index1) {
		printf("Test intal_binsearch and probably intal_sort PASSED\n");
	} else {
		printf("Test intal_binsearch and probably intal_sort FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 1);
	}

	index1 = intal_binsearch(newTestCase, 6, "4");
	if(0 == index1) {
		printf("Lowest index with multiple occurrences : Test intal_binsearch and probably intal_sort PASSED\n");
	} else {
		printf("Lowest index with multiple occurrences : Test intal_binsearch and probably intal_sort FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 0);
	}

	index1 = intal_binsearch(newTestCase, 6, "9");
	if(4 == index1) {
		printf("Lowest index with multiple occurrences 2 : Test intal_binsearch and probably intal_sort PASSED\n");
	} else {
		printf("Lowest index with multiple occurrences 2 : Test intal_binsearch and probably intal_sort FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 4);
	}

	printf("\n");

	for (int i = 0; i < newLen; i++)
	{
		free(newTestCase[i]);
	}
	free(newTestCase);
	
	// Don't forget to free all the memory that is dynamically allocated.
	for(int i = 0; i < n; i++) {
		free(a[i]);
	}
	free(a);
	return 0;
}
