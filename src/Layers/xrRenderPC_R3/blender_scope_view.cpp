#include "stdafx.h"

#include "blender_scope_view.h"

CBlender_scope_view::CBlender_scope_view()
{
    description.CLS = 0;
}

void CBlender_scope_view::Compile(CBlender_Compile& C)
{
	IBlender::Compile(C);

	C.r_Pass("stub_screen_space", "scope_view", FALSE, FALSE, FALSE);
	C.r_dx10Texture("s_position", r2_RT_P);
	C.r_dx10Texture("s_image", r2_RT_generic0);
	C.r_dx10Texture("s_bloom_new", r2_RT_pp_bloom);
	C.r_dx10Texture("s_blur_2", r2_RT_blur_2);
	C.r_dx10Texture("s_blur_4", r2_RT_blur_4);
	C.r_dx10Texture("s_blur_8", r2_RT_blur_8);

	C.r_dx10Sampler("smp_base");
	C.r_dx10Sampler("smp_nofilter");
	C.r_dx10Sampler("smp_rtlinear");
	C.r_End();
}
