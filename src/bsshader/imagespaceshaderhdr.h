#ifndef IMAGESPACESHADERHDR_H
#define IMAGESPACESHADERHDR_H


#include "imagespaceshaderhdr_support.h"

// @fnv 0x00b90720
void ImageSpaceShaderHDRVariantFive::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].definition, 0, 0x44);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "BRIGHTFILTER";
        shader.kMacros[0].definition = 0;
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRBRIGHTT";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "BRIGHTFILTER";
        shader.kMacros[0].definition = 0;
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRBRIGHT";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b908a0
void ImageSpaceShaderHDRVariantSix::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].definition, 0, 0x44);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "16";
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRDOWN16T";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "16";
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRDOWN16";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b90590
void ImageSpaceShaderHDRVariantFour::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].definition, 0, 0x44);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "15";
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRBLURT";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "15";
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRBLUR";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b90a30
void HDRBaseImageSpaceShaderVariant4::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].definition, 0, 0x44);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "9";
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRDOWN9T";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "9";
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRDOWN9";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b90bc0
void HDRBaseImageSpaceShaderVariant1::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].definition, 0, 0x44);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "4";
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRDOWN4T";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "4";
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRDOWN4";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b90d50
void HDRBaseImageSpaceShaderVariant5::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].definition, 0, 0x44);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "ADAPT";
        shader.kMacros[0].definition = "";
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRADAPTT";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "ADAPT";
        shader.kMacros[0].definition = "";
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRADAPT";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b90ee0
void HDRBaseImageSpaceShaderVariant6::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].definition, 0, 0x44);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "LUMCLAMP";
        shader.kMacros[0].definition = "";
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRLUMCLAMPT";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "LUMCLAMP";
        shader.kMacros[0].definition = "";
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRLUMCLAMP";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b91070
void HDRBaseImageSpaceShaderVariant2::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].definition, 0, 0x44);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "4";
        shader.kMacros[1].name = "DOWNADAPT";
        shader.kMacros[1].definition = "";
        shader.kMacros[2].name = 0;
        fnv_zlib_memset(&shader.kMacros[2].definition, 0, 0x34);
        pixelShader = shader;
        shaderName = "HDRDS4ADAPTT";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "4";
        shader.kMacros[1].name = "DOWNADAPT";
        shader.kMacros[1].definition = "";
        shader.kMacros[2].name = 0;
        fnv_zlib_memset(&shader.kMacros[2].definition, 0, 0x34);
        pixelShader = shader;
        shaderName = "HDRDS4ADAPT";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b91210
void HDRBaseImageSpaceShaderVariant3::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].definition, 0, 0x44);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "4";
        shader.kMacros[1].name = "LUMCLAMP";
        shader.kMacros[1].definition = "";
        shader.kMacros[2].name = 0;
        fnv_zlib_memset(&shader.kMacros[2].definition, 0, 0x34);
        pixelShader = shader;
        shaderName = "HDRDS4LUMCLAMPT";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "4";
        shader.kMacros[1].name = "LUMCLAMP";
        shader.kMacros[1].definition = "";
        shader.kMacros[2].name = 0;
        fnv_zlib_memset(&shader.kMacros[2].definition, 0, 0x34);
        pixelShader = shader;
        shaderName = "HDRDS4LUMCLAMP";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b913b0
void ImageSpaceShaderHDRVariantSeven::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].definition, 0, 0x44);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "16";
        shader.kMacros[1].name = "DOWNADAPT";
        shader.kMacros[1].definition = "";
        shader.kMacros[2].name = 0;
        fnv_zlib_memset(&shader.kMacros[2].definition, 0, 0x34);
        pixelShader = shader;
        shaderName = "HDRDS16ADAPTT";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "16";
        shader.kMacros[1].name = "DOWNADAPT";
        shader.kMacros[1].definition = "";
        shader.kMacros[2].name = 0;
        fnv_zlib_memset(&shader.kMacros[2].definition, 0, 0x34);
        pixelShader = shader;
        shaderName = "HDRDS16ADAPT";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b91550
void ImageSpaceShaderHDRVariantEight::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].definition, 0, 0x44);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "16";
        shader.kMacros[1].name = "LUMCLAMP";
        shader.kMacros[1].definition = "";
        shader.kMacros[2].name = 0;
        fnv_zlib_memset(&shader.kMacros[2].definition, 0, 0x34);
        pixelShader = shader;
        shaderName = "HDRDS16LUMCLAMPT";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "16";
        shader.kMacros[1].name = "LUMCLAMP";
        shader.kMacros[1].definition = "";
        shader.kMacros[2].name = 0;
        fnv_zlib_memset(&shader.kMacros[2].definition, 0, 0x34);
        pixelShader = shader;
        shaderName = "HDRDS16LUMCLAMP";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b90060
void ImageSpaceShaderHDRVariantOne::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = "TEX2";
    vertexShader.kMacros[0].definition = 0;
    vertexShader.kMacros[1].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[1].definition, 0, 0x3c);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "SHBLEND";
        shader.kMacros[0].definition = 0;
        shader.kMacros[1].name = "TONEMAP";
        shader.kMacros[1].definition = 0;
        shader.kMacros[2].name = 0;
        fnv_zlib_memset(&shader.kMacros[2].definition, 0, 0x34);
        pixelShader = shader;
        shaderName = "HDRBLENDINSHADERT";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "SHBLEND";
        shader.kMacros[0].definition = 0;
        shader.kMacros[1].name = "TONEMAP";
        shader.kMacros[1].definition = 0;
        shader.kMacros[2].name = 0;
        fnv_zlib_memset(&shader.kMacros[2].definition, 0, 0x34);
        pixelShader = shader;
        shaderName = "HDRBLENDINSHADER";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b90200
void ImageSpaceShaderHDRVariantTwo::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = "TEX2";
    vertexShader.kMacros[0].definition = 0;
    vertexShader.kMacros[1].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[1].definition, 0, 0x3c);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "CINEMATIC";
        shader.kMacros[0].definition = 0;
        shader.kMacros[1].name = "SHBLEND";
        shader.kMacros[1].definition = 0;
        shader.kMacros[2].name = "TONEMAP";
        shader.kMacros[2].definition = 0;
        shader.kMacros[3].name = 0;
        fnv_zlib_memset(&shader.kMacros[3].definition, 0, 0x2c);
        pixelShader = shader;
        shaderName = "HDRBLENDINSHADERCINT";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "CINEMATIC";
        shader.kMacros[0].definition = 0;
        shader.kMacros[1].name = "SHBLEND";
        shader.kMacros[1].definition = 0;
        shader.kMacros[2].name = "TONEMAP";
        shader.kMacros[2].definition = 0;
        shader.kMacros[3].name = 0;
        fnv_zlib_memset(&shader.kMacros[3].definition, 0, 0x2c);
        pixelShader = shader;
        shaderName = "HDRBLENDINSHADERCIN";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b903a0
void ImageSpaceShaderHDRVariantThree::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = "TEX2";
    vertexShader.kMacros[0].definition = 0;
    vertexShader.kMacros[1].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[1].definition, 0, 0x3c);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "CINEMATIC";
        shader.kMacros[0].definition = 0;
        shader.kMacros[1].name = "SHBLEND";
        shader.kMacros[1].definition = 0;
        shader.kMacros[2].name = "TONEMAP";
        shader.kMacros[2].definition = 0;
        shader.kMacros[3].name = 0;
        fnv_zlib_memset(&shader.kMacros[3].definition, 0, 0x2c);
        pixelShader = shader;
        shaderName = "HDRBLENDINSHADERCINT";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "ALPHAMASK";
        shader.kMacros[0].definition = 0;
        shader.kMacros[1].name = "CINEMATIC";
        shader.kMacros[1].definition = 0;
        shader.kMacros[2].name = "SHBLEND";
        shader.kMacros[2].definition = 0;
        shader.kMacros[3].name = "TONEMAP";
        shader.kMacros[3].definition = 0;
        shader.kMacros[4].name = 0;
        memset(&shader.kMacros[4].definition, 0, 0x24);
        pixelShader = shader;
        shaderName = "HDRBLENDINSHADERCINAM";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b90190
ImageSpaceShaderHDRVariantTwo::ImageSpaceShaderHDRVariantTwo()
{
    textures.SetSize(4);
}

// @fnv 0x00b90330
ImageSpaceShaderHDRVariantThree::ImageSpaceShaderHDRVariantThree()
{
    textures.SetSize(4);
}

// @fnv 0x00b90520
ImageSpaceShaderHDRVariantFour::ImageSpaceShaderHDRVariantFour()
{
    textures.SetSize(2);
}

// @fnv 0x00b906b0
ImageSpaceShaderHDRVariantFive::ImageSpaceShaderHDRVariantFive()
{
    textures.SetSize(2);
}

// @fnv 0x00b90830
ImageSpaceShaderHDRVariantSix::ImageSpaceShaderHDRVariantSix()
{
    textures.SetSize(2);
}

// @fnv 0x00b909c0
HDRBaseImageSpaceShaderVariant4::HDRBaseImageSpaceShaderVariant4()
{
    textures.SetSize(2);
}

// @fnv 0x00b90b50
HDRBaseImageSpaceShaderVariant1::HDRBaseImageSpaceShaderVariant1()
{
    textures.SetSize(2);
}

// @fnv 0x00b91000
HDRBaseImageSpaceShaderVariant2::HDRBaseImageSpaceShaderVariant2()
{
    textures.SetSize(3);
}

// @fnv 0x00b911a0
HDRBaseImageSpaceShaderVariant3::HDRBaseImageSpaceShaderVariant3()
{
    textures.SetSize(2);
}

// @fnv 0x00b91340
ImageSpaceShaderHDRVariantSeven::ImageSpaceShaderHDRVariantSeven()
{
    textures.SetSize(3);
}

// @fnv 0x00b914e0
ImageSpaceShaderHDRVariantEight::ImageSpaceShaderHDRVariantEight()
{
    textures.SetSize(2);
}

// @fnv 0x00b90ce0
HDRBaseImageSpaceShaderVariant5::HDRBaseImageSpaceShaderVariant5()
{
    textures.SetSize(3);
}

// @fnv 0x00b90e70
HDRBaseImageSpaceShaderVariant6::HDRBaseImageSpaceShaderVariant6()
{
    textures.SetSize(2);
}

#endif
