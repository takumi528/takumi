#pragma once

/**
*	@file	Easing.h
*	@brief	エフェクトに便利な関数群 詳細<http://easings.net/ja>　参考<https://qiita.com/hart_edsf/items/962ac03281b871dcc0df>
*	@author Photon
*/

#include "DxLib.h"
#include <math.h>

namespace suken {
	/**
	*	@brief　アニメーションに使える便利な関数 表現の幅をかなり広げてくれる 詳細<http://easings.net/ja>　参考<https://qiita.com/hart_edsf/items/962ac03281b871dcc0df>
	*/
	namespace easing {
		static double InQuad(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			max -= min;
			t /= totaltime;
			return max*t*t + min;
		}
		static double OutQuad(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			max -= min;
			t /= totaltime;
			return -max*t*(t - 2) + min;
		}
		static double InOutQuad(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			max -= min;
			t /= totaltime;
			if (t / 2 < 1)
				return max / 2 * t * t + min;
			--t;
			return -max * (t * (t - 2) - 1) + min;
		}
		static double InCubic(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			max -= min;
			t /= totaltime;
			return max * t*t*t + min;
		}
		static double OutCubic(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			max -= min;
			t = t / totaltime - 1;
			return max * (t*t*t + 1) + min;
		}
		static 	double InOutCubic(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			max -= min;
			t /= totaltime;
			if (t / 2 < 1)
				return max / 2 * t*t*t + min;
			t -= 2;
			return max / 2 * (t*t*t + 2) + min;
		}
		static double InQuart(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			max -= min;
			t /= totaltime;
			return max * t*t*t*t + min;
		}
		static 	double OutQuart(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			max -= min;
			t = t / totaltime - 1;
			return -max*(t*t*t*t - 1) + min;
		}
		static double InOutQuart(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			max -= min;
			t /= totaltime;
			if (t / 2 < 1)
				return max / 2 * t*t*t*t + min;
			t -= 2;
			return -max / 2 * (t*t*t*t - 2) + min;
		}
		static 	double InQuint(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			max -= min;
			t /= totaltime;
			return max*t*t*t*t*t + min;
		}
		static double OutQuint(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			max -= min;
			t = t / totaltime - 1;
			return max*(t*t*t*t*t + 1) + min;
		}
		static double InOutQuint(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			max -= min;
			t /= totaltime;
			if (t / 2 < 1)
				return max / 2 * t*t*t*t*t + min;
			t -= 2;
			return max / 2 * (t*t*t*t*t + 2) + min;
		}
		static double InSine(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			max -= min;
			return -max*cos(t*DX_PI / 2 / totaltime) + max + min;
		}
		static double OutSine(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			max -= min;
			return max * sin(t*DX_PI / 2 / totaltime) + min;
		}
		static 	double InOutSine(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			max -= min;
			return -max / 2 * (cos(t*DX_PI / totaltime) - 1) + min;
		}
		static double InExp(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			max -= min;
			return t == 0.0 ? min : max*pow(2, 10 * (t / totaltime - 1)) + min;
		}
		static double OutExp(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			max -= min;
			return t == totaltime ? max + min : max*(-pow(2, -10 * t / totaltime) + 1) + min;
		}
		static double InOutExp(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			if (t == 0.0)
				return min;
			if (t == totaltime)
				return max;
			max -= min;
			t /= totaltime;

			if (t / 2 < 1)
				return max / 2 * pow(2, 10 * (t - 1)) + min;
			--t;
			return max / 2 * (-pow(2, -10 * t) + 2) + min;

		}
		static double InCirc(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			max -= min;
			t /= totaltime;
			return -max*(sqrt(1 - t*t) - 1) + min;
		}
		static double OutCirc(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			max -= min;
			t = t / totaltime - 1;
			return max*sqrt(1 - t*t) + min;
		}
		static double InOutCirc(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			max -= min;
			t /= totaltime;
			if (t / 2 < 1)
				return -max / 2 * (sqrt(1 - t*t) - 1) + min;
			t -= 2;
			return max / 2 * (sqrt(1 - t*t) + 1) + min;
		}
		static double InElastic(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			double s = 1.70158;
			max -= min;
			double p = totaltime* 0.3;
			double v = max;
			if (t == 0) return min;
			if ((t /= totaltime) == 1) return max + min;
			if (v < 0){
				v = max;
				s = p / 4; 
			}
			else s = p / (2 * DX_PI) * asin(max / v);
			return -(v*pow(2, 10 * (t -= 1)) * sin((t*totaltime - s)*(2 * DX_PI) / p)) + min;
		}
		static double OutElastic(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			double s = 1.70158;
			max -= min;
			double p = totaltime* 0.3;
			double a = max;
			if (t == 0) return min;
			if ((t /= totaltime) == 1) return max + min;
			if (a < 0) {
				a = max;
				s = p / 4; 
			}
			else s = p / (2 * DX_PI) * asin(max / a);
			return a*pow(2, -10 * t) * sin((t*totaltime - s)*(2 * DX_PI) / p) + max + min;
		}
		static double InOutElastic(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			double s = 1.70158;
			max -= min;
			double p = totaltime*(0.3*1.5);
			double a = max;
			if (t == 0) return min;
			if ((t /= totaltime / 2) == 2) return min + max;
			if (a < 0) { a = max; s = p / 4; }
			else s = p / (2 * DX_PI) * asin(max / a);
			if (t < 1) return -.5*(a*pow(2, 10 * (t -= 1)) * sin((t*totaltime - s)*(2 * DX_PI) / p)) + min;
			return a*pow(2, -10 * (t -= 1)) * sin((t*totaltime - s)*(2 * DX_PI) / p)*.5 + max + min;
		}
		static 	double InBack(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			double s = 1.70158;
			max -= min;
			t /= totaltime;
			return max*t*t*((s + 1)*t - s) + min;
		}
		static 	double OutBack(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			double s = 1.70158;
			max -= min;
			t = t / totaltime - 1;
			return max*(t*t*((s + 1)*t + s) + 1) + min;
		}
		static 	double InOutBack(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			double s = 1.70158;
			max -= min;
			s *= 1.525;
			if (t / 2 < 1)
			{
				return max*(t*t*((s + 1)*t - s)) + min;
			}
			t -= 2;
			return max / 2 * (t*t*((s + 1)*t + s) + 2) + min;
		}
		static 	double OutBounce(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			max -= min;
			t /= totaltime;

			if (t < 1 / 2.75)
				return max*(7.5625*t*t) + min;
			else if (t < 2 / 2.75)
			{
				t -= 1.5 / 2.75;
				return max*(7.5625*t*t + 0.75) + min;
			}
			else if (t < 2.5 / 2.75)
			{
				t -= 2.25 / 2.75;
				return max*(7.5625*t*t + 0.9375) + min;
			}
			else
			{
				t -= 2.625 / 2.75;
				return max*(7.5625*t*t + 0.984375) + min;
			}
		}
		static 	double InBounce(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			return max - OutBounce(totaltime - t, totaltime, 0, max - min) + min;
		}
		static 	double InOutBounce(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			if (t < totaltime / 2)
				return InBounce(t * 2, totaltime, 0, max-min)*0.5 + min;
			else
				return OutBounce(t * 2 - totaltime, totaltime, 0, max - min)*0.5 + min + (max - min)*0.5;
		}
		static double Linear(double t, double totaltime, double min = 0.0, double max = 1.0)
		{
			return (max - min)*t / totaltime + min;
		}
	}
}