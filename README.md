```markdown
# 🚀 Dynamic-Hierarchical-3D-Robot-Rendering

---

## 🤖 Dynamic-Hierarchical-3D-Robot-Rendering
This project demonstrates **hierarchical robot modeling** using **OpenGL** with transformations like:
- **Translation (`glTranslate`)**
- **Rotation (`glRotate`)**
- **Matrix Stacking (`glPushMatrix`, `glPopMatrix`)**

Each robot part is modeled **independently** but connected using **parent-child relationships**, allowing **joint-based movements**.

---

## ✨ Features
- **Multi-Part Model**: The robot consists of **4 hierarchical levels**, making movements more natural.
- **Controllable Joints**: Move key parts of the robot (**head, arms, legs**) using keyboard inputs.
- **Animations**:
  - **Walking Animation** (`W` to start, `w` to stop): Simulates stepping by rotating hip and leg joints.
  - **Spinning Cannon** (`S` to start, `s` to stop): Rotates the cannon continuously.
- **Dynamic Camera Control**: Change viewpoints to explore the robot in 3D.
- **Realistic Material & Lighting**: The model features **real-time shading**, including:

  - 🎨 **Metallic Blue**  
    - `Ambient:` `0.101, 0.146, 0.229`  
    - `Diffuse:` `0.101, 0.146, 0.229`  
    - `Specular:` `0.337, 0.486, 0.765`  
    - `Shininess:` `32.0`

  - ⚪ **Matte White**  
    - `Ambient:` `0.251, 0.268, 0.262`  
    - `Diffuse:` `0.418, 0.447, 0.438`  
    - `Specular:` `0.835, 0.894, 0.875`  
    - `Shininess:` `32.0`

  - 🔴 **Glossy Red**  
    - `Ambient:` `0.247, 0.066, 0.038`  
    - `Diffuse:` `0.412, 0.110, 0.063`  
    - `Specular:` `0.824, 0.220, 0.125`  
    - `Shininess:` `32.0`

  - 🟡 **Khaki Yellow**  
    - `Ambient:` `0.274, 0.194, 0.045`  
    - `Diffuse:` `0.913, 0.647, 0.149`  
    - `Specular:` `0.457, 0.324, 0.075`  
    - `Shininess:` `32.0`

  - ⚙️ **Metallic Grey**  
    - `Ambient:` `0.133, 0.160, 0.169`  
    - `Diffuse:` `0.222, 0.267, 0.282`  
    - `Specular:` `0.443, 0.533, 0.565`  
    - `Shininess:` `32.0`

---

## 🛠 Requirements
To run this project, you need:
- **Visual Studio 2022** (or compatible version)
- **OpenGL & GLUT Libraries** installed
- **Windows OS** (Tested on Windows 10 & 11)

---

## 🕹 Usage
- **Move Camera**: Use arrow keys (`↑ ↓ ← →`).
- **Rotate the Robot**: Press `R` key.
- **Walking Animation**: Press `W` to start, `w` to stop.
- **Spin Cannon**: Press `S` to start, `s` to stop.
- **Change Perspective**: `A`, `D`, `W`, `S` keys.

---

## 🙏 Acknowledgements
- Created for the **CPS511: Computer Graphics** course at **Toronto Metropolitan University**.
- Uses **OpenGL** for real-time rendering and hierarchical transformations.

---

## 📧 Contact
For questions, suggestions, or feedback, feel free to reach out:  
📩 **Your Email**: [hasibur2060@gmail.com](mailto:hasibur2060@gmail.com)

---

This version improves **readability, structure, and formatting** while keeping all essential information. 🚀
```
