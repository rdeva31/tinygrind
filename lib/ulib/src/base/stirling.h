/* The MIT License

   Copyright (C) 2012 Zilong Tan (eric.zltan@gmail.com)

   Permission is hereby granted, free of charge, to any person obtaining
   a copy of this software and associated documentation files (the
   "Software"), to deal in the Software without restriction, including
   without limitation the rights to use, copy, modify, merge, publish,
   distribute, sublicense, and/or sell copies of the Software, and to
   permit persons to whom the Software is furnished to do so, subject to
   the following conditions:

   The above copyright notice and this permission notice shall be
   included in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
*/

#ifndef __ULIB_STIRLING_H
#define __ULIB_STIRLING_H

#include <math.h>

#define PI 3.1415926

/* compute ln(n!) using stirling's approximation */
static inline double st_perm_ln(unsigned int n)
{
	if (n == 0)
		return 0;
	return n * (log(n) - 1.0) + 0.5 * log(2 * PI * n) + 1.0 / (12 * n);
}

/* compute n! using stirling's approximation */
static inline double st_perm(unsigned int n)
{
	if (n == 0)
		return 1;
	return sqrt(2 * PI) * pow(n,
				  n + 0.5) * exp(-(double)n + 1.0 / (12 * n));
}

static inline double st_comb_ln(unsigned int n, unsigned int r)
{
	if (r == n || r == 0)
		return 0;
	return (n - r) * log((double)n / (n - r)) + r * log((double)n / r) -
	       0.5 * log(2 * PI * r * (n - r) / n) +
	       1.0 / 12 * (1.0 / n - 1.0 / (n - r) - 1.0 / r);
}

static inline double st_comb(unsigned int n, unsigned int r)
{
	if (r > n)
		return 0;
	if (n == 0 || r == 0 || n == r)
		return 1;
	/* won't calculate directly since it may cause overflow */
	return exp(st_comb_ln(n, r));
}

#endif              /* __ULIB_STIRLING_H */
