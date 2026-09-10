#include "core/os/file_access.h"
#include "scene/3d/mesh_instance.h"

uint32_t EditorSceneImporterGSC::get_import_flags() {

	return IMPORT_SCENE;
}

void EditorSceneImporterGSC::get_extensions(List<String> *r_extensions) {

	r_extensions->push_back("gsc");
}
Error EditorSceneImporterGSC::import_scene(String &p_path) {
	Error err;
	FileAccessRef f = FileAccess::open(p_path, FileAccess::READ, &err);
	if (!f) {
		return err;
	}
	fseek(f, 0, 0) = f->seek(0);
	fseek(f, 0, 2) = f->seek_end();
	uint32_t filesize = f->get_position();
	fseek(f, 0, 0) = f->seek(0);
	while (f->get_position() < filesize){
		uint32_t Chunk = f->get_32();
		if (Chunk == int(808605006)){
			//NU20
			uint32_t primtype = f->get_32();
			if (primtype == int(6)){
				uint32_t padding01 = f->get_32();
			} else if (primtype != int(6)){
				uint32_t primtype_ = f->get_32();
				uint32_t padding01_ = f->get_32();
			}
		} else if (Chunk == int(1279415374)){
			//NTBL
			uint32_t NTBL_FileSize = f->get_32();
			if (NTBL_FileSize == int(16)){
				uint32_t namedtablelength = f->get_32();
				uint32_t padding02 = f->get_32();
			} else if (NTBL_FileSize != (16)){
				uint32_t namedtablelength_ = f->get_32();
			}
		} else if (Chunk == int(810832724)){
			//TST0
			uint32_t TST_FileSize = f->get_32();
			uint32_t TextureCount = f->get_32();
			uint32_t padding03 = f->get_32();
			for (int i = 0; i<TextureCount; ++i){
				uint32_t TextureSize1 = f->get_32();
				uint32_t TexturePaddingSize1 = f->get_32();
			}
				
		}
			
	}
};
