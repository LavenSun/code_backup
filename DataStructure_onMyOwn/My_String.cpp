#include<stdio.h>
#include"My_String.h"
#include <malloc.h>
#include <string.h>

bool Concat(my_string& T, my_string s1, my_string s2)
{
	bool uncut;
	if (s1[0] + s2[0] <= MAXSTRLEN)
	{
		for (int i = 1; i <= s1[0]; i++)
			T[i] = s1[i];
		for (int i = 1; i <= s2[0]; i++)
			T[i + s1[0]] = s2[i];
		T[0] = s1[0] + s2[0];
		uncut = true;
	}
	else if (s1[0] < MAXSTRLEN)
	{
		for (int i = 1; i <= s1[0]; i++)
			T[i] = s1[i];
		for (int i = 1; i <= MAXSTRLEN - s1[0]; i++)
			T[i + s1[0]] = s2[i];
		T[0] = MAXSTRLEN;
		uncut = false;
	}
	else
	{
		for (int i = 0; i <= MAXSTRLEN; i++)
			T[i] = s1[i];
		uncut = false;
	}
	return uncut;
}

bool SubString(my_string& sub, my_string s, int pos, int len)
{
	if (pos < 1 || pos > s[0] || len < 0 || len > s[0] - pos + 1)
		return false;
	for (int i = 1; i <= len; i++)
		sub[i] = s[pos + i - 1];
	sub[0] = len;
	return true;
}

bool StrInsert(HString& s, int pos, HString T)
{
	if (pos < 1 || pos > s.length + 1)
		return false;
	if (T.length)
	{
		if (!(s.ch = (char*)realloc(s.ch, (s.length + T.length) * sizeof(char))))
			return false;
		for (int i = s.length - 1; i >= pos - 1; --i)
		{
			s.ch[i + T.length] = s.ch[i];
		}
		for (int i = 0; i < T.length; i++)
			s.ch[i + pos - 1] = T.ch[i];
		s.length += T.length;
	}
	return true;
}

bool StrAssign(HString& T, char* ch)
{
	if (T.ch)
		free(T.ch);
	int i = 0;
	char* c;
	for (i = 0, c = ch; c; ++i, ++c);
	if (!i)
	{
		T.ch = NULL;
		T.length = 0;
	}
	else
	{
		if (!(T.ch = (char*)malloc(i * sizeof(char))))
			return false;
		for (int j = 0; j < i; j++)
			T.ch[j] = ch[j];
		T.length = i;
	}
	return true;
}

int StrLength(HString s)
{
	return s.length;
}

int StrCompare(HString s, HString t)
{
	for (int i = 0; i < s.length && i < t.length; ++i)
	{
		if (s.ch[i] != t.ch[i])
			return s.ch[i] - t.ch[i];
	}
	return s.length - t.length;
}

void ClearStr(HString& s)
{
	if (s.ch)
	{
		free(s.ch);
		s.ch = NULL;
	}
	s.length = 0;
	return;
}

bool ConCat(HString& t, HString s1, HString s2)
{
	if (t.ch)
		free(t.ch);
	if (!(t.ch = (char*)malloc((s1.length + s2.length) * sizeof(char))))
		return false;
	for (int i = 0; i < s1.length; i++)
		t.ch[i] = s1.ch[i];
	t.length = s1.length + s2.length;
	for (int i = 0; i < s2.length; i++)
		t.ch[i + s1.length] = s2.ch[i];
	return true;
}

bool SubStr(HString& t, HString s, int pos, int len)
{
	if (pos < 1 || pos > s.length || len < 0 || len > s.length - pos + 1)
		return false;
	if (t.ch)
		free(t.ch);
	if (!len)
	{
		t.ch = NULL;
		t.length = 0;
	}
	else
	{
		t.ch = (char*)malloc(len * sizeof(char));
		for (int i = 0; i < len; i++)
			t.ch[i] = s.ch[i + pos - 1];
		t.length = len;
	}
	return true;
}

int Index(my_string s, my_string t, int pos)
{
	int i = pos, j = 1;
	while (i <= s[0] && j <= t[0])
	{
		if (s[i] == t[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > t[0])
		return i - t[0];
	else return 0;
}

void getNext(my_string t, int next[])
{
	int i = 1, j = 0;
	next[1] = 0;
	while (i < t[0])
	{
		if (j == 0 || t[i] == t[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else j = next[j];
	}
}

void getNextval(my_string t, int next[])
{
	int i = 1, j = 0;
	next[1] = 0;
	while (i < t[0])
	{
		if (j == 0 || t[i] == t[j])
		{
			++i;
			++j;
			if (t[i] != t[j])
				next[i] = j;
			else next[i] = next[j];
		}
		else j = next[j];
	}
}

int Index_KMP(my_string s, my_string t, int pos)
{
	int i = pos, j = 1;
	int next[MAXSTRLEN];
	getNext(t, next);
	while (i <= s[0] && j <= t[0])
	{
		if (j == 0 || s[i] == t[j])
		{
			++i;
			++j;
		}
		else j = next[j];
	}
}

