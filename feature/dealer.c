// /feature/dealer.c ����

// This is a inheritable object.
// Each dealer should support buy, sell, list, value 4 commands

// Modified by Constant Jan 7 2001
#include <command.h> 
#include <dbase.h>
#include <ansi.h>

string makeup_space(string s);
string filter_color(string arg);//ȥ����ɫ

int is_dealer() {return 1;}
string is_vendor_good(string arg)
{
	string *goods;
	object ob;
	int i;
  seteuid(getuid());
	if (arrayp(goods = query("vendor_goods"))) 
		for (i = 0; i < sizeof(goods); i++) 
			{
			  	if (goods[i]->id(arg))
   			  	return goods[i];
          call_other(goods[i], "???");
          if (! objectp(find_object(goods[i])))
          {
             log_file("_vendor", sprintf("No found vendor good:%s\n", goods[i]));
             continue;
          }
          ob=find_object(goods[i]);
          if (!ob) return "";
          if (filter_color(ob->name(1)) == arg)
            return goods[i];
      }
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
	int i,j;
	int count,count1;
	int value;
  int amount=1;
	object *inv;
	object *obs;
	
	if (!arg )
		return notify_fail("��Ҫ��ʲô��\n");

	if( this_player()->is_busy() )
		return notify_fail("Ӵ����Ǹ���������æ���ء��������Ժ�\n");

  sscanf(arg,"%d %s",amount,arg);
  ob = present(arg,this_player());
  if (!ob)
   {
	  inv = all_inventory(this_player());
  	for (i = 0; i < sizeof(inv); i++)
	  {
		  if (filter_color(inv[i]->name(1)) == arg)
		  {
		  	ob=inv[i];
		  	break;
		  }
	  }
  }

  if ( !objectp(ob) || amount < 1 )
    return notify_fail("��Ҫ��ʲô��\n");

	if (ob->query("money_id"))
		return notify_fail("��������Ǯ������\n");

  if (intp(ob->query("no_sell")) && ob->query("no_sell") >0 )
    return notify_fail("����������������\n");

  if (stringp(ob->query("no_sell")))
    return notify_fail(ob->query("no_sell"));

	if (stringp(ob->query("no_drop")))
		return notify_fail("����������������\n");

	if (is_vendor_good(arg) != "") 
		return notify_fail("������ò��ã�\n");

	if (ob->query("food_supply") || ob->query("water_supply"))
		return notify_fail("ʣ��ʣ���������Լ��ðɡ�\n");
	
	if (ob->query("shaolin"))
		return notify_fail("С��ֻ��һ���Դ����ɲ��������������\n");

	inv = all_inventory(this_player());
	count1=0;
	for (i = 0; i < sizeof(inv); i++)
	{
		if (base_name(inv[i])==base_name(ob))
			count1++;
	}
	if (count1 < amount)	
    return notify_fail("��û����ô���"+ob->name(1)+"��\n");

	inv = all_inventory(this_object());
	count=0;
	for (i = 0; i < sizeof(inv); i++)
	{
		if (base_name(inv[i])==base_name(ob) && inv[i]->name()==ob->name())
			count++;
	}
	if (count+amount > 100 && !wizardp(this_player()))
		return notify_fail("���ﱾ����̫�࣬��ȥ��ĵ꿴����\n");

	if (userp(ob))
	{
	//	ob->set("value", ob->query("per") * 500);
      ob->set("value", ob->query("per") * 3);
	//	ob->set("value", 0);
		CHANNEL_D->do_channel(ob, "rumor",
			sprintf("%s��ĳ�˹���������ˡ�", ob->name(1)));
	}

	value = ob->query("value");
	if (value < 30 || ob->query_amount())//����������Ʒsell����Ǳ��bug��Ŀǰ������sell
		write(ob->query("name") + "һ�Ĳ�ֵ��\n");
	else
	{
		if ( userp(ob) )
		{
      if( !wizardp(ob) ) {
                obs = all_inventory(ob);
                for(i=0; i<sizeof(obs); i++)
                        if( !obs[i]->query_autoload() )
                                DROP_CMD->do_drop(ob, obs[i]);
			 }
			ob->move("/d/city/cangku");
			ob->set("startroom","/d/city/cangku");
			ob->set_temp("selled",1);
			ob->save();
			i=1;
		}
    else 
    {
	  	for(i=0;i<amount;i++)
	  	{
        inv=all_inventory(this_player());
        for (j=0;j<sizeof(inv);j++)
         {
         	if (base_name(inv[j])==base_name(ob) && inv[j]->name()==ob->name())
		        {
		        	inv[j]->move(this_object());
		        	if (inv[j]->query("last_value"))
		        	{
		        		inv[j]->set("value",inv[j]->query("last_value"));
		        		inv[j]->delete("last_value");
		        	}
      		    MONEY_D->pay_player(this_player(), value * 70 / 100);
	            MONEY_D->player_pay(this_player(), 0);//������Ǯ
		          break;
		        }
		    }
      }
    }
		message_vision("$N������" +chinese_number(i)+ ob->query("unit") + 
		ob->query("name") + "��$n��\n", this_player(), this_object());
   
	}
	this_player()->start_busy(1);
	return 1;
}

int do_list(string arg)
{
	string *goods, str;
	object *inv=({}), *inv1=({});
	int *count=({}), i, j;
	string *invname=({});

	inv = all_inventory(this_object());

	if( arg && arg!="weapon" && arg!="armor" &&
		arg!="book" && arg!="medicine" &&
		arg!="food" && arg!="fruit" && arg!="liquid" &&
		arg!="other")
		return notify_fail("û�����ַ���Ķ�����\n");

	for (i = 0; i < sizeof(inv); i++) 
	{
		if (!inv[i]->query("equipped") && !inv[i]->query("money_id"))
		{
         j=member_array(inv[i]->short()+"/"+inv[i]->query("id"),invname); 
         if ( j == -1 )
				 {
				  	inv1+=({inv[i]});
            invname+=({ inv[i]->short()+"/"+inv[i]->query("id") });
			  		count+=({1});
		 		 }
				 else count[j]++;
		}
	}

	if (!sizeof(inv1) && !arrayp(goods = query("vendor_goods")))
		return notify_fail("Ŀǰû�п������Ķ�����\n");

	str = "";
	if( !arg || arg == "other" )
		str = sprintf("�������%s����������Ʒ��\n", query("name"));
	else
		switch (arg)
		{
			case "armor":
				str = sprintf("�������%s�������з��ߣ�\n", query("name"));
				break;
			case "weapon":
				str = sprintf("�������%s�������б�����\n", query("name"));
				break;
			case "food":
				str = sprintf("�������%s��������ʳƷ��\n", query("name"));
				break;
			case "fruit":
				str = sprintf("�������%s�������й�Ʒ��\n", query("name"));
				break;
			case "liquid":
				str = sprintf("�������%s����������Ʒ��\n", query("name"));
				break;
			case "medicine":
				str = sprintf("�������%s��������ҩƷ��\n", query("name"));
				break;
			case "book":
				str = sprintf("�������%s���������鼮��\n", query("name"));
				break;
		}

	for (i = 0; i < sizeof(inv1); i++) 
	{
		if( !arg ||
			(arg=="other" &&
				(!inv1[i]->query("weapon_prop") &&
				!inv1[i]->query("armor_prop") &&
				!inv1[i]->query("skill") &&
				!inv1[i]->query("pour_type") &&
				!inv1[i]->query("food_remaining") &&
				!inv1[i]->query("fruit_remaining") &&
				!inv1[i]->query("liquid") ) ) ||
			(arg=="weapon" && inv1[i]->query("weapon_prop")) ||
			(arg=="armor" && inv1[i]->query("armor_type")) ||
			(arg=="book" && inv1[i]->query("skill")) ||
			(arg=="medicine" && inv1[i]->query("pour_type")) ||
			(arg=="food" && inv1[i]->query("food_remaining")) ||
			(arg=="fruit" && inv1[i]->query("fruit_remaining")) ||
			(arg=="liquid" && inv1[i]->query("liquid")) )
			str += sprintf("%30-s%s������%3-i %s\n", 
				inv1[i]->short(),
				makeup_space(inv1[i]->short()), count[i],
				MONEY_D->price_str(inv1[i]->query("value") * 6 / 5));
	}
	if (arrayp(goods = query("vendor_goods")))
	{
		for (i = 0; i < sizeof(goods); i++)
		{
			if( !arg ||
			(arg=="other" &&
				(!goods[i]->query("weapon_prop") &&
				!goods[i]->query("armor_prop") &&
				!goods[i]->query("skill") &&
				!goods[i]->query("pour_type") &&
				!goods[i]->query("food_remaining") &&
				!goods[i]->query("fruit_remaining") &&
				!goods[i]->query("liquid") ) ) ||
			(arg=="weapon" && goods[i]->query("weapon_prop")) ||
			(arg=="armor" && goods[i]->query("armor_type")) ||
			(arg=="book" && goods[i]->query("skill")) ||
			(arg=="medicine" && goods[i]->query("pour_type")) ||
			(arg=="food" && goods[i]->query("food_remaining")) ||
			(arg=="fruit" && goods[i]->query("fruit_remaining")) ||
			(arg=="liquid" && goods[i]->query("liquid")) )
			str = sprintf("%s%30-s%s��%s\n", str, 
				goods[i]->short(),
				makeup_space(goods[i]->short()),
				MONEY_D->price_str(goods[i]->query("value")));
		}
	}
	if( !arg )
		str += sprintf(HIY
"������������������������"HIC"�������"HIY"��������������������������"HIG"
armor ������  weapon ������  book  �鼮��  medicine ҩƷ��
food  ʳƷ��  liquid ��Ʒ��  fruit ��Ʒ��  other    ������"NOR);
  if (SHOP_D->is_owner(this_player()->query("id")))
    str += HIW"\n������ҵЭ��ĳ�Ա���ڴ˹������ܰ����Żݡ�"NOR;

	this_player()->start_more(str);

	return 1;
}	

int do_buy(string arg)
{
	int value, val_factor;
	string ob_file;
	object *inv;
	int i,j,count,amount=1;
	string from;
	object ob;
	mapping fam;
	int discount;
	int zscount;
	string unit;

	if ((fam = this_player()->query("family")) && fam["family_name"] == "ؤ��")
		return notify_fail("���Ǹ���л�����ʲ�ᶫ����\n");
	
	if( this_player()->is_busy() )
		return notify_fail("Ӵ����Ǹ���������æ���ء��������Ժ�\n");

	if (!arg) 
	  return notify_fail("������ʲô�� \n");
 
  sscanf(arg,"%d %s",amount,arg);
 
  if (amount<1) 
    return notify_fail("������ʲô�� \n");
  if (amount>100)
    return notify_fail("�𼱣���������\n");
  if (!(ob = present(arg, this_object())))
	 {
	  inv = all_inventory(this_object());
  	for (i = 0; i < sizeof(inv); i++)
	  {
		  if (filter_color(inv[i]->name(1)) == arg)
		  {
		  	ob=inv[i];
		  	break;
		  }
	  }
	 }
	if (!ob && (ob_file = is_vendor_good(arg)) == "")
			return notify_fail("������ʲô�� \n");

	if (!ob)
	{
		ob = new(ob_file);
		val_factor = 10;
		from="vendor";
	}
	else {
		if (ob->query("equipped"))
			return notify_fail("������ʲô�� \n");
		if (ob->query("money_id"))
		  return notify_fail("��Ҫ��Ǯ��\n");
		from="pawn";
		val_factor = 12;
		inv=all_inventory(this_object());
		count=0;
		for (i=0;i<sizeof(inv);i++)
		{
			if (base_name(inv[i])==base_name(ob) && inv[i]->name()==ob->name())
      count++;
		}
		if (count < amount)
		 return notify_fail("����û����ô���"+ob->name()+"��\n");
	}
	if (query_temp("busy"))
		return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");
  if (SHOP_D->is_owner(this_player()->query("id")))
   discount = 8;
  else
   discount = 10;
  zscount = 10 - SCBORN_D->query_scborn_times(this_player())*2;
  if (zscount < 0) zscount = 0;

	switch(MONEY_D->player_pay(this_player(),ob->query("value") * discount/10 * amount * val_factor/10 * zscount/10))
	{
		case 0:
			return notify_fail("��⵰��һ�ߴ���ȥ��\n");
		case 2:
			return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
		default:
			set_temp("busy", 1);
			if (ob->query("base_unit")) unit = ob->query("base_unit");
			else unit = ob->query("unit");
			message_vision("$N��$n����������"+chinese_number(amount) + unit + 
			ob->query("name") + "��\n", this_player(), this_object());
	}
	  for(i=0;i<amount;i++)
	  {
	  	if (from=="pawn")
	  	{
	  		inv=all_inventory(this_object());
	  		for (j=0;j<sizeof(inv);j++)
	  		if (base_name(inv[j])==base_name(ob) && inv[j]->name()==ob->name())
          {
          	inv[j]->move(this_player());
          	inv[j]->set("last_value",inv[j]->query("value"));
          	inv[j]->set("value",inv[j]->query("value")*zscount/10);
          	break;
          }
	 		}
	 		else if (from=="vendor")
      {
      	if (objectp(environment(ob)))
         	ob=new(ob_file);
          ob->move(this_player());
          ob->set("last_value",ob->query("value"));
          ob->set("value",ob->query("value")*zscount/10);
      }
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

	for (i = 0; i < space_count; i ++) space += " ";
	return space;
}

string filter_color(string arg)
{
  if(!arg) return "";
  arg = replace_string(arg, BLK, "");
  arg = replace_string(arg, RED, "");
  arg = replace_string(arg, GRN, "");
  arg = replace_string(arg, YEL, "");
  arg = replace_string(arg, BLU, "");
  arg = replace_string(arg, MAG, "");
  arg = replace_string(arg, CYN, "");
  arg = replace_string(arg, WHT, "");
  arg = replace_string(arg, HIR, "");
  arg = replace_string(arg, HIG, "");
  arg = replace_string(arg, HIY, "");
  arg = replace_string(arg, HIB, "");
  arg = replace_string(arg, HIM, "");
  arg = replace_string(arg, HIC, "");
  arg = replace_string(arg, HIW, "");
  arg = replace_string(arg, NOR, "");
/*  arg = replace_string(arg, BBLK, "");
  arg = replace_string(arg, BRED, "");
  arg = replace_string(arg, BGRN, "");
  arg = replace_string(arg, BYEL, "");
  arg = replace_string(arg, BBLU, "");
  arg = replace_string(arg, BMAG, "");
  arg = replace_string(arg, BCYN, "");
  arg = replace_string(arg, HBRED, "");
  arg = replace_string(arg, HBGRN, "");
  arg = replace_string(arg, HBYEL, "");
  arg = replace_string(arg, HBBLU, "");
  arg = replace_string(arg, HBMAG, "");
  arg = replace_string(arg, HBCYN, "");
  arg = replace_string(arg, HBWHT, "");
  arg = replace_string(arg, NOR, "");
*/
  return arg;
}