# gdscript2rst

The aim of this project is to produce API documentation for Godot V4 projects.  

The documentation is created from the projects **gdscript** files and relies upon the files being commented as per the recommendations in [GDScript documentation comments](https://docs.godotengine.org/en/stable/tutorials/scripting/gdscript/gdscript_documentation_comments.html#).

The gdscript file's comments are parsed and converted into reStructuredText files with all links, codeblocks etc respected.  These rst. files are then built into a coherent document using the [Sphinx](https://www.sphinx-doc.org) documentation generator.

[Sphinx](https://www.sphinx-doc.org) was chosen as the document generator as it relies primarily on python modules.  This allows gdscript2rst to create a virtual environment and install all the required files on a project by project basis without polluting the users own python environment.

