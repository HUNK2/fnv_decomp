// fnv_asm_helpers.h - x87 helpers written for this project.
//
// Two instruction sequences in the original program cannot be produced from plain C++ with this compiler
// (Visual C++ 2008 SP1, cl 15.00.30729.01):
//   - fsincos (sine and cosine of one angle in a single instruction), and
//   - a float-to-int conversion in the current FPU rounding mode (fld + fistp, without the _ftol2 helper call).
// The original engine reached them through small inline helpers written in inline assembly. These functions are our
// own versions with the same instruction sequences. Call them from C++; inline assembly in submitted code stays
// forbidden. In units compiled with inlining enabled (/Ob1, /O2) the compiler inlines them like the originals.
#pragma once

__forceinline void fnv_SinCos(float fRadians, float& fSin, float& fCos)
{
    float s, c;
    __asm {
        fld fRadians
        fsincos
        fstp c
        fstp s
    }
    fSin = s;
    fCos = c;
}

__forceinline int fnv_FloatToInt(float fValue)
{
    int iValue;
    __asm {
        fld fValue
        fistp iValue
    }
    return iValue;
}

// Fixed operations reconstructed from the PC executable. Candidate source calls these helpers;
// arbitrary inline assembly in submissions remains forbidden. Transform labels allow one use per function.
#define fnv_TransformVectors(n,src,dst,matrix) __asm { \
__asm mov edx, n \
__asm cmp edx, 0 \
__asm jne La74895 \
__asm jmp La748fb \
__asm La74895: \
__asm mov eax, src \
__asm mov ebx, dst \
__asm mov ecx, matrix \
__asm La7489e: \
__asm fld dword ptr [eax] \
__asm fmul dword ptr [ecx] \
__asm fld dword ptr [eax + 4] \
__asm fmul dword ptr [ecx + 4] \
__asm fld dword ptr [eax + 8] \
__asm fmul dword ptr [ecx + 8] \
__asm fxch st(1) \
__asm faddp st(2), st(0) \
__asm fld dword ptr [eax] \
__asm fmul dword ptr [ecx + 0xc] \
__asm fxch st(2) \
__asm faddp st(1), st(0) \
__asm fxch st(1) \
__asm fld dword ptr [eax + 4] \
__asm fmul dword ptr [ecx + 0x10] \
__asm fld dword ptr [eax + 8] \
__asm fmul dword ptr [ecx + 0x14] \
__asm fxch st(3) \
__asm fstp dword ptr [ebx] \
__asm faddp st(1), st(0) \
__asm fld dword ptr [eax] \
__asm fmul dword ptr [ecx + 0x18] \
__asm fxch st(2) \
__asm faddp st(1), st(0) \
__asm fld dword ptr [eax + 4] \
__asm fmul dword ptr [ecx + 0x1c] \
__asm fld dword ptr [eax + 8] \
__asm fmul dword ptr [ecx + 0x20] \
__asm fxch st(1) \
__asm faddp st(3), st(0) \
__asm fxch st(1) \
__asm fstp dword ptr [ebx + 4] \
__asm faddp st(1), st(0) \
__asm add eax, 0xc \
__asm add ebx, 0xc \
__asm fstp dword ptr [ebx - 4] \
__asm dec edx \
__asm jne La7489e \
__asm La748fb: \
}

#define fnv_TransformPoints(n,src,dst,matrix,tx,ty,tz) __asm { \
__asm mov edx, n \
__asm cmp edx, 0 \
__asm jne La74985 \
__asm jmp La749fe \
__asm La74985: \
__asm mov eax, src \
__asm mov ebx, dst \
__asm mov ecx, matrix \
__asm La7498e: \
__asm fld dword ptr [eax] \
__asm fmul dword ptr [ecx] \
__asm fld dword ptr [eax + 4] \
__asm fmul dword ptr [ecx + 4] \
__asm fld dword ptr [eax + 8] \
__asm fmul dword ptr [ecx + 8] \
__asm fxch st(1) \
__asm faddp st(2), st(0) \
__asm fld dword ptr [eax] \
__asm fmul dword ptr [ecx + 0xc] \
__asm fxch st(2) \
__asm faddp st(1), st(0) \
__asm fxch st(1) \
__asm fld dword ptr [eax + 4] \
__asm fmul dword ptr [ecx + 0x10] \
__asm fld dword ptr [eax + 8] \
__asm fmul dword ptr [ecx + 0x14] \
__asm fxch st(1) \
__asm faddp st(2), st(0) \
__asm fxch st(2) \
__asm fadd tx \
__asm fld dword ptr [ecx + 0x18] \
__asm fxch st(2) \
__asm faddp st(3), st(0) \
__asm fxch st(1) \
__asm fmul dword ptr [eax] \
__asm fld dword ptr [ecx + 0x1c] \
__asm fld dword ptr [ecx + 0x20] \
__asm fxch st(1) \
__asm fmul dword ptr [eax + 4] \
__asm fxch st(4) \
__asm fadd ty \
__asm fxch st(1) \
__asm fmul dword ptr [eax + 8] \
__asm fxch st(4) \
__asm faddp st(2), st(0) \
__asm fxch st(2) \
__asm fstp dword ptr [ebx] \
__asm faddp st(2), st(0) \
__asm fstp dword ptr [ebx + 4] \
__asm fadd tz \
__asm add eax, 0xc \
__asm add ebx, 0xc \
__asm fstp dword ptr [ebx - 4] \
__asm dec edx \
__asm jne La7498e \
__asm La749fe: \
}

#define fnv_ReadTicks64(ticks) __asm { \
__asm push ebx \
__asm pop ebx \
__asm rdtsc \
__asm mov dword ptr[ticks],eax \
__asm mov dword ptr[ticks+4],edx \
}

#define fnv_CpuidMaxExtended(result) __asm { \
__asm mov eax,80000000h \
__asm cpuid \
__asm mov result,eax \
}

#define fnv_CpuidLegacyExtended(result) __asm { \
__asm mov edx,80000001h \
__asm cpuid \
__asm mov result,eax \
}

#define fnv_CpuidFeatures(result) __asm { \
__asm mov eax,1 \
__asm cpuid \
__asm mov result,edx \
}

// Havok HK_BREAKPOINT (hkBaseTypes.h, MSVC IA32: __asm { int 3 }), reached at the end of HK_ERROR / HK_ASSERT reports
// in release builds. An inline-asm block changes how VC9 /O2 lays out the frame of the function that holds it, and
// __debugbreak() does not (0x00d7b600: 73 bytes of stack slots differ). Candidate source calls fnv_Breakpoint();
// arbitrary inline assembly in submissions remains forbidden. Added 2026-10-30.
// A macro, not a function: a function body here (even unused) shifts the string-literal ($SG) numbering of every
// file that includes this header.
#define fnv_Breakpoint() __asm { int 3 }

// 0x00a855f0 (position-only skinning loop): dst += p * weight, fixed x87 sequence from the PC executable. Pass three
// named locals: the destination NiPoint3 pointer, a float pointer to the transformed point, and the float weight.
#define fnv_AddWeightedPoint(out,point,weight) __asm { \
__asm mov eax, out \
__asm mov ecx, point \
__asm fld dword ptr [ecx] \
__asm fmul weight \
__asm fld dword ptr [ecx + 4] \
__asm fmul weight \
__asm fxch st(1) \
__asm fadd dword ptr [eax] \
__asm fld dword ptr [ecx + 8] \
__asm fmul weight \
__asm fxch st(2) \
__asm fadd dword ptr [eax + 4] \
__asm fxch st(1) \
__asm fstp dword ptr [eax] \
__asm fxch st(1) \
__asm fadd dword ptr [eax + 8] \
__asm fxch st(1) \
__asm fstp dword ptr [eax + 4] \
__asm fstp dword ptr [eax + 8] \
}
