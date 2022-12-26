import json
import os

from pathlib import Path
from abc import ABC, abstractmethod

from problem_scrapers import KattisProblemScraper


class WorkspaceCreator(ABC):
    def __init__(self, url):
        self.problem_scraper = None
        self.base_path = Path(__file__).absolute().parent.parent
        self.url = url

    def create_workspace(self):
        self.create_directory()
        self.write_testcases()
        self.write_info_json()

    @abstractmethod
    def create_directory(self):
        pass

    @abstractmethod
    def write_testcases(self):
        pass

    @abstractmethod
    def write_info_json(self):
        pass


class NoWorkspaceCreator(WorkspaceCreator):
    def create_directory(self):
        pass

    def write_testcases(self):
        pass

    def write_info_json(self):
        pass


class KattisWorkspaceCreator(WorkspaceCreator):
    def __init__(self, url):
        super().__init__(url)
        self.problem_scraper = KattisProblemScraper(url)
        self.solutions_dir = self.base_path / "solutions"
        self.problem_dir = None

    def create_directory(self):
        self.problem_dir = self.solutions_dir / self.problem_scraper.get_problem_name()
        if not os.path.exists(self.problem_dir):
            os.mkdir(self.problem_dir)

    def write_testcases(self):
        testcases = self.problem_scraper.get_testcases()

        for idx, testcase in enumerate(testcases):
            file_path = self.problem_dir / f"in{idx}"
            with open(file_path, "w") as file_handle:
                file_handle.write(testcase)

    def write_info_json(self):
        name = self.problem_scraper.get_problem_name()
        id = self.url.split('/')[-1]

        info = {
            "Name": name,
            "URL": self.url,
            "ID": id
        }

        with open(self.problem_dir / "info.json", "w") as json_handle:
            json.dump(info, json_handle, indent=4)