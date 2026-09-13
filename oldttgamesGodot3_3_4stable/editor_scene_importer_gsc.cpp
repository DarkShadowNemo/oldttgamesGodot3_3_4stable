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
			} else {
				uint32_t primtype_ = f->get_32();
				uint32_t padding01_ = f->get_32();
			}
		} else if (Chunk == int(1279415374)){
			//NTBL
			uint32_t NTBL_FileSize = f->get_32();
			if (NTBL_FileSize == int(16)){
				uint32_t namedtablelength = f->get_32();
				uint32_t padding02 = f->get_32();
			} else {
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
				if (TexturePaddingSize1 != int(0)){
					for (int i = 0; i<TexturePaddingSize1; ++i){
						uint8_t bytes1 = f->get_8();
					}
					uint16_t height_ = f->get_16();
					uint16_t type1 = f->get_16();
					uint16_t width_ = f->get_16();
					uint16_t type2 = f->get_16();
					uint32_t pitch = f->get_32();
					uint8_t flag1 = f->get_8();
					uint8_t flag2 = f->get_8();
					uint8_t flag3 = f->get_8();
					uint8_t flag4 = f->get_8();
					uint32_t size1 = f->get_32();
					uint32_t size2 = f->get_32();
					uint32_t type3 = f->get_32();
					uint32_t type4 = f->get_32();
					if (type4 == int(0)){
						uint8_t textureRumble = f->get_8();
						uint8_t textureBrightness = f->get_8();
						uint8_t null01 = f->get_8();
						uint8_t flag5 = f->get_8();
						uint32_t null02 = f->get_32();
						uint32_t null03 = f->get_32();
						uint8_t textureRumbleAgain = f->get_8();
						uint8_t textureBrightnessAgain = f->get_8();
						uint8_t null01Again = f->get_8();
						uint8_t flag5Again = f->get_8();
						uint8_t type5 = f->get_8();
						uint8_t value01 = f->get_8();
						uint16_t null04 = f->get_16();
						uint32_t pitch01 = f->get_32();
						uint32_t flag_1 = f->get_32(); //0x0E
						uint32_t zero01 = f->get_32();
						uint32_t zero02 = f->get_32();
						uint32_t zero03 = f->get_32();
						uint32_t flag_2 = f->get_32(); //0x51
						uint32_t zero04 = f->get_32();
						uint32_t comprHeight = f->get_32();
						uint32_t comprWidth = f->get_32();
						uint32_t flag_3 = f->get_32(); //0x52
						uint32_t zero05 = f->get_32();
						uint32_t zero06 = f->get_32();
						uint32_t zero07 = f->get_32();
						uint32_t flag_4 = f->get_32(); //0x53
						uint32_t zero08 = f->get_32();
						uint16_t pallete_offset = f->get_16();
						uint16_t zero09 = f->get_16();
						uint16_t zero10 = f->get_16();
						uint16_t pallete_length = f->get_16(); // 2048
						uint16_t zero11 = f->get_16();
						uint16_t zero12 = f->get_16();
						uint16_t zero13 = f->get_16();
						uint16_t zero14 = f->get_16();
					} else if (type4 != int(0)){
						uint32_t padsize01 = f->get_32();
						for (int i = 0; i<padsize01; ++i){
							uint8_t padbytes1 = f->get_8();
						}
						uint8_t textureRumble = f->get_8();
						uint8_t textureBrightness = f->get_8();
						uint8_t null01 = f->get_8();
						uint8_t flag5 = f->get_8();
						uint32_t null02 = f->get_32();
						uint32_t null03 = f->get_32();
						uint8_t textureRumbleAgain = f->get_8();
						uint8_t textureBrightnessAgain = f->get_8();
						uint8_t null01Again = f->get_8();
						uint8_t flag5Again = f->get_8();
						uint8_t type5 = f->get_8();
						uint8_t value01 = f->get_8();
						uint16_t null04 = f->get_16();
						uint32_t pitch01 = f->get_32();
						uint32_t flag_1 = f->get_32(); //0x0E
						uint32_t zero01 = f->get_32();
						uint32_t zero02 = f->get_32();
						uint32_t zero03 = f->get_32();
						uint32_t flag_2 = f->get_32(); //0x51
						uint32_t zero04 = f->get_32();
						uint32_t comprHeight = f->get_32();
						uint32_t comprWidth = f->get_32();
						uint32_t flag_3 = f->get_32(); //0x52
						uint32_t zero05 = f->get_32();
						uint32_t zero06 = f->get_32();
						uint32_t zero07 = f->get_32();
						uint32_t flag_4 = f->get_32(); //0x53
						uint32_t zero08 = f->get_32();
						uint16_t pallete_offset = f->get_16();
						uint16_t zero09 = f->get_16();
						uint16_t zero10 = f->get_16();
						uint16_t pallete_length = f->get_16(); // 2048
						uint16_t zero11 = f->get_16();
						uint16_t zero12 = f->get_16();
						uint16_t zero13 = f->get_16();
						uint16_t zero14 = f->get_16();
						if (pallete_offset == int(49152)){
							
						} else if (pallete_offset == int(40960)){
							
						} else if (pallete_offset == int(36864)){
							
						} else if (pallete_offset == int(33792)){
							
						}
					}
				} else if (TexturePaddingSize1 == int(0)){
					uint32_t pad_01 = f->get_32();
					uint32_t pad_02 = f->get_32();
					uint16_t height_ = f->get_16();
					uint16_t type1 = f->get_16();
					uint16_t width_ = f->get_16();
					uint16_t type2 = f->get_16();
					uint32_t pitch = f->get_32();
					uint8_t flag1 = f->get_8();
					uint8_t flag2 = f->get_8();
					uint8_t flag3 = f->get_8();
					uint8_t flag4 = f->get_8();
					uint32_t size1 = f->get_32();
					uint32_t size2 = f->get_32();
					uint32_t type3 = f->get_32();
					uint32_t type4 = f->get_32();
					if (type4 == int(0)){
						uint8_t textureRumble = f->get_8();
						uint8_t textureBrightness = f->get_8();
						uint8_t null01 = f->get_8();
						uint8_t flag5 = f->get_8();
						uint32_t null02 = f->get_32();
						uint32_t null03 = f->get_32();
						uint8_t textureRumbleAgain = f->get_8();
						uint8_t textureBrightnessAgain = f->get_8();
						uint8_t null01Again = f->get_8();
						uint8_t flag5Again = f->get_8();
						uint8_t type5 = f->get_8();
						uint8_t value01 = f->get_8();
						uint16_t null04 = f->get_16();
						uint32_t pitch01 = f->get_32();
						uint32_t flag_1 = f->get_32(); //0x0E
						uint32_t zero01 = f->get_32();
						uint32_t zero02 = f->get_32();
						uint32_t zero03 = f->get_32();
						uint32_t flag_2 = f->get_32(); //0x51
						uint32_t zero04 = f->get_32();
						uint32_t comprHeight = f->get_32();
						uint32_t comprWidth = f->get_32();
						uint32_t flag_3 = f->get_32(); //0x52
						uint32_t zero05 = f->get_32();
						uint32_t zero06 = f->get_32();
						uint32_t zero07 = f->get_32();
						uint32_t flag_4 = f->get_32(); //0x53
						uint32_t zero08 = f->get_32();
						uint16_t pallete_offset = f->get_16();
						uint16_t zero09 = f->get_16();
						uint16_t zero10 = f->get_16();
						uint16_t pallete_length = f->get_16(); // 2048
						uint16_t zero11 = f->get_16();
						uint16_t zero12 = f->get_16();
						uint16_t zero13 = f->get_16();
						uint16_t zero14 = f->get_16();
					} else if (type4 != int(0)){
						uint32_t padsize01 = f->get_32();
						for (int i = 0; i<padsize01; ++i){
							uint8_t padbytes1 = f->get_8();
						}
						uint8_t textureRumble = f->get_8();
						uint8_t textureBrightness = f->get_8();
						uint8_t null01 = f->get_8();
						uint8_t flag5 = f->get_8();
						uint32_t null02 = f->get_32();
						uint32_t null03 = f->get_32();
						uint8_t textureRumbleAgain = f->get_8();
						uint8_t textureBrightnessAgain = f->get_8();
						uint8_t null01Again = f->get_8();
						uint8_t flag5Again = f->get_8();
						uint8_t type5 = f->get_8();
						uint8_t value01 = f->get_8();
						uint16_t null04 = f->get_16();
						uint32_t pitch01 = f->get_32();
						uint32_t flag_1 = f->get_32(); //0x0E
						uint32_t zero01 = f->get_32();
						uint32_t zero02 = f->get_32();
						uint32_t zero03 = f->get_32();
						uint32_t flag_2 = f->get_32(); //0x51
						uint32_t zero04 = f->get_32();
						uint32_t comprHeight = f->get_32();
						uint32_t comprWidth = f->get_32();
						uint32_t flag_3 = f->get_32(); //0x52
						uint32_t zero05 = f->get_32();
						uint32_t zero06 = f->get_32();
						uint32_t zero07 = f->get_32();
						uint32_t flag_4 = f->get_32(); //0x53
						uint32_t zero08 = f->get_32();
						uint16_t pallete_offset = f->get_16();
						uint16_t zero09 = f->get_16();
						uint16_t zero10 = f->get_16();
						uint16_t pallete_length = f->get_16(); // 2048
						uint16_t zero11 = f->get_16();
						uint16_t zero12 = f->get_16();
						uint16_t zero13 = f->get_16();
						uint16_t zero14 = f->get_16();
						if (pallete_offset == int(49152)){
							
						} else if (pallete_offset == int(40960)){
							
						} else if (pallete_offset == int(36864)){
							
						} else if (pallete_offset == int(33792)){
							
						}
					}
				
				}
				
			}
				
		} else if (Chunk == int(808473421)){
			//MS00
			uint32_t MaterialSet_FileSize = f->get_32();
			uint32_t MaterialCount = f-get_32();
			uint32_t padding04 = f->get_32();
		}
			
	}
};
