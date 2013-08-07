// /feature/dealer.c ����

// This is a inheritable object.
// Each dealer should support buy, sell, list, value 4 commands

// Modified by Constant Jan 7 2001

#include <dbase.h>
#include <ansi.h>

string makeup_space(string s);

string is_vendor_good(string arg)
{
	string *goods;
	object ob;
	int i;

	if (arrayp(goods = query("vendor_goods"))) 
		for (i = 0; i < sizeof(goods); i++) 
			if (goods[i]->id(arg))
				return goods[i];
	return "";
}

int do_value(string arg)
{
	object ob;
	int value;

	if (!arg || !(ob = present(arg, this_player())))
		return notify_fail("��Ҫ��ʲô�ļۣ�\n");
	
	if (ob->query("money_id"))
		return notify_fail("��û�ù�Ǯ����\n");

	if (userp(ob))
		ob->set("value", ob->query("per") * 500);

	value = ob->query("value");
	if (value < 1)
		write(ob->query("name") + "һ�Ĳ�ֵ��\n");
	else 
		write(ob->query("name") + "ֵ" + 
		MONEY_D->price_str(value * 70 / 100) + "��\n");
	return 1;
}

int do_sell(string arg)
{
	object ob;
	int i;
	int count;
	int value;
	object *inv;
	
	if (!arg || !(ob = present(arg, this_player())))
		return notify_fail("��Ҫ��ʲô��\n");

	if( this_player()->is_busy() )
		return notify_fail("Ӵ����Ǹ���������æ���ء��������Ժ�\n");

	if (ob->query("money_id"))
		return notify_fail("��������Ǯ������\n");

	if (stringp(ob->query("no_drop")))
		return notify_fail("����������������\n");

	if (is_vendor_good(arg) != "") 
		return notify_fail("������ò��ã�\n");

	if (ob->query("food_supply"))
		return notify_fail("ʣ��ʣ���������Լ��ðɡ�\n");
	
	if (ob->query("shaolin"))
		return notify_fail("С��ֻ��һ���Դ����ɲ��������������\n");

	if (userp(ob))
	{
		ob->set("value", ob->query("per") * 500);
		ob->set("value", 0);
		CHANNEL_D->do_channel(ob, "rumor",
			sprintf("%s��ĳ�˹���������ˡ�", ob->name(1)));
	}

	value = ob->query("value");
	if (value < 30)
		write(ob->query("name") + "һ�Ĳ�ֵ��\n");
	else {
		message_vision("$N������һ" + ob->query("unit") + 
		ob->query("name") + "��$n��\n", this_player(), this_object());
		MONEY_D->pay_player(this_player(), value * 70 / 100);
		if ( userp(ob))
		{
			ob->move("/d/city/cangku");
			ob->set("startroom","/d/city/cangku");
			ob->set_temp("selled");
			ob->save();
		}
		else if (value < 50)
			destruct(ob);
		else
		{
			inv = all_inventory(this_object());
			count=0;
			for (i = 0; i < sizeof(inv); i++)
			{
				if (inv[i]->short()==ob->short())
					count++;
			}
			if (count<3)
				ob->move(this_object());
			else
				destruct(ob);
		}
	}
	this_player()->start_busy(1);
	return 1;
}

int do_list()
{
	string *goods, str;
	object *inv;
	object *inv1;
	int *count;
	int i;
	int j;

	inv = all_inventory(this_object());

	//if (!sizeof(inv) && !arrayp(goods = query("vendor_goods")))
		//return notify_fail("Ŀǰû�п������Ķ�����\n");
	for (i = 0; i < sizeof(inv); i++) 
	{
		if (!inv[i]->query("equipped") && !inv[i]->query("money_id"))
		{
			if (!arrayp(inv1))
			{
				inv1=({inv[i]});
				count=({1});
			}
			else
			{
				for (j = 0; j < sizeof(inv1); j++)
					if (inv[i]->short()==inv1[j]->short())
						break;
				if (j == sizeof(inv1))
				{
					inv1+=({inv[i]});
					count+=({1});
				}
				else
					count[j]+=1;
			}
		}
	}

	if (!sizeof(inv1) && !arrayp(goods = query("vendor_goods")))
		return notify_fail("Ŀǰû�п������Ķ�����\n");

	str = "";
	str = sprintf("�������%s����������Ʒ��\n", query("name"));

	// ���ú���makeup_space���ո񣬶��������ʽ��
	// Added by Constant Jan 7 2001
	for (i = 0; i < sizeof(inv1); i++) 
		str = sprintf("%s%30-s%s������%3-i %s\n", 
				str, inv1[i]->short(),
				makeup_space(inv1[i]->short()), count[i],
				MONEY_D->price_str(inv1[i]->query("value") * 6 / 5));

	if (arrayp(goods = query("vendor_goods")))
		for (i = 0; i < sizeof(goods); i++)
			str = sprintf("%s%30-s%s��%s\n", str, 
					goods[i]->short(),
					makeup_space(goods[i]->short()),
					MONEY_D->price_str(goods[i]->query("value")));

	this_player()->start_more(str);

	return 1;
}	

int do_buy(string arg)
{
	int value, val_factor;
	string ob_file;
	object ob;
	mapping fam;

	if ((fam = this_player()->query("family")) && fam["family_name"] == "ؤ��")
		return notify_fail("���Ǹ���л�����ʲ�ᶫ����\n");
	
	if( this_player()->is_busy() )
		return notify_fail("Ӵ����Ǹ���������æ���ء��������Ժ�\n");

	if (!arg) return notify_fail("������ʲô�� \n");
	else if (!(ob = present(arg, this_object())))
		if ((ob_file = is_vendor_good(arg)) == "")
			return notify_fail("������ʲô�� \n");

	if (!ob)
	{
		ob = new(ob_file);
		val_factor = 10;
	}
	else {
		if (ob->query("equipped"))
			return notify_fail("������ʲô�� \n");
		val_factor = 12;
	}

	if (query_temp("busy"))
		return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");
	
	switch(MONEY_D->player_pay(this_player(),ob->query("value")* val_factor/10))
	{
		case 0:
			return notify_fail("��⵰��һ�ߴ���ȥ��\n");
		case 2:
			return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
		default:
			set_temp("busy", 1);
			message_vision("$N��$n����������һ" + ob->query("unit") + 
			ob->query("name") + "��\n", this_player(), this_object());
			ob->move(this_player());
	}
	remove_call_out("enough_rest");
	call_out("enough_rest", 1);
	this_player()->start_busy(1);

	return 1;
}

void enough_rest()
{
	delete_temp("busy");
}

// ���Ӻ���makeup_space���������ո񣬶��������ʽ��
// Added by Constant Jan 1 2001
string makeup_space(string s)
{
	string *ansi_char = ({
		BLK,   RED,   GRN,   YEL,   BLU,   MAG,   CYN,   WHT,
		BBLK,  BRED,  BGRN,  BYEL,  BBLU,  BMAG,  BCYN,
		       HIR,   HIG,   HIY,   HIB,   HIM,   HIC,   HIW,
		       HBRED, HBGRN, HBYEL, HBBLU, HBMAG, HBCYN, HBWHT,
		NOR
	});

    	string space = s;
    	int i, space_count;

    	for (i = 0; i < sizeof(ansi_char); i ++)
    		space = replace_string(space, ansi_char[i], "", 0);
    	
    	space_count = sizeof(s) - sizeof(space);
	if (sizeof(s) >= 30)
		space_count = 30 - sizeof(space);

    	space = "";

    	for (i = 0; i < space_count; i ++)
    		space += " ";
    	return space;
}

