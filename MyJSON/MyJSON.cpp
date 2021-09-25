#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<cmath>
#include"MyJSON.h"
#include<iostream>
using namespace std;

static void* (*MyJSON_malloc)(size_t sz) = malloc;
static void(*MyJSON_free)(void* ptr) = free;

static const char* ep;

const char* skip(const char* in)
{
	while (in && *in && (unsigned char)*in <= 32)
		in++;
	return in;
}

MyJSON* MyJSON_NewItem()
{
	MyJSON* node = (MyJSON*)MyJSON_malloc(sizeof(MyJSON));
	if (node)
		memset(node, 0, sizeof(MyJSON));
	return node;
}

const char* parse_string(MyJSON* item, const char* value)
{
	const char* ptr = value + 1;
	char* out;
	char* ptr2;
	int len = 0;
	if (*value != '\"')
	{
		ep = value;
		return NULL;
	}
	while (*ptr != '\"' && *ptr && ++len)
	{
		if (*ptr++ == '\\')
			ptr++;
	}
	out = (char*)MyJSON_malloc(len + 1);
	if (!out)
		return NULL;
	ptr = value + 1;
	ptr2 = out;
	while (*ptr != '"' && *ptr)
	{
		if (*ptr != '\\')
			*ptr2++ = *ptr++;
	}
	*ptr2 = 0;
	if (*ptr == '"')
		ptr++;
	item->valueString = out;
	item->type = MyJSON_String;
	return ptr;
}

const char* parse_number(MyJSON* item, const char* value)
{
	int sign = 1;
	double n;
	int scale = 0;
	int subscale = 0;
	int signsubscale = 1;
	if (*value == '-')
	{
		sign = -1;
		value++;
	}
	if (*value == '0')
		value++;
	if (*value >= '0' && *value <= '9')
	{
		do
		{
			n = n * 10.0 + *value++ - '0';
		} while (*value >= '0' && *value <= '9');
	}
	if (*value == '.' && value[1] >= '0' && value[1] <= '9')
	{
		value++;
		do
		{
			n = n * 10.0 + *value++ - '0';
			scale--;
		} while (*value >= '0' && *value <= '9');
	}
	if (*value == 'e' || *value == 'E')
	{
		value++;
		if (*value == '+')
			value++;
		else if (*value == '-')
		{
			signsubscale = -1;
			value++;
		}
		do
		{
			subscale = subscale * 10.0 + *value++ - '0';
		} while (*value >= '0' && *value <= '9');
	}
	n = sign * n * pow(10.0, (scale + signsubscale * subscale));
	item->valueDouble = n;
	item->valueInt = static_cast<int>(n);
	item->type = MyJSON_Number;
	return value;
}

const char* parse_array(MyJSON* item, const char* value)
{
	MyJSON* child;
	if (*value != '[')
	{
		ep = value;
		return NULL;
	}
	item->type = MyJSON_Array;
	value = skip(value + 1);
	if (*value == ']')
		return value + 1;
	item->child = child = MyJSON_NewItem();
	if (!item->child)
		return NULL;
	value = skip(parse_value(child, skip(value)));
	if (!value)
		return NULL;
	while (*value == ',')
	{
		MyJSON* new_item;
		new_item = MyJSON_NewItem();
		if (!new_item)
			return NULL; 
		child->next = new_item;
		new_item->pre = child;
		child = new_item;
		value = skip(parse_value(child, skip(value + 1)));
		if (!value)
			return NULL;
	}
	if (*value == ']')
		return value + 1;
	ep = value;
	return NULL;
}

const char* parse_object(MyJSON* item, const char* value)
{

}

const char* parse_value(MyJSON* item, const char* value)
{
	if (!value)
		return NULL;
	if (!strncmp(value, "false", 5))
	{
		item->type = MyJSON_False;
		return value + 5;
	}
	if (!strncmp(value, "true", 4))
	{
		item->type = MyJSON_True;
		item->valueInt = 1;
		return value + 4;
	}
	if (!strncmp(value, "null", 4))
	{
		item->type = MyJSON_NULL;
		return value + 4;
	}
	if (*value == '\"')
		return parse_string(item, value);
	if (*value == '-' || (*value >= '0' && *value <= '9'))
		return parse_number(item, value);
	if (*value == '[')
		return parse_array(item, value);
	if (*value == '{')
		return parse_object(item, value);
}

MyJSON* MyJSON_Parse(const char* value)
{
	return MyJSON_ParseWithOptions(value, 0, 0);
}

MyJSON* MyJSON_ParseWithOptions(const char* value, const char** return_parse_end, int require_null_terminated)
{
	const char* end = NULL;
	MyJSON* c = MyJSON_NewItem();
	ep = NULL;
	if (!c)
		return NULL;
	parse_value();
}