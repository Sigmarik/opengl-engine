#include "keybind_importer.h"

#include <tinyxml2.h>

#include "input_controller.h"
#include "logger/logger.h"

REGISTER(BinaryInputImporter, keybind)

AbstractAsset* BinaryInputImporter::import(const char* path) {
    tinyxml2::XMLDocument doc;
    doc.LoadFile(path);

    const tinyxml2::XMLElement* element = doc.FirstChildElement("keybind");

    if (element == nullptr) return nullptr;

    Asset<BinaryInput>* asset = new Asset<BinaryInput>();

    for (const tinyxml2::XMLElement* child =
             element->FirstChildElement("input");
         child != nullptr; child = child->NextSiblingElement("input")) {
        const char* code = child->Attribute("code");

        if (code = nullptr) {
            log_printf(WARNINGS, "warning",
                       "Input action code was not specified. This input will "
                       "be ignored.\n");
        }

        InputAction* action = InputController::get_action(code);

        if (action == nullptr) {
            log_printf(WARNINGS, "warning",
                       "Input action \"%s\" does not exist, this input will be "
                       "ignored.\n",
                       code);
        }

        asset->content.add_activator(*action);
    }

    return asset;
}