#include "cpgf/ginterface.h"
#include "cpgf/gmetaclass.h"
#include "cpgf/gmetaapiutil.h"
#include "cpgf/gflags.h"

#include "cpgf/gmetadefine.h"
#include "cpgf/goutmain.h"

#include "gmetaarchivewriter.h"
#include "gmetaarchivereader.h"

#include "pinclude/gapiimpl.h"

#include <string.h>

#include <map>


#include <iostream>
#include <sstream>
using namespace std;


namespace cpgf {


namespace {

enum PermanentType {
	ptBool = 1,
	ptChar = 2,
	ptWchar = 3,
	ptSignedChar = 4,
	ptUnsignedChar = 5,
	ptSignedShort = 6,
	ptUnsignedShort = 7,
	ptSignedInt = 8,
	ptUnsignedInt = 9,
	ptSignedLong = 10,
	ptUnsignedLong = 11,
	ptSignedLongLong = 12,
	ptUnsignedLongLong = 13,
	ptFloat = 14,
	ptDouble = 15,
	ptLongDouble = 16,
	ptObject = 17,
	ptString = 18,
	ptWideString = 19,

	ptNull = 50, // for null pointer
	ptReferenceID = 51, // for one pointer reference to another

};

int defaultVariantTypeMap[] = {
	vtBool, ptBool,
	vtChar, ptChar,
	vtWchar, ptWchar,
	vtSignedChar, ptSignedChar,
	vtUnsignedChar, ptUnsignedChar,
	vtSignedShort, ptSignedShort,
	vtUnsignedShort, ptUnsignedShort,
	vtSignedInt, ptSignedInt,
	vtUnsignedInt, ptUnsignedInt,
	vtSignedLong, ptSignedLong,
	vtUnsignedLong, ptUnsignedLong,
	vtSignedLongLong, ptSignedLongLong,
	vtUnsignedLongLong, ptUnsignedLongLong,
	vtFloat, ptFloat,
	vtDouble, ptDouble,
	vtLongDouble, ptLongDouble,
	vtObject, ptObject,
	vtString, ptString,
	vtWideString, ptWideString,

	vtEmpty,
};

}

GVariantType getVariantTypeFromMap(int * variantTypeMap, int mappedType)
{
	while(*variantTypeMap != vtEmpty) {
		if(*(variantTypeMap + 1) == mappedType) {
			return static_cast<GVariantType>(*variantTypeMap);
		}
		variantTypeMap += 2;
	}

	return vtEmpty;
}

int getMappedTypeFromMap(int * variantTypeMap, GVariantType vt)
{
	while(*variantTypeMap != vtEmpty) {
		if(*variantTypeMap == vt) {
			return *(variantTypeMap + 1);
		}
		variantTypeMap += 2;
	}

	return -1;
}

template <typename T>
struct PermenentTypeMap
{
	typedef T Result;
};

template <>
struct PermenentTypeMap <wchar_t>
{
	typedef short Result;
};

template <typename Stream, template<typename> class TypeMap >
void streamWriteFundamental(Stream & stream, const GVariant & value)
{
	switch(value.getType()) {
		case vtBool:
			stream << fromVariant<typename TypeMap<bool>::Result>(value);
			break;

		case vtChar:
			stream << fromVariant<typename TypeMap<char>::Result>(value);
			break;

		case vtWchar:
			stream << fromVariant<typename TypeMap<wchar_t>::Result>(value);
			break;

		case vtSignedChar:
			stream << fromVariant<typename TypeMap<signed char>::Result>(value);
			break;

		case vtUnsignedChar:
			stream << fromVariant<typename TypeMap<unsigned char>::Result>(value);
			break;

		case vtSignedShort:
			stream << fromVariant<typename TypeMap<signed short>::Result>(value);
			break;

		case vtUnsignedShort:
			stream << fromVariant<typename TypeMap<unsigned short>::Result>(value);
			break;

		case vtSignedInt:
			stream << fromVariant<typename TypeMap<signed int>::Result>(value);
			break;

		case vtUnsignedInt:
			stream << fromVariant<typename TypeMap<unsigned int>::Result>(value);
			break;

		case vtSignedLong:
			stream << fromVariant<typename TypeMap<signed long>::Result>(value);
			break;

		case vtUnsignedLong:
			stream << fromVariant<typename TypeMap<unsigned long>::Result>(value);
			break;

		case vtSignedLongLong:
			stream << fromVariant<typename TypeMap<signed long long>::Result>(value);
			break;

		case vtUnsignedLongLong:
			stream << fromVariant<typename TypeMap<unsigned long long>::Result>(value);
			break;

		case vtFloat:
			stream << fromVariant<typename TypeMap<float>::Result>(value);
			break;

		case vtDouble:
			stream << fromVariant<typename TypeMap<double>::Result>(value);
			break;

		case vtLongDouble:
			stream << fromVariant<typename TypeMap<long double>::Result>(value);
			break;

		default:
			break;
	}
}

template <typename Stream, template<typename> class TypeMap >
GVariant streamReadFundamental(Stream & stream, GVariantType vt)
{
	switch(vt) {
		case vtBool: {
			typename TypeMap<bool>::Result value;
			stream >> value;
			return value;
		}

		case vtChar: {
			typename TypeMap<char>::Result value;
			stream >> value;
			return value;
		}

		case vtWchar: {
			typename TypeMap<wchar_t>::Result value;
			stream >> value;
			return value;
		}

		case vtSignedChar: {
			typename TypeMap<signed char>::Result value;
			stream >> value;
			return value;
		}

		case vtUnsignedChar: {
			typename TypeMap<unsigned char>::Result value;
			stream >> value;
			return value;
		}

		case vtSignedShort: {
			typename TypeMap<signed short>::Result value;
			stream >> value;
			return value;
		}

		case vtUnsignedShort: {
			typename TypeMap<unsigned short>::Result value;
			stream >> value;
			return value;
		}

		case vtSignedInt: {
			typename TypeMap<signed int>::Result value;
			stream >> value;
			return value;
		}

		case vtUnsignedInt: {
			typename TypeMap<unsigned int>::Result value;
			stream >> value;
			return value;
		}

		case vtSignedLong: {
			typename TypeMap<signed long>::Result value;
			stream >> value;
			return value;
		}

		case vtUnsignedLong: {
			typename TypeMap<unsigned long>::Result value;
			stream >> value;
			return value;
		}

		case vtSignedLongLong: {
			typename TypeMap<signed long long>::Result value;
			stream >> value;
			return value;
		}

		case vtUnsignedLongLong: {
			typename TypeMap<unsigned long long>::Result value;
			stream >> value;
			return value;
		}

		case vtFloat: {
			typename TypeMap<float>::Result value;
			stream >> value;
			return value;
		}

		case vtDouble: {
			typename TypeMap<double>::Result value;
			stream >> value;
			return value;
		}

		case vtLongDouble: {
			typename TypeMap<long double>::Result value;
			stream >> value;
			return value;
		}

		default:
			return 0;
	}
}

template <typename Stream, template<typename> class TypeMap = PermenentTypeMap>
class GTextStreamMetaWriter : public ImplObject, public IMetaWriter
{
private:
	enum DelimiterType {
		dtNone, dtSpace, dtNewline
	};

public:
	explicit GTextStreamMetaWriter(Stream & stream) : stream(stream), variantTypeMap(defaultVariantTypeMap), delimiter(dtNone) {
	}

protected:
	IMPL_OBJECT

	virtual void G_API_CC writeFundamental(const char * name, uint32_t archiveID, const GVariantData * value) {
		GVariant v(*value);

		this->writeType(getMappedTypeFromMap(this->variantTypeMap, v.getType()));

		this->writeDelimiter();

		streamWriteFundamental<Stream, TypeMap>(this->stream, v);
	}

	virtual void G_API_CC writeString(const char * name, uint32_t archiveID, const char * value) {
		this->writeType(ptString);
		
		this->writeDelimiter();

		size_t len = strlen(value);

		this->stream << static_cast<uint32_t>(len);

		this->writeDelimiter();

		this->stream.write(value, len);
	}

	virtual void G_API_CC writeNullPointer(const char * name) {
		this->writeType(ptNull);
	}

	virtual void G_API_CC beginWriteObject(const char * name, uint32_t archiveID, void * instance, IMetaClass * metaClass) {
		(void)name;
		(void)instance;
		(void)metaClass;

		if(this->delimiter != dtNone) {
			this->stream << '\n';
			this->delimiter = dtNone;
		}

		this->writeType(ptObject);
		this->writeDelimiter();
		this->stream << static_cast<uint32_t>(archiveID);
	}

	virtual void G_API_CC endWriteObject(const char * name, uint32_t archiveID, void * instance, IMetaClass * metaClass) {
		(void)name;
		(void)instance;
		(void)metaClass;

		this->delimiter == dtNewline;
	}

	virtual void G_API_CC writeReferenceID(const char * name, uint32_t archiveID, uint32_t referenceArchiveID) {
		this->writeType(ptReferenceID);
		
		this->writeDelimiter();
		
		this->stream << static_cast<uint32_t>(referenceArchiveID);
	}

protected:
	void writeDelimiter() {
		if(this->delimiter == dtNone) {
			this->delimiter = dtSpace;
		}
		else {
			if(this->delimiter == dtSpace) {
				this->stream << ' ';
			}
			else {
				this->stream << "\n";
				this->delimiter = dtNone;
			}
		}
	}

	void writeType(int permanentType) {
		this->writeDelimiter();
		this->stream << static_cast<uint16_t>(permanentType);
	}

private:
	Stream & stream;
	int * variantTypeMap;
	DelimiterType delimiter;
};

template <typename Stream, template<typename> class TypeMap = PermenentTypeMap>
class GTextStreamMetaReader : public ImplObject, public IMetaReader
{
private:
	class StreamMarker {
	public:
		StreamMarker(GTextStreamMetaReader * reader) : reader(reader), mark(reader->stream.tellg()) {
		}

		~StreamMarker() {
			this->reader->stream.seekg(this->mark);
		}

	private:
		GTextStreamMetaReader * reader;
		long mark;
	};

public:
	explicit GTextStreamMetaReader(Stream & stream) : stream(stream), variantTypeMap(defaultVariantTypeMap) {
	}

protected:
	IMPL_OBJECT

	virtual uint32_t G_API_CC getArchiveType(const char * name) {
		StreamMarker marker(this);
		PermanentType type = this->readType();
		switch(type) {
			case ptNull:
				return matNull;

			case ptObject:
				return matObject;

			case ptString:
				return matString;

			case ptReferenceID:
				return matReferenceObject;

			default:
				return matFundamental;
		}
	}

	virtual void G_API_CC readFundamental(const char * name, uint32_t * outArchiveID, GVariantData * outValue) {
		PermanentType type = this->readType();
		GVariantType vt = getVariantTypeFromMap(this->variantTypeMap, type);

		GVariant v(streamReadFundamental<Stream, TypeMap>(this->stream, vt));
		*outValue = v.takeData();
	}

	virtual char * G_API_CC readString(const char * name, IMemoryAllocator * allocator, uint32_t * outArchiveID) {
		PermanentType type = this->readType();
		uint32_t len;
		this->stream >> len;
		this->skipDelimiter();
		char * s = static_cast<char *>(allocator->allocate(len + 1));
		this->stream.read(s, len);
		s[len] = 0;
		return s;
	}

	virtual void * G_API_CC readNullPointer(const char * name) {
		PermanentType type = this->readType();
		if(type == ptNull) {
		}

		return NULL;
	}

	virtual void G_API_CC beginReadObject(const char * name, void * instance, IMetaClass * metaClass, uint32_t * outArchiveID) {
		(void)name;
		(void)instance;
		(void)metaClass;

		PermanentType type = this->readType();
		this->stream >> *outArchiveID;
	}

	virtual void G_API_CC endReadObject(const char * name, uint32_t archiveID, void * instance, IMetaClass * metaClass) {
		(void)name;
		(void)instance;
		(void)metaClass;

	}

	virtual uint32_t G_API_CC readReferenceID(const char * name) {
		PermanentType type = this->readType();
		uint32_t referenceArchiveID;
		this->stream >> referenceArchiveID;
		return referenceArchiveID;
	}

protected:
	void skipDelimiter() {
		this->stream.get();
	}

	PermanentType readType() {
		uint16_t type;
		this->stream >> type;
		this->skipDelimiter();
		return static_cast<PermanentType>(type);
	}

private:
	Stream & stream;
	int * variantTypeMap;
};



} // namespace cpgf


using namespace cpgf;

class TestClassSerializeBase {
public:
	TestClassSerializeBase() : baseA(5.8) {
	}

	double baseA;
};

class TestClassSerialize : public TestClassSerializeBase {
public:
	TestClassSerialize() : a(NULL), object(NULL) {
	}
	
	~TestClassSerialize() {
		delete object;
	}

	const char * a;
	int fieldInt;
	string fieldString;
	
	int fieldReadonlyInt;
	string fieldWriteonlyString;

	TestClassSerialize * object;
};


G_AUTO_RUN_BEFORE_MAIN()
{
	using namespace cpgf;

	GDefineMetaClass<TestClassSerializeBase>
		::define("TestClassSerializeBase")

		._field("baseA", &TestClassSerializeBase::baseA)
	;

	GDefineMetaClass<TestClassSerialize, TestClassSerializeBase>
		::define("TestClassSerialize")

		._field("a", &TestClassSerialize::a)
			._annotation("serialize")
				._element("enable", false)

		._field("fieldInt", &TestClassSerialize::fieldInt)
//		._field("fieldString", &TestClassSerialize::fieldString)
//		._field("fieldReadonlyInt", &TestClassSerialize::fieldReadonlyInt, GMetaPolicyReadOnly())
//		._field("fieldWriteonlyString", &TestClassSerialize::fieldWriteonlyString, GMetaPolicyWriteOnly())
		._field("object", &TestClassSerialize::object)
	;
}

void testSer()
{
	GScopedInterface<IMetaService> service(createDefaultMetaService());

	stringstream stream;

	GTextStreamMetaWriter<stringstream> outputStream(stream);
	GMetaArchiveWriter archiveWriter(GMetaArchiveWriterConfig(), service.get(), &outputStream);

	GScopedInterface<IMetaClass> metaClass(service->findClassByName("TestClassSerialize"));

	GScopedInterface<IMetaField> field;

	TestClassSerialize instance;
	TestClassSerialize * pobj = &instance;
	instance.fieldInt = 38;
	instance.a = "abcdef";
	instance.object = new TestClassSerialize;
	instance.object->fieldInt = 98;

	field.reset(metaClass->getField("fieldInt"));
//	archiveWriter.writeField(field->getName(), pobj, field.get());
	
	archiveWriter.writeObjectValue("obj", pobj, metaClass.get());

	cout << stream.str().c_str();

	stream.seekg(0);
	
	GTextStreamMetaReader<stringstream> inputStream(stream);
	GMetaArchiveReader archiveReader(GMetaArchiveReaderConfig(), service.get(), &inputStream);
	TestClassSerialize readInstance;
	archiveReader.readObject("", &readInstance, metaClass.get());
	cout << endl << "Read object" << endl;
	cout << readInstance.fieldInt << endl;
	cout << readInstance.object->fieldInt << endl;
}

