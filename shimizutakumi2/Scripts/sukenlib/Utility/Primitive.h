#pragma once

#include "../Manager.h"

namespace suken {

	/**
	*	@brief 二次元ベクトル構造体の最終形態
	*/
	template<typename T = float>
	struct Twin {
		T x, y;

		Twin() {
			x = 0;
			y = 0;
		}

		Twin(T x, T y) {
			this->x = x;
			this->y = y;
		}

		template<typename T2>
		operator Twin<T2>() {
			return Twin<T2>((T2)x, (T2)y);
		}

		virtual ~Twin() {}

		Twin<T>& operator=(const Twin<T>& vec) {
			x = vec.x;
			y = vec.y;
			return *this;
		}

		Twin<T> operator+(const Twin<T>& vec)const {
			return Twin<T>(x + vec.x, y + vec.y);
		}

		Twin<T>& operator+=(const Twin<T>& vec) {
			x += vec.x;
			y += vec.y;
			return *this;
		}

		Twin<T> operator-(const Twin<T>& vec)const {
			return Twin<T>(x - vec.x, y - vec.y);
		}

		Twin<T>& operator-=(const Twin<T>& vec) {
			x -= vec.x;
			y -= vec.y;
			return *this;
		}

		Twin<T> operator-()const {
			return Twin<T>(-x, -y);
		}

		Twin<T> operator*(const Twin<T>& vec)const {
			return Twin<T>(x * vec.x, y * vec.y);
		}

		Twin<T>& operator*=(const Twin<T>& vec) {
			x *= vec.x;
			y *= vec.y;
			return *this;
		}

		Twin<T> operator/(const Twin<T>& vec)const {
			return Twin<T>(x / vec.x, y / vec.y);
		}

		Twin<T>& operator/=(const Twin<T>& vec) {
			x /= vec.x;
			y /= vec.y;
			return *this;
		}

		Twin<T> operator*(T arg)const {
			return Twin<T>(x * arg, y * arg);
		}

		Twin<T>& operator*=(T arg) {
			x *= arg;
			y *= arg;
			return *this;
		}

		Twin<T> operator/(T arg)const {
			return Twin<T>(x / arg, y / arg);
		}

		Twin<T>& operator/=(T arg) {
			x /= arg;
			y /= arg;
			return *this;
		}

		void Set(T x, T y) {
			this->x = x;
			this->y = y;
		}

		T Dot(const Twin<T>& vec)const {
			return x*vec.x + y*vec.y;
		}

		T Cross(const Twin<T>& vec)const {
			return x*vec.y - y*vec.x;
		}

		T GetLength()const {
			return sqrtf(x*x + y*y);
		}

		T GetLengthSq()const {
			return x*x + y*y;
		}

		void Norm() {
			const T len = GetLength();
			if (len > 0.0f) {
				x /= len;
				y /= len;
			}
		}

		Twin<T> GetNorm()const {
			const T len = GetLength();
			if (len > 0.0f) {
				return Twin<T>(x / len, y / len);
			}
			return Twin<T>(0.0f, 0.0f);
		}

		Twin<T> Rotation(T rad)const {
			return Twin<T>(x*cosf(rad) - y*sinf(rad), x*sinf(rad) + y*cosf(rad));
		}

		bool IsZero() {
			if (x != 0 || y != 0) {
				return false;
			}
			else {
				return true;
			}
		}
	};

	struct Vector2D :public Twin<float> {
		Vector2D();
		Vector2D(float x, float y);
		Vector2D(const Twin<>& vec);
		~Vector2D();

		bool IsVertical(const Vector2D& vec)const;
		bool IsParallel(const Vector2D& vec)const;
		bool IsSharpAngle(const Vector2D& vec)const;
	};

	struct Line2D {
		Point2D p;
		Vector2D v;
		Line2D();
		Line2D(const Point2D& p, const Vector2D& v);
		~Line2D();

		Line2D operator+(const Twin<float>& vec)const;

		Point2D GetPoint(float t)const;
	};

	struct Segment2D :public Line2D {
		Segment2D();
		Segment2D(const Point2D& p, const Vector2D& v);
		Segment2D(const Point2D& p1, const Point2D& p2);

		Segment2D operator+(const Twin<float>& vec)const;

		Twin<float> GetEndPoint()const;
	};

	struct Circle2D {
		Point2D p;
		float r;

		Circle2D operator+(const Twin<float>& vec)const;

		Circle2D();
		Circle2D(const Point2D& p, float r);
		~Circle2D();
	};

	struct Capsule2D {
		Segment2D s;
		float r;

		Capsule2D operator+(const Twin<float>& vec)const;

		Capsule2D();
		Capsule2D(const Segment2D& s, float r);
		Capsule2D(const Point2D& p1, const Point2D& p2, float r);
		~Capsule2D();
	};

	struct AABB2D{
		Point2D p;
		Twin<float> hl;
		AABB2D();
		AABB2D(const Point2D& p, const Twin<float>& hl);
		AABB2D(const Vector2D& upperLeft, const Vector2D& lowerRight);

		float GetLengthX();
		float GetLengthY();
	};

	bool Hit(Point2D p1, Point2D p2);

	bool Hit(Segment2D s, Point2D p);

	bool Hit(Circle2D c, Point2D p);

	bool Hit(Circle2D c1, Circle2D c2);

	bool Hit(Circle2D c, Segment2D s);

	/**
	*	@brief	長方形描画
	*/
	void DrawBox(Vector2D upperLeft, Vector2D lowerRight, unsigned int color, bool fillFlag);

	/**
	*	@brief	四角形描画
	*/
	void DrawQuadrangle(Vector2D upperLeft, Vector2D upperRight, Vector2D lowerRight, Vector2D lowerLeft, unsigned int color, bool fillFlag);
}