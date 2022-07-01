#include "stdafx.h"

#include "blender_scope_view.h"

CBlender_scope_view::CBlender_scope_view()
{
    description.CLS = 0;
}

void CBlender_scope_view::Compile(CBlender_Compile& C) //crookr
{
	IBlender::Compile(C);
	C.r_Pass("null", "scope_view", FALSE, FALSE, FALSE);
	C.r_Sampler_rtf("s_position", r2_RT_P);
	C.r_Sampler_clf("s_image", r2_RT_generic0);
	C.r_End();
}
