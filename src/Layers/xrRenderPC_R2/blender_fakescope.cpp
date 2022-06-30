#include "stdafx.h"

#include "blender_fakescope.h"

CBlender_fakescope::CBlender_fakescope()
{
    description.CLS = 0;
}

void CBlender_fakescope::Compile(CBlender_Compile& C) //crookr
{
	IBlender::Compile(C);
	C.r_Pass("null", "fakescope", FALSE, FALSE, FALSE);
	C.r_Sampler_rtf("s_position", r2_RT_P);
	C.r_Sampler_clf("s_image", r2_RT_generic0);
	C.r_End();
}
