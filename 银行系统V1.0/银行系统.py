# import pymysql
#
#
# conn = pymysql.Connect (
#     host="localhost",
#     port=3306,
#     user="root",
#     password="SUsu@1223",
#     autocommit=True
# )
# cursor=conn.cursor()#获取游标
# #使用数据库
# conn.select_db("system_bank")#类似于MySQL的use 数据库;命令
# #cursor.execute("insert into student values(2007,'小毛','男',19) ")#插入数据
# #必须通过commit确认
# # conn.commit()
# num=100
# carde_id=88888888
#
# # cursor.execute("update cards set money=money-%s where card_id=%s",(num,carde_id))
# # conn.commit()
# # cursor.execute("select * from cards")#查询表的所有数据
# cursor.execute("select money from cards where card_id=411976")#查询表的所有数据
# relust=cursor.fetchone()#结果存取
# # print(relust)
# balance = relust[0]
# print(f"钱为：{balance}")
# # amounts = [result[0] for result in relust] # 将结果转换为列表
# #
# # print("您的金额是: " + str(amounts))


from admin import Admin
from atm import ATM

class HomePage:
    def main(admin, atm):
            admin.printAdminView()
            while True:
                adminU = int(input("请输入管理员账户："))
                adpwd = int(input("请输入密码："))
                if admin.isright(adminU, adpwd):
                    while True:
                        admin.printsysFunctionView()
                        option = input("请输入操作编号：")
                        if option == '1':
                            atm.createUser()
                        elif option == '2':
                            atm.searchUser()
                        elif option == '3':
                            atm.getMoney()
                        elif option == '4':
                            atm.saveMoney()
                        elif option == '5':
                            atm.transferMoney()
                        elif option == '6':
                            atm.lockCard()
                        elif option == '7':
                            atm.unlockCard()
                        elif option.upper() == 'Q':
                            print("退出系统")
                            break
                        else:
                            print("无效的操作编号")
                else:
                    print("管理员账号或密码错误")


if __name__ == '__main__':
    admin = Admin()
    atm = ATM()
    HomePage.main(admin, atm)
