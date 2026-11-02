
// src/havok/physics/constraintsolver/constraint/chain/hkpchainbuildjacobian.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/constraint/chain/hkpchainbuildjacobian.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

class ChainIndex
{
    int index;

  public:
    __forceinline ChainIndex(int initial) : index(initial)
    {}
    __forceinline operator int() const
    {
        return index;
    }
    __forceinline void operator++()
    {
        ++index;
    }
    __forceinline ChainIndex operator++(int)
    {
        ChainIndex before(*this);
        ++index;
        return before;
    }
};
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" void _mm_store_ss(float*, __m128);

typedef float hkReal;

class VectorComponentValue
{
  public:
    __forceinline VectorComponentValue(const __m128& x) : m_vValue(x)
    {}
    __forceinline operator hkReal() const
    {
        hkReal s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }

  private:
    __m128 m_vValue;
};

class hkVector4
{
  public:
    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void add4(const hkVector4& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void sub4(const hkVector4& v)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void mul4(const hkVector4& v)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline VectorComponentValue horizontalAdd3() const
    {
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0x55), m_vComponents);
        return _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa), xySum);
    }
    __forceinline void setBroadcast(const hkVector4& v, int i)
    {
        if (i == 0)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
        }
        else if (i == 1)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
        }
        else if (i == 2)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
        }
        else if (i == 3)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
        }
    }
    __forceinline void setBroadcast3clobberW(const hkVector4& v, int i)
    {
        setBroadcast(v, i);
    }
    __forceinline hkReal& operator()(int a)
    {
        return reinterpret_cast<hkReal*>(&m_vComponents)[a];
    }
    __forceinline const hkReal& operator()(int a) const
    {
        return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
    }

    __m128 m_vComponents;
};

class hkMatrix3
{
  public:
    __forceinline hkMatrix3()
    {}
    __forceinline hkVector4& getColumn(int x)
    {
        return (&m_kColumn0)[x];
    }
    __forceinline const hkVector4& getColumn(int x) const
    {
        return (&m_kColumn0)[x];
    }
    __forceinline hkReal& operator()(int r, int c)
    {
        return getColumn(c)(r);
    }
    __forceinline const hkReal& operator()(int r, int c) const
    {
        return getColumn(c)(r);
    }
    __forceinline void operator=(const hkMatrix3& a)
    {
        m_kColumn0 = a.getColumn(0);
        m_kColumn1 = a.getColumn(1);
        m_kColumn2 = a.getColumn(2);
    }
    __forceinline void _setTranspose(const hkMatrix3& s)
    {
        hkMatrix3& d = *this;
        d(0, 0) = s(0, 0);
        d(1, 1) = s(1, 1);
        d(2, 2) = s(2, 2);
        d(3, 0) = 0.0f;
        d(3, 1) = 0.0f;
        d(3, 2) = 0.0f;
        d(1, 0) = s(0, 1);
        d(0, 1) = s(1, 0);
        d(2, 0) = s(0, 2);
        d(0, 2) = s(2, 0);
        d(2, 1) = s(1, 2);
        d(1, 2) = s(2, 1);
    }
    __forceinline void _setMul(const hkMatrix3& aTb, const hkMatrix3& bTc);
    __forceinline void _sub(const hkMatrix3& a)
    {
        getColumn(0).sub4(a.getColumn(0));
        getColumn(1).sub4(a.getColumn(1));
        getColumn(2).sub4(a.getColumn(2));
    }
    __forceinline void setZero()
    {
        hkVector4 zero;
        zero.setZero4();
        getColumn(0) = zero;
        getColumn(1) = zero;
        getColumn(2) = zero;
    }

    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
};

void __cdecl FUN_00cd5530(hkMatrix3* thisMatrix, const hkMatrix3& aTb, const hkMatrix3& bTc);
void __cdecl FUN_00cd55a0(hkMatrix3& thisMatrix);

__forceinline void hkMatrix3::_setMul(const hkMatrix3& aTb, const hkMatrix3& bTc)
{
    FUN_00cd5530(this, aTb, bTc);
}

template <class T> class ByteView
{
    T* start;

  public:
    __forceinline ByteView(T* value) : start(value)
    {}
    __forceinline T* add(long distance) const
    {
        return reinterpret_cast<T*>(reinterpret_cast<char*>(start) + distance);
    }
};
template <class T> class ConstByteView
{
    const T* start;

  public:
    __forceinline ConstByteView(const T* value) : start(value)
    {}
    __forceinline const T* add(long distance) const
    {
        return reinterpret_cast<const T*>(reinterpret_cast<const char*>(start) + distance);
    }
};
template <typename TYPE> __forceinline TYPE* hkAddByteOffset(TYPE* base, long offset)
{
    return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base) + offset);
}

template <typename TYPE> __forceinline const TYPE* hkAddByteOffsetConst(const TYPE* base, long offset)
{
    return ConstByteView<TYPE>(base).add(offset);
}

template <typename TYPE> class ValueWrapper
{
  public:
    __forceinline void operator=(const TYPE& t)
    {
        m_kStorage = t;
    }
    __forceinline TYPE val() const
    {
        return m_kStorage;
    }

  private:
    TYPE m_kStorage;
};

class QuantizedBoundsData
{
  public:
    hkVector4 m_vLinearVelocity;
    hkVector4 m_vAngularVelocity;
    hkVector4 m_vCenterOfMass;
    hkVector4 m_vInverseInertiaAndMass;
};

class QuantizedBoundsDataOffset
{
  public:
    __forceinline const QuantizedBoundsData& getAccumulator(const QuantizedBoundsData* base)
    {
        return *hkAddByteOffsetConst(base, m_offset);
    }
    int m_offset;
};

class ConstraintJacobian
{
  public:
    __forceinline hkReal getNonDiagOptimized(const QuantizedBoundsData& mA, const QuantizedBoundsData& mB,
                                             const ConstraintJacobian& jacB) const
    {
        const ConstraintJacobian& jacA = *this;
        hkVector4 lin;
        lin.setMul4(jacA.m_kLinearJacobian, jacB.m_kLinearJacobian);
        hkVector4 ang0;
        ang0.setMul4(jacA.m_kAngularVelocity[0], jacB.m_kAngularVelocity[0]);
        hkVector4 ang1;
        ang1.setMul4(jacA.m_kAngularVelocity[1], jacB.m_kAngularVelocity[1]);
        hkVector4 invMassA;
        invMassA.setBroadcast3clobberW(mA.m_vInverseInertiaAndMass, 3);
        hkVector4 invMassB;
        invMassB.setBroadcast3clobberW(mB.m_vInverseInertiaAndMass, 3);
        hkVector4 linA;
        linA.setMul4(invMassA, lin);
        hkVector4 linB;
        linB.setMul4(invMassB, lin);
        ang0.mul4(mA.m_vInverseInertiaAndMass);
        ang1.mul4(mB.m_vInverseInertiaAndMass);
        linA.add4(linB);
        ang0.add4(ang1);
        ang0.add4(linA);
        return ang0.horizontalAdd3();
    }
    __forceinline hkReal getNonDiagSameObjects(const QuantizedBoundsData& mA, const QuantizedBoundsData& mB,
                                               const ConstraintJacobian& jacB) const
    {
        return getNonDiagOptimized(mA, mB, jacB);
    }
    __forceinline hkReal getNonDiagDifferentObjects_With2ndBodyFromFirstObject(const QuantizedBoundsData& mB,
                                                                               const ConstraintJacobian& jacB) const
    {
        const ConstraintJacobian& jacA = *this;
        hkVector4 lin;
        lin.setMul4(jacA.m_kLinearJacobian, jacB.m_kLinearJacobian);
        hkVector4 ang;
        ang.setMul4(jacA.m_kAngularVelocity[1], jacB.m_kAngularVelocity[0]);
        hkVector4 invMassB;
        invMassB.setBroadcast(mB.m_vInverseInertiaAndMass, 3);
        hkVector4 linB;
        linB.setMul4(invMassB, lin);
        ang.mul4(mB.m_vInverseInertiaAndMass);
        ang.sub4(linB);
        return ang.horizontalAdd3();
    }

    hkVector4 m_kLinearJacobian;
    hkVector4 m_kAngularVelocity[2];
};

struct Matrix3LowerDiagonalUpperFactors
{
    hkMatrix3 m_lower;
    hkMatrix3 m_diagInv;
    hkMatrix3 m_upper;
};

template <class E, class S> class EnumCode
{
  public:
    EnumCode()
    {}
    EnumCode(E value)
    {
        code = static_cast<S>(value);
    }
    operator E() const
    {
        return static_cast<E>(code);
    }
    void operator=(E value)
    {
        code = static_cast<S>(value);
    }

  private:
    S code;
};

class SolverSchemaHeader
{
  public:
    enum SchemaKind
    {
        BallSocketChain = 30
    };
    __forceinline static void setType(SolverSchemaHeader* schema, EnumCode<SchemaKind, signed char> type)
    {
        *reinterpret_cast<hkReal*>(schema) = float(*reinterpret_cast<hkReal*>(schema) + 1.1920928955078125e-07);
        *reinterpret_cast<EnumCode<SchemaKind, signed char>*>(hkAddByteOffset(schema, 0)) = type;
    }
};

class BallSocketChainSchema : public SolverSchemaHeader
{
  public:
    __forceinline static ConstraintJacobian* getJacobians(SolverSchemaHeader* schema)
    {
        return reinterpret_cast<ConstraintJacobian*>(reinterpret_cast<char*>(schema) + 0x10);
    }
    __forceinline Matrix3LowerDiagonalUpperFactors* getMatrixBuffer()
    {
        return reinterpret_cast<Matrix3LowerDiagonalUpperFactors*>(
            hkAddByteOffset(getJacobians(this), m_iConstraintCount * 3 * 0x30));
    }
    __forceinline hkVector4* getTempBuffer()
    {
        return reinterpret_cast<hkVector4*>(hkAddByteOffset(getMatrixBuffer(), m_iConstraintCount * 0x90));
    }
    __forceinline QuantizedBoundsDataOffset* getAccumulatorOffsetsBase()
    {
        return reinterpret_cast<QuantizedBoundsDataOffset*>(
            hkAddByteOffset(getTempBuffer(), (m_iConstraintCount + 1) << 4));
    }
    __forceinline void* GetStreamEnd()
    {
        return hkAddByteOffset(getAccumulatorOffsetsBase(), m_iConstraintCount * 4 + 4);
    }
    __forceinline void initBallSocketChainSchema(int numConstraints, QuantizedBoundsDataOffset* accumulators,
                                                 hkReal tau, hkReal damping)
    {
        setType(this, BallSocketChain);
        m_iConstraintCount = (unsigned short)numConstraints;
        m_fTau = tau;
        m_fMotorDamping = damping;
        int size = int(reinterpret_cast<char*>(GetStreamEnd()) - reinterpret_cast<char*>(this));
        m_sizeOfSchema = (size + 0xf) & ~0xf;
        QuantizedBoundsDataOffset* dst = getAccumulatorOffsetsBase();
        const int numAccumulators = numConstraints + 1;
        for (ChainIndex i = 0; i < numAccumulators; i++)
        {
            *(dst++) = *(accumulators++);
        }
    }

    unsigned char m_type;
    unsigned char m_iValueAfterStandIn;
    unsigned short m_iConstraintCount;
    int m_sizeOfSchema;
    hkReal m_fTau;
    hkReal m_fMotorDamping;
};

template <typename T> __forceinline T hkMath_max2(T x, T y)
{
    return x > y ? x : y;
}

__forceinline void buildConstraintMatrixLuDecompositionForBallAndSocketChain(
    int numConstraints, hkReal cfm, ConstraintJacobian* jac, QuantizedBoundsDataOffset* accumsOffsets,
    const QuantizedBoundsData* accumsBase, Matrix3LowerDiagonalUpperFactors* triple, int bufferSize)
{
    hkMatrix3 prevNonDiag;
    prevNonDiag.setZero();
    hkMatrix3 prevUpper;
    prevUpper.setZero();

    for (ChainIndex row = 0; row < numConstraints; row++)
    {
        int jacobiansPerRow = 3;
        const int jacIdx = row * jacobiansPerRow;

        hkMatrix3 diag;
        for (ChainIndex i = 0; i < 3; i++)
        {
            for (int j = i; j < 3; j++)
            {
                diag(i, j) = jac[jacIdx + i].getNonDiagSameObjects(accumsOffsets[row].getAccumulator(accumsBase),
                                                                   accumsOffsets[row + 1].getAccumulator(accumsBase),
                                                                   jac[jacIdx + j]);
                diag(j, i) = diag(i, j);
            }
            diag(i, i) += cfm;
        }

        hkMatrix3 nonDiag;
        nonDiag.setZero();
        if (row < numConstraints - 1)
        {
            for (ChainIndex i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    hkReal x = jac[jacIdx + i].getNonDiagDifferentObjects_With2ndBodyFromFirstObject(
                        accumsOffsets[row + 1].getAccumulator(accumsBase), jac[jacIdx + jacobiansPerRow + j]);
                    nonDiag(i, j) = x;
                }
            }
        }
        else
        {
            nonDiag.getColumn(0).setZero4();
            nonDiag.getColumn(1).setZero4();
            nonDiag.getColumn(2).setZero4();
        }

        triple[row].m_lower._setTranspose(prevNonDiag);
        hkMatrix3 tmp;
        tmp._setMul(triple[row].m_lower, prevUpper);
        triple[row].m_diagInv = diag;
        triple[row].m_diagInv._sub(tmp);
        for (int k = 0; k < 3; k++)
        {
            hkReal& e = triple[row].m_diagInv(k, k);
            e = hkMath_max2<hkReal>(e, 1.192092896e-07F);
        }
        FUN_00cd55a0(triple[row].m_diagInv);
        triple[row].m_upper._setMul(triple[row].m_diagInv, nonDiag);
        prevNonDiag = nonDiag;
        prevUpper = triple[row].m_upper;
    }
}

// Initializes a BallSocketChainSchema, builds LU-decomposed constraint matrices, and advances the schema pointer past the schema block.
// @fnv 0x00dd0ad0
extern "C" void FUN_00dd0ad0(int numConstraints, hkReal tau, hkReal afMotorDamping, hkReal cfm,
                             QuantizedBoundsDataOffset* accumulatorOffsets, const QuantizedBoundsData* accumsBase,
                             Matrix3LowerDiagonalUpperFactors* tripleBuffer, int bufferSize,
                             ValueWrapper<SolverSchemaHeader*>& schemaInOut)
{
    BallSocketChainSchema* schema = static_cast<BallSocketChainSchema*>(schemaInOut.val());
    schema->initBallSocketChainSchema(numConstraints, accumulatorOffsets, tau, afMotorDamping);
    ConstraintJacobian* jacobians = BallSocketChainSchema::getJacobians(schemaInOut.val());
    QuantizedBoundsDataOffset* offsets = schema->getAccumulatorOffsetsBase();
    Matrix3LowerDiagonalUpperFactors* matrices = schema->getMatrixBuffer();
    int size = 0x90 * numConstraints;
    buildConstraintMatrixLuDecompositionForBallAndSocketChain(numConstraints, cfm, jacobians, offsets, accumsBase,
                                                              matrices, size);
    schemaInOut = hkAddByteOffset(schemaInOut.val(), schema->m_sizeOfSchema);
}
