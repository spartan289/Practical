class Update_viagithub:
    def __init__(self):
        self.__url = "https://api.github.com/repos/viagogo/viagogo-api/releases/latest"
        self.__version = "0.0.0"
        self.__release_url = ""
    def get_version(self):
        return self.__version
