#pragma once
#include "math.h"
#define PI 3.141592


namespace ya {


	struct Vector2
	{
		static Vector2 Zero;
		static Vector2 One;
		static Vector2 Right;
		static Vector2 Left;
		static Vector2 Up;
		static Vector2 Down;

		float x;
		float y;

		Vector2(float x, float y)
		{
			this->x = x;
			this->y = y;
		}

		Vector2(const Vector2& other) = default;
		Vector2() = default;
		~Vector2() = default;

		Vector2 operator / (const float value)
		{
			Vector2 temp;
			temp.x = x / value;
			temp.y = y / value;

			return temp;
		}

		Vector2 operator +(const Vector2& other)
		{
			Vector2 temp;
			temp.x = x + other.x;
			temp.y = y + other.y;

			return temp;
		}


		Vector2 operator -(const Vector2& other)
		{
			Vector2 temp;
			temp.x = x - other.x;
			temp.y = y - other.y;

			return temp;
		}

		void operator +=(const Vector2& other)
		{
			x += other.x;
			y += other.y;
		}

		float Length()
		{
			return sqrtf((x * x) + (y * y));
		}

		Vector2& Normailize()
		{
			float length = Length();

			x /= length;
			y /= length;

			return *this;

		}
	};

	namespace math {
		__forceinline float DegreeToRadian(float degree)
		{
			return degree * (180.0f / PI);
		}

		__forceinline float RadianToDegree(float radian)
		{
			return radian * (PI / 180.0f);
		}

		inline Vector2 Rotate(const Vector2 value,float degeree)
		{
			Vector2 ret = Vector2::Zero;
			float radian = DegreeToRadian(degeree);
			ret.x = value.x * cosf(radian) - value.y * sinf(radian);
			ret.y = value.x * sinf(radian) + value.y * cosf(radian);

			return ret;
		}
	}
}