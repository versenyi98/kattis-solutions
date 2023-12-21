import constants

from urllib.parse import quote
from abc import ABC, abstractmethod


class EntryBuilder(ABC):
    def __init__(self):
        self.entry = ""

    def get(self):
        return self.entry

    @abstractmethod
    def build(self, data):
        pass


class KattisEntryBuilder(EntryBuilder):
    def build(self, data):
        name = data["Name"]
        problem_id = data["ID"]
        url = data["URL"]

        path_to_solution = f"{constants.GITHUB_MAIN_BRANCH}/solutions/{quote(name)}"

        self.entry = f"| [{problem_id}]({url}) | {name} | [Solution]({path_to_solution})|\n"
        return self