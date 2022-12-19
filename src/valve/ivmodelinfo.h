#pragma once
#include "../util/memory.h"

#include "cvector.h"

// thx qo0!
enum EHitboxIndex : int
{
	HITBOX_INVALID = -1,
	HITBOX_HEAD,
	HITBOX_NECK,
	HITBOX_PELVIS,
	HITBOX_STOMACH,
	HITBOX_THORAX,
	HITBOX_CHEST,
	HITBOX_UPPER_CHEST,
	HITBOX_RIGHT_THIGH,
	HITBOX_LEFT_THIGH,
	HITBOX_RIGHT_CALF,
	HITBOX_LEFT_CALF,
	HITBOX_RIGHT_FOOT,
	HITBOX_LEFT_FOOT,
	HITBOX_RIGHT_HAND,
	HITBOX_LEFT_HAND,
	HITBOX_RIGHT_UPPER_ARM,
	HITBOX_RIGHT_FOREARM,
	HITBOX_LEFT_UPPER_ARM,
	HITBOX_LEFT_FOREARM,
	HITBOX_MAX
};

class CStudioBone
{
public:

};

class CStudioBoundingBox
{
public:
	int bone;
	int group;
	CVector bbMin;
	CVector bbMax;
	int hitboxNameIndex;
	CVector offsetRotation;
	float capsuleRadius;
	int unused[4];
};

class CStudioHitboxSet
{
public:
	int nameIndex;
	int numHitboxes;
	int hitboxIndex;


	inline const char* GetName() const noexcept 
	{
		return reinterpret_cast<char*>(std::uintptr_t(this) + nameIndex);
	}

	inline CStudioBoundingBox* GetHitbox(int index) noexcept
	{
		if (index < 0 || index >= numHitboxes)
			return nullptr;

		return reinterpret_cast<CStudioBoundingBox*>(reinterpret_cast<std::uint8_t*>(this) + hitboxIndex) + index;
	}
};

class CStudioHdr
{
public:
	inline CStudioBone* GetBone(int index) noexcept
	{
		if (index < 0 || index >= numBones)
			return nullptr;

		return reinterpret_cast<CStudioBone*>(std::uintptr_t(this) + boneIndex) + index;
	}

	inline CStudioHitboxSet* GetHitboxSet(int index) noexcept
	{
		if (index < 0 || index >= numHitboxSets)
			return nullptr;

		return reinterpret_cast<CStudioHitboxSet*>(std::uintptr_t(this) + hitboxSetIndex) + index;
	}

	int id;
	int version;
	int checksum;
	char name[64];
	int length;

	CVector eyePosition;
	CVector illumPosition;
	CVector hullMin;
	CVector hullMax;
	CVector bbMin;
	CVector bbMax;

	int flags;
	int numBones;
	int boneIndex;
	int numBoneControllers;
	int boneControllerIndex;
	int numHitboxSets;
	int hitboxSetIndex;
};

class CModel
{
public:
	std::int32_t handle;
	char name[260];
	std::int32_t loadFlags;
	std::int32_t serverCount;
	std::int32_t type;
	std::int32_t flags;
	CVector mins;
	CVector maxs;
	float radius;
};

class IVModelInfo
{
public:
	enum ERenderFlags : std::uint32_t
	{
		RENDER_FLAGS_DISABLE_RENDERING = 0x01,
		RENDER_FLAGS_HASCHANGED = 0x02,
		RENDER_FLAGS_ALTERNATE_SORTING = 0x04,
		RENDER_FLAGS_RENDER_WITH_VIEWMODELS = 0x08,
		RENDER_FLAGS_BLOAT_BOUNDS = 0x10,
		RENDER_FLAGS_BOUNDS_VALID = 0x20,
		RENDER_FLAGS_BOUNDS_ALWAYS_RECOMPUTE = 0x40,
		RENDER_FLAGS_IS_SPRITE = 0x80,
		RENDER_FLAGS_FORCE_OPAQUE_PASS = 0x100,
	};

	constexpr const char* GetModelName(const CModel* model) noexcept
	{
		return memory::Call<const char*>(this, 3, model);
	}

	constexpr CStudioHdr* GetStudioModel(const CModel* model) noexcept
	{
		return memory::Call<CStudioHdr*>(this, 32, model);
	}
};
