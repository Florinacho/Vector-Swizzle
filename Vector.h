#ifndef __VECTOR_H__
#define __VECTOR_H__

// https://stackoverflow.com/questions/51641131/how-to-achieve-vector-swizzling-in-c
// https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
// http://learnwebgl.brown37.net/12_shader_language/glsl_mathematical_operations.html

/*****************************************************************************/
/* Vector2                                                                   */
/*****************************************************************************/
template <typename T>
struct Vector2 {
	template<unsigned int A, unsigned int B>
	struct Swizzle {
		union {
			T d[2];
			struct { T x, y; };
			struct { T r, g; };
			struct { T s, t; };
		};
		
		Vector2<T>& operator = (const Vector2<T>& rhs) {
			d[A] = rhs.x;
			d[B] = rhs.y;
			return *(Vector2<T>*)this;
		}
		
		Vector2<T> operator + (const Vector2<T>& rhs) const {
			return *(Vector2<T>*)this + rhs;
		}
		
		Vector2<T> operator - (const Vector2<T>& rhs) const {
			return *(Vector2<T>*)this - rhs;
		}
		
		Vector2<T> operator * (const Vector2<T>& rhs) const {
			return *(Vector2<T>*)this * rhs;
		}
		
		Vector2<T> operator / (const Vector2<T>& rhs) const {
			return *(Vector2<T>*)this / rhs;
		}
		
		Vector2<T>& operator += (const Vector2<T>& rhs) {
			return (*(Vector2<T>*)this += rhs);
		}
		
		Vector2<T>& operator -= (const Vector2<T>& rhs) {
			return (*(Vector2<T>*)this -= rhs);
		}
		
		Vector2<T>& operator *= (const Vector2<T>& rhs) {
			return (*(Vector2<T>*)this *= rhs);
		}
		
		Vector2<T>& operator /= (const Vector2<T>& rhs) {
			return (*(Vector2<T>*)this /= rhs);
		}
		
		Vector2<T> operator ++ () const {
			return ++(*(Vector2<T>*)this);
		}
		
		Vector2<T> operator ++ (int) const {
			return (*(Vector2<T>*)this)++;
		}
		
		Vector2<T> operator -- () const {
			return --(*(Vector2<T>*)this);
		}
		
		Vector2<T> operator -- (int) const {
			return (*(Vector2<T>*)this)--;
		}
		
		bool operator == (const Vector2<T>& rhs) const {
			return (*(Vector2<T>*)this == rhs);
		}
		
		bool operator != (const Vector2<T>& rhs) const {
			return (*(Vector2<T>*)this != rhs);
		}
		
		operator Vector2<T>() const {
			return Vector2<T>(d[A], d[B]);
		}
	};

	typedef Swizzle<0, 0> SwizzleXX;	
	typedef Swizzle<0, 1> SwizzleXY;
	typedef Swizzle<1, 0> SwizzleYX;
	typedef Swizzle<1, 1> SwizzleYY;
	
	union {
		struct { T x, y; };
		T d[2];
		SwizzleXX xx;
		SwizzleXY xy;
		SwizzleYX yx;
		SwizzleYY yy;
	};
	
	Vector2() : x((T)0), y((T)0) { }
	
	Vector2(const T value) : x(value), y(value) { }
	
	Vector2(const T value0, const T value1) : x(value0), y(value1) { }
	
	Vector2(const Vector2<T>& other) : x(other.x), y(other.y) { }
	
	// Arithmetic operators
	Vector2<T>& operator = (const Vector2<T>& rhs) {
		x = rhs.x;
		y = rhs.y;
	}

	Vector2<T> operator + (const Vector2<T>& rhs) const {
		return Vector2<T>(x + rhs.x, y + rhs.y);
	}
	
	Vector2<T> operator - (const Vector2<T>& rhs) const {
		return Vector2<T>(x - rhs.x, y - rhs.y);
	}
	
	Vector2<T> operator + () const {
		return *this;
	}
	
	Vector2<T> operator - () const {
		return Vector2<T>(-x, -y);
	}
	
	Vector2<T> operator * (const Vector2<T>& rhs) const {
		return Vector2<T>(x * rhs.x, y * rhs.y);
	}
	
	Vector2<T> operator / (const Vector2<T>& rhs) const {
		return Vector2<T>(x / rhs.x, y / rhs.y);
	}
	
	Vector2<T>& operator += (const Vector2<T>& rhs) {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}
	
	Vector2<T>& operator -= (const Vector2<T>& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}
	
	Vector2<T>& operator *= (const Vector2<T>& rhs) {
		x *= rhs.x;
		y *= rhs.y;
		return *this;
	}
	
	Vector2<T>& operator /= (const Vector2<T>& rhs) {
		x /= rhs.x;
		y /= rhs.y;
		return *this;
	}
	
	// Prefix ++
	Vector2<T>& operator ++ () {
		++x;
		++y;
		return *this;
	}
	
	// Postfix ++
	Vector2<T> operator ++ (int) {
		const Vector2<T> ans = *this;
		++x;
		++y;
		return ans;
	}

	// Prefix --
	Vector2<T>& operator -- () {
		--x;
		--y;
		return *this;
	}
	
	// Postfix ++
	Vector2<T> operator -- (int) {
		const Vector2<T> ans = *this;
		--x;
		--y;
		return ans;
	}

	// Comparison operators/relational operators
	bool operator == (const Vector2<T>& rhs) const {
		return ((x == rhs.x) && (y == rhs.y));
	}
	
	bool operator != (const Vector2<T>& rhs) const {
		return ((x != rhs.x) || (y != rhs.y));
	}

	T& operator [] (const unsigned int index) {
		return d[index];
	}

	T operator [] (const unsigned int index) const {
		return d[index];
	}

	void print() {
		printf("Vector2(%f, %f)\n", (float)x, (float)y);
	}
};

/*****************************************************************************/
/* Vector3                                                                   */
/*****************************************************************************/
template <typename T>
struct Vector3 {
	template<unsigned int A, unsigned int B, unsigned int C>
	struct Swizzle {
		union {
			T d[3];
			struct { T x, y, z; };
			struct { T r, g, b; };
			struct { T s, t, p; };
			typename Vector2<T>::SwizzleXX xx;
			typename Vector2<T>::SwizzleXY xy;
			typename Vector2<T>::SwizzleYX yx;
			typename Vector2<T>::SwizzleYY yy;
		};
		
		Vector3<T>& operator = (const Vector3<T>& rhs) {
			d[A] = rhs.x;
			d[B] = rhs.y;
			d[C] = rhs.z;
			return *(Vector3<T>*)this;
		}
		
		Vector3<T> operator + (const Vector3<T>& rhs) const {
			return *(Vector3<T>*)this + rhs;
		}
		
		Vector3<T> operator - (const Vector3<T>& rhs) const {
			return *(Vector3<T>*)this - rhs;
		}
		
		Vector3<T> operator * (const Vector3<T>& rhs) const {
			return *(Vector3<T>*)this * rhs;
		}
		
		Vector3<T> operator / (const Vector3<T>& rhs) const {
			return *(Vector3<T>*)this / rhs;
		}
		
		Vector3<T>& operator += (const Vector3<T>& rhs) {
			return (*(Vector3<T>*)this += rhs);
		}
		
		Vector3<T>& operator -= (const Vector3<T>& rhs) {
			return (*(Vector3<T>*)this -= rhs);
		}
		
		Vector3<T>& operator *= (const Vector3<T>& rhs) {
			return (*(Vector3<T>*)this *= rhs);
		}
		
		Vector3<T>& operator /= (const Vector3<T>& rhs) {
			return (*(Vector3<T>*)this /= rhs);
		}
		
		Vector3<T> operator ++ () const {
			return ++(*(Vector3<T>*)this);
		}
		
		Vector3<T> operator ++ (int) const {
			return (*(Vector3<T>*)this)++;
		}
		
		Vector3<T> operator -- () const {
			return --(*(Vector3<T>*)this);
		}
		
		Vector3<T> operator -- (int) const {
			return (*(Vector3<T>*)this)--;
		}
		
		bool operator == (const Vector3<T>& rhs) const {
			return (*(Vector3<T>*)this == rhs);
		}
		
		bool operator != (const Vector3<T>& rhs) const {
			return (*(Vector3<T>*)this != rhs);
		}
		
		operator Vector3<T>() const {
			return Vector3<T>(d[A], d[B], d[C]);
		}
	};
	
	typedef Swizzle<0, 0, 0> SwizzleXXX;
	typedef Swizzle<0, 0, 1> SwizzleXXY;
	typedef Swizzle<0, 0, 2> SwizzleXXZ;
	typedef Swizzle<0, 1, 0> SwizzleXYX;
	typedef Swizzle<0, 1, 1> SwizzleXYY;
	typedef Swizzle<0, 1, 2> SwizzleXYZ;
	typedef Swizzle<0, 2, 0> SwizzleXZX;
	typedef Swizzle<0, 2, 1> SwizzleXZY;
	typedef Swizzle<0, 2, 2> SwizzleXZZ;
	typedef Swizzle<1, 0, 0> SwizzleYXX;
	typedef Swizzle<1, 0, 1> SwizzleYXY;
	typedef Swizzle<1, 0, 2> SwizzleYXZ;
	typedef Swizzle<1, 1, 0> SwizzleYYX;
	typedef Swizzle<1, 1, 1> SwizzleYYY;
	typedef Swizzle<1, 1, 2> SwizzleYYZ;
	typedef Swizzle<1, 2, 0> SwizzleYZX;
	typedef Swizzle<1, 2, 1> SwizzleYZY;
	typedef Swizzle<1, 2, 2> SwizzleYZZ;
	typedef Swizzle<2, 0, 0> SwizzleZXX;
	typedef Swizzle<2, 0, 1> SwizzleZXY;
	typedef Swizzle<2, 0, 2> SwizzleZXZ;
	typedef Swizzle<2, 1, 0> SwizzleZYX;
	typedef Swizzle<2, 1, 1> SwizzleZYY;
	typedef Swizzle<2, 1, 2> SwizzleZYZ;
	typedef Swizzle<2, 2, 0> SwizzleZZX;
	typedef Swizzle<2, 2, 1> SwizzleZZY;
	typedef Swizzle<2, 2, 2> SwizzleZZZ;
	
	union {
		T d[3];
		struct { T x, y, z; };
		struct { T r, g, b; };
		struct { T s, t, p; };
		typename Vector2<T>::SwizzleXX xx;
		typename Vector2<T>::SwizzleXY xy;
		typename Vector2<T>::SwizzleYX yx;
		typename Vector2<T>::SwizzleYY yy;
		SwizzleXXZ xxz;
		SwizzleXYX xyx;
		SwizzleXYY xyy;
		SwizzleXYZ xyz;
		SwizzleXZX xzx;
		SwizzleXZY xzy;
		SwizzleXZZ xzz;
		SwizzleYXX yxx;
		SwizzleYXY yxy;
		SwizzleYXZ yxz;
		SwizzleYYX yyx;
		SwizzleYYY yyy;
		SwizzleYYZ yyz;
		SwizzleYZX yzx;
		SwizzleYZY yzy;
		SwizzleYZZ yzz;
		SwizzleZXX zxx;
		SwizzleZXY zxy;
		SwizzleZXZ zxz;
		SwizzleZYX zyx;
		SwizzleZYY zyy;
		SwizzleZYZ zyz;
		SwizzleZZX zzx;
		SwizzleZZY zzy;
		SwizzleZZZ zzz;
	};
	
	// Constructors
	Vector3() : x((T)0), y((T)0), z((T)0) { }
	
	Vector3(const T value) : x(value), y(value), z(value) { }
	
	Vector3(const T value0, const T value1, const T value2) : x(value0), y(value1), z(value2) { }
	
	Vector3(const Vector3<T>& other) : x(other.x), y(other.y), z(other.z) { }
	
	// Arithmetic operators
	Vector3<T>& operator = (const Vector3<T>& rhs) {
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
	}
	
	Vector3<T> operator + (const Vector3<T>& rhs) const {
		return Vector3<T>(x + rhs.x, y + rhs.y, z + rhs.z);
	}
	
	Vector3<T> operator - (const Vector3<T>& rhs) const {
		return Vector3<T>(x - rhs.x, y - rhs.y, z - rhs.z);
	}
	
	Vector3<T> operator + () const {
		return *this;
	}
	
	Vector3<T> operator - () const {
		return Vector3<T>(-x, -y, -z);
	}
	
	Vector3<T> operator * (const Vector3<T>& rhs) const {
		return Vector3<T>(x * rhs.x, y * rhs.y, z * rhs.z);
	}
	
	Vector3<T> operator / (const Vector3<T>& rhs) const {
		return Vector3<T>(x / rhs.x, y / rhs.y, z / rhs.z);
	}
	
	Vector3<T>& operator += (const Vector3<T>& rhs) {
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}
	
	Vector3<T>& operator -= (const Vector3<T>& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}
	
	Vector3<T>& operator *= (const Vector3<T>& rhs) {
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		return *this;
	}
	
	Vector3<T>& operator /= (const Vector3<T>& rhs) {
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;
		return *this;
	}
	
	// Prefix ++
	Vector3<T>& operator ++ () {
		++x;
		++y;
		++z;
		return *this;
	}
	
	// Postfix ++
	Vector3<T> operator ++ (int) {
		const Vector3<T> ans = *this;
		++x;
		++y;
		++z;
		return ans;
	}

	// Prefix --
	Vector3<T>& operator -- () {
		--x;
		--y;
		--z;
		return *this;
	}
	
	// Postfix ++
	Vector3<T> operator -- (int) {
		const Vector3<T> ans = *this;
		--x;
		--y;
		--z;
		return ans;
	}

	// Comparison operators/relational operators
	bool operator == (const Vector3<T>& rhs) const {
		return ((x == rhs.x) && (y == rhs.y) && (z == rhs.z));
	}
	
	bool operator != (const Vector3<T>& rhs) const {
		return ((x != rhs.x) || (y != rhs.y) || (z != rhs.z));
	}

	T& operator [] (const unsigned int index) {
		return d[index];
	}

	T operator [] (const unsigned int index) const {
		return d[index];
	}
};

/*****************************************************************************/
/* Vector4                                                                   */
/*****************************************************************************/
template <typename T>
struct Vector4 {
	template<unsigned int A, unsigned int B, unsigned int C, unsigned int D>
	struct Swizzle {
		union {
			struct { T x, y, z, w; };
			struct { T r, g, b, a; };
			struct { T s, t, p, q; };
			T d[4];
			typename Vector2<T>::SwizzleXX xx;
			typename Vector2<T>::SwizzleXY xy;
			typename Vector2<T>::SwizzleYX yx;
			typename Vector2<T>::SwizzleYY yy;
			typename Vector3<T>::SwizzleXXZ xxz;
			typename Vector3<T>::SwizzleXYX xyx;
			typename Vector3<T>::SwizzleXYY xyy;
			typename Vector3<T>::SwizzleXYZ xyz;
			typename Vector3<T>::SwizzleXZX xzx;
			typename Vector3<T>::SwizzleXZY xzy;
			typename Vector3<T>::SwizzleXZZ xzz;
			typename Vector3<T>::SwizzleYXX yxx;
			typename Vector3<T>::SwizzleYXY yxy;
			typename Vector3<T>::SwizzleYXZ yxz;
			typename Vector3<T>::SwizzleYYX yyx;
			typename Vector3<T>::SwizzleYYY yyy;
			typename Vector3<T>::SwizzleYYZ yyz;
			typename Vector3<T>::SwizzleYZX yzx;
			typename Vector3<T>::SwizzleYZY yzy;
			typename Vector3<T>::SwizzleYZZ yzz;
			typename Vector3<T>::SwizzleZXX zxx;
			typename Vector3<T>::SwizzleZXY zxy;
			typename Vector3<T>::SwizzleZXZ zxz;
			typename Vector3<T>::SwizzleZYX zyx;
			typename Vector3<T>::SwizzleZYY zyy;
			typename Vector3<T>::SwizzleZYZ zyz;
			typename Vector3<T>::SwizzleZZX zzx;
			typename Vector3<T>::SwizzleZZY zzy;
			typename Vector3<T>::SwizzleZZZ zzz;
		};
		
		Vector4<T>& operator = (const Vector4<T>& rhs) {
			d[A] = rhs.x;
			d[B] = rhs.y;
			d[C] = rhs.z;
			d[D] = rhs.w;
			return *(Vector4<T>*)this;
		}
		
		Vector4<T> operator + (const Vector4<T>& rhs) const {
			return *(Vector4<T>*)this + rhs;
		}
		
		Vector4<T> operator - (const Vector4<T>& rhs) const {
			return *(Vector4<T>*)this - rhs;
		}
		
		Vector4<T> operator * (const Vector4<T>& rhs) const {
			return *(Vector4<T>*)this * rhs;
		}
		
		Vector4<T> operator / (const Vector4<T>& rhs) const {
			return *(Vector4<T>*)this / rhs;
		}
		
		Vector4<T>& operator += (const Vector4<T>& rhs) {
			return (*(Vector4<T>*)this += rhs);
		}
		
		Vector4<T>& operator -= (const Vector4<T>& rhs) {
			return (*(Vector4<T>*)this -= rhs);
		}
		
		Vector4<T>& operator *= (const Vector4<T>& rhs) {
			return (*(Vector4<T>*)this *= rhs);
		}
		
		Vector4<T>& operator /= (const Vector4<T>& rhs) {
			return (*(Vector4<T>*)this /= rhs);
		}
		
		Vector4<T> operator ++ () const {
			return ++(*(Vector4<T>*)this);
		}
		
		Vector4<T> operator ++ (int) const {
			return (*(Vector4<T>*)this)++;
		}
		
		Vector4<T> operator -- () const {
			return --(*(Vector4<T>*)this);
		}
		
		Vector4<T> operator -- (int) const {
			return (*(Vector4<T>*)this)--;
		}
		
		bool operator == (const Vector4<T>& rhs) const {
			return (*(Vector4<T>*)this == rhs);
		}
		
		bool operator != (const Vector4<T>& rhs) const {
			return (*(Vector4<T>*)this != rhs);
		}
		
		operator Vector4<T>() const {
			return Vector4<T>(d[A], d[B], d[C], d[D]);
		}
	};

	typedef Swizzle<0, 0, 0, 0> SwizzleXXXX;
	typedef Swizzle<0, 0, 0, 1> SwizzleXXXY;
	typedef Swizzle<0, 0, 0, 2> SwizzleXXXZ;
	typedef Swizzle<0, 0, 0, 3> SwizzleXXXW;
	typedef Swizzle<0, 0, 1, 0> SwizzleXXYX;
	typedef Swizzle<0, 0, 1, 1> SwizzleXXYY;
	typedef Swizzle<0, 0, 1, 2> SwizzleXXYZ;
	typedef Swizzle<0, 0, 1, 3> SwizzleXXYW;
	typedef Swizzle<0, 0, 2, 0> SwizzleXXZX;
	typedef Swizzle<0, 0, 2, 1> SwizzleXXZY;
	typedef Swizzle<0, 0, 2, 2> SwizzleXXZZ;
	typedef Swizzle<0, 0, 2, 3> SwizzleXXZW;
	typedef Swizzle<0, 0, 3, 0> SwizzleXXWX;
	typedef Swizzle<0, 0, 3, 1> SwizzleXXWY;
	typedef Swizzle<0, 0, 3, 2> SwizzleXXWZ;
	typedef Swizzle<0, 0, 3, 3> SwizzleXXWW;
	typedef Swizzle<0, 1, 0, 0> SwizzleXYXX;
	typedef Swizzle<0, 1, 0, 1> SwizzleXYXY;
	typedef Swizzle<0, 1, 0, 2> SwizzleXYXZ;
	typedef Swizzle<0, 1, 0, 3> SwizzleXYXW;
	typedef Swizzle<0, 1, 1, 0> SwizzleXYYX;
	typedef Swizzle<0, 1, 1, 1> SwizzleXYYY;
	typedef Swizzle<0, 1, 1, 2> SwizzleXYYZ;
	typedef Swizzle<0, 1, 1, 3> SwizzleXYYW;
	typedef Swizzle<0, 1, 2, 0> SwizzleXYZX;
	typedef Swizzle<0, 1, 2, 1> SwizzleXYZY;
	typedef Swizzle<0, 1, 2, 2> SwizzleXYZZ;
	typedef Swizzle<0, 1, 2, 3> SwizzleXYZW;
	typedef Swizzle<0, 1, 3, 0> SwizzleXYWX;
	typedef Swizzle<0, 1, 3, 1> SwizzleXYWY;
	typedef Swizzle<0, 1, 3, 2> SwizzleXYWZ;
	typedef Swizzle<0, 1, 3, 3> SwizzleXYWW;
	typedef Swizzle<0, 2, 0, 0> SwizzleXZXX;
	typedef Swizzle<0, 2, 0, 1> SwizzleXZXY;
	typedef Swizzle<0, 2, 0, 2> SwizzleXZXZ;
	typedef Swizzle<0, 2, 0, 3> SwizzleXZXW;
	typedef Swizzle<0, 2, 1, 0> SwizzleXZYX;
	typedef Swizzle<0, 2, 1, 1> SwizzleXZYY;
	typedef Swizzle<0, 2, 1, 2> SwizzleXZYZ;
	typedef Swizzle<0, 2, 1, 3> SwizzleXZYW;
	typedef Swizzle<0, 2, 2, 0> SwizzleXZZX;
	typedef Swizzle<0, 2, 2, 1> SwizzleXZZY;
	typedef Swizzle<0, 2, 2, 2> SwizzleXZZZ;
	typedef Swizzle<0, 2, 2, 3> SwizzleXZZW;
	typedef Swizzle<0, 2, 3, 0> SwizzleXZWX;
	typedef Swizzle<0, 2, 3, 1> SwizzleXZWY;
	typedef Swizzle<0, 2, 3, 2> SwizzleXZWZ;
	typedef Swizzle<0, 2, 3, 3> SwizzleXZWW;
	typedef Swizzle<0, 3, 0, 0> SwizzleXWXX;
	typedef Swizzle<0, 3, 0, 1> SwizzleXWXY;
	typedef Swizzle<0, 3, 0, 2> SwizzleXWXZ;
	typedef Swizzle<0, 3, 0, 3> SwizzleXWXW;
	typedef Swizzle<0, 3, 1, 0> SwizzleXWYX;
	typedef Swizzle<0, 3, 1, 1> SwizzleXWYY;
	typedef Swizzle<0, 3, 1, 2> SwizzleXWYZ;
	typedef Swizzle<0, 3, 1, 3> SwizzleXWYW;
	typedef Swizzle<0, 3, 2, 0> SwizzleXWZX;
	typedef Swizzle<0, 3, 2, 1> SwizzleXWZY;
	typedef Swizzle<0, 3, 2, 2> SwizzleXWZZ;
	typedef Swizzle<0, 3, 2, 3> SwizzleXWZW;
	typedef Swizzle<0, 3, 3, 0> SwizzleXWWX;
	typedef Swizzle<0, 3, 3, 1> SwizzleXWWY;
	typedef Swizzle<0, 3, 3, 2> SwizzleXWWZ;
	typedef Swizzle<0, 3, 3, 3> SwizzleXWWW;
	typedef Swizzle<1, 0, 0, 0> SwizzleYXXX;
	typedef Swizzle<1, 0, 0, 1> SwizzleYXXY;
	typedef Swizzle<1, 0, 0, 2> SwizzleYXXZ;
	typedef Swizzle<1, 0, 0, 3> SwizzleYXXW;
	typedef Swizzle<1, 0, 1, 0> SwizzleYXYX;
	typedef Swizzle<1, 0, 1, 1> SwizzleYXYY;
	typedef Swizzle<1, 0, 1, 2> SwizzleYXYZ;
	typedef Swizzle<1, 0, 1, 3> SwizzleYXYW;
	typedef Swizzle<1, 0, 2, 0> SwizzleYXZX;
	typedef Swizzle<1, 0, 2, 1> SwizzleYXZY;
	typedef Swizzle<1, 0, 2, 2> SwizzleYXZZ;
	typedef Swizzle<1, 0, 2, 3> SwizzleYXZW;
	typedef Swizzle<1, 0, 3, 0> SwizzleYXWX;
	typedef Swizzle<1, 0, 3, 1> SwizzleYXWY;
	typedef Swizzle<1, 0, 3, 2> SwizzleYXWZ;
	typedef Swizzle<1, 0, 3, 3> SwizzleYXWW;
	typedef Swizzle<1, 1, 0, 0> SwizzleYYXX;
	typedef Swizzle<1, 1, 0, 1> SwizzleYYXY;
	typedef Swizzle<1, 1, 0, 2> SwizzleYYXZ;
	typedef Swizzle<1, 1, 0, 3> SwizzleYYXW;
	typedef Swizzle<1, 1, 1, 0> SwizzleYYYX;
	typedef Swizzle<1, 1, 1, 1> SwizzleYYYY;
	typedef Swizzle<1, 1, 1, 2> SwizzleYYYZ;
	typedef Swizzle<1, 1, 1, 3> SwizzleYYYW;
	typedef Swizzle<1, 1, 2, 0> SwizzleYYZX;
	typedef Swizzle<1, 1, 2, 1> SwizzleYYZY;
	typedef Swizzle<1, 1, 2, 2> SwizzleYYZZ;
	typedef Swizzle<1, 1, 2, 3> SwizzleYYZW;
	typedef Swizzle<1, 1, 3, 0> SwizzleYYWX;
	typedef Swizzle<1, 1, 3, 1> SwizzleYYWY;
	typedef Swizzle<1, 1, 3, 2> SwizzleYYWZ;
	typedef Swizzle<1, 1, 3, 3> SwizzleYYWW;
	typedef Swizzle<1, 2, 0, 0> SwizzleYZXX;
	typedef Swizzle<1, 2, 0, 1> SwizzleYZXY;
	typedef Swizzle<1, 2, 0, 2> SwizzleYZXZ;
	typedef Swizzle<1, 2, 0, 3> SwizzleYZXW;
	typedef Swizzle<1, 2, 1, 0> SwizzleYZYX;
	typedef Swizzle<1, 2, 1, 1> SwizzleYZYY;
	typedef Swizzle<1, 2, 1, 2> SwizzleYZYZ;
	typedef Swizzle<1, 2, 1, 3> SwizzleYZYW;
	typedef Swizzle<1, 2, 2, 0> SwizzleYZZX;
	typedef Swizzle<1, 2, 2, 1> SwizzleYZZY;
	typedef Swizzle<1, 2, 2, 2> SwizzleYZZZ;
	typedef Swizzle<1, 2, 2, 3> SwizzleYZZW;
	typedef Swizzle<1, 2, 3, 0> SwizzleYZWX;
	typedef Swizzle<1, 2, 3, 1> SwizzleYZWY;
	typedef Swizzle<1, 2, 3, 2> SwizzleYZWZ;
	typedef Swizzle<1, 2, 3, 3> SwizzleYZWW;
	typedef Swizzle<1, 3, 0, 0> SwizzleYWXX;
	typedef Swizzle<1, 3, 0, 1> SwizzleYWXY;
	typedef Swizzle<1, 3, 0, 2> SwizzleYWXZ;
	typedef Swizzle<1, 3, 0, 3> SwizzleYWXW;
	typedef Swizzle<1, 3, 1, 0> SwizzleYWYX;
	typedef Swizzle<1, 3, 1, 1> SwizzleYWYY;
	typedef Swizzle<1, 3, 1, 2> SwizzleYWYZ;
	typedef Swizzle<1, 3, 1, 3> SwizzleYWYW;
	typedef Swizzle<1, 3, 2, 0> SwizzleYWZX;
	typedef Swizzle<1, 3, 2, 1> SwizzleYWZY;
	typedef Swizzle<1, 3, 2, 2> SwizzleYWZZ;
	typedef Swizzle<1, 3, 2, 3> SwizzleYWZW;
	typedef Swizzle<1, 3, 3, 0> SwizzleYWWX;
	typedef Swizzle<1, 3, 3, 1> SwizzleYWWY;
	typedef Swizzle<1, 3, 3, 2> SwizzleYWWZ;
	typedef Swizzle<1, 3, 3, 3> SwizzleYWWW;
	typedef Swizzle<2, 0, 0, 0> SwizzleZXXX;
	typedef Swizzle<2, 0, 0, 1> SwizzleZXXY;
	typedef Swizzle<2, 0, 0, 2> SwizzleZXXZ;
	typedef Swizzle<2, 0, 0, 3> SwizzleZXXW;
	typedef Swizzle<2, 0, 1, 0> SwizzleZXYX;
	typedef Swizzle<2, 0, 1, 1> SwizzleZXYY;
	typedef Swizzle<2, 0, 1, 2> SwizzleZXYZ;
	typedef Swizzle<2, 0, 1, 3> SwizzleZXYW;
	typedef Swizzle<2, 0, 2, 0> SwizzleZXZX;
	typedef Swizzle<2, 0, 2, 1> SwizzleZXZY;
	typedef Swizzle<2, 0, 2, 2> SwizzleZXZZ;
	typedef Swizzle<2, 0, 2, 3> SwizzleZXZW;
	typedef Swizzle<2, 0, 3, 0> SwizzleZXWX;
	typedef Swizzle<2, 0, 3, 1> SwizzleZXWY;
	typedef Swizzle<2, 0, 3, 2> SwizzleZXWZ;
	typedef Swizzle<2, 0, 3, 3> SwizzleZXWW;
	typedef Swizzle<2, 1, 0, 0> SwizzleZYXX;
	typedef Swizzle<2, 1, 0, 1> SwizzleZYXY;
	typedef Swizzle<2, 1, 0, 2> SwizzleZYXZ;
	typedef Swizzle<2, 1, 0, 3> SwizzleZYXW;
	typedef Swizzle<2, 1, 1, 0> SwizzleZYYX;
	typedef Swizzle<2, 1, 1, 1> SwizzleZYYY;
	typedef Swizzle<2, 1, 1, 2> SwizzleZYYZ;
	typedef Swizzle<2, 1, 1, 3> SwizzleZYYW;
	typedef Swizzle<2, 1, 2, 0> SwizzleZYZX;
	typedef Swizzle<2, 1, 2, 1> SwizzleZYZY;
	typedef Swizzle<2, 1, 2, 2> SwizzleZYZZ;
	typedef Swizzle<2, 1, 2, 3> SwizzleZYZW;
	typedef Swizzle<2, 1, 3, 0> SwizzleZYWX;
	typedef Swizzle<2, 1, 3, 1> SwizzleZYWY;
	typedef Swizzle<2, 1, 3, 2> SwizzleZYWZ;
	typedef Swizzle<2, 1, 3, 3> SwizzleZYWW;
	typedef Swizzle<2, 2, 0, 0> SwizzleZZXX;
	typedef Swizzle<2, 2, 0, 1> SwizzleZZXY;
	typedef Swizzle<2, 2, 0, 2> SwizzleZZXZ;
	typedef Swizzle<2, 2, 0, 3> SwizzleZZXW;
	typedef Swizzle<2, 2, 1, 0> SwizzleZZYX;
	typedef Swizzle<2, 2, 1, 1> SwizzleZZYY;
	typedef Swizzle<2, 2, 1, 2> SwizzleZZYZ;
	typedef Swizzle<2, 2, 1, 3> SwizzleZZYW;
	typedef Swizzle<2, 2, 2, 0> SwizzleZZZX;
	typedef Swizzle<2, 2, 2, 1> SwizzleZZZY;
	typedef Swizzle<2, 2, 2, 2> SwizzleZZZZ;
	typedef Swizzle<2, 2, 2, 3> SwizzleZZZW;
	typedef Swizzle<2, 2, 3, 0> SwizzleZZWX;
	typedef Swizzle<2, 2, 3, 1> SwizzleZZWY;
	typedef Swizzle<2, 2, 3, 2> SwizzleZZWZ;
	typedef Swizzle<2, 2, 3, 3> SwizzleZZWW;
	typedef Swizzle<2, 3, 0, 0> SwizzleZWXX;
	typedef Swizzle<2, 3, 0, 1> SwizzleZWXY;
	typedef Swizzle<2, 3, 0, 2> SwizzleZWXZ;
	typedef Swizzle<2, 3, 0, 3> SwizzleZWXW;
	typedef Swizzle<2, 3, 1, 0> SwizzleZWYX;
	typedef Swizzle<2, 3, 1, 1> SwizzleZWYY;
	typedef Swizzle<2, 3, 1, 2> SwizzleZWYZ;
	typedef Swizzle<2, 3, 1, 3> SwizzleZWYW;
	typedef Swizzle<2, 3, 2, 0> SwizzleZWZX;
	typedef Swizzle<2, 3, 2, 1> SwizzleZWZY;
	typedef Swizzle<2, 3, 2, 2> SwizzleZWZZ;
	typedef Swizzle<2, 3, 2, 3> SwizzleZWZW;
	typedef Swizzle<2, 3, 3, 0> SwizzleZWWX;
	typedef Swizzle<2, 3, 3, 1> SwizzleZWWY;
	typedef Swizzle<2, 3, 3, 2> SwizzleZWWZ;
	typedef Swizzle<2, 3, 3, 3> SwizzleZWWW;
	typedef Swizzle<3, 0, 0, 0> SwizzleWXXX;
	typedef Swizzle<3, 0, 0, 1> SwizzleWXXY;
	typedef Swizzle<3, 0, 0, 2> SwizzleWXXZ;
	typedef Swizzle<3, 0, 0, 3> SwizzleWXXW;
	typedef Swizzle<3, 0, 1, 0> SwizzleWXYX;
	typedef Swizzle<3, 0, 1, 1> SwizzleWXYY;
	typedef Swizzle<3, 0, 1, 2> SwizzleWXYZ;
	typedef Swizzle<3, 0, 1, 3> SwizzleWXYW;
	typedef Swizzle<3, 0, 2, 0> SwizzleWXZX;
	typedef Swizzle<3, 0, 2, 1> SwizzleWXZY;
	typedef Swizzle<3, 0, 2, 2> SwizzleWXZZ;
	typedef Swizzle<3, 0, 2, 3> SwizzleWXZW;
	typedef Swizzle<3, 0, 3, 0> SwizzleWXWX;
	typedef Swizzle<3, 0, 3, 1> SwizzleWXWY;
	typedef Swizzle<3, 0, 3, 2> SwizzleWXWZ;
	typedef Swizzle<3, 0, 3, 3> SwizzleWXWW;
	typedef Swizzle<3, 1, 0, 0> SwizzleWYXX;
	typedef Swizzle<3, 1, 0, 1> SwizzleWYXY;
	typedef Swizzle<3, 1, 0, 2> SwizzleWYXZ;
	typedef Swizzle<3, 1, 0, 3> SwizzleWYXW;
	typedef Swizzle<3, 1, 1, 0> SwizzleWYYX;
	typedef Swizzle<3, 1, 1, 1> SwizzleWYYY;
	typedef Swizzle<3, 1, 1, 2> SwizzleWYYZ;
	typedef Swizzle<3, 1, 1, 3> SwizzleWYYW;
	typedef Swizzle<3, 1, 2, 0> SwizzleWYZX;
	typedef Swizzle<3, 1, 2, 1> SwizzleWYZY;
	typedef Swizzle<3, 1, 2, 2> SwizzleWYZZ;
	typedef Swizzle<3, 1, 2, 3> SwizzleWYZW;
	typedef Swizzle<3, 1, 3, 0> SwizzleWYWX;
	typedef Swizzle<3, 1, 3, 1> SwizzleWYWY;
	typedef Swizzle<3, 1, 3, 2> SwizzleWYWZ;
	typedef Swizzle<3, 1, 3, 3> SwizzleWYWW;
	typedef Swizzle<3, 2, 0, 0> SwizzleWZXX;
	typedef Swizzle<3, 2, 0, 1> SwizzleWZXY;
	typedef Swizzle<3, 2, 0, 2> SwizzleWZXZ;
	typedef Swizzle<3, 2, 0, 3> SwizzleWZXW;
	typedef Swizzle<3, 2, 1, 0> SwizzleWZYX;
	typedef Swizzle<3, 2, 1, 1> SwizzleWZYY;
	typedef Swizzle<3, 2, 1, 2> SwizzleWZYZ;
	typedef Swizzle<3, 2, 1, 3> SwizzleWZYW;
	typedef Swizzle<3, 2, 2, 0> SwizzleWZZX;
	typedef Swizzle<3, 2, 2, 1> SwizzleWZZY;
	typedef Swizzle<3, 2, 2, 2> SwizzleWZZZ;
	typedef Swizzle<3, 2, 2, 3> SwizzleWZZW;
	typedef Swizzle<3, 2, 3, 0> SwizzleWZWX;
	typedef Swizzle<3, 2, 3, 1> SwizzleWZWY;
	typedef Swizzle<3, 2, 3, 2> SwizzleWZWZ;
	typedef Swizzle<3, 2, 3, 3> SwizzleWZWW;
	typedef Swizzle<3, 3, 0, 0> SwizzleWWXX;
	typedef Swizzle<3, 3, 0, 1> SwizzleWWXY;
	typedef Swizzle<3, 3, 0, 2> SwizzleWWXZ;
	typedef Swizzle<3, 3, 0, 3> SwizzleWWXW;
	typedef Swizzle<3, 3, 1, 0> SwizzleWWYX;
	typedef Swizzle<3, 3, 1, 1> SwizzleWWYY;
	typedef Swizzle<3, 3, 1, 2> SwizzleWWYZ;
	typedef Swizzle<3, 3, 1, 3> SwizzleWWYW;
	typedef Swizzle<3, 3, 2, 0> SwizzleWWZX;
	typedef Swizzle<3, 3, 2, 1> SwizzleWWZY;
	typedef Swizzle<3, 3, 2, 2> SwizzleWWZZ;
	typedef Swizzle<3, 3, 2, 3> SwizzleWWZW;
	typedef Swizzle<3, 3, 3, 0> SwizzleWWWX;
	typedef Swizzle<3, 3, 3, 1> SwizzleWWWY;
	typedef Swizzle<3, 3, 3, 2> SwizzleWWWZ;
	typedef Swizzle<3, 3, 3, 3> SwizzleWWWW;

	union {
		struct { T x, y, z, w; };
		struct { T r, g, b, a; };
		struct { T s, t, p, q; };
		T d[4];
		typename Vector2<T>::SwizzleXX xx;
		typename Vector2<T>::SwizzleXY xy;
		typename Vector2<T>::SwizzleYX yx;
		typename Vector2<T>::SwizzleYY yy;
		typename Vector3<T>::SwizzleXXZ xxx;
		typename Vector3<T>::SwizzleXXZ xxy;
		typename Vector3<T>::SwizzleXXZ xxz;
		typename Vector3<T>::SwizzleXYX xyx;
		typename Vector3<T>::SwizzleXYY xyy;
		typename Vector3<T>::SwizzleXYZ xyz;
		typename Vector3<T>::SwizzleXZX xzx;
		typename Vector3<T>::SwizzleXZY xzy;
		typename Vector3<T>::SwizzleXZZ xzz;
		typename Vector3<T>::SwizzleYXX yxx;
		typename Vector3<T>::SwizzleYXY yxy;
		typename Vector3<T>::SwizzleYXZ yxz;
		typename Vector3<T>::SwizzleYYX yyx;
		typename Vector3<T>::SwizzleYYY yyy;
		typename Vector3<T>::SwizzleYYZ yyz;
		typename Vector3<T>::SwizzleYZX yzx;
		typename Vector3<T>::SwizzleYZY yzy;
		typename Vector3<T>::SwizzleYZZ yzz;
		typename Vector3<T>::SwizzleZXX zxx;
		typename Vector3<T>::SwizzleZXY zxy;
		typename Vector3<T>::SwizzleZXZ zxz;
		typename Vector3<T>::SwizzleZYX zyx;
		typename Vector3<T>::SwizzleZYY zyy;
		typename Vector3<T>::SwizzleZYZ zyz;
		typename Vector3<T>::SwizzleZZX zzx;
		typename Vector3<T>::SwizzleZZY zzy;
		typename Vector3<T>::SwizzleZZZ zzz;
		SwizzleXXXX xxxx;
		SwizzleXXXY xxxy;
		SwizzleXXXZ xxxz;
		SwizzleXXXW xxxw;
		SwizzleXXYX xxyx;
		SwizzleXXYY xxyy;
		SwizzleXXYZ xxyz;
		SwizzleXXYW xxyw;
		SwizzleXXZX xxzx;
		SwizzleXXZY xxzy;
		SwizzleXXZZ xxzz;
		SwizzleXXZW xxzw;
		SwizzleXXWX xxwx;
		SwizzleXXWY xxwy;
		SwizzleXXWZ xxwz;
		SwizzleXXWW xxww;
		SwizzleXYXX xyxx;
		SwizzleXYXY xyxy;
		SwizzleXYXZ xyxz;
		SwizzleXYXW xyxw;
		SwizzleXYYX xyyx;
		SwizzleXYYY xyyy;
		SwizzleXYYZ xyyz;
		SwizzleXYYW xyyw;
		SwizzleXYZX xyzx;
		SwizzleXYZY xyzy;
		SwizzleXYZZ xyzz;
		SwizzleXYZW xyzw;
		SwizzleXYWX xywx;
		SwizzleXYWY xywy;
		SwizzleXYWZ xywz;
		SwizzleXYWW xyww;
		SwizzleXZXX xzxx;
		SwizzleXZXY xzxy;
		SwizzleXZXZ xzxz;
		SwizzleXZXW xzxw;
		SwizzleXZYX xzyx;
		SwizzleXZYY xzyy;
		SwizzleXZYZ xzyz;
		SwizzleXZYW xzyw;
		SwizzleXZZX xzzx;
		SwizzleXZZY xzzy;
		SwizzleXZZZ xzzz;
		SwizzleXZZW xzzw;
		SwizzleXZWX xzwx;
		SwizzleXZWY xzwy;
		SwizzleXZWZ xzwz;
		SwizzleXZWW xzww;
		SwizzleXWXX xwxx;
		SwizzleXWXY xwxy;
		SwizzleXWXZ xwxz;
		SwizzleXWXW xwxw;
		SwizzleXWYX xwyx;
		SwizzleXWYY xwyy;
		SwizzleXWYZ xwyz;
		SwizzleXWYW xwyw;
		SwizzleXWZX xwzx;
		SwizzleXWZY xwzy;
		SwizzleXWZZ xwzz;
		SwizzleXWZW xwzw;
		SwizzleXWWX xwwx;
		SwizzleXWWY xwwy;
		SwizzleXWWZ xwwz;
		SwizzleXWWW xwww;
		SwizzleYXXX yxxx;
		SwizzleYXXY yxxy;
		SwizzleYXXZ yxxz;
		SwizzleYXXW yxxw;
		SwizzleYXYX yxyx;
		SwizzleYXYY yxyy;
		SwizzleYXYZ yxyz;
		SwizzleYXYW yxyw;
		SwizzleYXZX yxzx;
		SwizzleYXZY yxzy;
		SwizzleYXZZ yxzz;
		SwizzleYXZW yxzw;
		SwizzleYXWX yxwx;
		SwizzleYXWY yxwy;
		SwizzleYXWZ yxwz;
		SwizzleYXWW yxww;
		SwizzleYYXX yyxx;
		SwizzleYYXY yyxy;
		SwizzleYYXZ yyxz;
		SwizzleYYXW yyxw;
		SwizzleYYYX yyyx;
		SwizzleYYYY yyyy;
		SwizzleYYYZ yyyz;
		SwizzleYYYW yyyw;
		SwizzleYYZX yyzx;
		SwizzleYYZY yyzy;
		SwizzleYYZZ yyzz;
		SwizzleYYZW yyzw;
		SwizzleYYWX yywx;
		SwizzleYYWY yywy;
		SwizzleYYWZ yywz;
		SwizzleYYWW yyww;
		SwizzleYZXX yzxx;
		SwizzleYZXY yzxy;
		SwizzleYZXZ yzxz;
		SwizzleYZXW yzxw;
		SwizzleYZYX yzyx;
		SwizzleYZYY yzyy;
		SwizzleYZYZ yzyz;
		SwizzleYZYW yzyw;
		SwizzleYZZX yzzx;
		SwizzleYZZY yzzy;
		SwizzleYZZZ yzzz;
		SwizzleYZZW yzzw;
		SwizzleYZWX yzwx;
		SwizzleYZWY yzwy;
		SwizzleYZWZ yzwz;
		SwizzleYZWW yzww;
		SwizzleYWXX ywxx;
		SwizzleYWXY ywxy;
		SwizzleYWXZ ywxz;
		SwizzleYWXW ywxw;
		SwizzleYWYX ywyx;
		SwizzleYWYY ywyy;
		SwizzleYWYZ ywyz;
		SwizzleYWYW ywyw;
		SwizzleYWZX ywzx;
		SwizzleYWZY ywzy;
		SwizzleYWZZ ywzz;
		SwizzleYWZW ywzw;
		SwizzleYWWX ywwx;
		SwizzleYWWY ywwy;
		SwizzleYWWZ ywwz;
		SwizzleYWWW ywww;
		SwizzleZXXX zxxx;
		SwizzleZXXY zxxy;
		SwizzleZXXZ zxxz;
		SwizzleZXXW zxxw;
		SwizzleZXYX zxyx;
		SwizzleZXYY zxyy;
		SwizzleZXYZ zxyz;
		SwizzleZXYW zxyw;
		SwizzleZXZX zxzx;
		SwizzleZXZY zxzy;
		SwizzleZXZZ zxzz;
		SwizzleZXZW zxzw;
		SwizzleZXWX zxwx;
		SwizzleZXWY zxwy;
		SwizzleZXWZ zxwz;
		SwizzleZXWW zxww;
		SwizzleZYXX zyxx;
		SwizzleZYXY zyxy;
		SwizzleZYXZ zyxz;
		SwizzleZYXW zyxw;
		SwizzleZYYX zyyx;
		SwizzleZYYY zyyy;
		SwizzleZYYZ zyyz;
		SwizzleZYYW zyyw;
		SwizzleZYZX zyzx;
		SwizzleZYZY zyzy;
		SwizzleZYZZ zyzz;
		SwizzleZYZW zyzw;
		SwizzleZYWX zywx;
		SwizzleZYWY zywy;
		SwizzleZYWZ zywz;
		SwizzleZYWW zyww;
		SwizzleZZXX zzxx;
		SwizzleZZXY zzxy;
		SwizzleZZXZ zzxz;
		SwizzleZZXW zzxw;
		SwizzleZZYX zzyx;
		SwizzleZZYY zzyy;
		SwizzleZZYZ zzyz;
		SwizzleZZYW zzyw;
		SwizzleZZZX zzzx;
		SwizzleZZZY zzzy;
		SwizzleZZZZ zzzz;
		SwizzleZZZW zzzw;
		SwizzleZZWX zzwx;
		SwizzleZZWY zzwy;
		SwizzleZZWZ zzwz;
		SwizzleZZWW zzww;
		SwizzleZWXX zwxx;
		SwizzleZWXY zwxy;
		SwizzleZWXZ zwxz;
		SwizzleZWXW zwxw;
		SwizzleZWYX zwyx;
		SwizzleZWYY zwyy;
		SwizzleZWYZ zwyz;
		SwizzleZWYW zwyw;
		SwizzleZWZX zwzx;
		SwizzleZWZY zwzy;
		SwizzleZWZZ zwzz;
		SwizzleZWZW zwzw;
		SwizzleZWWX zwwx;
		SwizzleZWWY zwwy;
		SwizzleZWWZ zwwz;
		SwizzleZWWW zwww;
		SwizzleWXXX wxxx;
		SwizzleWXXY wxxy;
		SwizzleWXXZ wxxz;
		SwizzleWXXW wxxw;
		SwizzleWXYX wxyx;
		SwizzleWXYY wxyy;
		SwizzleWXYZ wxyz;
		SwizzleWXYW wxyw;
		SwizzleWXZX wxzx;
		SwizzleWXZY wxzy;
		SwizzleWXZZ wxzz;
		SwizzleWXZW wxzw;
		SwizzleWXWX wxwx;
		SwizzleWXWY wxwy;
		SwizzleWXWZ wxwz;
		SwizzleWXWW wxww;
		SwizzleWYXX wyxx;
		SwizzleWYXY wyxy;
		SwizzleWYXZ wyxz;
		SwizzleWYXW wyxw;
		SwizzleWYYX wyyx;
		SwizzleWYYY wyyy;
		SwizzleWYYZ wyyz;
		SwizzleWYYW wyyw;
		SwizzleWYZX wyzx;
		SwizzleWYZY wyzy;
		SwizzleWYZZ wyzz;
		SwizzleWYZW wyzw;
		SwizzleWYWX wywx;
		SwizzleWYWY wywy;
		SwizzleWYWZ wywz;
		SwizzleWYWW wyww;
		SwizzleWZXX wzxx;
		SwizzleWZXY wzxy;
		SwizzleWZXZ wzxz;
		SwizzleWZXW wzxw;
		SwizzleWZYX wzyx;
		SwizzleWZYY wzyy;
		SwizzleWZYZ wzyz;
		SwizzleWZYW wzyw;
		SwizzleWZZX wzzx;
		SwizzleWZZY wzzy;
		SwizzleWZZZ wzzz;
		SwizzleWZZW wzzw;
		SwizzleWZWX wzwx;
		SwizzleWZWY wzwy;
		SwizzleWZWZ wzwz;
		SwizzleWZWW wzww;
		SwizzleWWXX wwxx;
		SwizzleWWXY wwxy;
		SwizzleWWXZ wwxz;
		SwizzleWWXW wwxw;
		SwizzleWWYX wwyx;
		SwizzleWWYY wwyy;
		SwizzleWWYZ wwyz;
		SwizzleWWYW wwyw;
		SwizzleWWZX wwzx;
		SwizzleWWZY wwzy;
		SwizzleWWZZ wwzz;
		SwizzleWWZW wwzw;
		SwizzleWWWX wwwx;
		SwizzleWWWY wwwy;
		SwizzleWWWZ wwwz;
		SwizzleWWWW wwww;
	};
	
	// Constructors
	Vector4() : x((T)0), y((T)0), z((T)0), w((T)0) { }
	
	Vector4(const T value) : x(value), y(value), z(value), w(value) { }
	
	Vector4(const T value0, const T value1, const T value2, const T value3) : x(value0), y(value1), z(value2), w(value3) { }
	
	Vector4(const Vector4<T>& other) : x(other.x), y(other.y), z(other.z), w(other.w) { }
	
	// Arithmetic operators
	Vector4<T>& operator = (const Vector4<T>& rhs) {
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		w = rhs.w;
	}
	
	Vector4<T> operator + (const Vector4<T>& rhs) const {
		return Vector4<T>(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
	}
	
	Vector4<T> operator - (const Vector4<T>& rhs) const {
		return Vector4<T>(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
	}
	
	Vector4<T> operator + () const {
		return *this;
	}
	
	Vector4<T> operator - () const {
		return Vector4<T>(-x, -y, -z, -w);
	}
	
	Vector4<T> operator * (const Vector4<T>& rhs) const {
		return Vector4<T>(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
	}
	
	Vector4<T> operator / (const Vector4<T>& rhs) const {
		return Vector4<T>(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
	}
	
	Vector4<T>& operator += (const Vector4<T>& rhs) {
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		w += rhs.w;
		return *this;
	}
	
	Vector4<T>& operator -= (const Vector4<T>& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		w -= rhs.w;
		return *this;
	}
	
	Vector4<T>& operator *= (const Vector4<T>& rhs) {
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		w *= rhs.w;
		return *this;
	}
	
	Vector4<T>& operator /= (const Vector4<T>& rhs) {
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;
		w /= rhs.w;
		return *this;
	}
	
	// Prefix ++
	Vector4<T>& operator ++ () {
		++x;
		++y;
		++z;
		++w;
		return *this;
	}
	
	// Postfix ++
	Vector4<T> operator ++ (int) {
		const Vector4<T> ans = *this;
		++x;
		++y;
		++z;
		++w;
		return ans;
	}

	// Prefix --
	Vector4<T>& operator -- () {
		--x;
		--y;
		--z;
		--w;
		return *this;
	}
	
	// Postfix ++
	Vector4<T> operator -- (int) {
		const Vector4<T> ans = *this;
		--x;
		--y;
		--z;
		--w;
		return ans;
	}

	// Comparison operators/relational operators
	bool operator == (const Vector4<T>& rhs) const {
		return ((x == rhs.x) && (y == rhs.y) && (z == rhs.z) && (w == rhs.w));
	}
	
	bool operator != (const Vector4<T>& rhs) const {
		return ((x != rhs.x) || (y != rhs.y) || (z != rhs.z) || (w != rhs.w));
	}

	T& operator [] (const unsigned int index) {
		return d[index];
	}

	T operator [] (const unsigned int index) const {
		return d[index];
	}
};

#if defined (DEFINE_GLSL_VECTOR_TYPES)
// Vector 2
typedef Vector2<bool> bvec2;
typedef Vector2<signed int> ivec2;
typedef Vector2<unsigned int> uvec2;
typedef Vector2<float> vec2;
typedef Vector2<double> dvec2;

// Vector3
typedef Vector3<bool> bvec3;
typedef Vector3<signed int> ivec3;
typedef Vector3<unsigned int> uvec3;
typedef Vector3<float> vec3;
typedef Vector3<double> dvec3;

// Vector4
typedef Vector4<bool> bvec4;
typedef Vector4<signed int> ivec4;
typedef Vector4<unsigned int> uvec4;
typedef Vector4<float> vec4;
typedef Vector4<double> dvec4;
#endif // DEFINE_GLSL_VEC_TYPES


#endif //__VECTOR_H__
