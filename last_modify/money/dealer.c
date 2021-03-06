// /feature/dealer.c 商人

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
		return notify_fail("你要估什么的价？\n");
	
	if (ob->query("money_id"))
		return notify_fail("你没用过钱啊？\n");

	if (userp(ob))
		ob->set("value", ob->query("per") * 500);

	value = ob->query("value");
	if (value < 1)
		write(ob->query("name") + "一文不值！\n");
	else 
		write(ob->query("name") + "值" + 
		MONEY_D->price_str(value * 70 / 100) + "。\n");
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
		return notify_fail("你要卖什么？\n");

	if( this_player()->is_busy() )
		return notify_fail("哟，抱歉，我这儿正忙着呢……您请稍候。\n");

	if (ob->query("money_id"))
		return notify_fail("你想卖「钱」？？\n");

	if (stringp(ob->query("no_drop")))
		return notify_fail("这样东西不能卖。\n");

	if (is_vendor_good(arg) != "") 
		return notify_fail("卖给你好不好？\n");

	if (ob->query("food_supply"))
		return notify_fail("剩菜剩饭留给您自己用吧。\n");
	
	if (ob->query("shaolin"))
		return notify_fail("小的只有一个脑袋，可不敢买少林庙产。\n");

	if (userp(ob))
	{
		ob->set("value", ob->query("per") * 500);
		ob->set("value", 0);
		CHANNEL_D->do_channel(ob, "rumor",
			sprintf("%s被某人拐卖给唐楠了。", ob->name(1)));
	}

	value = ob->query("value");
	if (value < 30)
		write(ob->query("name") + "一文不值！\n");
	else {
		message_vision("$N卖掉了一" + ob->query("unit") + 
		ob->query("name") + "给$n。\n", this_player(), this_object());
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
		//return notify_fail("目前没有可以卖的东西。\n");
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
		return notify_fail("目前没有可以卖的东西。\n");

	str = "";
	str = sprintf("你可以向%s购买下列物品：\n", query("name"));

	// 利用函数makeup_space填充空格，对齐输出格式。
	// Added by Constant Jan 7 2001
	for (i = 0; i < sizeof(inv1); i++) 
		str = sprintf("%s%30-s%s数量：%3-i %s\n", 
				str, inv1[i]->short(),
				makeup_space(inv1[i]->short()), count[i],
				MONEY_D->price_str(inv1[i]->query("value") * 6 / 5));

	if (arrayp(goods = query("vendor_goods")))
		for (i = 0; i < sizeof(goods); i++)
			str = sprintf("%s%30-s%s：%s\n", str, 
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

	if ((fam = this_player()->query("family")) && fam["family_name"] == "丐帮")
		return notify_fail("你是个穷叫化，买什麽东西！\n");
	
	if( this_player()->is_busy() )
		return notify_fail("哟，抱歉，我这儿正忙着呢……您请稍候。\n");

	if (!arg) return notify_fail("你想买什么？ \n");
	else if (!(ob = present(arg, this_object())))
		if ((ob_file = is_vendor_good(arg)) == "")
			return notify_fail("你想买什么？ \n");

	if (!ob)
	{
		ob = new(ob_file);
		val_factor = 10;
	}
	else {
		if (ob->query("equipped"))
			return notify_fail("你想买什么？ \n");
		val_factor = 12;
	}

	if (query_temp("busy"))
		return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");
	
	switch(MONEY_D->player_pay(this_player(),ob->query("value")* val_factor/10))
	{
		case 0:
			return notify_fail("穷光蛋，一边呆着去！\n");
		case 2:
			return notify_fail("您的零钱不够了，银票又没人找得开。\n");
		default:
			set_temp("busy", 1);
			message_vision("$N从$n那里买下了一" + ob->query("unit") + 
			ob->query("name") + "。\n", this_player(), this_object());
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

// 增加函数makeup_space，用于填充空格，对齐输出格式。
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

