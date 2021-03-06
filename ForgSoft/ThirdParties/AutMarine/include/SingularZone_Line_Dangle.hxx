#pragma once
#ifndef _SingularZone_Line_Dangle_Header
#define _SingularZone_Line_Dangle_Header

#include <SingularZone_Line.hxx>

namespace AutLib
{

	struct SingularZone_Line_Dangle_Base
	{
		static const word typeName;
	};

	template<class SurfPln>
	class SingularZone_Line_Dangle
		: public SingularZone_Line<SurfPln>
		, public SingularZone_Line_Dangle_Base
	{

		typedef typename SurfPln::parCurveType plnCurve;

		/*Private Data*/

		std::shared_ptr<plnCurve> theHorizon0_;
		std::shared_ptr<plnCurve> theHorizon1_;
		std::shared_ptr<plnCurve> theHorizon2_;

	public:

		SingularZone_Line_Dangle()
		{}

		SingularZone_Line_Dangle
		(
			const std::shared_ptr<plnCurve>& theHorizon0,
			const std::shared_ptr<plnCurve>& theHorizon1,
			const std::shared_ptr<plnCurve>& theHorizon2
		)
			: theHorizon0_(theHorizon0)
			, theHorizon1_(theHorizon1)
			, theHorizon2_(theHorizon2)
		{}

		SingularZone_Line_Dangle
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<plnCurve>& theHorizon0,
			const std::shared_ptr<plnCurve>& theHorizon1,
			const std::shared_ptr<plnCurve>& theHorizon2
		)
			: SingularZone_Line<SurfPln>(theIndex)
			, theHorizon0_(theHorizon0)
			, theHorizon1_(theHorizon1)
			, theHorizon2_(theHorizon2)
		{}

		Cad_SingularType Type() const override
		{
			return Cad_SingularType::Line_Dangle;
		}

		const word& TypeName() const override
		{
			return typeName;
		}

		Standard_Boolean IsLoaded() const
		{
			if (!theHorizon0_) return Standard_False;
			if (!theHorizon1_) return Standard_False;
			if (!theHorizon2_) return Standard_False;
			return Standard_True;
		}

		const std::shared_ptr<plnCurve>& Horizon0() const
		{
			return theHorizon0_;
		}

		const std::shared_ptr<plnCurve>& Horizon1() const
		{
			return theHorizon1_;
		}

		const std::shared_ptr<plnCurve>& Horizon2() const
		{
			return theHorizon2_;
		}

		Standard_Integer NbHorizons() const override
		{
			return 3;
		}

		const std::shared_ptr<plnCurve>&
			Horizon
			(
				const Standard_Integer theIndex
			) const override
		{
			return (&theHorizon0_)[theIndex];
		}

		void LoadHorizons
		(
			const std::shared_ptr<plnCurve>& theHorizon0,
			const std::shared_ptr<plnCurve>& theHorizon1,
			const std::shared_ptr<plnCurve>& theHorizon2
		)
		{
			theHorizon0_ = theHorizon0;
			theHorizon1_ = theHorizon1;
			theHorizon2_ = theHorizon2;
		}
	};
}

#endif // !_SingularZone_Line_Dangle_Header
