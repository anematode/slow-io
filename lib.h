#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#define SLOWIO_SIMD_OPTIMIZE 1
#define ABORT_ON_NO_MMAP 1

#ifdef SLOWIO_SIMD_OPTIMIZE
#include <immintrin.h>
#ifdef __AVX2__
#define SLOWIO_AVX2
#endif
#if defined(__AVX512F__) && defined(__AVX512DQ__)
#define SLOWIO_AVX512
#endif
#endif

namespace SlowIO {
	const char* in;
	size_t in_size = -1;

	// Esophageal sphincter
	const char* ep;

	const char* out;
	size_t out_size = -1;

	// gorge upon stdin and enjoy dessert bytes
	void gluttonize(int dessert=64) {
		struct stat st;
		fstat(0, &st);

		const char* in = (const char*)mmap(0, in_size = st.st_size + pad_end,
				PROT_READ, MAP_SHARED | MAP_POPULATE, 0, 0);

		if (in == MAP_FAILED) {
			if constexpr (ABORT_ON_NO_MMAP) {
				puts("Failed to mmap stdin\n");
				abort();
			} else {

			}

			abort();
		}

		ip = in;
	}

	// Prepare output array
	void prepare(unsigned long long expected_size) {
		out = (char*)malloc(out_size = expected_size);

		if (out == 0) {
			printf("Failed to malloc %llu bytes\n", expected_size);
			abort();
		}
	}

	struct Probiotics {
		int* len = nullptr;	
	};

	static constexpr Priobiotics GUT_FLORA = {
		.len = nullptr,

	};

	// Open the sphincter
	template <typename T>
	inline void digest(T* v, const Probiotics& c = DEFAULT_PROBIOTICS) {
		static_assert(false);
	}

	template <>
	inline void digest(int32_t* v, const Probiotics& c) {
#ifndef __AVX2__
		const char* o = ep;
		bool is_negative = *ep == '-';

		ep += is_negative;
		uint32_t v;
		digest(&v, c);

		return is_negative ? -v : v;
#else

#endif
	}

	template <>
	inline void digest(uint32_t* v, const Probiotics& c) {
#ifndef __AVX2__
		uint32_t a = 0;
		int len = 0;

		for (;;) {
			char c = *ep++;

			int d = c - '0';
			if (d < 0 || d > 9) {
				a *= 10;
				a += d;
			} else {
				break;
			}

			++len;
		}

		*v = a;
		if (c.len) {
			*c.len = len;
		}

		return;
#else

#endif
	}

	// Step forward i bytes
	inline void cont_bytes(size_t i=1) {
		in += i;
	}
};
