components {
  id: "script"
  component: "/main/magic_fx.script"
  position {
    x: 0.0
    y: 0.0
    z: 0.0
  }
  rotation {
    x: 0.0
    y: 0.0
    z: 0.0
    w: 1.0
  }
}
embedded_components {
  id: "light"
  type: "sprite"
  data: "tile_set: \"/def-magic-link/sprites.atlas\"\ndefault_animation: \"magic-sphere_layer3\"\n"
  position {
    x: 0.0
    y: 0.0
    z: 0.002
  }
  rotation {
    x: 0.0
    y: 0.0
    z: 0.0
    w: 1.0
  }
}
embedded_components {
  id: "magic"
  type: "sprite"
  data: "tile_set: \"/def-magic-link/sprites.atlas\"\ndefault_animation: \"magic-sphere_layer2\"\n"
  position {
    x: 0.0
    y: 0.0
    z: 0.001
  }
  rotation {
    x: 0.0
    y: 0.0
    z: 0.0
    w: 1.0
  }
}
