#version 330 core

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;

in vec4 ourColor;	
in vec2 TexCoord;

out vec4 FragColor;

void main()
{
    FragColor = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord), 0.4f) * ourColor;
}