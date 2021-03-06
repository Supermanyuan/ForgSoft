#include <FrgBaseTree.hxx>
#include <FrgBaseTreeItem.hxx>
#include <FrgBaseMainWindow.hxx>
#include <FrgBaseTreeItemProperties.hxx>

#include <QtWidgets/QHeaderView>
#include <QtWidgets/QDockWidget>
#include <FrgBaseMenu.hxx>
#include <QKeyEvent>
#include <QtCore/QMutableListIterator>
#include <QtCore/QFlags>

ForgBaseLib::FrgBaseTree::FrgBaseTree(FrgBaseMainWindow* parent)
	: QTreeWidget(parent)
	, theParentMainWindow_(parent)
{

	this->setColumnCount(1);
	this->setHeaderLabel(tr("Simulation"));
	this->header()->setSectionResizeMode(0, QHeaderView::Interactive);
	this->setSelectionMode(QAbstractItemView::ExtendedSelection);
	//this->setSelectionMode(QAbstractItemView::SingleSelection);

	this->setContextMenuPolicy(Qt::CustomContextMenu);

	QString style = "QTreeView::branch:has-siblings:!adjoins-item {"
		"border-image:url(:/Icons/TreeStyle/stylesheet-vline.png)0;"
		"}"

		"QTreeView::branch:has-siblings:adjoins-item {"
		"    border-image: url(:/Icons/TreeStyle/stylesheet-branch-more.png) 0;"
		"}"

		"QTreeView::branch:!has-children:!has-siblings:adjoins-item {"
		"    border-image: url(:/Icons/TreeStyle/stylesheet-branch-end.png) 0;"
		"}"

		"QTreeView::branch:has-children:!has-siblings:closed,"
		"QTreeView::branch:closed:has-children:has-siblings {"
		"        border-image: none;"
		"        image: url(:/Icons/TreeStyle/User-Interface-Plus-icon.png);"
		"}"

		"QTreeView::branch:open:has-children:!has-siblings,"
		"QTreeView::branch:open:has-children:has-siblings  {"
		"        border-image: none;"
		"        image: url(:/Icons/TreeStyle/User-Interface-Minus-icon.png);"
		"}";

	this->setStyleSheet(style);

	connect(this, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(itemClickedSlot(QTreeWidgetItem*, int)));
	connect(this, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(itemDoubleClickedSlot(QTreeWidgetItem*, int)));

	this->setContextMenuPolicy(Qt::CustomContextMenu);

	connect(this,
		SIGNAL(customContextMenuRequested(const QPoint&)),
		SLOT(onCustomContextMenuRequested(const QPoint&)));
}

ForgBaseLib::FrgBaseTree::~FrgBaseTree()
{
	FreeVectorOfPointers(theItems_);
}

void ForgBaseLib::FrgBaseTree::FormTree()
{
	theItems_.push_back(FrgNew FrgBaseTreeItem("Geometry", FrgNullPtr, this, theParentMainWindow_));

	FrgNew FrgBaseTreeItem("3D-CAD Models", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgBaseTreeItem("Parts", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgBaseTreeItem("Contacts", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	theItems_.push_back(FrgNew FrgBaseTreeItem("Continua", FrgNullPtr, this, theParentMainWindow_));

	theItems_.push_back(FrgNew FrgBaseTreeItem("Regions", FrgNullPtr, this, theParentMainWindow_));

	theItems_.push_back(FrgNew FrgBaseTreeItem("Stopping Criteria", FrgNullPtr, this, theParentMainWindow_));

	theItems_.push_back(FrgNew FrgBaseTreeItem("Solution Histories", FrgNullPtr, this, theParentMainWindow_));

	theItems_.push_back(FrgNew FrgBaseTreeItem("Solution Views", FrgNullPtr, this, theParentMainWindow_));

	FrgNew FrgBaseTreeItem("Current Solution", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	theItems_.push_back(FrgNew FrgBaseTreeItem("Monitors", FrgNullPtr, this, theParentMainWindow_));

	FrgNew FrgBaseTreeItem("Physical Time", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);
	theItems_.at(theItems_.size() - 1)->child(theItems_.at(theItems_.size() - 1)->childCount() - 1)->setIcon(0, QIcon(":/Icons/TreeStyle/Eye.png"));

	theItems_.push_back(FrgNew FrgBaseTreeItem("Plots", FrgNullPtr, this, theParentMainWindow_));

	theItems_.push_back(FrgNew FrgBaseTreeItem("Summaries", FrgNullPtr, this, theParentMainWindow_));

	theItems_.push_back(FrgNew FrgBaseTreeItem("Tools", FrgNullPtr, this, theParentMainWindow_));

	FrgNew FrgBaseTreeItem("Annotations", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgBaseTreeItem("Colormaps", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgBaseTreeItem("Coordinate Systems", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgBaseTreeItem("Custom Trees", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgBaseTreeItem("Data Focus", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgBaseTreeItem("Data Set Functions", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgBaseTreeItem("Environment Maps", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgBaseTreeItem("Field Functions", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgBaseTreeItem("Filters", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgBaseTreeItem("Layouts", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgBaseTreeItem("Parameters", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgBaseTreeItem("Rendering Materials", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgBaseTreeItem("Tables", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgBaseTreeItem("Tags", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgBaseTreeItem("Transforms", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgBaseTreeItem("Units", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgBaseTreeItem("Update Events", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgBaseTreeItem("User Code", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgBaseTreeItem("Views", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);

	FrgNew FrgBaseTreeItem("Volume Shapes", theItems_.at(theItems_.size() - 1), this, theParentMainWindow_);
}

void ForgBaseLib::FrgBaseTree::ClearTree()
{
	this->clear();
}

void  ForgBaseLib::FrgBaseTree::keyPressEvent(QKeyEvent* event)
{
	QTreeWidget::keyPressEvent(event);
	switch (event->key())
	{
	case Qt::Key_Up:
	case Qt::Key_Down:
	case Qt::Key_Home:
	case Qt::Key_End:
	case Qt::Key_PageUp:
	case Qt::Key_PageDown:
		if (currentItem())
		{
			emit QTreeWidget::itemClicked(currentItem(), 0);
		}
	}
}

void ForgBaseLib::FrgBaseTree::itemClickedSlot(QTreeWidgetItem* item, int column)
{
	if (theParentMainWindow_->GetPropertyWidget())
	{
		theParentMainWindow_->GetPropertyWidget()->theProperty_ = (dynamic_cast<FrgBaseTreeItem*>(item))->GetProperties()->GetPropertyBrowser();
		theParentMainWindow_->GetPropertyWidget()->theDockWidget_->setWidget((dynamic_cast<FrgBaseTreeItem*>(item))->GetProperties()->GetPropertyBrowser());

		theLastLeftClicked_ = dynamic_cast<FrgBaseTreeItem*>(item);
	}
}

void ForgBaseLib::FrgBaseTree::itemDoubleClickedSlot(QTreeWidgetItem* item, int column)
{

}

ForgBaseLib::FrgBaseTreeItem* ForgBaseLib::FrgBaseTree::GetTreeItem(const FrgString& title)
{
	for (int i = 0; i < theItems_.size(); i++)
	{
		if (theItems_.at(i)->text(0) == title)
			return theItems_.at(i);
	}

	return FrgNullPtr;
}

void ForgBaseLib::FrgBaseTree::onCustomContextMenuRequested(const QPoint& pos)
{
	FrgBaseTreeItem* item = dynamic_cast<FrgBaseTreeItem*>(this->itemAt(pos));

	if (item)
	{
		emit itemClicked(item, 0);

		showContextMenu(item, this->viewport()->mapToGlobal(pos));
	}
}

void ForgBaseLib::FrgBaseTree::showContextMenu(FrgBaseTreeItem* item, const QPoint& globalPos)
{
	if (item)
	{
		theLastRightClicked_ = item;
		if(item->GetContextMenu())
			item->GetContextMenu()->exec(globalPos);
	}
}

void ForgBaseLib::FrgBaseTree::DeleteTreeItemSlot(bool)
{
	FrgBaseTreeItem* tmpItem = this->GetTreeItemFromList(theLastRightClicked_);
	if (tmpItem)
		theItems_.removeOne(tmpItem);

	FreePointer(theLastRightClicked_);
	theLastLeftClicked_ = FrgNullPtr;
}

ForgBaseLib::FrgBaseTreeItem*& ForgBaseLib::FrgBaseTree::GetTreeItemFromList(FrgBaseTreeItem* item)
{
	FrgBaseTreeItem* output;
	for (int i = 0; i < theItems_.size(); i++)
	{
		if (theItems_.at(i) == item)
		{
			output = theItems_.at(i);
			break;
		}
	}

	return output;
}

void ForgBaseLib::FrgBaseTree::ScrollToItem(FrgBaseTreeItem* item)
{
	clearSelection();
	scrollToItem(item);
	setItemSelected(item, true);
	this->setCurrentItem(item);

	emit itemClickedSlot(item, 0);

	setFocus();
}

void ForgBaseLib::FrgBaseTree::ScrollToItems(QList<FrgBaseTreeItem*> items)
{
	if (items.isEmpty())
		return;

	clearSelection();
	for (int i = 0; i < items.size(); i++)
		setItemSelected(items[i], true);

	scrollToItem(items.last());
	itemClickedSlot(items.last(), 0);
	//this->setCurrentItem(items.last());
	//emit itemClickedSlot(items.last(), 0);

	setFocus();

}

void ForgBaseLib::FrgBaseTree::TreeItemNameChangedSlot(bool)
{
	auto castedItem = dynamic_cast<FrgBaseTreeItem*>(theLastRightClicked_);

	if (castedItem)
	{
		disconnect(this, SIGNAL(itemChanged(QTreeWidgetItem *, int)), this, SLOT(TreeItemNameChangedSlot(QTreeWidgetItem *, int)));
		castedItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);

		castedItem->setFlags(castedItem->flags() | Qt::ItemIsEditable);
		editItem(castedItem, 0);
		connect(this, SIGNAL(itemChanged(QTreeWidgetItem *, int)), this, SLOT(TreeItemNameChangedSlot(QTreeWidgetItem *, int)));
	}
}

void ForgBaseLib::FrgBaseTree::TreeItemNameChangedSlot(QTreeWidgetItem * item, int column)
{
	auto castedItem = dynamic_cast<FrgBaseTreeItem*>(item);

	if (castedItem)
	{
		disconnect(this, SIGNAL(itemChanged(QTreeWidgetItem *, int)), this, SLOT(TreeItemNameChangedSlot(QTreeWidgetItem *, int)));
		castedItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
		castedItem->RenameTreeItemName(castedItem->text(column));
	}
}