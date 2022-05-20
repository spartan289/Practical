class Update_viagithub:
    def __init__(self):
        self.__url = "https://api.github.com/repos/spartan289/Practical/commits"
        self.__version = "0.0.0"
        self.__release_url = ""
    def get_version(self):
        return self.__version
    def get_current_commit_sha_id(self):
        return self.__commit_sha_id
    def get_total_commits(self):
        return self.__total_commits
    def get_commit_sha_id(self):
        return self.__commit_sha_id