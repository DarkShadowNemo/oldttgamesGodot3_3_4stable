#include "core/os/file_access.h"
#include "scene/3d/mesh_instance.h"

uint32_t EditorSceneImporterGSC::get_import_flags() {

	return IMPORT_SCENE;
}

void EditorSceneImporterGSC::get_extensions(List<String> *r_extensions) {

	r_extensions->push_back("gsc");
}
Error EditorSceneImporterGSC::(String &p_path) {
	Error err;
	FileAccessRef f = FileAccess::open(p_path, FileAccess::READ, &err);
	if (!f) {
		return err;
	}
	fseek(f, 0, 0)
	fseek(f, 0, 2)
	long filesize = ftell(f)
	fseek(f, 0, 0)
	}
	

};
