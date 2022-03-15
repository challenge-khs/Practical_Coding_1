#include <stdio.h>

typedef unsigned int t_rgba;

#define fromRGBA(r, g, b, a) (((r)&0xff)<<24|((g)&0xff)<<16|((b)&0xff)<<8|((a)&0xff))
#define F_NUM_1_255 (1.0f/255.0f)

t_rgba mul_float(t_rgba c1, t_rgba c2)
{
	float r1, g1, b1, a1;
	float r2, g2, b2, a2;
	int   ir, ig, ib, ia;

	r1 = (float) ((c1 >> 24)       ) * F_NUM_1_255;
	g1 = (float) ((c1 >> 16) & 0xff) * F_NUM_1_255;
	b1 = (float) ((c1 >>  8) & 0xff) * F_NUM_1_255;
	a1 = (float) ((c1      ) & 0xff) * F_NUM_1_255;

	r2 = (float) ((c2 >> 24)       ) * F_NUM_1_255;
	g2 = (float) ((c2 >> 16) & 0xff) * F_NUM_1_255;
	b2 = (float) ((c2 >>  8) & 0xff) * F_NUM_1_255;
	a2 = (float) ((c2      ) & 0xff) * F_NUM_1_255;

	ir = (int) ((r1 * r2) * 255.0f);
	ig = (int) ((g1 * g2) * 255.0f);
	ib = (int) ((b1 * b2) * 255.0f);
	ia = (int) ((a1 * a2) * 255.0f);

	return fromRGBA(ir, ig, ib, ia);
}

t_rgba mul_int(t_rgba c1, t_rgba c2)
{
	unsigned int r1, g1, b1, a1;
	unsigned int r2, g2, b2, a2;
	unsigned int r, g, b, a;

	r1 = (c1 >> 24)       ; r2 = (c2 >> 24);
	g1 = (c1 >> 16) & 0xff; g2 = (c2 >> 16) & 0xff;
	b1 = (c1 >>  8) & 0xff; b2 = (c2 >>  8) & 0xff;
	a1 = (c1      ) & 0xff; a2 = (c2      ) & 0xff;
	
	r = (r1 * r2) / 255;
	g = (g1 * g2) / 255;
	b = (b1 * b2) / 255;
	a = (a1 * a2) / 255;

	return fromRGBA(r, g, b, a);
}

int main()
{
	int red, green, blue, alpha;
	t_rgba rgba_1, rgba_2, rgba_3;

	// input value must be in 0~255 : 0.0~1.0
	// rgba_1 [rrrrrrrr][gggggggg][bbbbbbbb][aaaaaaaa]
	printf("Input 4 values with 0~255 ");
	scanf("%d %d %d %d", &red, &green, &blue, &alpha);
	rgba_1 = fromRGBA(red, green, blue, alpha);
	printf("%d %d %d %d : %u 0x%08x\n", red, green, blue, alpha, rgba_1, rgba_1);

	rgba_2 = mul_float(rgba_1, rgba_1);
	printf("%u 0x%08x\n", rgba_2, rgba_2);
	
	rgba_3 = mul_int(rgba_1, rgba_1);
	printf("%u 0x%08x\n", rgba_3, rgba_3);

}

