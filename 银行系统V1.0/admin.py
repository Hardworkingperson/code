class Admin:
    def __init__(self, adminU=123, adpwd=321):
        self.adminU = adminU
        self.adpwd = adpwd

    def printAdminView(self):
        print("*" * 20)
        print("*" + " " * 18 + "*")
        print("*  欢迎登录银行系统  *")
        print("*" + " " * 18 + "*")
        print("*" * 20)

    def printsysFunctionView(self):
        print("*" * 20)
        print("1.开户     2.查询")
        print("3.取款     4.存款")
        print("5.转账     6.锁定")
        print("7.解锁")
        print("Q.退出")
        print("*" * 20)

    def isright(self, zhanghu, mima):
        return self.adminU == zhanghu and self.adpwd == mima
