from abc import ABC, abstractmethod


class HeaderProvider(ABC):
    @abstractmethod
    def get(self):
        pass


class KattisHeaderProvider(HeaderProvider):
    def get(self):
        header = "| ID | Problem name | Link to solution |\n" + \
                 "|:---|:---|:---:|\n"

        return header