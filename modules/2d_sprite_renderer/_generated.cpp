#include "apparatus.h"
#include "./2d_sprite_renderer.h"

#include <vector>
#include <functional>

#include <entt/meta/meta.hpp>
#include <entt/meta/resolve.hpp>

#include <misc/cpp/imgui_stdlib.h>
#include <asset_manager/asset_manager.h>

Hash_Set<uintptr_t> runtime_ids;
Hash_Map<std::string, uintptr_t> name_id_map;
Hash_Map<uintptr_t, Component_Info> component_info;

template <typename type_t>
void do_gui(const std::string& name, type_t* data) {

    std::string label = name;

    if constexpr (std::is_same<type_t, bool>()) {
        ImGui::RCheckbox(label.c_str(), data);
    } else if constexpr (std::is_integral<type_t>()) {
        ImGui::RDragInt(label.c_str(), (s32*)data, .1f);
    } else if constexpr (std::is_same<type_t, mz::ivec2>()) {
        ImGui::RDragInt2(label.c_str(), (s32*)data, .1f);
    } else if constexpr (std::is_same<type_t, mz::ivec3>()) {
        ImGui::RDragInt3(label.c_str(), (s32*)data, .1f);
    } else if constexpr (std::is_same<type_t, mz::ivec4>()) {
        ImGui::RDragInt4(label.c_str(), (s32*)data, .1f);
    } else if constexpr (std::is_same<type_t, f32>()) {
        ImGui::RDragFloat(label.c_str(), (f32*)data, 0.1f);
    } else if constexpr (std::is_same<type_t, mz::fvec2>()) {
        ImGui::RDragFloat2(label.c_str(), (f32*)data, 0.1f);
    } else if constexpr (std::is_same<type_t, mz::fvec3>()) {
        ImGui::RDragFloat3(label.c_str(), (f32*)data, 0.1f);
    } else if constexpr (std::is_same<type_t, mz::fvec4>()) {
        ImGui::RDragFloat4(label.c_str(), (f32*)data, 0.1f);
    } else {
        ImGui::Text("%s N/A", label.c_str());
    }
}

module_scope {

    // Generated
	module_function(void) init() {

        {
            uintptr_t id = (uintptr_t)typeid(Sprite2D).name();
            runtime_ids.emplace(id);
            name_id_map["Sprite2D"] = id;
            component_info[id] = {
                [](entt::registry& reg, entt::entity entity) { 
                    return &reg.emplace<Sprite2D>(entity);
                },
                [](entt::registry& reg, entt::entity entity) { 
                    if (!reg.has<Sprite2D>(entity)) return (void*)NULL;
                    return (void*)&reg.get<Sprite2D>(entity);
                }, 
                [](entt::registry& reg, entt::entity entity) { 
                    reg.remove<Sprite2D>(entity);
                },
            
                "Sprite2D",
                id,
                false,
                sizeof(Sprite2D),
                std::vector<Property_Info> {
                    Property_Info { 
                        [](void* data) {
                            ImGui::InputAsset("texture", (asset_id_t*)data, "Texture");                        },
                        "texture",
                        sizeof(asset_id_t),
                        ap_offsetof(Sprite2D, texture),
                    },
                    Property_Info { 
                        [](void* data) {
                            ImGui::RColorEdit4("tint", (f32*)data);
                        },
                        "tint",
                        sizeof(color),
                        ap_offsetof(Sprite2D, tint),
                    },
                    Property_Info { 
                        [](void* data) {
                            do_gui<fvec2>("origin", (fvec2*)data);
                        },
                        "origin",
                        sizeof(fvec2),
                        ap_offsetof(Sprite2D, origin),
                    },
                    Property_Info { 
                        [](void* data) {
                            do_gui<int>("depth_level", (int*)data);
                        },
                        "depth_level",
                        sizeof(int),
                        ap_offsetof(Sprite2D, depth_level),
                    },
                }
            };
        }
        {
            uintptr_t id = (uintptr_t)typeid(SpriteAnimation2D).name();
            runtime_ids.emplace(id);
            name_id_map["SpriteAnimation2D"] = id;
            component_info[id] = {
                [](entt::registry& reg, entt::entity entity) { 
                    return &reg.emplace<SpriteAnimation2D>(entity);
                },
                [](entt::registry& reg, entt::entity entity) { 
                    if (!reg.has<SpriteAnimation2D>(entity)) return (void*)NULL;
                    return (void*)&reg.get<SpriteAnimation2D>(entity);
                }, 
                [](entt::registry& reg, entt::entity entity) { 
                    reg.remove<SpriteAnimation2D>(entity);
                },
            
                "SpriteAnimation2D",
                id,
                true,
                sizeof(SpriteAnimation2D),
                std::vector<Property_Info> {
                    Property_Info { 
                        [](void* data) {
                            on_gui((SpriteAnimation2D*)data);
                        },
                        "is_playing",
                        sizeof(bool),
                        ap_offsetof(SpriteAnimation2D, is_playing),
                    },
                    Property_Info { 
                        [](void* data) {
                            on_gui((SpriteAnimation2D*)data);
                        },
                        "depth_level",
                        sizeof(int),
                        ap_offsetof(SpriteAnimation2D, depth_level),
                    },
                    Property_Info { 
                        [](void* data) {
                            on_gui((SpriteAnimation2D*)data);
                        },
                        "origin",
                        sizeof(fvec2),
                        ap_offsetof(SpriteAnimation2D, origin),
                    },
                    Property_Info { 
                        [](void* data) {
                            on_gui((SpriteAnimation2D*)data);
                        },
                        "tint",
                        sizeof(color16),
                        ap_offsetof(SpriteAnimation2D, tint),
                    },
                    Property_Info { 
                        [](void* data) {
                            on_gui((SpriteAnimation2D*)data);
                        },
                        "animation_preset",
                        sizeof(asset_id_t),
                        ap_offsetof(SpriteAnimation2D, animation_preset),
                    },
                    Property_Info { 
                        [](void* data) {
                            on_gui((SpriteAnimation2D*)data);
                        },
                        "texture_sheet",
                        sizeof(asset_id_t),
                        ap_offsetof(SpriteAnimation2D, texture_sheet),
                    },
                    Property_Info { 
                        [](void* data) {
                            on_gui((SpriteAnimation2D*)data);
                        },
                        "frames_per_second",
                        sizeof(f32),
                        ap_offsetof(SpriteAnimation2D, frames_per_second),
                    },
                    Property_Info { 
                        [](void* data) {
                            on_gui((SpriteAnimation2D*)data);
                        },
                        "target_frames",
                        sizeof(irange),
                        ap_offsetof(SpriteAnimation2D, target_frames),
                    },
                    Property_Info { 
                        [](void* data) {
                            on_gui((SpriteAnimation2D*)data);
                        },
                        "xflip",
                        sizeof(bool),
                        ap_offsetof(SpriteAnimation2D, xflip),
                    },
                    Property_Info { 
                        [](void* data) {
                            on_gui((SpriteAnimation2D*)data);
                        },
                        "current_frame",
                        sizeof(s32),
                        ap_offsetof(SpriteAnimation2D, current_frame),
                    },
                    Property_Info { 
                        [](void* data) {
                            on_gui((SpriteAnimation2D*)data);
                        },
                        "time",
                        sizeof(f32),
                        ap_offsetof(SpriteAnimation2D, time),
                    },
                    Property_Info { 
                        [](void* data) {
                            on_gui((SpriteAnimation2D*)data);
                        },
                        "preview_frame",
                        sizeof(s32),
                        ap_offsetof(SpriteAnimation2D, preview_frame),
                    },
                    Property_Info { 
                        [](void* data) {
                            on_gui((SpriteAnimation2D*)data);
                        },
                        "preview_time",
                        sizeof(f32),
                        ap_offsetof(SpriteAnimation2D, preview_time),
                    },
                }
            };
        }

    
    }

    module_function(Component_Info*) get_component_info(uintptr_t runtime_id) {
		return &component_info[runtime_id];
	}

	module_function(const Hash_Set<uintptr_t>&)get_component_ids() {
		return runtime_ids;
	}

	module_function(void*) create_component(uintptr_t runtime_id, entt::registry& reg, entt::entity entity) {
		return component_info[runtime_id].create(reg, entity);
	}

    module_function(void*) get_component(uintptr_t runtime_id, entt::registry& reg, entt::entity entity) {
        return component_info[runtime_id].get(reg, entity);
    }

    module_function(void) remove_component(uintptr_t runtime_id, entt::registry& reg, entt::entity entity) {
		component_info[runtime_id].remove(reg, entity);
	}

    module_function(uintptr_t) get_component_id(const std::string& name) {
        if (name_id_map.find(name) != name_id_map.end())
            return name_id_map[name];
        else
            return 0;
    }

    module_function(void) set_imgui_context(ImGuiContext* ctx) {
        ImGui::SetCurrentContext(ctx);
    }

}

module_scope {
    module_function(void) deinit() {
        entt::resolve<Sprite2D>().reset();
        entt::resolve<SpriteAnimation2D>().reset();
    }
}
