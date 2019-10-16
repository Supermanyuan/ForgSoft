#pragma once
#ifndef _SelectObjectsDlg_Header
#define _SelectObjectsDlg_Header

#include <FrgBaseGlobals.hxx>

#include <QtWidgets/QDialog>

class QTreeWidgetItem;
class QPushButton;
class QHBoxLayout;
class QTreeWidget;
class QGridLayout;

BeginFrgBaseLib

class QTreeWidgetItemPtr;

class SelectObjectsDlg : public QDialog
{

	Q_OBJECT

public:

	SelectObjectsDlg(QWidget* parent, QTreeWidgetItem* treeItem);

	FrgGetMacro(QList<QTreeWidgetItem*>, SelectedObjects, theSelectedObjects_);

private:

	QPushButton* theButtonOK_ = FrgNullPtr;
	QPushButton* theButtonCancel_ = FrgNullPtr;
	QHBoxLayout* theButtonLayout_ = FrgNullPtr;

	QGridLayout* theGridLayout_ = FrgNullPtr;

	QTreeWidget* theTree_ = FrgNullPtr;

	QList<QTreeWidgetItem*> theSelectedObjects_;

	void setupLayout();

private slots:

	void onOK();

protected:

	void keyPressEvent(QKeyEvent* event);
};

EndFrgBaseLib

#endif // !_SelectObjectsDlg_Header
