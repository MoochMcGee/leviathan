#include "DebugMenuHandler.h"
#include "VRAMViewModel.h"
#include "PaletteViewModel.h"
#include "ImageViewModel.h"
#include "RegistersViewModel.h"
#include "LayerRemovalViewModel.h"
#include "SettingsViewModel.h"
#include "SpriteListViewModel.h"
#include "SpriteListDetailsViewModel.h"
#include "PortMonitorViewModel.h"
#include "PortMonitorDetailsViewModel.h"

//----------------------------------------------------------------------------------------
//Constructors
//----------------------------------------------------------------------------------------
VDP::DebugMenuHandler::DebugMenuHandler(VDP* adevice)
:MenuHandlerBase(L"VDPDebugMenu"), device(adevice)
{}

//----------------------------------------------------------------------------------------
//Window functions
//----------------------------------------------------------------------------------------
void VDP::DebugMenuHandler::OpenSpriteListDetailsView(unsigned int aspriteMappingAddress, unsigned int aspriteIndex)
{
	IViewModel* viewModelBase = GetViewModelIfOpen(MENUITEM_SPRITELISTDETAILS);
	if(viewModelBase != 0)
	{
		SpriteListDetailsViewModel* viewModel = dynamic_cast<SpriteListDetailsViewModel*>(viewModelBase);
		if(viewModel != 0)
		{
			viewModel->SetSpriteAddress(aspriteMappingAddress, aspriteIndex);
		}
	}
	else
	{
		viewModelBase = new SpriteListDetailsViewModel(GetMenuHandlerName(), GetMenuItemName(MENUITEM_SPRITELISTDETAILS), MENUITEM_SPRITELISTDETAILS, device, aspriteMappingAddress, aspriteIndex);
		if(!AddCreatedViewModel(MENUITEM_SPRITELISTDETAILS, viewModelBase))
		{
			delete viewModelBase;
		}
	}
}

//----------------------------------------------------------------------------------------
void VDP::DebugMenuHandler::OpenPortMonitorDetailsView(const PortMonitorEntry& aentry)
{
	IViewModel* viewModelBase = GetViewModelIfOpen(MENUITEM_PORTMONITORDETAILS);
	if(viewModelBase != 0)
	{
		PortMonitorDetailsViewModel* viewModel = dynamic_cast<PortMonitorDetailsViewModel*>(viewModelBase);
		if(viewModel != 0)
		{
			viewModel->SetPortMonitorEntry(aentry);
		}
	}
	else
	{
		viewModelBase = new PortMonitorDetailsViewModel(GetMenuHandlerName(), GetMenuItemName(MENUITEM_PORTMONITORDETAILS), MENUITEM_PORTMONITORDETAILS, device, aentry);
		if(!AddCreatedViewModel(MENUITEM_PORTMONITORDETAILS, viewModelBase))
		{
			delete viewModelBase;
		}
	}
}

//----------------------------------------------------------------------------------------
//Management functions
//----------------------------------------------------------------------------------------
void VDP::DebugMenuHandler::GetMenuItems(std::list<MenuItemDefinition>& menuItems) const
{
	menuItems.push_back(MenuItemDefinition(MENUITEM_VRAMVIEWER, L"VRAMPatterns", L"VRAM Pattern Viewer", true));
	menuItems.push_back(MenuItemDefinition(MENUITEM_PALETTEVIEWER, L"Palette", L"Palette", true));
	menuItems.push_back(MenuItemDefinition(MENUITEM_IMAGE, L"Image", L"Image", true));
	menuItems.push_back(MenuItemDefinition(MENUITEM_REGISTERS, L"Registers", L"Registers", true));
	menuItems.push_back(MenuItemDefinition(MENUITEM_LAYERREMOVAL, L"LayerRemoval", L"Layer Removal", true));
	menuItems.push_back(MenuItemDefinition(MENUITEM_SETTINGS, L"Settings", L"Settings", true));
	menuItems.push_back(MenuItemDefinition(MENUITEM_SPRITELIST, L"SpriteList", L"Sprite List", true));
	menuItems.push_back(MenuItemDefinition(MENUITEM_SPRITELISTDETAILS, L"SpriteListDetails", L"Sprite List Details", true, true));
	menuItems.push_back(MenuItemDefinition(MENUITEM_PORTMONITOR, L"PortMonitor", L"Port Monitor", true));
	menuItems.push_back(MenuItemDefinition(MENUITEM_PORTMONITORDETAILS, L"PortMonitorDetails", L"Port Monitor Details", true, true));
}

//----------------------------------------------------------------------------------------
IViewModel* VDP::DebugMenuHandler::CreateViewModelForItem(int menuItemID, const std::wstring& viewModelName)
{
	switch(menuItemID)
	{
	case MENUITEM_VRAMVIEWER:
		return new VRAMViewModel(GetMenuHandlerName(), viewModelName, MENUITEM_VRAMVIEWER, device);
	case MENUITEM_PALETTEVIEWER:
		return new PaletteViewModel(GetMenuHandlerName(), viewModelName, MENUITEM_PALETTEVIEWER, device);
	case MENUITEM_IMAGE:
		return new ImageViewModel(GetMenuHandlerName(), viewModelName, MENUITEM_IMAGE, device);
	case MENUITEM_REGISTERS:
		return new RegistersViewModel(GetMenuHandlerName(), viewModelName, MENUITEM_REGISTERS, device);
	case MENUITEM_LAYERREMOVAL:
		return new LayerRemovalViewModel(GetMenuHandlerName(), viewModelName, MENUITEM_LAYERREMOVAL, device);
	case MENUITEM_SETTINGS:
		return new SettingsViewModel(GetMenuHandlerName(), viewModelName, MENUITEM_SETTINGS, device);
	case MENUITEM_SPRITELIST:
		return new SpriteListViewModel(GetMenuHandlerName(), viewModelName, MENUITEM_SPRITELIST, device);
	case MENUITEM_PORTMONITOR:
		return new PortMonitorViewModel(GetMenuHandlerName(), viewModelName, MENUITEM_PORTMONITOR, device);
	}
	return 0;
}

//----------------------------------------------------------------------------------------
void VDP::DebugMenuHandler::DeleteViewModelForItem(int menuItemID, IViewModel* viewModel)
{
	delete viewModel;
}
