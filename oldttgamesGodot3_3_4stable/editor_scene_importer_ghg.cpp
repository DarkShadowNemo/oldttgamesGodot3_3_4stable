#include "core/os/file_access.h"
#include "scene/3d/mesh_instance.h"

uint32_t EditorSceneImporterGHG::get_import_flags() {

	return IMPORT_SCENE;
}

void EditorSceneImporterGHG::get_extensions(List<String> *r_extensions) {

	r_extensions->push_back("ghg");
}

Error EditorSceneImporterGHG::(String &p_path) {
	Error err;
	FileAccessRef f = FileAccess::open(p_path, FileAccess::READ, &err);
	if (!f) {
		return err;
	}
	uint32_t FileSize = f->get_32();
	uint32_t null1 = f->get_32();
	uint32_t TextureCount = f->get_32();
	uint32_t TextureEntrySize1 = f->get_32();
	uint32_t MaterialCount = f->get_32();
	uint32_t MaterialEntrySize1 = f->get_32();
	uint32_t BoneCount = f->get_32();
	uint32_t RotationBoneEntrySize1 = f->get_32();
	uint32_t ScaleBoneEntrySize1 = f->get_32();
	uint32_t PositionBoneEntrySize1 = f->get_32();
	uint32_t unknown_01 = f->get_32();
	uint32_t MatrixEntrySize1 = f->get_32();
	uint32_t NamedtableEntrySize1 = f->get_32();
	uint32_t NamedtableLength = f->get_32();
	uint32_t Count1 = f->get_32();
	uint32_t Size1 = f->get_32();
	uint32_t Count2 = f->get_32();
	uint32_t Size2 = f->get_32();
	uint32_t DefaultLayerCount = f->get_32();
	uint32_t DefaultLayerSize = f->get_32();
	uint32_t Size3 = f->get_32();
	for (int i = 1; i <= 11; i++){
		float float01 = f->get_float();
	}
};
