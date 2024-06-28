import pymysql
import random
import user
import card

class ATM:
    def __init__(self):
        self.conn = pymysql.connect(
            host="localhost",
            port=3306,
            user="root",
            password="SUsu@1223",
            database="system_bank",
            autocommit=True
        )
        self.cursor = self.conn.cursor()

    def is_right_card(self, card_id, pwd):
        self.cursor.execute(
            "SELECT * FROM cards WHERE card_id=%s AND card_pwd=%s", (card_id, pwd)
        )
        result = self.cursor.fetchone()
        return result is not None

    def checkpwg(self, pwd):  # 实现核对
        count = 1
        while True:
            pwd_test = input("请再次输入你的密码")
            if (count > 3):
                print("你玩个蛋密码都能输错")
                return False
            else:
                count += 1
                if pwd_test == pwd:
                    return True
                else:
                    print("你小子最好晓得密码")
                    continue

    def randomCardId(self):  # 随机卡号
        return str(random.randint(100000, 999999))

    def card_status(self,card_id):
        self.cursor.execute("select card_status from cards where card_id=(%s)", card_id)
        return self.cursor.fetchone()[0]

    def createUser(self):  # 创建
        name = input("请输入姓名：")
        id_num = input("请输入身份证号：")
        phone = input("请输入手机号：")
        pre_money = float(input("请输入预存金额："))
        if pre_money > 0:
            card_pwd = input("请输入密码：")
            if self.checkpwg(card_pwd):
                card_id = self.randomCardId()
                u=user.User(name, id_num, phone, card_id)
                c=card.Card(card_id,card_pwd,pre_money,1)
                self.cursor.execute(
                    "insert into cards (card_id, card_pwd, money, card_status) values (%s, %s, %s, %s)",
                    (c.card_id,c.card_pwd, c.pre_money, 1)
                )
                self.cursor.execute(
                    "insert into users (name, id_num, phone, card_id) values (%s, %s, %s, %s)",
                    (u.name ,  u.id_num, u.phone, u.card_id)
                )
                print(f"开户成功！卡号为：{card_id}")
        else:
            print("你小子是不是想白嫖")

    def lockCard(self):  # 锁定
        card_id = input("请输入卡号")
        pwd = input("请输入密码")
        if self.is_right_card(card_id, pwd):
            self.cursor.execute("select card_status from cards where card_id=(%s)", card_id)
            result = self.cursor.fetchone()
            if result is not None and result[0] == 0:
                print("该账号已锁定，无需再操作")
            else:
                self.cursor.execute("update cards set card_status=0 where card_id=(%s)", card_id)
        else:
            print("账号密码错误")

    def unlockCard(self):
        card_id = input("请输入卡号")
        pwd = input("请输入密码")
        if self.is_right_card(card_id, pwd):
            self.cursor.execute("select card_status from cards where card_id=(%s)", card_id)
            result = self.cursor.fetchone()
            if result is not None and result[0] == 1:
                print("该账号没锁定，无需再操作")
            else:
                self.cursor.execute("update cards set card_status=1 where card_id=(%s)", card_id)
        else:
            print("账号密码错误")

    def getMoney(self):
        card_id = input("请输入卡号")
        pwd = input("请输入密码")
        mount = float(input("请输入您要取走的金额"))
        if self.card_status(card_id):
            if self.is_right_card(card_id, pwd):
                self.cursor.execute("select money from cards where card_id=%s", card_id)
                count = self.cursor.fetchone()
                if count is None or count[0] < mount:
                    print("余额不足")
                else:
                    self.cursor.execute("update cards set money=money-%s where card_id=%s", (mount, card_id))
                    self.cursor.execute("select money from cards where  card_id=%s", card_id)
                    new_count = self.cursor.fetchone()[0]
                    print(f"你还有{new_count}")
            else:
                print("你小子密码账号错误")
        else:
            print("你的卡锁定了请解锁")

    def saveMoney(self):
        card_id = input("请输入卡号")
        pwd = input("请输入密码")
        mount = float(input("请输入您要存入的金额"))
        if self.card_status(card_id):
            if self.is_right_card(card_id, pwd):
                self.cursor.execute("update cards set money=money+%s where card_id=%s", (mount, card_id))
                self.cursor.execute("select money from cards where card_id=%s", (card_id))
                new_count = self.cursor.fetchone()[0]
                print(new_count)
            else:
                print("你小子滚呐")
        else:
            print("状态错误")

    def transferMoney(self):
        card_id = input("请输入转出卡号")
        pwd = input("请输入转出密码")
        if self.card_status(card_id):
            if self.is_right_card(card_id, pwd):
                card_id1 = input("请输入转入卡号")
                mount = float(input("转多少钱"))
                self.cursor.execute("update cards set money=money-%s where card_id=%s", (mount, card_id))
                self.cursor.execute("update cards set money=money+%s where card_id=%s", (mount, card_id1))
                print("转账成功")
            else:
                print("账号密码错误滚啊")
        else:
            print("滚呐")

    def searchUser(self):
        card_id = input("请输入卡号")
        pwd = input("请输入密码")
        if self.card_status(card_id):
            if self.is_right_card(card_id, pwd):
                self.cursor.execute("select money from cards where card_id=%s", card_id)
                new_count = self.cursor.fetchone()[0]
                print(new_count)
            else:
                print("账号密码错误")
        else:
            print("你的卡锁定了请解锁")
