
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Maps an HRESULT or D3D error code to its string name, returning "UNKNOWN!" for unrecognized codes.
// @fnv 0x00e89d50
const char* GetHResultName(unsigned int uiResult)
{
    switch (uiResult)
    {
    case 0x8007000eu:
        return "E_OUTOFMEMORY";
    case 0x80004005u:
        return "E_FAIL";
    case 0x80070057u:
        return "E_INVALIDARG";
    case 0x8876017cu:
        return "D3DERR_OUTOFVIDEOMEMORY";
    case 0x88760818u:
        return "D3DERR_WRONGTEXTUREFORMAT";
    case 0x88760821u:
        return "D3DERR_CONFLICTINGRENDERSTATE";
    case 0x8876081eu:
        return "D3DERR_CONFLICTINGTEXTUREFILTER";
    case 0x88760826u:
        return "D3DERR_CONFLICTINGTEXTUREPALETTE";
    case 0x88760868u:
        return "D3DERR_DEVICELOST";
    case 0x88760869u:
        return "D3DERR_DEVICENOTRESET";
    case 0x88760827u:
        return "D3DERR_DRIVERINTERNALERROR";
    case 0x8876086cu:
        return "D3DERR_INVALIDCALL";
    case 0x8876086bu:
        return "D3DERR_INVALIDDEVICE";
    case 0x88760867u:
        return "D3DERR_MOREDATA";
    case 0x8876086au:
        return "D3DERR_NOTAVAILABLE";
    case 0x88760866u:
        return "D3DERR_NOTFOUND";
    case 0x8876081du:
        return "D3DERR_TOOMANYOPERATIONS";
    case 0x8876081cu:
        return "D3DERR_UNSUPPORTEDALPHAARG";
    case 0x8876081bu:
        return "D3DERR_UNSUPPORTEDALPHAOPERATION";
    case 0x8876081au:
        return "D3DERR_UNSUPPORTEDCOLORARG";
    case 0x88760819u:
        return "D3DERR_UNSUPPORTEDCOLOROPERATION";
    case 0x8876081fu:
        return "D3DERR_UNSUPPORTEDFACTORVALUE";
    case 0x88760822u:
        return "D3DERR_UNSUPPORTEDTEXTUREFILTER";
    default:
        return "UNKNOWN!";
    }
}
