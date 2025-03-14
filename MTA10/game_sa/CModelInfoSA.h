/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        game_sa/CModelInfoSA.h
*  PURPOSE:     Header file for entity model information handler class
*  DEVELOPERS:  Ed Lyons <eai@opencoding.net>
*               Cecill Etheredge <ijsf@gmx.net>
*               Christian Myhre Lundheim <>
*               Jax <>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CGAMESA_MODELINFO
#define __CGAMESA_MODELINFO

#include <game/CModelInfo.h>
#include <game/Common.h>

#include "CColModelSA.h"
#include "CRenderWareSA.h"
class CPedModelInfoSA;
class CPedModelInfoSAInterface;

#define     ARRAY_ModelLoaded               0x8E4CD0 // ##SA##

#define     FUNC_CStreaming__HasModelLoaded 0x4044C0

// CModelInfo/ARRAY_ModelInfo __thiscall to load/replace vehicle models
#define     FUNC_LoadVehicleModel           0x4C95C0
#define     FUNC_LoadWeaponModel            0x4C9910
#define     FUNC_LoadPedModel               0x4C7340

#define     DWORD_AtomicsReplacerModelID    0xB71840
#define     FUNC_AtomicsReplacer            0x537150

#define     ARRAY_ModelInfo                 0xA9B0C8
#define     CLASS_CText                     0xC1B340
#define     FUNC_CText_Get                  0x6A0050
#define     FUNC_GetModelFlags              0x4044E0
#define     FUNC_GetBoundingBox             0x4082F0

#define     FUNC_RemoveRef                  0x4C4BB0
#define     FUNC_IsBoatModel                0x4c5a70
#define     FUNC_IsCarModel                 0x4c5aa0
#define     FUNC_IsTrainModel               0x4c5ad0
#define     FUNC_IsHeliModel                0x4c5b00
#define     FUNC_IsPlaneModel               0x4c5b30
#define     FUNC_IsBikeModel                0x4c5b60
#define     FUNC_IsFakePlaneModel           0x4c5b90    
#define     FUNC_IsMonsterTruckModel        0x4c5bc0        
#define     FUNC_IsQuadBikeModel            0x4c5bf0
#define     FUNC_IsBmxModel                 0x4c5c20
#define     FUNC_IsTrailerModel             0x4c5c50
#define     FUNC_IsVehicleModelType         0x4c5c80

#define     FUNC_RemoveModel                0x4089a0
#define     FUNC_FlushRequestList           0x40E4E0

#define     FUNC_HasVehicleUpgradeLoaded    0x407820
#define     FUNC_RequestVehicleUpgrade      0x408C70

#define     FUNC_CVehicleModelInfo__GetNumRemaps        0x4C86B0

#define     FUNC_SetColModel                0x4C4BC0
#define     FUNC_AddPedModel                0x4c67a0
#define     VAR_CTempColModels_ModelPed1    0x968DF0
/**
 * \todo Fill this class with info from R*
 */
class CBaseModelInfo_SA_VTBL
{
public:
    DWORD           Destructor;
    DWORD           AsAtomicModelInfoPtr;           // (void)
    DWORD           AsDamageAtomicModelInfoPtr;     // (void)
    DWORD           AsLodAtomicModelInfoPtr;        // (void)
    DWORD           GetModelType;                   // (void)           - Not defined in the base
    DWORD           GetTimeInfo;                    // (void)
    DWORD           Init;                           // (void)
    DWORD           Shutdown;                       // (void)
    DWORD           DeleteRwObject;                 // (void)           - Not defined in the base
    DWORD           GetRwModelType;                 // (void)           - Not defined in the base
    DWORD           CreateInstance_;                // (RwMatrixTag*)   - Not defined in the base
    DWORD           CreateInstance;                 // (void)           - Not defined in the base
    DWORD           SetAnimFile;                    // (char const*)
    DWORD           ConvertAnimFileIndex;           // (void)
    DWORD           GetAnimFileIndex;               // (void)
};

class CAtomicModelInfo_SA_VTBL: public CBaseModelInfo_SA_VTBL
{
    DWORD           SetAtomic;                      // (RpAtomic*)
};

class CDamageAtomicModelInfo_SA_VTBL: public CAtomicModelInfo_SA_VTBL
{
};

class CLodAtomicModelInfo_SA_VTBL: public CAtomicModelInfo_SA_VTBL
{
};

class CTimeModelInfo_SA_VTBL: public CAtomicModelInfo_SA_VTBL
{
};

class CLodTimeModelInfo_SA_VTBL: public CLodAtomicModelInfo_SA_VTBL
{
};

class CClumpModelInfo_SA_VTBL: public CBaseModelInfo_SA_VTBL
{
    DWORD           SetClump;                       // (RpClump*)
};

class CWeaponModelInfo_SA_VTBL: public CClumpModelInfo_SA_VTBL
{
};

class CPedModelInfo_SA_VTBL: public CClumpModelInfo_SA_VTBL
{
};

class CVehicleModelInfo_SA_VTBL: public CClumpModelInfo_SA_VTBL
{
};


class CBaseModelInfoSAInterface
{
public:
    CBaseModelInfo_SA_VTBL* VFTBL;                      // +0

    unsigned long           ulHashKey;                  // +4   Generated by CKeyGen::GetUppercaseKey(char const *) called by CBaseModelInfo::SetModelName(char const *)
    unsigned short          usNumberOfRefs: 16;         // +8
    unsigned short          usTextureDictionary: 16;    // +10
    unsigned char           ucAlpha: 8;                 // +12

    unsigned char           ucNumOf2DEffects: 8;        // +13
    unsigned short          usUnknown: 16;              // +14     Something with 2d effects

    unsigned char           ucDynamicIndex: 8;          // +16

    unsigned char           dwUnknownFlag9: 1;          // +17
    unsigned char           dwUnknownFlag10: 1;
    unsigned char           dwUnknownFlag11: 1;
    unsigned char           dwUnknownFlag12: 1;
    unsigned char           dwUnknownFlag13: 1;
    unsigned char           dwUnknownFlag14: 1;
    unsigned char           dwUnknownFlag15: 1;
    unsigned char           dwUnknownFlag16: 1;

    // Flags used by CBaseModelInfo
    unsigned char           bDoWeOwnTheColModel: 1;     // +18
    unsigned char           bIsBackfaceCulled: 1;
    unsigned char           bIsLod: 1;
    unsigned char           bDontCastShadowsOn: 1;
    unsigned char           bDontWriteZBuffer: 1;
    unsigned char           bDrawAdditive: 1;
    unsigned char           bDrawLast: 1;
    unsigned char           bHasBeenPreRendered: 1;

    unsigned char           dwUnknownFlag25: 1;         // +19
    unsigned char           dwUnknownFlag26: 1;
    unsigned char           dwUnknownFlag27: 1;
    unsigned char           bSwaysInWind: 1;
    unsigned char           bCollisionWasStreamedWithModel: 1;  // CClumpModelInfo::SetCollisionWasStreamedWithModel(unsigned int)
    unsigned char           bDontCollideWithFlyer: 1;           // CAtomicModelInfo::SetDontCollideWithFlyer(unsigned int)
    unsigned char           bHasComplexHierarchy: 1;            // CClumpModelInfo::SetHasComplexHierarchy(unsigned int)
    unsigned char           bWetRoadReflection: 1;              // CAtomicModelInfo::SetWetRoadReflection(unsigned int)

    CColModelSAInterface*   pColModel;                  // +20      CColModel: public CBoundingBox

    float                   fLodDistanceUnscaled;       // +24      Scaled is this value multiplied with flt_B6F118
    RwObject*               pRwObject;                  // +28

    // CWeaponModelInfo:
    // +36 = Weapon info as int

    // CPedModelInfo:
    // +36 = Motion anim group (AssocGroupID, long)
    // +40 = Default ped type (long)
    // +44 = Default ped stats (ePedStats)
    // +48 = Can drive cars (byte)
    // +50 = Ped flags (short)
    // +52 = Hit col model (CColModel*)
    // +56 = First radio station
    // +57 = Second radio station
    // +58 = Race (byte)
    // +60 = Audio ped type (short)
    // +62 = First voice
    // +64 = Last voice
    // +66 = Next voice (short)

    // CVehicleModelInfo:
    // +36 = Custom plate material (RpMaterial*)
    // +49 = Custom plate design (byte)
    // +50 = Pointer to game name (const char*)
    // +60 = Vehicle type (enum, int)
    // +64 = Wheel scale (float). Front/rear?
    // +68 = Wheel scale (float). Front/rear?
    // +72 = Wheel model id
    // +74 = Vehicle handling ID (word)
    // +76 = Number of doors (byte)
    // +77 = Vehicle list (byte)
    // +78 = Vehicle flags (byte)
    // +79 = Wheel upgrade class (byte)
    // +80 = Number of times used (byte)
    // +82 = Vehicle freq (short)
    // +84 = Component rules mask (long)
    // +88 = Steer angle
    // +92 = Pointer to some class containing back seat position @ +60
    // +180 = Vehicle upgrade position descriptors array (32 bytes each)
    // +720 = Number of possible colors
    // +726 = Word array as referenced in CVehicleModelInfo::GetVehicleUpgrade(int)
    // +762 = Array of WORD containing something relative to paintjobs
    // +772 = Anim file index
};

/**
 * \todo Someone move GetLevelFromPosition out of here or delete it entirely please
 */


class CModelInfoSA : public CModelInfo
{
protected:
    CBaseModelInfoSAInterface *     m_pInterface;
    DWORD                           m_dwModelID;
    DWORD                           m_dwReferences;
    CColModel*                      m_pCustomColModel;
    CColModelSAInterface*           m_pOriginalColModelInterface;
    RpClump*                        m_pCustomClump;
    static std::map < unsigned short, int > ms_RestreamTxdIDMap;

public:
                                    CModelInfoSA            ( void );
                                    CModelInfoSA            ( DWORD dwModelID );

    CBaseModelInfoSAInterface *     GetInterface             ( void );
    CPedModelInfoSAInterface *      GetPedModelInfoInterface ( void )              { return reinterpret_cast < CPedModelInfoSAInterface * > ( GetInterface () ); }

    DWORD                           GetModel                ( void )               { return m_dwModelID; }
    uint                            GetAnimFileIndex        ( void );

    bool                            IsPlayerModel           ( void );

    BOOL                            IsBoat                  ( void );
    BOOL                            IsCar                   ( void );
    BOOL                            IsTrain                 ( void );
    BOOL                            IsHeli                  ( void );
    BOOL                            IsPlane                 ( void );
    BOOL                            IsBike                  ( void );
    BOOL                            IsFakePlane             ( void );
    BOOL                            IsMonsterTruck          ( void );
    BOOL                            IsQuadBike              ( void );
    BOOL                            IsBmx                   ( void );
    BOOL                            IsTrailer               ( void );
    BOOL                            IsVehicle               ( void );
    BOOL                            IsUpgrade               ( void );

    char *                          GetNameIfVehicle        ( void );

    VOID                            Request                 ( bool bAndLoad = false, bool bWaitForLoad = false, bool bHighPriority = false );
    VOID                            Remove                  ( void );
    BYTE                            GetLevelFromPosition    ( CVector * vecPosition );
    BOOL                            IsLoaded                ( void );
    void                            InternalRemoveGTARef    ( void );
    BYTE                            GetFlags                ( void );
    CBoundingBox *                  GetBoundingBox          ( void );
    bool                            IsValid                 ( void );
    float                           GetDistanceFromCentreOfMassToBaseOfModel ( void );
    unsigned short                  GetTextureDictionaryID  ( void );
    void                            SetTextureDictionaryID  ( unsigned short usID );
    float                           GetLODDistance          ( void );
    void                            SetLODDistance          ( float fDistance );
    void                            RestreamIPL             ( void );
    static void                     StaticFlushPendingRestreamIPL ( void );

    void                            AddRef                  ( bool bWaitForLoad, bool bHighPriority = false );
    int                             GetRefCount             ( void );
    void                            RemoveRef               ( bool bRemoveExtraGTARef = false );
    void                            MaybeRemoveExtraGTARef  ( void );
    void                            DoRemoveExtraGTARef     ( void );

    // CVehicleModelInfo specific
    short                           GetAvailableVehicleMod  ( unsigned short usSlot );
    bool                            IsUpgradeAvailable      ( eVehicleUpgradePosn posn );
    void                            SetCustomCarPlateText   ( const char * szText );
    unsigned int                    GetNumRemaps            ( void );
    void*                           GetVehicleSuspensionData( void );
    void*                           SetVehicleSuspensionData( void* pSuspensionLines );

    // Upgrades only!
    void                            RequestVehicleUpgrade   ( void );

    // ONLY use for peds
    void                            GetVoice                ( short* psVoiceType, short* psVoice );
    void                            GetVoice                ( const char** pszVoiceType, const char** szVoice );
    void                            SetVoice                ( short sVoiceType, short sVoice );
    void                            SetVoice                ( const char* szVoiceType, const char* szVoice );

    // Custom collision related functions
    void                            SetCustomModel          ( RpClump* pClump );
    void                            RestoreOriginalModel    ( void );
    void                            SetColModel             ( CColModel* pColModel );
    void                            RestoreColModel         ( void );
    void                            MakeCustomModel         ( void );

    inline void                     SetModelID              ( DWORD dwModelID ) { m_dwModelID = dwModelID; }

    inline RwObject*                GetRwObject             ( void ) { return m_pInterface ? m_pInterface->pRwObject : NULL; }

    // CModelInfoSA methods
    void                            MakePedModel            ( char * szTexture );
    void                            Sure2Load               ( DWORD dwFlags );

};

#endif