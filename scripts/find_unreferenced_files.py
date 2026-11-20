from pathlib import Path
import re

chapters = Path("content").rglob("chapter.tex")
included = set()
for chapter in chapters:
    included.update(
        (chapter.parent / name).resolve()
        for name in re.findall(r"\\kactlimport(?:\[[^]]*\])?\{([^}]+)\}", chapter.read_text())
    )
for source in sorted(Path("src").rglob("*")):
    if source.suffix in (".hpp", ".java") and source.resolve() not in included:
        print(source)
