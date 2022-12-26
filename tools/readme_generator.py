import os
import json

from pathlib import Path

from readme_content_providers import KattisReadmeContentProvider


class ReadmeAppender:
    def __init__(self):
        self.writers = []

    def write(self, text):
        for writer in self.writers:
            writer.write(text)

    def add_writer(self, writer):
        self.writers.append(writer)

    def remove_writer(self, writer):
        self.writers.remove(writer)


class ReadmeWriter:
    def __init__(self, path, content_provider):
        self.readme_appender = None
        self.content_provider = content_provider
        self.path = path

    def set_readme_appender(self, readme_appender):
        if self.readme_appender:
            self.readme_appender.remove_generator(self)

        self.readme_appender = readme_appender
        self.readme_appender.add_writer(self)

    def __enter__(self):
        self.file = open(self.path, 'w', encoding="utf-8")
        self.file.write(self.content_provider.get_header())
        return self

    def __exit__(self, exc_type, exc_value, tb):
        self.readme_appender.remove_writer(self)
        self.file.close()

    def write(self, text):
        self.file.write(text)


class RecursiveReadmeWriter:
    def __init__(self, path, content_provider):
        self.path = path
        self.content_provider = content_provider
        self.readme_appender = ReadmeAppender()

    def generate(self):

        def generate_recursive(path: Path):
            with ReadmeWriter(path / "README.md", self.content_provider) as readme_handle:
                readme_handle.set_readme_appender(self.readme_appender)

                info_json = path / "info.json"
                if info_json.exists():
                    with open(info_json, "r") as json_file:
                        data = json.load(json_file)
                    entry = self.content_provider.get_entry(data)
                    self.readme_appender.write(entry)

                if os.path.exists(path / "DESCRIPTION.md"):
                    with open(path / "DESCRIPTION.md", "r") as description_handle:
                        readme_handle.write(description_handle.read())

                content = sorted(os.listdir(path))
                for element in content:
                    element_path = path / str(element)
                    if os.path.isdir(element_path):
                        generate_recursive(element_path)

        return generate_recursive(self.path)


def generate_readme(path, content_provider):
    readme_writer = RecursiveReadmeWriter(path, content_provider)
    readme_writer.generate()


def main():
    base_path = Path(__file__).parent.parent

    content_provider_mapping = {
        "solutions": KattisReadmeContentProvider()
    }

    for folder in content_provider_mapping:
        generate_readme(base_path / folder, content_provider_mapping[folder])

    with open(base_path / "README.md", "w") as readme_handle:
        for folder in content_provider_mapping:
            with open(base_path / folder / "README.md", "r") as sub_readme_handle:
                sub_readme_content = sub_readme_handle.read()
            readme_handle.writelines(sub_readme_content)


if __name__ == "__main__":
    main()
