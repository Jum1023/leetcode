#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int anyof(char *s, char low, char up)
{
	for (; *s; ++s)
	{
		if (*s >= low && *s <= up)
			return 0;
	}
	return 1;
}

int strongPasswordChecker(char *s)
{
	int missing = 0, N = strlen(s);
	missing += anyof(s, '1', '9');
	missing += anyof(s, 'a', 'z');
	missing += anyof(s, 'A', 'Z');
	int change = 0, one = 0 /*mod3==0*/, two = 0 /*mod3==1*/;
	for (int i = 2; i < N; ++i)
	{
		if (s[i] == s[i - 1] && s[i] == s[i - 2])
		{
			int count = 3;
			for (; i + 1 < N && s[i] == s[i + 1]; ++i)
				++count;
			change += count / 3;
			if (count % 3 == 0)
				++one;
			else if (count % 3 == 1)
				++two;
		}
	}
	if (N < 6)
		return max(missing, 6 - N);
	if (N <= 20)
		return max(missing, change);
	int deletion = N - 20;
	change -= min(deletion, one);
	change -= min(max(deletion - one, 0) / 2, two);
	change -= max(deletion - one - two * 2, 0) / 3;
	return deletion + max(missing, change);
}
