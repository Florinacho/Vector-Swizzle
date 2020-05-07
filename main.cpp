#include <ctime>
#include <stdio.h>
#include <assert.h>
#include <algorithm>

#define DEFINE_GLSL_VECTOR_TYPES
#include "Vector.h"

int main() {
	vec2 a, b, c;
	float k0, k1, k2;

	assert(sizeof(bvec2) == 2 * sizeof(bool));
	assert(sizeof(ivec2) == 2 * sizeof(signed int));
	assert(sizeof(uvec2) == 2 * sizeof(unsigned int));
	assert(sizeof(vec2) == 2 * sizeof(float));
	assert(sizeof(dvec2) == 2 * sizeof(double));

	assert(a.x == 0.0f);
	assert(a.y == 0.0f);

	k0 = a.xx.x;
	a.xx.x = k0;
	k0 = a.xx.y;
	a.xx.y = k0;

	k0 = a.xy.x;
	a.xy.x = k0;
	k0 = a.xy.y;
	a.xy.y = k0;

	k0 = a.yx.x;
	a.yx.x = k0;
	k0 = a.yx.y;
	a.yx.y = k0;

	k0 = a.yy.x;
	a.xx.x = k0;
	k0 = a.yy.y;
	a.xx.y = k0;

	a.x = 1.0f;
	assert(a.x == 1.0f);

	a.y = 2.0f;
	assert(a.y == 2.0f);

	a.xy = a.yx;
	assert(a.x == 2.0f);
	assert(a.y == 1.0f);

	a.x = a.y;
	assert(a.x == a.y);

	a.xy = 3.0f;
	assert(a.x == 3.0f);
	assert(a.y == 3.0f);

	a.xy = vec2(1.0f, 2.0f);
	assert(a.x == 1.0f);
	assert(a.y == 2.0f);

	b = vec2(a.xy);
	assert(b.x == 1.0f);
	assert(b.y == 2.0f);

	c = vec2(a.yx);
	assert(c.x == 2.0f);
	assert(c.y == 1.0f);

	a = vec2(a.xx);
	assert(a.x == 1.0f);
	assert(a.y == 1.0f);

	b = vec2(b.yy);
	assert(b.x == 2.0f);
	assert(b.y == 2.0f);
	
	a = 3;
	assert(a.x == 3 && a.y == 3);
	(a = 2) = 1;
//	assert(a.x == 1 && a.y == 1);
	
	a = 3;
	assert(a.x == 3 && a.y == 3);
	(a.xy = 2) = 1;
	assert(a.x == 1 && a.y == 1); // 1, 1
	
	a == 3.0f;
	a == b;
	a == a.xy;
	
	a != 3.0f;
	a != b;
	a != a.xy;
	
	a + 2.0f;
	a + b;
	a + a.xy;
	
	a - 2.0f;
	a - b;
	a - a.xy;
	
	a = 1;
	b = 0;
	assert(a.x == 1 && a.y == 1);
	assert(b.x == 0 && b.y == 0);
	b = +a;
	assert(a.x == 1 && a.y == 1);
	assert(b.x == 1 && b.y == 1);
	b = -a;
	assert(a.x == 1 && a.y == 1);
	assert(b.x == -1 && b.y == -1);
	
	a * 2.0f;
	a * b;
	a * a.xy;
	
	a / 2.0f;
	a / b;
	a / a.xy;
	
	a += 3.0f;
	a += b;
	a += a.xy;
	
	a -= 3.0f;
	a -= b;
	a -= a.xy;
	
	a *= 3.0f;
	a *= b;
	a *= a.xy;
	
	a /= 3.0f;
	a /= b;
	a /= a.xy;
	
	a = 4;
	assert(a.x == 4 && a.y == 4);
	a.xy += 2;
	assert(a.x == 6 && a.y == 6);
	
	a = 1;
	b = 0;
	assert(a.x == 1 && a.y == 1);
	assert(b.x == 0 && b.y == 0);
	
	b = ++a;
	assert(a.x == 2 && a.y == 2);
	assert(b.x == 2 && b.y == 2);
	
	a = 1;
	b = 0;
	assert(a.x == 1 && a.y == 1);
	assert(b.x == 0 && b.y == 0);
	
	b = a++;
	assert(a.x == 2 && a.y == 2);
	assert(b.x == 1 && b.y == 1);
	
	b = a.xy++;
	assert(a.x == 3 && a.y == 3);
	assert(b.x == 2 && b.y == 2);
	
	b = ++a.xy;
	assert(a.x == 4 && a.y == 4);
	assert(b.x == 4 && b.y == 4);
	
	a = 2;
	b = 0;
	assert(a.x == 2 && a.y == 2);
	assert(b.x == 0 && b.y == 0);
	
	b = --a;
	assert(a.x == 1 && a.y == 1);
	assert(b.x == 1 && b.y == 1);
	
	a = 2;
	b = 0;
	assert(a.x == 2 && a.y == 2);
	assert(b.x == 0 && b.y == 0);
	
	b = a--;
	assert(a.x == 1 && a.y == 1);
	assert(b.x == 2 && b.y == 2);
	
	b = a.xy--;
	assert(a.x == 0 && a.y == 0);
	assert(b.x == 1 && b.y == 1);
	
	b = --a.xy;
	assert(a.x == -1 && a.y == -1);
	assert(b.x == -1 && b.y == -1);


	assert(sizeof(bvec3) == 3 * sizeof(bool));
	assert(sizeof(ivec3) == 3 * sizeof(signed int));
	assert(sizeof(uvec3) == 3 * sizeof(unsigned int));
	assert(sizeof(vec3 ) == 3 * sizeof(float));
	assert(sizeof(dvec3) == 3 * sizeof(double));
	
	assert(sizeof(bvec4) == 4 * sizeof(bool));
	assert(sizeof(ivec4) == 4 * sizeof(signed int));
	assert(sizeof(uvec4) == 4 * sizeof(unsigned int));
	assert(sizeof(vec4 ) == 4 * sizeof(float));
	assert(sizeof(dvec4) == 4 * sizeof(double));

	vec4 v0;
	vec3 v1 = v0.xyz;
	vec2 v2a = v0.xy;
	vec2 v2b = v1.xy;
	vec2 v2c = v0.xxy.yx.x;

	printf("Sanity check passed!\n");

	return 0;
}
