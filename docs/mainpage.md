# Documentation for GDScriptToSphinx {#mainpage}

This is the API documentation for my program to generate Sphinx documentation
from the API's in a Godot project.

It reads the Godot 4 style API comments; those comments that start with
a **##** (See [GDScript documentation comments](https://docs.godotengine.org/en/stable/tutorials/scripting/gdscript/gdscript_documentation_comments.html)).

After parsing the comments it creates individual reStructuredText files for each GDScript file in the project then uses Sphinx to build the documentation.

