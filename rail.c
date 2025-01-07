#include <stdlib.h>

#pragma warning(disable:4996)
#include "rail.h"
#include <stdio.h>
#include <string.h>


void initRail(const char* mot1, const char* mot2, Rail* r) {
	if (strcmp(mot1, mot2) < 0) {
		strcpy(r->recto, mot1);
		strcpy(r->recto, mot2);
		inverserRail(&r);
	}
	if (strcmp(mot1, mot2) > 0) {
		strcpy(r->recto, mot2);
		strcpy(r->recto, mot1);
		inverserRail(&r);
	}
	return;
}


void inverserRail(Rail* r){
	for (int i = 0; i < TAILLE_RAIL; ++i) {
		for (int j = TAILLE_RAIL; j > 0; --j) {
			r->verso[i] = r->recto[j];
		}
	}
	printf(r);
}