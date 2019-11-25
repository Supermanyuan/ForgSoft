#pragma once
#ifndef _FrgBaseCADScene_Header
#define _FrgBaseCADScene_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseTreeItem.hxx>

#include <QVTKOpenGLNativeWidget.h>

class vtkCamera;
class vtkActor;
class vtkGenericOpenGLRenderWindow;
class vtkTextActor;

BeginFrgBaseLib

class FrgBaseMainWindow;
class FrgBaseInteractorStyle;
class FrgBaseCADPartFeatureBase;

typedef QMap<vtkSmartPointer<vtkActor>, FrgBaseCADPartFeatureBase*> QMapActorToPartFeature;
typedef QMap<FrgBaseCADPartFeatureBase*, vtkSmartPointer<vtkActor>> QMapPartFeatureToActor;

class FORGBASE_EXPORT FrgBaseCADScene : public QVTKOpenGLNativeWidget
{

	Q_OBJECT

private:

	vtkSmartPointer<vtkRenderer> theRenderer_;

	vtkSmartPointer<vtkGenericOpenGLRenderWindow> theRenderWindow_;

	vtkSmartPointer<vtkRenderWindowInteractor> theRenderWindowInteractor_;

	vtkSmartPointer<FrgBaseInteractorStyle> theInteractorStyle_;

	vtkSmartPointer<vtkCamera> theCamera_;

	vtkSmartPointer<vtkTextActor> theLogoActor_;

	QList<vtkSmartPointer<vtkActor>> theActors_;

	QMapActorToPartFeature theActorToPartFeature_;
	QMapPartFeatureToActor thePartFeatureToActor_;

	FrgBaseTree* theParentTree_;

	void Init();


public:

	FrgBaseCADScene(FrgBaseTree* parentTree);

	void StartScene();

	FrgGetMacro(vtkSmartPointer<vtkRenderer>, Renderer, theRenderer_);
	FrgGetMacro(vtkSmartPointer<vtkRenderWindowInteractor>, RenderWindowInteractor, theRenderWindowInteractor_);
	FrgGetMacro(vtkSmartPointer<FrgBaseInteractorStyle>, InteractorStyle, theInteractorStyle_);
	FrgGetMacro(vtkSmartPointer<vtkCamera>, FrgBaseCamera, theCamera_);
	FrgGetMacro(vtkSmartPointer<vtkTextActor>, LogoActor, theLogoActor_);
	FrgGetMacro(vtkSmartPointer<vtkGenericOpenGLRenderWindow>, FrgBaseRenderWindow, theRenderWindow_);
	FrgGetMacro(QList<vtkSmartPointer<vtkActor>>, Actors, theActors_);
	FrgGetMacro(QMapActorToPartFeature, ActorToPartFeature, theActorToPartFeature_);
	FrgGetMacro(QMapPartFeatureToActor, PartFeatureToActor, thePartFeatureToActor_);

	void Render();

	FrgGetMacro(FrgBaseTree*, ParentTree, theParentTree_);

	void DrawGrid(int nX, int nY);
};

EndFrgBaseLib

#endif // !_FrgBaseCADScene_Header