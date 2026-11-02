// gamebryo2.2/corelibs/nimain/nitransform.cpp: NiTransform, Transform3D, TransformSaver (4 functions)
#include "nitransform_decls.h"
// @fnv 0x00a86bf0
void NiTransform::ResetToIdentity()
{
    m_kOrientation.ResetToIdentity();
    m_kTranslation = NiPoint3::ZERO;
    m_fScale = 1.0f;
}
// @fnv 0x00a86c80
void NiTransform::LoadBinary(NiStream& stream)
{
    m_kOrientation.LoadBinary(stream);
    m_kTranslation.LoadBinary(stream);
    stream.input->Read(&m_fScale);
}

struct TransformMatrix
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    bool FUN_004d9ae0(const TransformMatrix& other) const;
};
struct TransformPoint
{
    float x, y, z;
    bool FUN_00439090(const TransformPoint& other) const;
};
struct Transform3D
{
    TransformMatrix rotation;
    TransformPoint translation;
    float scale;
    unsigned int FUN_00a86c30(const Transform3D& other) const;
};
// @fnv 0x00a86c30
unsigned int Transform3D::FUN_00a86c30(const Transform3D& other) const
{
    if (rotation.FUN_004d9ae0(other.rotation))
    {
        if (!translation.FUN_00439090(other.translation))
        {
            if (scale == other.scale)
                return false;
        }
    }
    return true;
}

struct TransformRotationSaver : ThreeByThreeMatrix
{
    void FUN_00a59a90(NiStream* stream);
};

struct TransformTranslationSaver : NiPoint3
{
    void FUN_00a69780(NiStream& stream);
};

struct TransformBinaryOutput : NiBinaryStream
{
    void SaveScale(const float* value)
    {
        unsigned int componentSize = sizeof(float);
        position += write(this, value, sizeof(float), &componentSize, 1);
    }
};

struct TransformOutputStream : NiStream
{
    TransformBinaryOutput* output;
};

struct TransformSaver : NiTransform
{
    void FUN_00a86cd0(NiStream& stream);
};

// Writes the orientation, translation, and scale of the transform to the given NiStream.
// @fnv 0x00a86cd0
void TransformSaver::FUN_00a86cd0(NiStream& stream)
{
    static_cast<TransformRotationSaver&>(m_kOrientation).FUN_00a59a90(&stream);
    static_cast<TransformTranslationSaver&>(m_kTranslation).FUN_00a69780(stream);
    static_cast<TransformOutputStream&>(stream).output->SaveScale(&m_fScale);
}
