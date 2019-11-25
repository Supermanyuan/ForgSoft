#pragma once
#ifndef _ViewPorts_Header
#define _ViewPorts_Header

#include <FrgBaseGlobals.hxx>
#include <QtWidgets/QMdiArea>

BeginFrgBaseLib

class CADScene;
class NihadVesselPartTreeItem;

class ViewPorts : public QMdiArea
{

private:

	QList<CADScene*> theScenes_;

public:

	ViewPorts(QWidget* parent = FrgNullPtr);

	FrgGetMacro(QList<CADScene*>, Scenes, theScenes_);

	void SetLogoText(FrgString text);

	void CreateActor(NihadVesselPartTreeItem* part);

	void ClearScenes();

	void RenderScenes();

	void AddScene(CADScene* scene, Qt::WindowFlags flags = Qt::WindowFlags());

};

EndFrgBaseLib

#endif // !_ViewPorts_Header