#include "environment.h"

#include <Windows.h>	// for IsProcessorFeaturePresent function
//#include <immintrin.h>	// for SIMD

availableProcessors getAvailableProcessors() {

	availableProcessors result;

	result.AVX512F	= IsProcessorFeaturePresent(PF_AVX512F_INSTRUCTIONS_AVAILABLE);
	result.AVX2		= IsProcessorFeaturePresent(PF_AVX2_INSTRUCTIONS_AVAILABLE);
	result.SSE4_2	= IsProcessorFeaturePresent(PF_SSE4_2_INSTRUCTIONS_AVAILABLE);

	return result;

}