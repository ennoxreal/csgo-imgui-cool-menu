#pragma once
#include <cstdint>

enum class ESendPropType : std::int32_t 
{
	INT = 0,
	FLOAT,
	VECTOR,
	VECTOR2D,
	STRING,
	ARRAY,
	DATATABLE,
	INT64,
	SENDPROPTYPEMAX
};

class CDataVariant
{
	union
	{
		float Float;
		std::int32_t Int;
		char* String;
		void* Data;
		float Vector[3];
		std::int64_t Int64;
	};

	ESendPropType type;
};

class CRecvProp;
class CRecvProxyData
{
public:
	CRecvProp* prop;
	CDataVariant value;
	std::int32_t element;
	std::int32_t objectID;
};

class CRecvTable 
{
public:
	CRecvProp* props;
	std::int32_t count;
	void* decoder;
	char* name;
	bool isInitialized;
	bool inMainList;
};

class CRecvProp
{
public:
	char* name;
	ESendPropType type;
	std::int32_t flags;
	std::int32_t stringBufferSize;
	bool isInsideArray;
	const void* extraData;
	CRecvProp* prop;
	void* arrayLengthProxyFn;
	void* proxyFn;
	void* dataTableProxyFn;
	CRecvTable* table;
	unsigned int offset;
	std::int32_t stride;
	std::int32_t elements;
	const char* parentPropName;
};
