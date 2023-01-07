#include"animazione.h"

extern int anim_load(const char* filename, struct animation* anim) {
	FILE* f = fopen(filename,"rb");

	if (f == NULL)
		return 0;

	uint16_t len;
	int conta = 0;
	size_t elementiletti;
	while (fread(&len, sizeof(uint16_t), 1, f) != 0) {
		conta++;
		uint8_t* values = malloc(len * sizeof(uint8_t));
		elementiletti=fread(values, sizeof(uint8_t), len, f);
		if (elementiletti != len) {
			return 0;
		}
	}
	

	fclose(f);

	f = fopen(filename, "rb");
	anim->num = conta;
	anim->elems = malloc(conta * sizeof(struct elem));

	for (int i = 0; i < conta; ++i)
	{
		fread(&len, sizeof(uint16_t), 1, f);
		struct elem* e = malloc(sizeof(struct elem));
		e->len = len;
		e->values= malloc(len * sizeof(uint8_t));

		fread(e->values, sizeof(uint8_t), e->len, f);
		anim->elems[i] = *e;
	}

	return 1;

}


int main()
{
	struct animation* a = malloc(sizeof(struct animation));

	if (anim_load("C:\\TEMP\\anim3.bin", a)==0)
	{
		printf("ERRORE");
		return -1;
	}

	printf("%i", a->num);

	for (int i = 0; i < a->num; ++i)
	{
		printf("Elementi %i\n", a->elems[i].len);
		for (int j = 0; j < a->elems[i].len; ++j)
		{
			printf("\t%i\n", a->elems[i].values[j]);
		}
	}
}