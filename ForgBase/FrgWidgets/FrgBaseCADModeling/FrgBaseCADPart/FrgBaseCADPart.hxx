#pragma once
#ifndef _FrgBaseCADPart_Header
#define _FrgBaseCADPart_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseCADPartFeatures.hxx>

BeginFrgBaseLib

template <class SurfaceEntity, class CurveEntity>
class FrgBaseCADPart : public FrgBaseTreeItem
{

private:

	typedef FrgBaseCADPartFeatures<SurfaceEntity, CurveEntity> CADPartFeatures;

	std::vector<std::shared_ptr<SurfaceEntity>> theSurfaces_;
	std::vector<std::shared_ptr<CurveEntity>> theCurves_;
	FrgBaseCADPartFeatures<SurfaceEntity, CurveEntity>* theFeatures_ = FrgNullPtr;

public:

	FrgBaseCADPart
	(
		const FrgString& title,
		FrgBaseTreeItem* parent
	);

	FrgBaseCADPart
	(
		const FrgString& title,
		FrgBaseTree* parentTree
	);

	FrgBaseCADPart
	(
		const FrgString& title,
		FrgBaseTreeItem* parent,
		std::vector<std::shared_ptr<SurfaceEntity>> surfaces,
		std::vector<std::shared_ptr<CurveEntity>> curves
	);

	FrgBaseCADPart
	(
		const FrgString& title,
		FrgBaseTree* parentTree,
		std::vector<std::shared_ptr<SurfaceEntity>> surfaces,
		std::vector<std::shared_ptr<CurveEntity>> curves
	);

	virtual void DoAfterConstruct() override;

	FrgGetMacro(CADPartFeatures*, Features, theFeatures_);
	FrgGetMacro(std::vector<std::shared_ptr<SurfaceEntity>>, Surfaces, theSurfaces_);
	FrgGetMacro(std::vector<std::shared_ptr<CurveEntity>>, Curves, theCurves_);
};

EndFrgBaseLib

#include <FrgBaseCADPartI.hxx>

#endif // !_FrgBaseCADPart_Header
