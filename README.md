# Yet Another GameDev Framework

![screenshot.png](docs/screenshot.png)

## Description

This project is a game development framework with rudimentary physics, graphics and asset management systems.

Its features include, but not limited to:
- [gbuffer-based rendering pipeline](./docs/graphics/CORE.md),
- [flexible asset system](./docs/asset_system/CORE.md) with the ability to write [custom importers](./docs/asset_system/CUSTOM_IMPORTERS.md),
- [robust physics engine](./docs/physics/CORE.md),
- [hierarchical scene organization system](./docs/logics/CORE.md),
- [simple Blender addon for framework scene format capability](./docs/logics/BLENDER_ADDON.md),
- [asset-based user input system](./docs/input/CORE.md) (soon to be enhanced with an event-driven interface).
- [high-level scripting language for sequence programming](docs/asset_system/EVENT_ROUTING.md),

WIP (Work In Progress) features:
- [support for animated models](https://github.com/Sigmarik/graphics-engine/issues/4),
- [adequate project structure :)](https://github.com/Sigmarik/graphics-engine/issues/26).

## Documentation

An overview of the project's systems with links to relevant pieces of documentation can be found [here](./docs/structure/FRAMEWORK_STRUCTURE.md).

Detailed code documentation of the project's systems can be generated by running the command `make doxy` (make sure you have doxygen installed). Examining the code of the template project can also help.

Many features were documented in the corresponding [pull requests](https://github.com/Sigmarik/graphics-engine/pulls?q=is%3Apr+is%3Aclosed), so it is a good idea to look at one of these if you want to learn more about certain features of the project.

## Building the project

The project was tested on *Linux Mint 21.2* OS, but should work on other common linux distributions as well.

### GNU Make

1. Install GNU Make version 4.3 or above,
2. Install assimp version 5.2 or above,
3. Install the GLFW library (manually or by running `$ make install-glfw`),
4. Run `$ make`.

After the build is complete, the executable with all corresponding assets can be found in the [build](build/) folder. It can be ran either manually or by executing `$ make run`.

## Screenshots and snippets

![asset_preview](docs/blend_preview_table.png)

*Fig. 1. A preview of the table asset in Blender, ready to be either directly imported into the program, or used in a bigger scene. Blue boxes represent exportable colliders.*

![scene_preview](docs/blend_preview_scene.png)

*Fig. 2. A preview of the entire pool table.*

```XML
<material>
    <shader path="assets/shaders/basic.shader.xml"></shader>

    <texture uniform="albedo" path="assets/textures/green_field.png"></texture>
    <texture uniform="ao_map" path="assets/textures/field_ao.texture.xml"></texture>
</material>
```

*Snippet 1. Example of a material asset in the XML format. This particular material can be found [here](assets/materials/field.material.xml).*

```python
message = "Hello from the scripting world! See the level script to learn where this message came from!"

@SomeShouterComponent::shout <- message
@SomeShouterComponent::shout <- [@PlayerBall.knocked_down] ? "RESET!" : IMPOSSIBLE
```

*Snippet 2. An example of a high-level event routing script, written on a custom programming language. This particular script can be found [here](assets/levels/pool_table.level.xml).*
