//
// Generated file, do not edit! Created by nedtool 5.2 from App_pck.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "App_pck_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp


// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(App_pck)

App_pck::App_pck(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    data_arraysize = 0;
    this->data = 0;
}

App_pck::App_pck(const App_pck& other) : ::omnetpp::cPacket(other)
{
    data_arraysize = 0;
    this->data = 0;
    copy(other);
}

App_pck::~App_pck()
{
    delete [] this->data;
}

App_pck& App_pck::operator=(const App_pck& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void App_pck::copy(const App_pck& other)
{
    delete [] this->data;
    this->data = (other.data_arraysize==0) ? nullptr : new char[other.data_arraysize];
    data_arraysize = other.data_arraysize;
    for (unsigned int i=0; i<data_arraysize; i++)
        this->data[i] = other.data[i];
}

void App_pck::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    b->pack(data_arraysize);
    doParsimArrayPacking(b,this->data,data_arraysize);
}

void App_pck::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    delete [] this->data;
    b->unpack(data_arraysize);
    if (data_arraysize==0) {
        this->data = 0;
    } else {
        this->data = new char[data_arraysize];
        doParsimArrayUnpacking(b,this->data,data_arraysize);
    }
}

void App_pck::setDataArraySize(unsigned int size)
{
    char *data2 = (size==0) ? nullptr : new char[size];
    unsigned int sz = data_arraysize < size ? data_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        data2[i] = this->data[i];
    for (unsigned int i=sz; i<size; i++)
        data2[i] = 0;
    data_arraysize = size;
    delete [] this->data;
    this->data = data2;
}

unsigned int App_pck::getDataArraySize() const
{
    return data_arraysize;
}

char App_pck::getData(unsigned int k) const
{
    if (k>=data_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", data_arraysize, k);
    return this->data[k];
}

void App_pck::setData(unsigned int k, char data)
{
    if (k>=data_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", data_arraysize, k);
    this->data[k] = data;
}

class App_pckDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    App_pckDescriptor();
    virtual ~App_pckDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(App_pckDescriptor)

App_pckDescriptor::App_pckDescriptor() : omnetpp::cClassDescriptor("App_pck", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

App_pckDescriptor::~App_pckDescriptor()
{
    delete[] propertynames;
}

bool App_pckDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<App_pck *>(obj)!=nullptr;
}

const char **App_pckDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *App_pckDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int App_pckDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int App_pckDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *App_pckDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "data",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int App_pckDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "data")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *App_pckDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "char",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **App_pckDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *App_pckDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int App_pckDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    App_pck *pp = (App_pck *)object; (void)pp;
    switch (field) {
        case 0: return pp->getDataArraySize();
        default: return 0;
    }
}

const char *App_pckDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    App_pck *pp = (App_pck *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string App_pckDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    App_pck *pp = (App_pck *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getData(i));
        default: return "";
    }
}

bool App_pckDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    App_pck *pp = (App_pck *)object; (void)pp;
    switch (field) {
        case 0: pp->setData(i,string2long(value)); return true;
        default: return false;
    }
}

const char *App_pckDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *App_pckDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    App_pck *pp = (App_pck *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(IP_pck)

IP_pck::IP_pck(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->destIp = 0;
    this->srcIP = 0;
    this->reserved1 = 0;
    this->length = 0;
    this->id = 0;
    this->fregOffset = 0;
    this->TTL = 0;
    this->protocol = 0;
    this->checksum = 0;
}

IP_pck::IP_pck(const IP_pck& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

IP_pck::~IP_pck()
{
}

IP_pck& IP_pck::operator=(const IP_pck& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void IP_pck::copy(const IP_pck& other)
{
    this->destIp = other.destIp;
    this->srcIP = other.srcIP;
    this->reserved1 = other.reserved1;
    this->length = other.length;
    this->id = other.id;
    this->fregOffset = other.fregOffset;
    this->TTL = other.TTL;
    this->protocol = other.protocol;
    this->checksum = other.checksum;
}

void IP_pck::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->destIp);
    doParsimPacking(b,this->srcIP);
    doParsimPacking(b,this->reserved1);
    doParsimPacking(b,this->length);
    doParsimPacking(b,this->id);
    doParsimPacking(b,this->fregOffset);
    doParsimPacking(b,this->TTL);
    doParsimPacking(b,this->protocol);
    doParsimPacking(b,this->checksum);
}

void IP_pck::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->destIp);
    doParsimUnpacking(b,this->srcIP);
    doParsimUnpacking(b,this->reserved1);
    doParsimUnpacking(b,this->length);
    doParsimUnpacking(b,this->id);
    doParsimUnpacking(b,this->fregOffset);
    doParsimUnpacking(b,this->TTL);
    doParsimUnpacking(b,this->protocol);
    doParsimUnpacking(b,this->checksum);
}

int IP_pck::getDestIp() const
{
    return this->destIp;
}

void IP_pck::setDestIp(int destIp)
{
    this->destIp = destIp;
}

int IP_pck::getSrcIP() const
{
    return this->srcIP;
}

void IP_pck::setSrcIP(int srcIP)
{
    this->srcIP = srcIP;
}

short IP_pck::getReserved1() const
{
    return this->reserved1;
}

void IP_pck::setReserved1(short reserved1)
{
    this->reserved1 = reserved1;
}

short IP_pck::getLength() const
{
    return this->length;
}

void IP_pck::setLength(short length)
{
    this->length = length;
}

short IP_pck::getId() const
{
    return this->id;
}

void IP_pck::setId(short id)
{
    this->id = id;
}

short IP_pck::getFregOffset() const
{
    return this->fregOffset;
}

void IP_pck::setFregOffset(short fregOffset)
{
    this->fregOffset = fregOffset;
}

char IP_pck::getTTL() const
{
    return this->TTL;
}

void IP_pck::setTTL(char TTL)
{
    this->TTL = TTL;
}

char IP_pck::getProtocol() const
{
    return this->protocol;
}

void IP_pck::setProtocol(char protocol)
{
    this->protocol = protocol;
}

short IP_pck::getChecksum() const
{
    return this->checksum;
}

void IP_pck::setChecksum(short checksum)
{
    this->checksum = checksum;
}

class IP_pckDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IP_pckDescriptor();
    virtual ~IP_pckDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(IP_pckDescriptor)

IP_pckDescriptor::IP_pckDescriptor() : omnetpp::cClassDescriptor("IP_pck", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

IP_pckDescriptor::~IP_pckDescriptor()
{
    delete[] propertynames;
}

bool IP_pckDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IP_pck *>(obj)!=nullptr;
}

const char **IP_pckDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IP_pckDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IP_pckDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int IP_pckDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<9) ? fieldTypeFlags[field] : 0;
}

const char *IP_pckDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "destIp",
        "srcIP",
        "reserved1",
        "length",
        "id",
        "fregOffset",
        "TTL",
        "protocol",
        "checksum",
    };
    return (field>=0 && field<9) ? fieldNames[field] : nullptr;
}

int IP_pckDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destIp")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcIP")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "reserved1")==0) return base+2;
    if (fieldName[0]=='l' && strcmp(fieldName, "length")==0) return base+3;
    if (fieldName[0]=='i' && strcmp(fieldName, "id")==0) return base+4;
    if (fieldName[0]=='f' && strcmp(fieldName, "fregOffset")==0) return base+5;
    if (fieldName[0]=='T' && strcmp(fieldName, "TTL")==0) return base+6;
    if (fieldName[0]=='p' && strcmp(fieldName, "protocol")==0) return base+7;
    if (fieldName[0]=='c' && strcmp(fieldName, "checksum")==0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IP_pckDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "short",
        "short",
        "short",
        "short",
        "char",
        "char",
        "short",
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : nullptr;
}

const char **IP_pckDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *IP_pckDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int IP_pckDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IP_pck *pp = (IP_pck *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IP_pckDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IP_pck *pp = (IP_pck *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IP_pckDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IP_pck *pp = (IP_pck *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getDestIp());
        case 1: return long2string(pp->getSrcIP());
        case 2: return long2string(pp->getReserved1());
        case 3: return long2string(pp->getLength());
        case 4: return long2string(pp->getId());
        case 5: return long2string(pp->getFregOffset());
        case 6: return long2string(pp->getTTL());
        case 7: return long2string(pp->getProtocol());
        case 8: return long2string(pp->getChecksum());
        default: return "";
    }
}

bool IP_pckDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IP_pck *pp = (IP_pck *)object; (void)pp;
    switch (field) {
        case 0: pp->setDestIp(string2long(value)); return true;
        case 1: pp->setSrcIP(string2long(value)); return true;
        case 2: pp->setReserved1(string2long(value)); return true;
        case 3: pp->setLength(string2long(value)); return true;
        case 4: pp->setId(string2long(value)); return true;
        case 5: pp->setFregOffset(string2long(value)); return true;
        case 6: pp->setTTL(string2long(value)); return true;
        case 7: pp->setProtocol(string2long(value)); return true;
        case 8: pp->setChecksum(string2long(value)); return true;
        default: return false;
    }
}

const char *IP_pckDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *IP_pckDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IP_pck *pp = (IP_pck *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Eth_pck)

Eth_pck::Eth_pck(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->length = 0;
}

Eth_pck::Eth_pck(const Eth_pck& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

Eth_pck::~Eth_pck()
{
}

Eth_pck& Eth_pck::operator=(const Eth_pck& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void Eth_pck::copy(const Eth_pck& other)
{
    this->srcMac = other.srcMac;
    this->destMac = other.destMac;
    this->length = other.length;
}

void Eth_pck::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->srcMac);
    doParsimPacking(b,this->destMac);
    doParsimPacking(b,this->length);
}

void Eth_pck::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->srcMac);
    doParsimUnpacking(b,this->destMac);
    doParsimUnpacking(b,this->length);
}

const char * Eth_pck::getSrcMac() const
{
    return this->srcMac.c_str();
}

void Eth_pck::setSrcMac(const char * srcMac)
{
    this->srcMac = srcMac;
}

const char * Eth_pck::getDestMac() const
{
    return this->destMac.c_str();
}

void Eth_pck::setDestMac(const char * destMac)
{
    this->destMac = destMac;
}

short Eth_pck::getLength() const
{
    return this->length;
}

void Eth_pck::setLength(short length)
{
    this->length = length;
}

class Eth_pckDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Eth_pckDescriptor();
    virtual ~Eth_pckDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(Eth_pckDescriptor)

Eth_pckDescriptor::Eth_pckDescriptor() : omnetpp::cClassDescriptor("Eth_pck", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

Eth_pckDescriptor::~Eth_pckDescriptor()
{
    delete[] propertynames;
}

bool Eth_pckDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Eth_pck *>(obj)!=nullptr;
}

const char **Eth_pckDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Eth_pckDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Eth_pckDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Eth_pckDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *Eth_pckDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcMac",
        "destMac",
        "length",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int Eth_pckDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcMac")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destMac")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "length")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Eth_pckDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "short",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **Eth_pckDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *Eth_pckDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int Eth_pckDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Eth_pck *pp = (Eth_pck *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Eth_pckDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Eth_pck *pp = (Eth_pck *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Eth_pckDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Eth_pck *pp = (Eth_pck *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSrcMac());
        case 1: return oppstring2string(pp->getDestMac());
        case 2: return long2string(pp->getLength());
        default: return "";
    }
}

bool Eth_pckDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Eth_pck *pp = (Eth_pck *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrcMac((value)); return true;
        case 1: pp->setDestMac((value)); return true;
        case 2: pp->setLength(string2long(value)); return true;
        default: return false;
    }
}

const char *Eth_pckDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *Eth_pckDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Eth_pck *pp = (Eth_pck *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(ARP)

ARP::ARP(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->type = 0;
    this->srcIP = 0;
    this->destIP = 0;
}

ARP::ARP(const ARP& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

ARP::~ARP()
{
}

ARP& ARP::operator=(const ARP& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void ARP::copy(const ARP& other)
{
    this->type = other.type;
    this->srcMac = other.srcMac;
    this->destMac = other.destMac;
    this->srcIP = other.srcIP;
    this->destIP = other.destIP;
}

void ARP::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->srcMac);
    doParsimPacking(b,this->destMac);
    doParsimPacking(b,this->srcIP);
    doParsimPacking(b,this->destIP);
}

void ARP::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->srcMac);
    doParsimUnpacking(b,this->destMac);
    doParsimUnpacking(b,this->srcIP);
    doParsimUnpacking(b,this->destIP);
}

char ARP::getType() const
{
    return this->type;
}

void ARP::setType(char type)
{
    this->type = type;
}

const char * ARP::getSrcMac() const
{
    return this->srcMac.c_str();
}

void ARP::setSrcMac(const char * srcMac)
{
    this->srcMac = srcMac;
}

const char * ARP::getDestMac() const
{
    return this->destMac.c_str();
}

void ARP::setDestMac(const char * destMac)
{
    this->destMac = destMac;
}

int ARP::getSrcIP() const
{
    return this->srcIP;
}

void ARP::setSrcIP(int srcIP)
{
    this->srcIP = srcIP;
}

int ARP::getDestIP() const
{
    return this->destIP;
}

void ARP::setDestIP(int destIP)
{
    this->destIP = destIP;
}

class ARPDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    ARPDescriptor();
    virtual ~ARPDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(ARPDescriptor)

ARPDescriptor::ARPDescriptor() : omnetpp::cClassDescriptor("ARP", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

ARPDescriptor::~ARPDescriptor()
{
    delete[] propertynames;
}

bool ARPDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ARP *>(obj)!=nullptr;
}

const char **ARPDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ARPDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ARPDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int ARPDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *ARPDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "srcMac",
        "destMac",
        "srcIP",
        "destIP",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int ARPDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcMac")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destMac")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcIP")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "destIP")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ARPDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "char",
        "string",
        "string",
        "int",
        "int",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **ARPDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ARPDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ARPDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ARP *pp = (ARP *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ARPDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ARP *pp = (ARP *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ARPDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ARP *pp = (ARP *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getType());
        case 1: return oppstring2string(pp->getSrcMac());
        case 2: return oppstring2string(pp->getDestMac());
        case 3: return long2string(pp->getSrcIP());
        case 4: return long2string(pp->getDestIP());
        default: return "";
    }
}

bool ARPDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ARP *pp = (ARP *)object; (void)pp;
    switch (field) {
        case 0: pp->setType(string2long(value)); return true;
        case 1: pp->setSrcMac((value)); return true;
        case 2: pp->setDestMac((value)); return true;
        case 3: pp->setSrcIP(string2long(value)); return true;
        case 4: pp->setDestIP(string2long(value)); return true;
        default: return false;
    }
}

const char *ARPDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *ARPDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ARP *pp = (ARP *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


