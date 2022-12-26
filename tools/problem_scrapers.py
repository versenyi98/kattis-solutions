from abc import ABC, abstractmethod
from lxml import etree

import requests


class ProblemScraper(ABC):

    def __init__(self, url):
        self.url = url
        result = requests.get(url)
        self.tree = etree.HTML(result.text)

    @abstractmethod
    def get_testcases(self):
        pass

    @abstractmethod
    def get_problem_name(self):
        pass


class KattisProblemScraper(ProblemScraper):

    def get_testcases(self):
        xpath_expression = "//table/tr[2]/td[1]/pre"
        elements = self.tree.xpath(xpath_expression)

        return [element.text for element in elements]

    def get_problem_name(self):
        xpath_expression = "//h1"
        return self.tree.xpath(xpath_expression)[0].text