// Three.js Scene Setup
const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(
  75,
  window.innerWidth / window.innerHeight,
  0.1,
  1000
);
const renderer = new THREE.WebGLRenderer({ alpha: true }); // Transparency enabled

renderer.setSize(window.innerWidth, window.innerHeight);
document.getElementById("three-container").appendChild(renderer.domElement);

// Lighting
const ambientLight = new THREE.AmbientLight(0x404040, 2);
scene.add(ambientLight);

const directionalLight = new THREE.DirectionalLight(0xffffff, 1);
directionalLight.position.set(5, 3, 5);
scene.add(directionalLight);

// Load Textures
const textureLoader = new THREE.TextureLoader();
const earthTexture = textureLoader.load(
  "https://raw.githubusercontent.com/mrdoob/three.js/refs/heads/master/examples/textures/planets/earth_atmos_2048.jpg"
);
const bumpMap = textureLoader.load(
  "https://raw.githubusercontent.com/mrdoob/three.js/refs/heads/master/examples/textures/planets/earth_normal_2048.jpg"
);

// Create Earth (Only After Textures Are Loaded)
const earthGeometry = new THREE.SphereGeometry(0.55, 64, 64);
const earthMaterial = new THREE.MeshStandardMaterial({
  map: earthTexture,
  bumpMap: bumpMap,
  bumpScale: 0, // Lower bump intensity
});
const earth = new THREE.Mesh(earthGeometry, earthMaterial);

earth.rotation.x = THREE.MathUtils.degToRad(37.5);

// Position the Earth in the center
earth.position.set(0, 0, 4); // Move Earth slightly away from camera
scene.add(earth);

// Stars Background
const starsGeometry = new THREE.BufferGeometry();
const starVertices = [];
for (let i = 0; i < 5000; i++) {
  const x = (Math.random() - 0.5) * 2000;
  const y = (Math.random() - 0.5) * 2000;
  const z = (Math.random() - 0.5) * 2000;
  starVertices.push(x, y, z);
}
starsGeometry.setAttribute(
  "position",
  new THREE.Float32BufferAttribute(starVertices, 3)
);
const starsMaterial = new THREE.PointsMaterial({ color: 0xffffff, size: 1 });
const stars = new THREE.Points(starsGeometry, starsMaterial);
scene.add(stars);

// Adjust Camera Position
camera.position.z = 5;

// Set Scene Background Color
renderer.setClearColor(0x000011, 1);

function animate() {
  requestAnimationFrame(animate);

  // Rotate Earth
  earth.rotation.y += 0.003;

  renderer.render(scene, camera);
}
animate();

// Handle Window Resizing
window.addEventListener("resize", () => {
  renderer.setSize(window.innerWidth, window.innerHeight);
  camera.aspect = window.innerWidth / window.innerHeight;
  camera.updateProjectionMatrix();
});
