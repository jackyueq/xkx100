// /adm/daemons/moneyd.c  Ǯ�Ĺ���
// Modified by Zeratul Jan 5 2001

// by Xiang@XKX (95/12/22)

string money_str(int amount)
{
        // returns a chinese string of `amount` of money
        string output;

        if (amount / 10000) {
                output = chinese_number(amount / 10000) + "���ƽ�";
                amount %= 10000;
        }
        else
                output = "";
        if (amount / 100) {
                output = output + chinese_number(amount / 100) + "������";
                amount %= 100;
        }
        if (amount)
                return output + chinese_number(amount) + "��ͭǮ";
        return output;
}

string price_str(int amount)
{
        // returns a chinese string of `amount` of money
	string output;

        if (amount < 1)
                amount = 1;

        if (amount / 10000) {
                output = chinese_number(amount / 10000) + "���ƽ�";
                amount %= 10000;
        }
        else
                output = "";
        if (amount / 100) {
		if (output != "")
                	output += "��" + chinese_number(amount / 100) + "������";
		else
			output = chinese_number(amount / 100) + "������";
                amount %= 100;
        }
        if (amount)
		if (output != "")
                	return output + "��" + chinese_number(amount) + "��ͭ��";
		else
			return chinese_number(amount) + "��ͭ��";
        return output;
}

void pay_player(object who, int amount)
{
        int v;
        object ob;
		string err;
	seteuid(getuid());
        if (amount < 1)
                amount = 1;
       if (v = amount / 10000) {
                ob = new(GOLD_OB);
                ob->set_amount(amount / 10000);
                if (!ob->move(who) && objectp(environment(who)))
						     {
                   	message_vision("����$n��$N����̫���ˣ�ֻ���ȷ��ڵ����ˡ�\n",who,ob);
                    ob->move(environment(who));
                 }
                amount %= 10000;
        }
       if (amount / 100) {
                ob = new(SILVER_OB);
                ob->set_amount(amount / 100);
//                ob->move(who);
                if (!ob->move(who) && objectp(environment(who)))
						     {
                   	message_vision("����$n��$N����̫���ˣ�ֻ���ȷ��ڵ����ˡ�\n",who,ob);
                    ob->move(environment(who));
                 }
                amount %= 100;
        }
        if (amount) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
//                ob->move(who);
                if (!ob->move(who) && objectp(environment(who)))
						     {
                   	message_vision("����$n��$N����̫���ˣ�ֻ���ȷ��ڵ����ˡ�\n",who,ob);
                    ob->move(environment(who));
                 }
        }
}

int player_pay(object who, int amount)
{
	object g_ob, s_ob, c_ob;
	int gc, sc, cc, left;

	seteuid(getuid());

	if (g_ob = present("gold_money", who))
		gc = g_ob->query_amount();
	else
		gc = 0;
	if (s_ob = present("silver_money", who))
		sc = s_ob->query_amount();
	else
		sc = 0;
	if (c_ob = present("coin_money", who))
		cc = c_ob->query_amount();
	else
		cc = 0;
	
	// Modified by zeratul 2001-1-1
	if (cc + sc * 100 + gc * 10000 < amount) 
/*		if (present("thousand-cash", who))
			return 2;
		else 
			return 0;*/
		return 0;
	else {
		left = cc + sc * 100 + gc * 10000 - amount;
		gc = left / 10000;
		left = left % 10000;
		sc = left / 100;
		cc = left % 100;

		if (g_ob)
			g_ob->set_amount(gc);
//		else sc += (gc * 100);
		else if (gc) {
			g_ob = new(GOLD_OB);
			g_ob->set_amount(gc);
			g_ob->move(who);
		}
		if (s_ob)
		 	s_ob->set_amount(sc);
		else if (sc) {
			s_ob = new(SILVER_OB);
			s_ob->set_amount(sc);
			s_ob->move(who);
		}
		if (c_ob)
			c_ob->set_amount(cc);
		else if (cc) {
			c_ob = new(COIN_OB);
			c_ob->set_amount(cc);
			c_ob->move(who);
		}

		return 1;
	}
}
