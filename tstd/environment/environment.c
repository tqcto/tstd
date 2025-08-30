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

size_t getAlignment(availableProcessors processors) {

	if (processors.AVX512F) return 64;		// 64byte
	else if (processors.AVX2) return 32;	// 32byte
	else return 16;	// 16byte

}
