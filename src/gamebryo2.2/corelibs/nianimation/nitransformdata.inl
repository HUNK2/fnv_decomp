struct NiQuaternionConjugateValue
{
    float w, x, y, z;
};

// Quaternion conjugation inferred from the PC instructions.
// @fnv 0x00a6dc00
NiQuaternionConjugateValue __cdecl NiQuaternionConjugate(const NiQuaternionConjugateValue& value)
{
    NiQuaternionConjugateValue result;
    result.w = value.w;
    result.x = -value.x;
    result.y = -value.y;
    result.z = -value.z;
    return result;
}
