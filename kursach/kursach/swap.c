#include "Header.h"
#include <string.h>

void swap(struct stab* i1, struct stab* i2) {
	struct stab temp;
	strcpy(temp.mark, i1->mark);
	temp.Rin = i1->Rin;
	temp.KPD = i1->KPD;
	temp.Kst = i1->Kst;
	temp.Ksp = i1->Ksp;

	strcpy(i1->mark, i2->mark);
	i1->Rin = i2->Rin;
	i1->KPD = i2->KPD;
	i1->Kst = i2->Kst;
	i1->Ksp = i2->Ksp;

	strcpy(i2->mark, temp.mark);
	i2->Rin = temp.Rin;
	i2->KPD = temp.KPD;
	i2->Kst = temp.Kst;
	i2->Ksp = temp.Ksp;
}
