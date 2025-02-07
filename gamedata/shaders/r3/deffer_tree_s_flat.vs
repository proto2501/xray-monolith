#include "common.h"

uniform float3x4	m_xform;
uniform float3x4	m_xform_v;
uniform float4 		consts; 	// {1/quant,1/quant,???,???}
uniform float4 		c_scale,c_bias,wind,wave;
uniform float2 		c_sun;		// x=*, y=+

v2p_flat main (v_tree I)
{
	I.Nh	=	unpack_D3DCOLOR(I.Nh);
	I.T		=	unpack_D3DCOLOR(I.T);
	I.B		=	unpack_D3DCOLOR(I.B);

	v2p_flat 		o;

	// Transform to world coords
	float3 	pos		= mul		(m_xform, I.P);

	//
	float2 	result	= 0;
	float4 	f_pos 	= float4(pos.x+result.x, pos.y, pos.z+result.y, 1);

	// Final xform(s)
	// Final xform
	float3	Pe		= mul		(m_V,  f_pos				);
	float 	hemi 	= I.Nh.w*c_scale.w + c_bias.w;
    //float 	hemi 	= I.Nh.w;
	o.hpos			= mul		(m_VP, f_pos				);
	o.N 			= mul		((float3x3)m_xform_v, unpack_bx2(I.Nh)	);
	o.tcdh 			= float4	((I.tc * consts).xyyy		);
	o.position		= float4	(Pe, hemi					);

#if defined(USE_R2_STATIC_SUN) && !defined(USE_LM_HEMI)
	float 	suno 	= I.Nh.w * c_sun.x + c_sun.y	;
	o.tcdh.w		= suno;					// (,,,dir-occlusion)
#endif

	#ifdef USE_TDETAIL
	o.tcdbump	= o.tcdh*dt_params;					// dt tc
	#endif

	return o;
}
FXVS;
