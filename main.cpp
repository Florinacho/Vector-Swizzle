#include <stdio.h>

#include "Vector.h"
#include "Test.h"

void test_vec2_size(void *state) {
	Vector2<float> vec;
	assert_int_equal(sizeof(vec.xx), 2 * sizeof(float));
	assert_int_equal(sizeof(vec.xy), 2 * sizeof(float));
	assert_int_equal(sizeof(vec.yx), 2 * sizeof(float));
	assert_int_equal(sizeof(vec.yy), 2 * sizeof(float));
	assert_int_equal(sizeof(vec   ), 2 * sizeof(float));

	assert_int_equal(sizeof(bvec2), 2 * sizeof(char));
	assert_int_equal(sizeof(ivec2), 2 * sizeof(int));
	assert_int_equal(sizeof(uvec2), 2 * sizeof(unsigned int));
	assert_int_equal(sizeof( vec2), 2 * sizeof(float));
	assert_int_equal(sizeof(dvec2), 2 * sizeof(double));
}

void test_vec2(void *state) {
	vec2 tmp0;

	assert_float_equal(tmp0.x, 0.0f);
	assert_float_equal(tmp0.y, 0.0f);

	vec2 tmp1(1.0f, 2.0f);
	assert_float_equal(tmp1.x, 1.0f);
	assert_float_equal(tmp1.y, 2.0f);

	vec2 tmp2(tmp1);
	assert_float_equal(tmp1.x, 1.0f);
	assert_float_equal(tmp1.y, 2.0f);
}

void test_vec2_assign(void *state) {
	vec2 vec;

	vec = 3.0f;
	assert_float_equal(vec.x, 3.0f);
	assert_float_equal(vec.y, 3.0f);

	vec = 4;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 4.0f);

	vec = vec2(1.0f, 2.0f);
	assert_float_equal(vec.x, 1.0f);
	assert_float_equal(vec.y, 2.0f);

	vec = vec2(3.0f, 4.0f);
	assert_float_equal(vec.x, 3.0f);
	assert_float_equal(vec.y, 4.0f);

	vec = vec2(5.0f, 6.0f).yx;
	assert_float_equal(vec.x, 6.0f);
	assert_float_equal(vec.y, 5.0f);
}

void test_vec2_unary(void *state) {
	const vec2 src(12.34f, 56.78f);
	vec2 dst;

	dst = +src;
	assert_float_equal(dst.x, src.x);
	assert_float_equal(dst.y, src.y);

	dst = -src;
	assert_float_equal(dst.x, -src.x);
	assert_float_equal(dst.y, -src.y);
}

void test_vec2_binary(void *state) {
	const vec2 lvalue(1.0f, 2.0f);
	const vec2 rvalue(3.0f, 4.0f);

	vec2 vec;

	vec = lvalue + rvalue;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 6.0f);

	vec = lvalue - rvalue;
	assert_float_equal(vec.x, -2.0f);
	assert_float_equal(vec.y, -2.0f);

	vec = lvalue * rvalue;
	assert_float_equal(vec.x, 3.0f);
	assert_float_equal(vec.y, 8.0f);

	vec = rvalue / lvalue;
	assert_float_equal(vec.x, 3.0f);
	assert_float_equal(vec.y, 2.0f);

	vec = lvalue + rvalue.xy;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 6.0f);

	vec = lvalue - rvalue.xy;
	assert_float_equal(vec.x, -2.0f);
	assert_float_equal(vec.y, -2.0f);

	vec = lvalue * rvalue.xy;
	assert_float_equal(vec.x, 3.0f);
	assert_float_equal(vec.y, 8.0f);

	vec = rvalue / lvalue.xy;
	assert_float_equal(vec.x, 3.0f);
	assert_float_equal(vec.y, 2.0f);
}

void test_vec2_combined(void *state) {
	const vec2 lvalue(1.0f, 2.0f);
	const vec2 rvalue(3.0f, 4.0f);

	vec2 vec;

	vec = lvalue;
	vec += rvalue;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 6.0f);

	vec = lvalue;
	vec -= rvalue;
	assert_float_equal(vec.x, -2.0f);
	assert_float_equal(vec.y, -2.0f);

	vec = lvalue;
	vec *= rvalue;
	assert_float_equal(vec.x, 3.0f);
	assert_float_equal(vec.y, 8.0f);

	vec = rvalue;
	vec /= lvalue;
	assert_float_equal(vec.x, 3.0f);
	assert_float_equal(vec.y, 2.0f);

	vec = lvalue;
	vec += rvalue.xy;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 6.0f);

	vec = lvalue;
	vec -= rvalue.xy;
	assert_float_equal(vec.x, -2.0f);
	assert_float_equal(vec.y, -2.0f);

	vec = lvalue;
	vec *= rvalue.xy;
	assert_float_equal(vec.x, 3.0f);
	assert_float_equal(vec.y, 8.0f);

	vec = rvalue;
	vec /= lvalue.xy;
	assert_float_equal(vec.x, 3.0f);
	assert_float_equal(vec.y, 2.0f);
}

void test_vec2_increment(void *state) {
	const vec2 src(1.0f, 2.0f);
	vec2 tmp0, tmp1;

	tmp0 = src;
	tmp1 = tmp0++;
	assert_float_equal(tmp0.x, src.x + 1.0f);
	assert_float_equal(tmp0.y, src.y + 1.0f);
	assert_float_equal(tmp1.x, src.x);
	assert_float_equal(tmp1.y, src.y);

	tmp0 = src;
	tmp1 = ++tmp0;
	assert_float_equal(tmp0.x, src.x + 1.0f);
	assert_float_equal(tmp0.y, src.y + 1.0f);
	assert_float_equal(tmp1.x, src.x + 1.0f);
	assert_float_equal(tmp1.y, src.y + 1.0f);

	tmp0 = src;
	tmp1 = ++tmp0 = vec2(5.0f, 6.0f);
	assert_float_equal(tmp0.x, 5.0f);
	assert_float_equal(tmp0.y, 6.0f);
	assert_float_equal(tmp1.x, 5.0f);
	assert_float_equal(tmp1.y, 6.0f);
}

void test_vec2_decrement(void *state) {
	const vec2 src(1.0f, 2.0f);
	vec2 tmp0, tmp1;

	tmp0 = src;
	tmp1 = tmp0--;
	assert_float_equal(tmp0.x, src.x - 1.0f);
	assert_float_equal(tmp0.y, src.y - 1.0f);
	assert_float_equal(tmp1.x, src.x);
	assert_float_equal(tmp1.y, src.y);

	tmp0 = src;
	tmp1 = --tmp0;
	assert_float_equal(tmp0.x, src.x - 1.0f);
	assert_float_equal(tmp0.y, src.y - 1.0f);
	assert_float_equal(tmp1.x, src.x - 1.0f);
	assert_float_equal(tmp1.y, src.y - 1.0f);

	tmp0 = src;
	tmp1 = --tmp0 = vec2(5.0f, 6.0f);
	assert_float_equal(tmp0.x, 5.0f);
	assert_float_equal(tmp0.y, 6.0f);
	assert_float_equal(tmp1.x, 5.0f);
	assert_float_equal(tmp1.y, 6.0f);
}

void test_vec2_equal(void *state) {
	const vec2 src(1.0f, 2.0f);
	vec2 vec;

	vec = src;
	assert_condition(vec == src);
	assert_condition(vec == src);

	vec = vec2(0.0f, 0.0f);
	assert_condition(vec != src);
	assert_condition(vec != src);
}

void test_vec2_index(void *state) {
	vec2 vec(1.0f, 5.0f);

	assert_float_equal(vec[0], vec.x);
	assert_float_equal(vec[1], vec.y);

	vec[0] = 2.0f;
	vec[1] = 3.0f;
	assert_float_equal(vec.x, 2.0f);
	assert_float_equal(vec.y, 3.0f);
}

void test_vec2_swizzle(void *state) {
	vec2 vec;

	vec = vec2(0.0f, 11.0f).xx;
	assert_float_equal(vec.x, 0.0f);
	assert_float_equal(vec.y, 0.0f);

	vec = vec2(22.0f, 33.0f).xy;
	assert_float_equal(vec.x, 22.0f);
	assert_float_equal(vec.y, 33.0f);

	vec = vec2(44.0f, 55.0f).yx;
	assert_float_equal(vec.x, 55.0f);
	assert_float_equal(vec.y, 44.0f);

	vec = vec2(0.0f, 11.0f).yy;
	assert_float_equal(vec.x, 11.0f);
	assert_float_equal(vec.y, 11.0f);
}

void test_vec2_swizzle_assign(void *state) {
	vec2 vec;

	vec = 5.0f;
	assert_float_equal(vec.x, 5.0f);
	assert_float_equal(vec.y, 5.0f);

	vec = vec2(1.0f, 2.0f);
	assert_float_equal(vec.x, 1.0f);
	assert_float_equal(vec.y, 2.0f);

	vec.xy = vec2(3.0f, 4.0f);
	assert_float_equal(vec.x, 3.0f);
	assert_float_equal(vec.y, 4.0f);

	vec.yx = vec2(5.0f, 6.0f);
	assert_float_equal(vec.x, 6.0f);
	assert_float_equal(vec.y, 5.0f);

	vec.xy = vec.yx;
	assert_float_equal(vec.x, 5.0f);
	assert_float_equal(vec.y, 6.0f);
}

void test_vec2_swizzle_unary(void *state) {
	const vec2 src(12.34f, 56.78f);
	vec2 dst;

	dst = +src.xy;
	assert_float_equal(dst.x, src.x);
	assert_float_equal(dst.y, src.y);

	dst = -src.xy;
	assert_float_equal(dst.x, -src.x);
	assert_float_equal(dst.y, -src.y);
}

void test_vec2_swizzle_binary(void *state) {
	const vec2 lvalue(1.0f, 2.0f);
	const vec2 rvalue(3.0f, 4.0f);

	vec2 vec;

	vec = lvalue.xy + rvalue.xy;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 6.0f);

	vec = lvalue.xy - rvalue.xy;
	assert_float_equal(vec.x, -2.0f);
	assert_float_equal(vec.y, -2.0f);

	vec = lvalue.xy * rvalue.xy;
	assert_float_equal(vec.x, 3.0f);
	assert_float_equal(vec.y, 8.0f);

	vec = rvalue.xy / lvalue.xy;
	assert_float_equal(vec.x, 3.0f);
	assert_float_equal(vec.y, 2.0f);

	vec = lvalue.xy + rvalue;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 6.0f);

	vec = lvalue.xy - rvalue;
	assert_float_equal(vec.x, -2.0f);
	assert_float_equal(vec.y, -2.0f);

	vec = lvalue.xy * rvalue;
	assert_float_equal(vec.x, 3.0f);
	assert_float_equal(vec.y, 8.0f);

	vec = rvalue.xy / lvalue;
	assert_float_equal(vec.x, 3.0f);
	assert_float_equal(vec.y, 2.0f);
}

void test_vec2_swizzle_combined(void *state) {
	const vec2 lvalue(1.0f, 2.0f);
	const vec2 rvalue(3.0f, 4.0f);

	vec2 vec;

	vec = lvalue;
	vec.xy += rvalue.xy;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 6.0f);

	vec = lvalue;
	vec.xy -= rvalue.xy;
	assert_float_equal(vec.x, -2.0f);
	assert_float_equal(vec.y, -2.0f);

	vec = lvalue;
	vec.xy *= rvalue.xy;
	assert_float_equal(vec.x, 3.0f);
	assert_float_equal(vec.y, 8.0f);

	vec = rvalue;
	vec.xy /= lvalue.xy;
	assert_float_equal(vec.x, 3.0f);
	assert_float_equal(vec.y, 2.0f);

	vec = lvalue;
	vec.xy += rvalue;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 6.0f);

	vec = lvalue;
	vec.xy -= rvalue;
	assert_float_equal(vec.x, -2.0f);
	assert_float_equal(vec.y, -2.0f);

	vec = lvalue;
	vec.xy *= rvalue;
	assert_float_equal(vec.x, 3.0f);
	assert_float_equal(vec.y, 8.0f);

	vec = rvalue;
	vec.xy /= lvalue;
	assert_float_equal(vec.x, 3.0f);
	assert_float_equal(vec.y, 2.0f);
}

void test_vec2_swizzle_increment(void *state) {
	const vec2 src(1.0f, 2.0f);
	vec2 tmp0, tmp1;

	tmp0 = src;
	tmp1 = tmp0.xy++;
	assert_float_equal(tmp0.x, src.x + 1.0f);
	assert_float_equal(tmp0.y, src.y + 1.0f);
	assert_float_equal(tmp1.x, src.x);
	assert_float_equal(tmp1.y, src.y);

	tmp0 = src;
	tmp1 = ++tmp0.xy;
	assert_float_equal(tmp0.x, src.x + 1.0f);
	assert_float_equal(tmp0.y, src.y + 1.0f);
	assert_float_equal(tmp1.x, src.x + 1.0f);
	assert_float_equal(tmp1.y, src.y + 1.0f);

	tmp0 = src;
	tmp1 = (++tmp0.xx = vec2(5.0f, 6.0f)) += vec2(0.0f, 0);
	assert_float_equal(tmp0.x, 6.0f);
	assert_float_equal(tmp0.y, 2.0f);
	assert_float_equal(tmp1.x, 6.0f);
	assert_float_equal(tmp1.y, 6.0f);

	tmp0 = src;
	tmp1 = tmp0.xx++;
	assert_float_equal(tmp0.x, src.x + 2.0f);
	assert_float_equal(tmp0.y, src.y);
	assert_float_equal(tmp1.x, src.x);
	assert_float_equal(tmp1.y, src.x);

	tmp0 = src;
	tmp1 = tmp0.yy++;
	assert_float_equal(tmp0.x, src.x);
	assert_float_equal(tmp0.y, src.y + 2.0f);
	assert_float_equal(tmp1.x, src.y);
	assert_float_equal(tmp1.y, src.y);

	tmp0 = src;
	tmp1 = tmp0.yx++;
	assert_float_equal(tmp0.x, src.x + 1.0f);
	assert_float_equal(tmp0.y, src.y + 1.0f);
	assert_float_equal(tmp1.x, src.y);
	assert_float_equal(tmp1.y, src.x);
}

void test_vec2_swizzle_decrement(void *state) {
	const vec2 src(1.0f, 2.0f);
	vec2 tmp0, tmp1;

	tmp0 = src;
	tmp1 = tmp0.xy--;
	assert_float_equal(tmp0.x, src.x - 1.0f);
	assert_float_equal(tmp0.y, src.y - 1.0f);
	assert_float_equal(tmp1.x, src.x);
	assert_float_equal(tmp1.y, src.y);

	tmp0 = src;
	tmp1 = --tmp0.xy;
	assert_float_equal(tmp0.x, src.x - 1.0f);
	assert_float_equal(tmp0.y, src.y - 1.0f);
	assert_float_equal(tmp1.x, src.x - 1.0f);
	assert_float_equal(tmp1.y, src.y - 1.0f);
}

void test_vec2_swizzle_equal(void *state) {
	const vec2 src(1.0f, 2.0f);
	vec2 vec;

	vec = src;
	assert_condition(vec.xy == src.xy);
	assert_condition(vec.xy == src);

	assert_condition(vec.xx == vec2(1.0f, 1.0f));

	vec = vec2(0.0f, 0.0f);
	assert_condition(vec.xy != src.xy);
	assert_condition(vec.xy != src);
}

void test_vec2_swizzle_index(void *state) {
	vec2 vec(1.0f, 5.0f);

	assert_float_equal(vec.xx[0], vec.x);
	assert_float_equal(vec.xx[1], vec.x);

	assert_float_equal(vec.xy[0], vec.x);
	assert_float_equal(vec.xy[1], vec.y);

	assert_float_equal(vec.yx[0], vec.y);
	assert_float_equal(vec.yx[1], vec.x);

	assert_float_equal(vec.yy[0], vec.y);
	assert_float_equal(vec.yy[1], vec.y);

	vec.xx[0] = 2.0f;
	vec.xx[1] = 3.0f;
	assert_float_equal(vec.x, 3.0f);
	assert_float_equal(vec.y, 5.0f);

	vec.xy[0] = 2.0f;
	vec.xy[1] = 3.0f;
	assert_float_equal(vec.x, 2.0f);
	assert_float_equal(vec.y, 3.0f);

	vec.yx[0] = 4.0f;
	vec.yx[1] = 5.0f;
	assert_float_equal(vec.x, 5.0f);
	assert_float_equal(vec.y, 4.0f);

	vec.yy[0] = 6.0f;
	vec.yy[1] = 7.0f;
	assert_float_equal(vec.x, 5.0f);
	assert_float_equal(vec.y, 7.0f);
}

void test_vec2_misc(void *state) {
	vec2 v0, v1;

	v0 = vec2(1.0f, 2.0f);

	float k = (++v0.xx + v0.yy++).x;
	assert_float_equal(k, 5.0f);

	assert_float_equal(v0.x, 3.0f);
	assert_float_equal(v0.y, 4.0f);

	(v0.xx += vec2(5.0f, 8.0f)) += vec2(1.0f, 2.0f);
	assert_float_equal(v0.x, 19.0f);
	assert_float_equal(v0.y, 4.0f);
}

void test_vec3_size(void *state) {
	Vector3<float> vec;

	assert_int_equal(sizeof(vec.xx), 2 * sizeof(float));
	assert_int_equal(sizeof(vec.xy), 2 * sizeof(float));
	assert_int_equal(sizeof(vec.yx), 2 * sizeof(float));
	assert_int_equal(sizeof(vec.yy), 2 * sizeof(float));

	assert_int_equal(sizeof(vec.xxx), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.xxy), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.xxz), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.xyx), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.xyy), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.xyz), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.xzx), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.xzy), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.xzz), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.yxx), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.yxy), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.yxz), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.yyx), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.yyy), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.yyz), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.yzx), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.yzy), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.yzz), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.zxx), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.zxy), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.zxz), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.zyx), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.zyy), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.zyz), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.zzx), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.zzy), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.zzz), 3 * sizeof(float));

	assert_int_equal(sizeof(vec    ), 3 * sizeof(float));

	assert_int_equal(sizeof(bvec3), 3 * sizeof(char));
	assert_int_equal(sizeof(ivec3), 3 * sizeof(int));
	assert_int_equal(sizeof(uvec3), 3 * sizeof(unsigned int));
	assert_int_equal(sizeof( vec3), 3 * sizeof(float));
	assert_int_equal(sizeof(dvec3), 3 * sizeof(double));
}

void test_vec3(void *state) {
	vec3 tmp0;

	assert_float_equal(tmp0.x, 0.0f);
	assert_float_equal(tmp0.y, 0.0f);
	assert_float_equal(tmp0.z, 0.0f);

	vec3 tmp1(1.0f, 2.0f, 3.0f);
	assert_float_equal(tmp1.x, 1.0f);
	assert_float_equal(tmp1.y, 2.0f);
	assert_float_equal(tmp1.z, 3.0f);

	vec3 tmp2(tmp1);
	assert_float_equal(tmp1.x, 1.0f);
	assert_float_equal(tmp1.y, 2.0f);
	assert_float_equal(tmp1.z, 3.0f);
}

void test_vec3_assign(void *state) {
	vec3 vec;

	vec = vec3(1.0f, 2.0f, 3.0f);
	assert_float_equal(vec.x, 1.0f);
	assert_float_equal(vec.y, 2.0f);
	assert_float_equal(vec.z, 3.0f);

	vec = vec3(4.0f, 5.0f, 6.0f);
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 5.0f);
	assert_float_equal(vec.z, 6.0f);

	vec = vec3(7.0f, 8.0f, 9.0f).zyx;
	assert_float_equal(vec.x, 9.0f);
	assert_float_equal(vec.y, 8.0f);
	assert_float_equal(vec.z, 7.0f);
}

void test_vec3_unary(void *state) {
	const vec3 src(12.34f, 56.78f, 9.0f);
	vec3 dst;

	dst = +src;
	assert_float_equal(dst.x, src.x);
	assert_float_equal(dst.y, src.y);
	assert_float_equal(dst.z, src.z);

	dst = -src;
	assert_float_equal(dst.x, -src.x);
	assert_float_equal(dst.y, -src.y);
	assert_float_equal(dst.z, -src.z);
}

void test_vec3_binary(void *state) {
	const vec3 lvalue(1.0f, 2.0f, 3.0f);
	const vec3 rvalue(4.0f, 5.0f, 6.0f);

	vec3 vec;

	vec = lvalue + rvalue;
	assert_float_equal(vec.x, 5.0f);
	assert_float_equal(vec.y, 7.0f);
	assert_float_equal(vec.z, 9.0f);

	vec = lvalue - rvalue;
	assert_float_equal(vec.x, -3.0f);
	assert_float_equal(vec.y, -3.0f);
	assert_float_equal(vec.z, -3.0f);

	vec = lvalue * rvalue;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 10.0f);
	assert_float_equal(vec.z, 18.0f);

	vec = rvalue / lvalue;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 2.5f);
	assert_float_equal(vec.z, 2.0f);

	vec = lvalue + rvalue.xyz;
	assert_float_equal(vec.x, 5.0f);
	assert_float_equal(vec.y, 7.0f);
	assert_float_equal(vec.z, 9.0f);

	vec = lvalue - rvalue.xyz;
	assert_float_equal(vec.x, -3.0f);
	assert_float_equal(vec.y, -3.0f);
	assert_float_equal(vec.z, -3.0f);

	vec = lvalue * rvalue.xyz;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 10.0f);
	assert_float_equal(vec.z, 18.0f);

	vec = rvalue / lvalue.xyz;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 2.5f);
	assert_float_equal(vec.z, 2.0f);
}

void test_vec3_combined(void *state) {
	const vec3 lvalue(1.0f, 2.0f, 3.0f);
	const vec3 rvalue(4.0f, 5.0f, 6.0f);

	vec3 vec;

	vec = lvalue;
	vec += rvalue;
	assert_float_equal(vec.x, 5.0f);
	assert_float_equal(vec.y, 7.0f);
	assert_float_equal(vec.z, 9.0f);

	vec = lvalue;
	vec -= rvalue;
	assert_float_equal(vec.x, -3.0f);
	assert_float_equal(vec.y, -3.0f);
	assert_float_equal(vec.z, -3.0f);

	vec = lvalue;
	vec *= rvalue;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 10.0f);
	assert_float_equal(vec.z, 18.0f);

	vec = rvalue;
	vec /= lvalue;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 2.5f);
	assert_float_equal(vec.z, 2.0f);

	vec = lvalue;
	vec += rvalue.xyz;
	assert_float_equal(vec.x, 5.0f);
	assert_float_equal(vec.y, 7.0f);
	assert_float_equal(vec.z, 9.0f);

	vec = lvalue;
	vec -= rvalue.xyz;
	assert_float_equal(vec.x, -3.0f);
	assert_float_equal(vec.y, -3.0f);
	assert_float_equal(vec.z, -3.0f);

	vec = lvalue;
	vec *= rvalue.xyz;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 10.0f);
	assert_float_equal(vec.z, 18.0f);

	vec = rvalue;
	vec /= lvalue.xyz;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 2.5f);
	assert_float_equal(vec.z, 2.0f);
}

void test_vec3_increment(void *state) {
	const vec3 src(1.0f, 2.0f, 3.0f);
	vec3 tmp0, tmp1;

	tmp0 = src;
	tmp1 = tmp0++;
	assert_float_equal(tmp0.x, src.x + 1.0f);
	assert_float_equal(tmp0.y, src.y + 1.0f);
	assert_float_equal(tmp0.z, src.z + 1.0f);
	assert_float_equal(tmp1.x, src.x);
	assert_float_equal(tmp1.y, src.y);
	assert_float_equal(tmp1.z, src.z);

	tmp0 = src;
	tmp1 = ++tmp0;
	assert_float_equal(tmp0.x, src.x + 1.0f);
	assert_float_equal(tmp0.y, src.y + 1.0f);
	assert_float_equal(tmp0.z, src.z + 1.0f);
	assert_float_equal(tmp1.x, src.x + 1.0f);
	assert_float_equal(tmp1.y, src.y + 1.0f);
	assert_float_equal(tmp1.z, src.z + 1.0f);
}

void test_vec3_decrement(void *state) {

	const vec3 src(1.0f, 2.0f, 3.0f);
	vec3 tmp0, tmp1;

	tmp0 = src;
	tmp1 = tmp0--;
	assert_float_equal(tmp0.x, src.x - 1.0f);
	assert_float_equal(tmp0.y, src.y - 1.0f);
	assert_float_equal(tmp0.z, src.z - 1.0f);
	assert_float_equal(tmp1.x, src.x);
	assert_float_equal(tmp1.y, src.y);
	assert_float_equal(tmp1.z, src.z);

	tmp0 = src;
	tmp1 = --tmp0;
	assert_float_equal(tmp0.x, src.x - 1.0f);
	assert_float_equal(tmp0.y, src.y - 1.0f);
	assert_float_equal(tmp0.z, src.z - 1.0f);
	assert_float_equal(tmp1.x, src.x - 1.0f);
	assert_float_equal(tmp1.y, src.y - 1.0f);
	assert_float_equal(tmp1.z, src.z - 1.0f);
}

void test_vec3_equal(void *state) {
	const vec3 src(1.0f, 2.0f, 3.0f);
	vec3 vec;

	vec = src;
	assert_condition(vec == src);
	assert_condition(vec == src);

	vec = vec3(0.0f, 0.0f, 0.0f);
	assert_condition(vec != src);
	assert_condition(vec != src);
}

void test_vec3_index(void *state) {
	vec3 vec(1.0f, 5.0f, 7.0f);

	assert_float_equal(vec[0], vec.x);
	assert_float_equal(vec[1], vec.y);
	assert_float_equal(vec[2], vec.z);

	vec[0] = 2.0f;
	vec[1] = 3.0f;
	vec[2] = 5.0f;
	assert_float_equal(vec.x, 2.0f);
	assert_float_equal(vec.y, 3.0f);
	assert_float_equal(vec.z, 5.0f);
}

void test_vec3_swizzle(void *state) {
	vec3 vec;

	vec = vec3(0.0f, 11.0f, 22.0f).xxx;
	assert_float_equal(vec.x, 0.0f);
	assert_float_equal(vec.y, 0.0f);
	assert_float_equal(vec.z, 0.0f);

	vec = vec3(33.0f, 44.0f, 55.0f).xyz;
	assert_float_equal(vec.x, 33.0f);
	assert_float_equal(vec.y, 44.0f);
	assert_float_equal(vec.z, 55.0f);

	vec = vec3(66.0f, 77.0f, 88.0f).zyx;
	assert_float_equal(vec.x, 88.0f);
	assert_float_equal(vec.y, 77.0f);
	assert_float_equal(vec.z, 66.0f);

	vec = vec3(0.0f, 11.0f, 22.0f).yyy;
	assert_float_equal(vec.x, 11.0f);
	assert_float_equal(vec.y, 11.0f);
	assert_float_equal(vec.z, 11.0f);
}

void test_vec3_swizzle_assign(void *state) {
	vec3 vec;

	vec = vec3(1.0f, 2.0f, 3.0f);
	assert_float_equal(vec.x, 1.0f);
	assert_float_equal(vec.y, 2.0f);
	assert_float_equal(vec.z, 3.0f);

	vec.xyz = vec3(4.0f, 5.0f, 6.0f);
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 5.0f);
	assert_float_equal(vec.z, 6.0f);

	vec.zyx = vec3(7.0f, 8.0f, 9.0f);
	assert_float_equal(vec.x, 9.0f);
	assert_float_equal(vec.y, 8.0f);
	assert_float_equal(vec.z, 7.0f);

	vec.xyz = vec.zyx;
	assert_float_equal(vec.x, 7.0f);
	assert_float_equal(vec.y, 8.0f);
	assert_float_equal(vec.z, 9.0f);
}

void test_vec3_swizzle_unary(void *state) {
	const vec3 src(12.34f, 56.78f, 9.0f);
	vec3 dst;

	dst = +src.xyz;
	assert_float_equal(dst.x, src.x);
	assert_float_equal(dst.y, src.y);
	assert_float_equal(dst.z, src.z);

	dst = -src.xyz;
	assert_float_equal(dst.x, -src.x);
	assert_float_equal(dst.y, -src.y);
	assert_float_equal(dst.z, -src.z);
}

void test_vec3_swizzle_binary(void *state) {
	const vec3 lvalue(1.0f, 2.0f, 3.0f);
	const vec3 rvalue(4.0f, 5.0f, 6.0f);

	vec3 vec;

	vec = lvalue.xyz + rvalue.xyz;
	assert_float_equal(vec.x, 5.0f);
	assert_float_equal(vec.y, 7.0f);
	assert_float_equal(vec.z, 9.0f);

	vec = lvalue.xyz - rvalue.xyz;
	assert_float_equal(vec.x, -3.0f);
	assert_float_equal(vec.y, -3.0f);
	assert_float_equal(vec.z, -3.0f);

	vec = lvalue.xyz * rvalue.xyz;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 10.0f);
	assert_float_equal(vec.z, 18.0f);

	vec = rvalue.xyz / lvalue.xyz;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 2.5f);
	assert_float_equal(vec.z, 2.0f);

	vec = lvalue.xyz + rvalue;
	assert_float_equal(vec.x, 5.0f);
	assert_float_equal(vec.y, 7.0f);
	assert_float_equal(vec.z, 9.0f);

	vec = lvalue.xyz - rvalue;
	assert_float_equal(vec.x, -3.0f);
	assert_float_equal(vec.y, -3.0f);
	assert_float_equal(vec.z, -3.0f);

	vec = lvalue.xyz * rvalue;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 10.0f);
	assert_float_equal(vec.z, 18.0f);

	vec = rvalue.xyz / lvalue;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 2.5f);
	assert_float_equal(vec.z, 2.0f);
}

void test_vec3_swizzle_combined(void *state) {
	const vec3 lvalue(1.0f, 2.0f, 3.0f);
	const vec3 rvalue(4.0f, 5.0f, 6.0f);

	vec3 vec;

	vec = lvalue;
	vec.xyz += rvalue.xyz;
	assert_float_equal(vec.x, 5.0f);
	assert_float_equal(vec.y, 7.0f);
	assert_float_equal(vec.z, 9.0f);

	vec = lvalue;
	vec.xyz -= rvalue.xyz;
	assert_float_equal(vec.x, -3.0f);
	assert_float_equal(vec.y, -3.0f);
	assert_float_equal(vec.z, -3.0f);

	vec = lvalue;
	vec.xyz *= rvalue.xyz;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 10.0f);
	assert_float_equal(vec.z, 18.0f);

	vec = rvalue;
	vec.xyz /= lvalue.xyz;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 2.5f);
	assert_float_equal(vec.z, 2.0f);

	vec = lvalue;
	vec.xyz += rvalue;
	assert_float_equal(vec.x, 5.0f);
	assert_float_equal(vec.y, 7.0f);
	assert_float_equal(vec.z, 9.0f);

	vec = lvalue;
	vec.xyz -= rvalue;
	assert_float_equal(vec.x, -3.0f);
	assert_float_equal(vec.y, -3.0f);
	assert_float_equal(vec.z, -3.0f);

	vec = lvalue;
	vec.xyz *= rvalue;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 10.0f);
	assert_float_equal(vec.z, 18.0f)

	vec = rvalue;
	vec.xyz /= lvalue;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 2.5f);
	assert_float_equal(vec.z, 2.0f);
}

void test_vec3_swizzle_increment(void *state) {
	const vec3 src(1.0f, 2.0f, 3.0f);
	vec3 tmp0, tmp1;

	tmp0 = src;
	tmp1 = tmp0.xyz++;
	assert_float_equal(tmp0.x, src.x + 1.0f);
	assert_float_equal(tmp0.y, src.y + 1.0f);
	assert_float_equal(tmp0.z, src.z + 1.0f);
	assert_float_equal(tmp1.x, src.x);
	assert_float_equal(tmp1.y, src.y);
	assert_float_equal(tmp1.z, src.z);

	tmp0 = src;
	tmp1 = ++tmp0.xyz;
	assert_float_equal(tmp0.x, src.x + 1.0f);
	assert_float_equal(tmp0.y, src.y + 1.0f);
	assert_float_equal(tmp0.z, src.z + 1.0f);
	assert_float_equal(tmp1.x, src.x + 1.0f);
	assert_float_equal(tmp1.y, src.y + 1.0f);
	assert_float_equal(tmp1.z, src.z + 1.0f);
}

void test_vec3_swizzle_decrement(void *state) {
	const vec3 src(1.0f, 2.0f, 3.0f);
	vec3 tmp0, tmp1;

	tmp0 = src;
	tmp1 = tmp0.xyz--;
	assert_float_equal(tmp0.x, src.x - 1.0f);
	assert_float_equal(tmp0.y, src.y - 1.0f);
	assert_float_equal(tmp0.z, src.z - 1.0f);
	assert_float_equal(tmp1.x, src.x);
	assert_float_equal(tmp1.y, src.y);
	assert_float_equal(tmp1.z, src.z);

	tmp0 = src;
	tmp1 = --tmp0.xyz;
	assert_float_equal(tmp0.x, src.x - 1.0f);
	assert_float_equal(tmp0.y, src.y - 1.0f);
	assert_float_equal(tmp0.z, src.z - 1.0f);
	assert_float_equal(tmp1.x, src.x - 1.0f);
	assert_float_equal(tmp1.y, src.y - 1.0f);
	assert_float_equal(tmp1.z, src.z - 1.0f);
}

void test_vec3_swizzle_equal(void *state) {
	const vec3 src(1.0f, 2.0f, 3.0f);
	vec3 vec;

	vec = src;
	assert_condition(vec.xyz == src.xyz);
	assert_condition(vec.xyz == src);

	vec = vec3(0.0f, 0.0f, 0.0f);
	assert_condition(vec.xyz != src.xyz);
	assert_condition(vec.xyz != src);
}

void test_vec3_swizzle_index(void *state) {
	vec3 vec(1.0f, 5.0f, 8.0f);

	assert_float_equal(vec.xxx[0], vec.x);
	assert_float_equal(vec.xxx[1], vec.x);
	assert_float_equal(vec.xxx[2], vec.x);

	assert_float_equal(vec.xyz[0], vec.x);
	assert_float_equal(vec.xyz[1], vec.y);
	assert_float_equal(vec.xyz[2], vec.z);

	assert_float_equal(vec.zyx[0], vec.z);
	assert_float_equal(vec.zyx[1], vec.y);
	assert_float_equal(vec.zyx[2], vec.x);

	assert_float_equal(vec.yyy[0], vec.y);
	assert_float_equal(vec.yyy[1], vec.y);
	assert_float_equal(vec.yyy[2], vec.y);

	vec.xxx[0] = 2.0f;
	vec.xxx[1] = 3.0f;
	vec.xxx[2] = 4.0f;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 5.0f);
	assert_float_equal(vec.z, 8.0f);

	vec.xyz[0] = 2.0f;
	vec.xyz[1] = 3.0f;
	vec.xyz[2] = 4.0f;
	assert_float_equal(vec.x, 2.0f);
	assert_float_equal(vec.y, 3.0f);
	assert_float_equal(vec.z, 4.0f);

	vec.zyx[0] = 4.0f;
	vec.zyx[1] = 5.0f;
	vec.zyx[2] = 6.0f;
	assert_float_equal(vec.x, 6.0f);
	assert_float_equal(vec.y, 5.0f);
	assert_float_equal(vec.z, 4.0f);

	vec.yyy[0] = 6.0f;
	vec.yyy[1] = 7.0f;
	vec.yyy[2] = 8.0f;
	assert_float_equal(vec.x, 6.0f);
	assert_float_equal(vec.y, 8.0f);
	assert_float_equal(vec.z, 4.0f);
}

void test_vec3_misc(void *state) {
}

void test_vec4_size(void *state) {
	Vector4<float> vec;

	assert_int_equal(sizeof(vec.xx), 2 * sizeof(float));
	assert_int_equal(sizeof(vec.xy), 2 * sizeof(float));
	assert_int_equal(sizeof(vec.yx), 2 * sizeof(float));
	assert_int_equal(sizeof(vec.yy), 2 * sizeof(float));

	assert_int_equal(sizeof(vec.xxx), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.xxy), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.xxz), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.xyx), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.xyy), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.xyz), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.xzx), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.xzy), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.xzz), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.yxx), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.yxy), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.yxz), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.yyx), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.yyy), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.yyz), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.yzx), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.yzy), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.yzz), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.zxx), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.zxy), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.zxz), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.zyx), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.zyy), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.zyz), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.zzx), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.zzy), 3 * sizeof(float));
	assert_int_equal(sizeof(vec.zzz), 3 * sizeof(float));

	assert_int_equal(sizeof(vec.xxxx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xxxy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xxxz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xxxw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xxyx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xxyy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xxyz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xxyw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xxzx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xxzy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xxzz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xxzw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xxwx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xxwy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xxwz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xxww), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xyxx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xyxy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xyxz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xyxw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xyyx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xyyy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xyyz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xyyw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xyzx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xyzy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xyzz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xyzw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xywx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xywy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xywz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xyww), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xzxx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xzxy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xzxz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xzxw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xzyx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xzyy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xzyz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xzyw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xzzx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xzzy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xzzz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xzzw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xzwx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xzwy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xzwz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xzww), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xwxx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xwxy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xwxz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xwxw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xwyx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xwyy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xwyz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xwyw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xwzx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xwzy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xwzz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xwzw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xwwx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xwwy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xwwz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.xwww), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yxxx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yxxy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yxxz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yxxw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yxyx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yxyy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yxyz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yxyw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yxzx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yxzy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yxzz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yxzw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yxwx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yxwy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yxwz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yxww), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yyxx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yyxy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yyxz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yyxw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yyyx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yyyy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yyyz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yyyw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yyzx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yyzy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yyzz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yyzw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yywx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yywy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yywz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yyww), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yzxx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yzxy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yzxz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yzxw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yzyx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yzyy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yzyz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yzyw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yzzx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yzzy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yzzz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yzzw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yzwx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yzwy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yzwz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.yzww), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.ywxx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.ywxy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.ywxz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.ywxw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.ywyx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.ywyy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.ywyz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.ywyw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.ywzx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.ywzy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.ywzz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.ywzw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.ywwx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.ywwy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.ywwz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.ywww), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zxxx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zxxy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zxxz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zxxw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zxyx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zxyy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zxyz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zxyw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zxzx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zxzy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zxzz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zxzw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zxwx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zxwy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zxwz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zxww), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zyxx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zyxy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zyxz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zyxw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zyyx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zyyy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zyyz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zyyw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zyzx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zyzy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zyzz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zyzw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zywx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zywy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zywz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zyww), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zzxx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zzxy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zzxz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zzxw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zzyx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zzyy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zzyz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zzyw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zzzx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zzzy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zzzz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zzzw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zzwx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zzwy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zzwz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zzww), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zwxx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zwxy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zwxz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zwxw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zwyx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zwyy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zwyz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zwyw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zwzx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zwzy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zwzz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zwzw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zwwx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zwwy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zwwz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.zwww), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wxxx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wxxy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wxxz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wxxw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wxyx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wxyy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wxyz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wxyw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wxzx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wxzy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wxzz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wxzw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wxwx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wxwy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wxwz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wxww), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wyxx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wyxy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wyxz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wyxw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wyyx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wyyy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wyyz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wyyw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wyzx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wyzy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wyzz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wyzw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wywx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wywy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wywz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wyww), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wzxx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wzxy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wzxz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wzxw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wzyx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wzyy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wzyz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wzyw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wzzx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wzzy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wzzz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wzzw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wzwx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wzwy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wzwz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wzww), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wwxx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wwxy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wwxz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wwxw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wwyx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wwyy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wwyz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wwyw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wwzx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wwzy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wwzz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wwzw), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wwwx), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wwwy), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wwwz), 4 * sizeof(float));
	assert_int_equal(sizeof(vec.wwww), 4 * sizeof(float));


	assert_int_equal(sizeof(vec    ), 4 * sizeof(float));

	assert_int_equal(sizeof(bvec4), 4 * sizeof(char));
	assert_int_equal(sizeof(ivec4), 4 * sizeof(int));
	assert_int_equal(sizeof(uvec4), 4 * sizeof(unsigned int));
	assert_int_equal(sizeof( vec4), 4 * sizeof(float));
	assert_int_equal(sizeof(dvec4), 4 * sizeof(double));
}

void test_vec4(void *state) {
	vec4 tmp0;

	assert_float_equal(tmp0.x, 0.0f);
	assert_float_equal(tmp0.y, 0.0f);
	assert_float_equal(tmp0.z, 0.0f);
	assert_float_equal(tmp0.w, 0.0f);

	vec4 tmp1(1.0f, 2.0f, 3.0f, 4.0f);
	assert_float_equal(tmp1.x, 1.0f);
	assert_float_equal(tmp1.y, 2.0f);
	assert_float_equal(tmp1.z, 3.0f);
	assert_float_equal(tmp1.w, 4.0f);

	vec4 tmp2(tmp1);
	assert_float_equal(tmp1.x, 1.0f);
	assert_float_equal(tmp1.y, 2.0f);
	assert_float_equal(tmp1.z, 3.0f);
	assert_float_equal(tmp1.w, 4.0f);
}

void test_vec4_assign(void *state) {
	vec4 vec;

	vec = vec4(1.0f, 2.0f, 3.0f, 4.0f);
	assert_float_equal(vec.x, 1.0f);
	assert_float_equal(vec.y, 2.0f);
	assert_float_equal(vec.z, 3.0f);
	assert_float_equal(vec.w, 4.0f);

	vec = vec4(4.0f, 5.0f, 6.0f, 7.0f);
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 5.0f);
	assert_float_equal(vec.z, 6.0f);
	assert_float_equal(vec.w, 7.0f);

	vec = vec4(7.0f, 8.0f, 9.0f, 10.0f).wzyx;
	assert_float_equal(vec.x, 10.0f);
	assert_float_equal(vec.y, 9.0f);
	assert_float_equal(vec.z, 8.0f);
	assert_float_equal(vec.w, 7.0f);
}

void test_vec4_unary(void *state) {
	const vec4 src(12.34f, 56.78f, 9.0f, 8.0f);
	vec4 dst;

	dst = +src;
	assert_float_equal(dst.x, src.x);
	assert_float_equal(dst.y, src.y);
	assert_float_equal(dst.z, src.z);
	assert_float_equal(dst.w, src.w);

	dst = -src;
	assert_float_equal(dst.x, -src.x);
	assert_float_equal(dst.y, -src.y);
	assert_float_equal(dst.z, -src.z);
	assert_float_equal(dst.w, -src.w);
}

void test_vec4_binary(void *state) {
	const vec4 lvalue(1.0f, 2.0f, 3.0f, 0.5f);
	const vec4 rvalue(4.0f, 5.0f, 6.0f, 8.0f);

	vec4 vec;

	vec = lvalue + rvalue;
	assert_float_equal(vec.x, 5.0f);
	assert_float_equal(vec.y, 7.0f);
	assert_float_equal(vec.z, 9.0f);
	assert_float_equal(vec.w, 8.5f);

	vec = lvalue - rvalue;
	assert_float_equal(vec.x, -3.0f);
	assert_float_equal(vec.y, -3.0f);
	assert_float_equal(vec.z, -3.0f);
	assert_float_equal(vec.w, -7.5f);

	vec = lvalue * rvalue;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 10.0f);
	assert_float_equal(vec.z, 18.0f);
	assert_float_equal(vec.w, 4.0f);

	vec = rvalue / lvalue;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 2.5f);
	assert_float_equal(vec.z, 2.0f);
	assert_float_equal(vec.w, 16.0f);

	vec = lvalue + rvalue.xyzw;
	assert_float_equal(vec.x, 5.0f);
	assert_float_equal(vec.y, 7.0f);
	assert_float_equal(vec.z, 9.0f);
	assert_float_equal(vec.w, 8.5f);

	vec = lvalue - rvalue.xyzw;
	assert_float_equal(vec.x, -3.0f);
	assert_float_equal(vec.y, -3.0f);
	assert_float_equal(vec.z, -3.0f);
	assert_float_equal(vec.w, -7.5f);

	vec = lvalue * rvalue.xyzw;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 10.0f);
	assert_float_equal(vec.z, 18.0f);
	assert_float_equal(vec.w, 4.0f);

	vec = rvalue / lvalue.xyzw;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 2.5f);
	assert_float_equal(vec.z, 2.0f);
	assert_float_equal(vec.w, 16.0f);
}

void test_vec4_combined(void *state) {
	const vec4 lvalue(1.0f, 2.0f, 3.0f, 0.2f);
	const vec4 rvalue(4.0f, 5.0f, 6.0f, 8.0f);

	vec4 vec;

	vec = lvalue;
	vec += rvalue;
	assert_float_equal(vec.x, 5.0f);
	assert_float_equal(vec.y, 7.0f);
	assert_float_equal(vec.z, 9.0f);
	assert_float_equal(vec.w, 8.2f);

	vec = lvalue;
	vec -= rvalue;
	assert_float_equal(vec.x, -3.0f);
	assert_float_equal(vec.y, -3.0f);
	assert_float_equal(vec.z, -3.0f);
	assert_float_equal(vec.w, -7.8f);

	vec = lvalue;
	vec *= rvalue;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 10.0f);
	assert_float_equal(vec.z, 18.0f);
	assert_float_equal(vec.w, 1.6f);

	vec = rvalue;
	vec /= lvalue;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 2.5f);
	assert_float_equal(vec.z, 2.0f);
	assert_float_equal(vec.w, 40.0f);

	vec = lvalue;
	vec += rvalue.xyzw;
	assert_float_equal(vec.x, 5.0f);
	assert_float_equal(vec.y, 7.0f);
	assert_float_equal(vec.z, 9.0f);
	assert_float_equal(vec.w, 8.2f);

	vec = lvalue;
	vec -= rvalue.xyzw;
	assert_float_equal(vec.x, -3.0f);
	assert_float_equal(vec.y, -3.0f);
	assert_float_equal(vec.z, -3.0f);
	assert_float_equal(vec.w, -7.8f);

	vec = lvalue;
	vec *= rvalue.xyzw;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 10.0f);
	assert_float_equal(vec.z, 18.0f);
	assert_float_equal(vec.w, 1.6f);

	vec = rvalue;
	vec /= lvalue.xyzw;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 2.5f);
	assert_float_equal(vec.z, 2.0f);
	assert_float_equal(vec.w, 40.0f);
}

void test_vec4_increment(void *state) {
	const vec4 src(1.0f, 2.0f, 3.0f, 4.0f);
	vec4 tmp0, tmp1;

	tmp0 = src;
	tmp1 = tmp0++;
	assert_float_equal(tmp0.x, src.x + 1.0f);
	assert_float_equal(tmp0.y, src.y + 1.0f);
	assert_float_equal(tmp0.z, src.z + 1.0f);
	assert_float_equal(tmp0.w, src.w + 1.0f);
	assert_float_equal(tmp1.x, src.x);
	assert_float_equal(tmp1.y, src.y);
	assert_float_equal(tmp1.z, src.z);
	assert_float_equal(tmp1.w, src.w);

	tmp0 = src;
	tmp1 = ++tmp0;
	assert_float_equal(tmp0.x, src.x + 1.0f);
	assert_float_equal(tmp0.y, src.y + 1.0f);
	assert_float_equal(tmp0.z, src.z + 1.0f);
	assert_float_equal(tmp0.w, src.w + 1.0f);
	assert_float_equal(tmp1.x, src.x + 1.0f);
	assert_float_equal(tmp1.y, src.y + 1.0f);
	assert_float_equal(tmp1.z, src.z + 1.0f);
	assert_float_equal(tmp1.w, src.w + 1.0f);
}

void test_vec4_decrement(void *state) {
	const vec4 src(1.0f, 2.0f, 3.0f, 4.0f);
	vec4 tmp0, tmp1;

	tmp0 = src;
	tmp1 = tmp0--;
	assert_float_equal(tmp0.x, src.x - 1.0f);
	assert_float_equal(tmp0.y, src.y - 1.0f);
	assert_float_equal(tmp0.z, src.z - 1.0f);
	assert_float_equal(tmp0.w, src.w - 1.0f);
	assert_float_equal(tmp1.x, src.x);
	assert_float_equal(tmp1.y, src.y);
	assert_float_equal(tmp1.z, src.z);
	assert_float_equal(tmp1.w, src.w);

	tmp0 = src;
	tmp1 = --tmp0;
	assert_float_equal(tmp0.x, src.x - 1.0f);
	assert_float_equal(tmp0.y, src.y - 1.0f);
	assert_float_equal(tmp0.z, src.z - 1.0f);
	assert_float_equal(tmp0.w, src.w - 1.0f);
	assert_float_equal(tmp1.x, src.x - 1.0f);
	assert_float_equal(tmp1.y, src.y - 1.0f);
	assert_float_equal(tmp1.z, src.z - 1.0f);
	assert_float_equal(tmp1.w, src.w - 1.0f);
}

void test_vec4_equal(void *state) {
	const vec4 src(1.0f, 2.0f, 3.0f, 4.0f);
	vec4 vec;

	vec = src;
	assert_condition(vec == src);
	assert_condition(vec == src);

	vec = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	assert_condition(vec != src);
	assert_condition(vec != src);
}

void test_vec4_index(void *state) {
	vec4 vec(1.0f, 5.0f, 7.0f, 9.0f);

	assert_float_equal(vec[0], vec.x);
	assert_float_equal(vec[1], vec.y);
	assert_float_equal(vec[2], vec.z);
	assert_float_equal(vec[3], vec.w);

	vec[0] = 2.0f;
	vec[1] = 3.0f;
	vec[2] = 5.0f;
	vec[3] = 7.0f;
	assert_float_equal(vec.x, 2.0f);
	assert_float_equal(vec.y, 3.0f);
	assert_float_equal(vec.z, 5.0f);
	assert_float_equal(vec.w, 7.0f);
}

void test_vec4_swizzle(void *state) {
	vec4 vec;

	vec = vec4(0.0f, 11.0f, 22.0f, 33.0f).xxxx;
	assert_float_equal(vec.x, 0.0f);
	assert_float_equal(vec.y, 0.0f);
	assert_float_equal(vec.z, 0.0f);
	assert_float_equal(vec.w, 0.0f);

	vec = vec4(33.0f, 44.0f, 55.0f, 66.0f).xyzw;
	assert_float_equal(vec.x, 33.0f);
	assert_float_equal(vec.y, 44.0f);
	assert_float_equal(vec.z, 55.0f);
	assert_float_equal(vec.w, 66.0f);

	vec = vec4(66.0f, 77.0f, 88.0f, 99.0f).wzyx;
	assert_float_equal(vec.x, 99.0f);
	assert_float_equal(vec.y, 88.0f);
	assert_float_equal(vec.z, 77.0f);
	assert_float_equal(vec.w, 66.0f);

	vec = vec4(0.0f, 11.0f, 22.0f, 33.0f).yyyy;
	assert_float_equal(vec.x, 11.0f);
	assert_float_equal(vec.y, 11.0f);
	assert_float_equal(vec.z, 11.0f);
	assert_float_equal(vec.w, 11.0f);
}

void test_vec4_swizzle_assign(void *state) {
	vec4 vec;

	vec = vec4(1.0f, 2.0f, 3.0f, 4.0f);
	assert_float_equal(vec.x, 1.0f);
	assert_float_equal(vec.y, 2.0f);
	assert_float_equal(vec.z, 3.0f);
	assert_float_equal(vec.w, 4.0f);

	vec.xyzw = vec4(4.0f, 5.0f, 6.0f, 7.0f);
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 5.0f);
	assert_float_equal(vec.z, 6.0f);
	assert_float_equal(vec.w, 7.0f);

	vec.wzyx = vec4(7.0f, 8.0f, 9.0f, 10.0f);
	assert_float_equal(vec.x, 10.0f);
	assert_float_equal(vec.y, 9.0f);
	assert_float_equal(vec.z, 8.0f);
	assert_float_equal(vec.w, 7.0f);

	vec.xyzw = vec.wzyx;
	assert_float_equal(vec.x, 7.0f);
	assert_float_equal(vec.y, 8.0f);
	assert_float_equal(vec.z, 9.0f);
	assert_float_equal(vec.w, 10.0f);

	vec.xyzw = vec.wxyz;
	assert_float_equal(vec.x, 10.0f);
	assert_float_equal(vec.y, 7.0f);
	assert_float_equal(vec.z, 8.0f);
	assert_float_equal(vec.w, 9.0f);
}

void test_vec4_swizzle_unary(void *state) {
	const vec4 src(12.34f, 56.78f, 9.0f, 10.0f);
	vec4 dst;

	dst = +src.xyzw;
	assert_float_equal(dst.x, src.x);
	assert_float_equal(dst.y, src.y);
	assert_float_equal(dst.z, src.z);
	assert_float_equal(dst.w, src.w);

	dst = -src.xyzw;
	assert_float_equal(dst.x, -src.x);
	assert_float_equal(dst.y, -src.y);
	assert_float_equal(dst.z, -src.z);
	assert_float_equal(dst.w, -src.w);
}

void test_vec4_swizzle_binary(void *state) {
	const vec4 lvalue(1.0f, 2.0f, 3.0f, 0.5f);
	const vec4 rvalue(4.0f, 5.0f, 6.0f, 8.0f);

	vec4 vec;

	vec = lvalue.xyzw + rvalue.xyzw;
	assert_float_equal(vec.x, 5.0f);
	assert_float_equal(vec.y, 7.0f);
	assert_float_equal(vec.z, 9.0f);
	assert_float_equal(vec.w, 8.5f);

	vec = lvalue.xyzw - rvalue.xyzw;
	assert_float_equal(vec.x, -3.0f);
	assert_float_equal(vec.y, -3.0f);
	assert_float_equal(vec.z, -3.0f);
	assert_float_equal(vec.w, -7.5f);

	vec = lvalue.xyzw * rvalue.xyzw;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 10.0f);
	assert_float_equal(vec.z, 18.0f);
	assert_float_equal(vec.w, 4.0f);

	vec = rvalue.xyzw / lvalue.xyzw;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 2.5f);
	assert_float_equal(vec.z, 2.0f);
	assert_float_equal(vec.w, 16.0f);

	vec = lvalue.xyzw + rvalue;
	assert_float_equal(vec.x, 5.0f);
	assert_float_equal(vec.y, 7.0f);
	assert_float_equal(vec.z, 9.0f);
	assert_float_equal(vec.w, 8.5f);

	vec = lvalue.xyzw - rvalue;
	assert_float_equal(vec.x, -3.0f);
	assert_float_equal(vec.y, -3.0f);
	assert_float_equal(vec.z, -3.0f);
	assert_float_equal(vec.w, -7.5f);

	vec = lvalue.xyzw * rvalue;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 10.0f);
	assert_float_equal(vec.z, 18.0f);
	assert_float_equal(vec.w, 4.0f);

	vec = rvalue.xyzw / lvalue;
	assert_float_equal(vec.x, 4.0f);
	assert_float_equal(vec.y, 2.5f);
	assert_float_equal(vec.z, 2.0f);
	assert_float_equal(vec.w, 16.0f);
}

void test_vec4_swizzle_combined(void *state) {
	const vec4 lvalue(1.0f, 2.0f, 3.0f, 4.0f);
	const vec4 rvalue(5.0f, 7.0f, 9.0f, 8.0f);

	vec4 vec;

	vec = lvalue;
	vec.xyzw += rvalue.xyzw;
	assert_float_equal(vec.x, 6.0f);
	assert_float_equal(vec.y, 9.0f);
	assert_float_equal(vec.z, 12.0f);
	assert_float_equal(vec.w, 12.0f);

	vec = lvalue;
	vec.xyzw -= rvalue.xyzw;
	assert_float_equal(vec.x, -4.0f);
	assert_float_equal(vec.y, -5.0f);
	assert_float_equal(vec.z, -6.0f);
	assert_float_equal(vec.w, -4.0f);

	vec = lvalue;
	vec.xyzw *= rvalue.xyzw;
	assert_float_equal(vec.x, 5.0f);
	assert_float_equal(vec.y, 14.0f);
	assert_float_equal(vec.z, 27.0f);
	assert_float_equal(vec.w, 32.0f);

	vec = rvalue;
	vec.xyzw /= lvalue.xyzw;
	assert_float_equal(vec.x, 5.0f);
	assert_float_equal(vec.y, 3.5f);
	assert_float_equal(vec.z, 3.0f);
	assert_float_equal(vec.w, 2.0f);

	vec = lvalue;
	vec.xyzw += rvalue;
	assert_float_equal(vec.x, 6.0f);
	assert_float_equal(vec.y, 9.0f);
	assert_float_equal(vec.z, 12.0f);
	assert_float_equal(vec.w, 12.0f);

	vec = lvalue;
	vec.xyzw -= rvalue;
	assert_float_equal(vec.x, -4.0f);
	assert_float_equal(vec.y, -5.0f);
	assert_float_equal(vec.z, -6.0f);
	assert_float_equal(vec.w, -4.0f);

	vec = lvalue;
	vec.xyzw *= rvalue;
	assert_float_equal(vec.x, 5.0f);
	assert_float_equal(vec.y, 14.0f);
	assert_float_equal(vec.z, 27.0f);
	assert_float_equal(vec.w, 32.0f);

	vec = rvalue;
	vec.xyzw /= lvalue;
	assert_float_equal(vec.x, 5.0f);
	assert_float_equal(vec.y, 3.5f);
	assert_float_equal(vec.z, 3.0f);
	assert_float_equal(vec.w, 2.0f);
}

void test_vec4_swizzle_increment(void *state) {
	const vec4 src(1.0f, 2.0f, 3.0f, 4.0f);
	vec4 tmp0, tmp1;

	tmp0 = src;
	tmp1 = tmp0.xyzw++;
	assert_float_equal(tmp0.x, src.x + 1.0f);
	assert_float_equal(tmp0.y, src.y + 1.0f);
	assert_float_equal(tmp0.z, src.z + 1.0f);
	assert_float_equal(tmp0.w, src.w + 1.0f);
	assert_float_equal(tmp1.x, src.x);
	assert_float_equal(tmp1.y, src.y);
	assert_float_equal(tmp1.z, src.z);
	assert_float_equal(tmp1.w, src.w);

	tmp0 = src;
	tmp1 = ++tmp0.xyzw;
	assert_float_equal(tmp0.x, src.x + 1.0f);
	assert_float_equal(tmp0.y, src.y + 1.0f);
	assert_float_equal(tmp0.z, src.z + 1.0f);
	assert_float_equal(tmp0.w, src.w + 1.0f);
	assert_float_equal(tmp1.x, src.x + 1.0f);
	assert_float_equal(tmp1.y, src.y + 1.0f);
	assert_float_equal(tmp1.z, src.z + 1.0f);
	assert_float_equal(tmp1.w, src.w + 1.0f);
}

void test_vec4_swizzle_decrement(void *state) {
	const vec4 src(1.0f, 2.0f, 3.0f, 4.0f);
	vec4 tmp0, tmp1;

	tmp0 = src;
	tmp1 = tmp0.xyzw--;
	assert_float_equal(tmp0.x, src.x - 1.0f);
	assert_float_equal(tmp0.y, src.y - 1.0f);
	assert_float_equal(tmp0.z, src.z - 1.0f);
	assert_float_equal(tmp0.w, src.w - 1.0f);
	assert_float_equal(tmp1.x, src.x);
	assert_float_equal(tmp1.y, src.y);
	assert_float_equal(tmp1.z, src.z);
	assert_float_equal(tmp1.w, src.w);

	tmp0 = src;
	tmp1 = --tmp0.xyzw;
	assert_float_equal(tmp0.x, src.x - 1.0f);
	assert_float_equal(tmp0.y, src.y - 1.0f);
	assert_float_equal(tmp0.z, src.z - 1.0f);
	assert_float_equal(tmp0.w, src.w - 1.0f);
	assert_float_equal(tmp1.x, src.x - 1.0f);
	assert_float_equal(tmp1.y, src.y - 1.0f);
	assert_float_equal(tmp1.z, src.z - 1.0f);
	assert_float_equal(tmp1.w, src.w - 1.0f);
}

void test_vec4_swizzle_equal(void *state) {
	const vec4 src(1.0f, 2.0f, 3.0f, 4.0f);
	vec4 vec;

	vec = src;
	assert_condition(vec.xyzw == src.xyzw);
	assert_condition(vec.xyzw == src);

	vec = vec4(0.0f, 0.0f, 0.0f, 0.0f);
	assert_condition(vec.xyzw != src.xyzw);
	assert_condition(vec.xyzw != src);
}

void test_vec4_swizzle_index(void *state) {
	vec4 vec(1.0f, 5.0f, 8.0f, 9.0f);

	assert_float_equal(vec.xxxx[0], vec.x);
	assert_float_equal(vec.xxxx[1], vec.x);
	assert_float_equal(vec.xxxx[2], vec.x);
	assert_float_equal(vec.xxxx[3], vec.x);

	assert_float_equal(vec.xyzw[0], vec.x);
	assert_float_equal(vec.xyzw[1], vec.y);
	assert_float_equal(vec.xyzw[2], vec.z);
	assert_float_equal(vec.xyzw[3], vec.w);

	assert_float_equal(vec.wzyx[0], vec.w);
	assert_float_equal(vec.wzyx[1], vec.z);
	assert_float_equal(vec.wzyx[2], vec.y);
	assert_float_equal(vec.wzyx[3], vec.x);

	assert_float_equal(vec.yyyy[0], vec.y);
	assert_float_equal(vec.yyyy[1], vec.y);
	assert_float_equal(vec.yyyy[2], vec.y);
	assert_float_equal(vec.yyyy[3], vec.y);

	vec.xxxx[0] = 2.0f;
	vec.xxxx[1] = 3.0f;
	vec.xxxx[2] = 4.0f;
	vec.xxxx[3] = 5.0f;
	assert_float_equal(vec.x, 5.0f);
	assert_float_equal(vec.y, 5.0f);
	assert_float_equal(vec.z, 8.0f);
	assert_float_equal(vec.w, 9.0f);

	vec.xyzw[0] = 2.0f;
	vec.xyzw[1] = 3.0f;
	vec.xyzw[2] = 4.0f;
	vec.xyzw[3] = 5.0f;
	assert_float_equal(vec.x, 2.0f);
	assert_float_equal(vec.y, 3.0f);
	assert_float_equal(vec.z, 4.0f);
	assert_float_equal(vec.w, 5.0f);

	vec.wzyx[0] = 4.0f;
	vec.wzyx[1] = 5.0f;
	vec.wzyx[2] = 6.0f;
	vec.wzyx[3] = 7.0f;
	assert_float_equal(vec.x, 7.0f);
	assert_float_equal(vec.y, 6.0f);
	assert_float_equal(vec.z, 5.0f);
	assert_float_equal(vec.w, 4.0f);

	vec.yyyy[0] = 6.0f;
	vec.yyyy[1] = 7.0f;
	vec.yyyy[2] = 8.0f;
	vec.yyyy[3] = 9.0f;
	assert_float_equal(vec.x, 7.0f);
	assert_float_equal(vec.y, 9.0f);
	assert_float_equal(vec.z, 5.0f);
	assert_float_equal(vec.w, 4.0f);
}

void test_vec4_misc(void *state) {
}

int main() {
	const TestEntry tests[] = {
		UNIT_TEST(test_vec2_size),
		UNIT_TEST(test_vec2),
		UNIT_TEST(test_vec2_assign),
		UNIT_TEST(test_vec2_unary),
		UNIT_TEST(test_vec2_binary),
		UNIT_TEST(test_vec2_combined),
		UNIT_TEST(test_vec2_increment),
		UNIT_TEST(test_vec2_decrement),
		UNIT_TEST(test_vec2_equal),
		UNIT_TEST(test_vec2_index),
		UNIT_TEST(test_vec2_swizzle),
		UNIT_TEST(test_vec2_swizzle_assign),
		UNIT_TEST(test_vec2_swizzle_unary),
		UNIT_TEST(test_vec2_swizzle_binary),
		UNIT_TEST(test_vec2_swizzle_combined),
		UNIT_TEST(test_vec2_swizzle_increment),
		UNIT_TEST(test_vec2_swizzle_decrement),
		UNIT_TEST(test_vec2_swizzle_equal),
		UNIT_TEST(test_vec2_swizzle_index),
		UNIT_TEST(test_vec2_misc),

		UNIT_TEST(test_vec3_size),
		UNIT_TEST(test_vec3),
		UNIT_TEST(test_vec3_assign),
		UNIT_TEST(test_vec3_unary),
		UNIT_TEST(test_vec3_binary),
		UNIT_TEST(test_vec3_combined),
		UNIT_TEST(test_vec3_increment),
		UNIT_TEST(test_vec3_decrement),
		UNIT_TEST(test_vec3_equal),
		UNIT_TEST(test_vec3_index),
		UNIT_TEST(test_vec3_swizzle),
		UNIT_TEST(test_vec3_swizzle_assign),
		UNIT_TEST(test_vec3_swizzle_unary),
		UNIT_TEST(test_vec3_swizzle_binary),
		UNIT_TEST(test_vec3_swizzle_combined),
		UNIT_TEST(test_vec3_swizzle_increment),
		UNIT_TEST(test_vec3_swizzle_decrement),
		UNIT_TEST(test_vec3_swizzle_equal),
		UNIT_TEST(test_vec3_swizzle_index),
		UNIT_TEST(test_vec3_misc),

		UNIT_TEST(test_vec4_size),
		UNIT_TEST(test_vec4),
		UNIT_TEST(test_vec4_assign),
		UNIT_TEST(test_vec4_unary),
		UNIT_TEST(test_vec4_binary),
		UNIT_TEST(test_vec4_combined),
		UNIT_TEST(test_vec4_increment),
		UNIT_TEST(test_vec4_decrement),
		UNIT_TEST(test_vec4_equal),
		UNIT_TEST(test_vec4_index),
		UNIT_TEST(test_vec4_swizzle),
		UNIT_TEST(test_vec4_swizzle_assign),
		UNIT_TEST(test_vec4_swizzle_unary),
		UNIT_TEST(test_vec4_swizzle_binary),
		UNIT_TEST(test_vec4_swizzle_combined),
		UNIT_TEST(test_vec4_swizzle_increment),
		UNIT_TEST(test_vec4_swizzle_decrement),
		UNIT_TEST(test_vec4_swizzle_equal),
		UNIT_TEST(test_vec4_swizzle_index),
		UNIT_TEST(test_vec4_misc),
	};

	RunTestArray(tests);

	return 0;
}
