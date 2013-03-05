//----------------------------------------------------------------------------------------
//Interface version functions
//----------------------------------------------------------------------------------------
unsigned int IExtension::ThisIExtensionVersion()
{
	return 1;
}

//----------------------------------------------------------------------------------------
//Reference functions
//----------------------------------------------------------------------------------------
bool IExtension::AddReference(const std::wstring& referenceName, IDevice* target)
{
	return AddReferenceInternal(referenceName.c_str(), target);
}

//----------------------------------------------------------------------------------------
bool IExtension::AddReference(const std::wstring& referenceName, IExtension* target)
{
	return AddReferenceInternal(referenceName.c_str(), target);
}

//----------------------------------------------------------------------------------------
bool IExtension::AddReference(const std::wstring& referenceName, IBusInterface* target)
{
	return AddReferenceInternal(referenceName.c_str(), target);
}

//----------------------------------------------------------------------------------------
bool IExtension::AddReference(const std::wstring& referenceName, IClockSource* target)
{
	return AddReferenceInternal(referenceName.c_str(), target);
}

//----------------------------------------------------------------------------------------
std::wstring IExtension::GetExtensionClassName() const
{
	return GetExtensionClassNameInternal();
}

//----------------------------------------------------------------------------------------
std::wstring IExtension::GetExtensionInstanceName() const
{
	return GetExtensionInstanceNameInternal();
}

//----------------------------------------------------------------------------------------
//Window functions
//----------------------------------------------------------------------------------------
void IExtension::RestoreViewModelState(const std::wstring& viewModelGroupName, const std::wstring& viewModelName, IHeirarchicalStorageNode& node, int xpos, int ypos, int width, int height, IViewModelLauncher& viewModelLauncher)
{
	RestoreViewModelStateInternal(viewModelGroupName.c_str(), viewModelName.c_str(), node, xpos, ypos, width, height, viewModelLauncher);
}

//----------------------------------------------------------------------------------------
void IExtension::OpenViewModel(const std::wstring& viewModelGroupName, const std::wstring& viewModelName, IViewModelLauncher& viewModelLauncher)
{
	OpenViewModelInternal(viewModelGroupName.c_str(), viewModelName.c_str(), viewModelLauncher);
}
