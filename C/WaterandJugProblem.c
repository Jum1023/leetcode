

int gcd(int x, int y)
{
	if (x == 0)
		return y;
	return gcd(y % x, x);
}

bool canMeasureWater(int x, int y, int z)
{
	if (z > x + y)
		return false;
	if (x == 0)
		return z == y || z == 0;
	if (y == 0)
		return z == x || z == 0;
	return z % gcd(x, y) == 0;
}

