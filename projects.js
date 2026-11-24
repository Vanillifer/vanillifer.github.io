window.projects=[{id:"agartha",name:"Agartha",type:"Unreal",tags:["Unreal Engine 5","C++","Motion Matching"],summary:"Third-person locomotion and character controller.",role:"Personal project · In development",tone:"#355e69",featured:true,details:["Character movement and gait transitions in C++.","Motion Matching integration using Pose Search and animation databases.","Iterative tuning of movement responsiveness and animation transitions."]},{id:"fairy",name:"Fairy Controller",type:"Unreal",tags:["Unreal Engine 5","Blueprints","Niagara"],summary:"Wing-assisted movement, triple jumping and physics interactions.",role:"Course project",tone:"#51476b",details:["Triple jump and forward boost tuning.","Push and pull interactions with physics objects.","Niagara effects and a ground-projected landing indicator."]},{id:"rpg",name:"RPG Gameplay Systems",type:"Unreal",tags:["Unreal Engine 5","Blueprints","UMG"],summary:"Reusable inventory, equipment, shop and chest systems.",role:"Team project",tone:"#68523e",details:["Inventory and equipment slot validation.","Item purchases, currency and persistent shop stock.","Chest loot and equipment stat modifiers."]},{id:"restoration",name:"World Restoration Shader",type:"Unreal",tags:["Unreal Engine 5","Materials","Shaders"],summary:"A world-space restoration effect with layered materials.",role:"Course project",tone:"#315b58",details:["World-space distance masks and soft falloff.","Triplanar vein masks, emissive pulses and foliage effects.","Material complexity and optimization experiments."]}];

projects.push({
  id: "heroes-of-the-depth",
  name: "Heroes of the Depth",
  type: "Unreal",
  tags: ["Unreal Engine", "C++", "Blueprints"],
  summary: "A turn-based roguelite dungeon crawler featuring two heroes, procedurally generated dungeons and character progression.",
  role: "Gameplay Programmer · Team of 10 · 4 weeks",
  tone: "#51476b",
  video: "assets/videos/heroes-gameplay.mp4",
  details: [
    "Developed a C++ upgrade system integrated with the designers' existing Blueprint prototype.",
    "Implemented experience progression and two skill points per level.",
    "Created a minimap that works with procedurally generated dungeons; dungeon generation was implemented by another programmer.",
    "Contributed character controls, enemy damage logic, debugging and gameplay integration."
  ],
  systems: [
    { title: "Combat & character controls", video: "heroes-combat.mp4", description: "I contributed character controls and enemy damage logic, working with the team to improve the existing gameplay prototype. This clip shows those contributions in the context of the team's turn-based combat." },
    { title: "Experience & leveling", video: "heroes-level-up.mp4", description: "I implemented the experience and progression system. Players earn XP and receive two skill points per level, which they can spend on hero upgrades." },
    { title: "Skill points & upgrades", video: "heroes-upgrades.mp4", description: "I developed a C++ upgrade system and connected it to the designers' existing Blueprint logic. Players spend skill points to improve their heroes, with validation of the selected character, upgrade cost and available points." }
  ]
});
