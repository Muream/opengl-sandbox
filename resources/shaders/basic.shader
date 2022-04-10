#shader vertex
#version 330 core

layout(location = 0) in vec4 position;

uniform mat4 mvp;

void main() {
	gl_Position = mvp * position;
	//gl_Position = position;
}


#shader fragment
#version 330 core

out vec4 FragColor;

uniform vec3 color;

void main() {
	FragColor = vec4(color.x, color.y, color.z, 1.0);
}
