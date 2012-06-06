#ifndef __IBUSINTERFACE_H__
#define __IBUSINTERFACE_H__
class IDeviceContext;
class IDevice;
class Data;

class IBusInterface
{
public:
	//Structures
	struct AccessResult;

	//Constructors
	virtual ~IBusInterface() = 0 {}

	//Memory interface functions
	virtual AccessResult ReadMemory(unsigned int location, Data& data, IDeviceContext* caller, double accessTime, unsigned int accessContext) = 0;
	virtual AccessResult WriteMemory(unsigned int location, const Data& data, IDeviceContext* caller, double accessTime, unsigned int accessContext) = 0;
	virtual void TransparentReadMemory(unsigned int location, Data& data, IDeviceContext* caller, unsigned int accessContext) const = 0;
	virtual void TransparentWriteMemory(unsigned int location, const Data& data, IDeviceContext* caller, unsigned int accessContext) const = 0;

	//Port interface functions
	virtual AccessResult ReadPort(unsigned int location, Data& data, IDeviceContext* caller, double accessTime, unsigned int accessContext) = 0;
	virtual AccessResult WritePort(unsigned int location, const Data& data, IDeviceContext* caller, double accessTime, unsigned int accessContext) = 0;
	virtual void TransparentReadPort(unsigned int location, Data& data, IDeviceContext* caller, unsigned int accessContext) const = 0;
	virtual void TransparentWritePort(unsigned int location, const Data& data, IDeviceContext* caller, unsigned int accessContext) const = 0;

	//Line interface functions
	//##TODO## Add some kind of function which can tell the user whether a specified line
	//has been mapped. This is intended to be used at system construction, to allow a
	//device to optimize its operation, implement default behaviour, or in any other way
	//alter its operation depending on whether a particular line has been connected or
	//not. Note that this does not have to be high performance, since lines cannot be
	//mapped dynamically while the system is running. It is up to the calling device to
	//cache the result of this function call in order to ensure the best performance.
	virtual bool SetLine(unsigned int sourceLine, const Data& lineData, IDeviceContext* sourceDevice, IDeviceContext* callingDevice, double accessTime, unsigned int accessContext) = 0;
};

#include "IBusInterface.inl"
#endif
