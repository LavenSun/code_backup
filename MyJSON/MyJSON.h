#pragma once
#ifndef _MyJSON_H_
#define _MyJSON_H_

/*
{
	"name": "Jack (\"Bee\") Nimble",
	"format":{
		"type":		 "rect",
		"width":	 1920,
		"height":	 1080,
		"interface"; false,
		"frame rate":24
	}
}
*/

#define MyJSON_False 0
#define MyJSON_True 1
#define MyJSON_NULL 2
#define MyJSON_Number 3
#define MyJSON_String 4
#define MyJSON_Array 5
#define MyJSON_Object 6

#define MyJSON_AddFalseToObject(object, name)\
	MyJSON_AddItemToObject(object, name, MyJSON_CreateFalse())

#define MyJSON_AddTrueToObject(object, name)\
	MyJSON_AddItemToObject(object, name, MyJSON_CreateTrue())

#define MyJSON_AddFalseToObject(object, name, b)\
	MyJSON_AddItemToObject(object, name, MyJSON_CreateBool(b))

#define MyJSON_AddNullToObject(object, name)\
	MyJSON_AddItemToObject(object, name, MyJSON_CreateNull())

#define MyJSON_AddNumberToObject(object, name, number)\
	MyJSON_AddItemToObject(object, name, MyJSON_CreateNumber(number))

#define MyJSON_AddStringToObject(object, name, s)\
	MyJSON_AddItemToObject(object, name, MyJSON_CreateString(s))

#define MyJSON_SetIntValue(object, val)\
	((object)?(object->valueInt = object->valueDouble = val):(val))

#define MyJSON_SetNumberValue(object, val)\
	((object)?(object->valueInt = object->valueDouble = val):(val))

typedef struct MyJSON
{
	struct MyJSON* next, * pre;
	struct MyJSON* child;

	/*array和object类型需要设子节点*/
	int type;
	char* valueString;
	int valueInt; 
	double valueDouble;
	char* String;
}MyJSON;

/*常用解析函数*/
/*
  函数功能：解析json数据，将其填入json树
  返回值为json树的根结点
*/
MyJSON* MyJSON_Parse(const char* value);

char* MyJSON_Print(MyJSON* item);

void MyJSON_Delete(MyJSON *item);

MyJSON* MyJSON_CreateObject();

MyJSON* MyJSON_CreateString(const char* String);

MyJSON* MyJSON_CreateNumber(double num);

MyJSON* MyJSON_CreateArray();

MyJSON* MyJSON_CreateBool(int b);
MyJSON* MyJSON_CreateTrue();
MyJSON* MyJSON_CreateFalse();
MyJSON* MyJSON_CreateNull();

void MyJSON_AddItemToObject(MyJSON* object, char* String, MyJSON* item);

void MyJSON_AddItemToArray(MyJSON* array, MyJSON* item);

MyJSON* MyJSON_ParseWithOptions(const char* value, const char** return_parse_end, int require_null_terminated);

MyJSON* MyJSON_NewItem();

const char* parse_value(MyJSON* item, const char* value);

const char* parse_string(MyJSON* item, const char* value);

const char* parse_number(MyJSON* item, const char* value);

const char* parse_array(MyJSON* item, const char* value);

const char* parse_object(MyJSON* item, const char* value);

const char* skip(const char* in);

#endif // !_MyJSON_H_
