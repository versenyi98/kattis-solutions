from abc import ABC, abstractmethod

from readme_entry_builders import KattisEntryBuilder
from readme_header_providers import KattisHeaderProvider


class ReadmeContentProvider(ABC):
    @abstractmethod
    def __init__(self):
        self.entry_builder = None
        self.header_provider = None

    def get_header(self):
        return self.header_provider.get()

    def get_entry(self, data):
        return self.entry_builder.build(data).get()


class KattisReadmeContentProvider(ReadmeContentProvider):
    def __init__(self):
        self.entry_builder = KattisEntryBuilder()
        self.header_provider = KattisHeaderProvider()