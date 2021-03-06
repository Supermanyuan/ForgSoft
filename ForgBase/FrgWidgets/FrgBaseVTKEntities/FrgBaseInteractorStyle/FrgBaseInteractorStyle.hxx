#pragma once
#ifndef _FrgBaseInteractorStyle_Header
#define _FrgBaseInteractorStyle_Header

#include <FrgBaseGlobals.hxx>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkObjectFactory.h>

#include <QtCore/QList>

class QColor;
class vtkActor;
class vtkProperty;

enum SelectedIconFromScene
{
	Cursor = 0,
	Move = 1,
	RotateX = 2,
	RotateY = 3,
	RotateZ = 4,
	RotateXYZ = 5
};

enum PlaneView
{
	PlaneXY = 0,
	PlaneXZ = 1,
	PlaneYZ = 2,
	PlaneXYZ = 3
};

BeginFrgBaseLib

class FrgBaseCADScene;

class FORGBASE_EXPORT FrgBaseInteractorStyle : public vtkInteractorStyleTrackballCamera
{
	struct FrgBaseActor
	{
		vtkActor* theActor_ = nullptr;
		vtkProperty* theProperty_ = nullptr;
	};

private:

	FrgBool theRotationEnabled_ = FrgTrue;

	QList<FrgBaseActor*> theSelectedActors_;

	QList<FrgBaseActor*> theHiddenActors_;

	FrgBaseCADScene* theParent_ = nullptr;

	SelectedIconFromScene theSelectedIconFromScene_ = Cursor;
	PlaneView thePlaneView_ = PlaneXYZ;

	int PreviousPosition[2];
	int ResetPixelDistance;

	vtkTypeMacro(FrgBaseInteractorStyle, vtkInteractorStyleTrackballCamera);

private:

	void SetSelectedActorColor(QColor color);

	void AddActorToSelectedActors(vtkActor* actor);

	void SetCursorShapeToDefault();
	void SetCursorShapeToMove();
	void SetCursorShapeToRotateXYZ();
	void SetCursorShapeToZoomIn();
	void SetCursorShapeToZoomOut();

public:

	FrgBaseInteractorStyle();

	static FrgBaseInteractorStyle* New();

	void SetParent(FrgBaseCADScene* parent)
	{
		theParent_ = parent;
	}

	void HideSelectedActors();

	void ShowAllActors();

	void SetGeometriesOpacity(double opacity = 1.0);

	virtual void OnLeftButtonUp() override;
	virtual void OnLeftButtonDown() override;
	virtual void OnMouseWheelForward() override;
	virtual void OnMouseWheelBackward() override;
	virtual void OnMiddleButtonDown() override;
	virtual void OnRightButtonDown() override;
	virtual void OnRightButtonUp() override;
	virtual void OnMouseMove() override;
	virtual void OnChar() override;

	void SelectActor(vtkActor* actor, int isControlKeyPressed, FrgBool isFromTree = FrgFalse);
	void SelectActors(QList<vtkActor*> actors, FrgBool isFromTree = FrgFalse);
	void UnSelectAllActors();

	FrgGetMacro(QList<FrgBaseActor*>, SelectedActors, theSelectedActors_);
	FrgGetMacro(FrgBaseCADScene*, ParentScene, theParent_);
	FrgGetMacro(FrgBool, RotationEnabled, theRotationEnabled_);
	FrgGetMacro(SelectedIconFromScene, SelectedIconFromScene, theSelectedIconFromScene_);
	FrgGetMacro(PlaneView, PlaneView, thePlaneView_);

	static QColor GeometryColorRGB;
	static QColor GeometrySelectedColorRGB;

public:

	void SetViewToXYPlane();
	void SetViewToXZPlane();
	void SetViewToYZPlane();
	void SetViewToXYZ();

	void ShowMesh(FrgBool condition);
};

EndFrgBaseLib

#endif // !_FrgBaseInteractorStyle_Header
