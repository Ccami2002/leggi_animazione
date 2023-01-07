#include"animazione.h"

extern int anim_load(const char* filename, struct animation* anim) {
	FILE* f = fopen(filename,"rb");

	if (f == NULL)
		return 0;

	uint16_t len;
	int conta = 0;
	size_t elementiletti;
	while (fread(&len, sizeof(uint16_t), 1, f) != EOF) {
		conta++;
		uint8_t* values = malloc(len * sizeof(uint8_t));
		elementiletti=fread(values, sizeof(uint8_t), len, f);
		if (elementiletti != len) {
			return 0;
		}
	}
	

	fclose(f);

	FILE* f = fopen(filename, "rb");
	anim->num = conta;
	anim->elems = malloc(conta * sizeof(struct elem));


	while (fread(&len, sizeof(uint16_t), 1, f) != EOF) {
		struct elem* e = malloc(sizeof(struct elem));
		e->len = len;
		e->values= malloc(len * sizeof(uint8_t));

		fread(e->values, sizeof(uint16_t), e->len, f);
		
	}






	return 1;

}
