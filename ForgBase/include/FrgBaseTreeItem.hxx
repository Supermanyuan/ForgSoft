#pragma once
#ifndef _FrgBaseTreeItem_Header
#define _FrgBaseTreeItem_Header

#include <FrgBaseGlobals.hxx>

#include <QtWidgets/QTreeWidgetItem>

class QtTreePropertyBrowser;
class QtVariantPropertyManager;
class QtVariantEditorFactory;
class QtBrowserItem;
class QtProperty;
class QVariant;

BeginFrgBaseLib

class FrgBaseMainWindow;
class FrgBaseTree;
class FrgBaseTreeItemProperties;
class FrgBaseMenu;

class FORGBASE_EXPORT FrgBaseTreeItem : public QTreeWidgetItem
{

private:

	FrgBaseMainWindow* theParentMainWindow_ = FrgNullPtr;
	FrgBaseTree* theParentTree_ = FrgNullPtr;
	FrgString theObjectName_ = "";

	FrgBaseTreeItemProperties* theProperties_ = FrgNullPtr;

	FrgBaseMenu* theContextMenu_ = FrgNullPtr;

public:

	FrgBaseTreeItem
	(
		const FrgString& itemName,
		FrgBaseTreeItem* parentItem = FrgNullPtr,
		FrgBaseTree* parentTree = FrgNullPtr,
		FrgBaseMainWindow* parentMainWindow = FrgNullPtr
	);

	~FrgBaseTreeItem();

	FrgGetMacro(FrgBaseMainWindow*, ParentMainWindow, theParentMainWindow_);
	FrgGetMacro(FrgBaseTree*, ParentTree, theParentTree_);
	FrgGetMacro(FrgString, ObjectName, theObjectName_);
	FrgGetMacro(FrgBaseTreeItemProperties*, Properties, theProperties_);
	FrgGetMacro(FrgBaseMenu*, ContextMenu, theContextMenu_);

	void SetTreeItemName(FrgString name);
	void RenameTreeItemName(FrgString name);

	virtual void DoAfterConstruct() {}

private:

	void CreateProperties();

};

EndFrgBaseLib

#endif // !_FrgBaseTreeItem_Header
