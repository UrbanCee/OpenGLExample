#version 450 core

out vec4 fColor;
in vec4 col;

void main()
{
    fColor = col;
}
