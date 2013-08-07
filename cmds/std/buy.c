#include <ansi.h>
inherit F_CLEAN_UP;

object i_have(object env,string name); // env��ȡ���� name����Ʒ
string filter_color(string arg);

int main(object me, string arg)
{
        mapping goods;
        int amount;
        int value, val_factor;
        string ob_file;
	object *obs;
        object ob, env, obj;
	string my_id;
	int i;
	
        
        if(me->is_busy())
                return notify_fail("ʲô�¶��õ���æ����˵�ɣ�\n");
        if (! arg)
                return notify_fail("ָ���ʽ��buy <��Ʒ> [from <���>]\n");
				env = environment(me);
				if (! (sscanf(arg, "%s from %s", arg, my_id) == 2) )
				{	        
  	      obs = all_inventory(env);
    	    for (i=0;i<sizeof(obs);i++)
     	   	{
     	   		if (!userp(obs[i]) && obs[i]->is_dealer())
     	   			return 0;
      	 	}
            return notify_fail("ָ���ʽ��buy <��Ʒ> [from <���>]\n");
         }

        if (! (obj = find_player(my_id)) || ! (present(obj->query("id"), env)))
                return notify_fail("����û��������ˡ�\n");

        if (obj == me)
                return notify_fail("���Լ��������Ա��˳ŵģ�\n");

        if (! obj->query("is_vendor"))
                return notify_fail(obj->name(1) + "���������ˡ�\n");

        if (! obj->query_temp("on_baitan"))
                return notify_fail(obj->name(1) + "��û�а�̯��\n");

				SHOP_D->reset_goods(obj);
				
        if (! (goods = obj->query("vendor_goods")))
                return notify_fail(obj->name(1) + "��û�ж����κλ��\n");

        ob = i_have(obj, arg);

				if (! ob || ! objectp(ob))
                return notify_fail(obj->name(1) + "��û�ж����������\n");

        if (! goods[file_name(ob)])
                return notify_fail(obj->name(1) + "��û�ж����������\n");

        value = goods[file_name(ob)];

        if (ob->query_amount()) 
        	return notify_fail("����������ֵǮ������Ҳû�á�\n");

        switch (MONEY_D->player_pay(me,value))
        {
        case 0:
                write(CYN + obj->name(1) + CYN "��Цһ�����������"
                      "�⵰��һ�ߴ���ȥ��\n" NOR);
                return 1;
        case 2:
                write(CYN + obj->name(1) + CYN "��ü����������û��"
                      "��Ǯ������Ʊ�ҿ��Ҳ�����\n" NOR);
                return 1;
        default:
                if (ob->query_amount())
                {
                        message_vision("$N��$n����������" + ob->short() + "��\n",
                                        me, obj);
                } else
                {
                        message_vision("$N��$n����������һ" + ob->query("unit") + 
                	               ob->query("name") + "��\n",
			               me, obj);
                }
                ob->move(me, 1);
                obj->add("balance", value * 19 / 20); // ֱ�Ӽ�����
                if (query_ip_number(obj) != query_ip_number(me))
               	 	obj->add("vendor_score", value / 2500);
        }
        me->start_busy(2);
        return 1;
}

object i_have(object env,string name)
{
	int i;
	object *inv;
	object obj;
	if (objectp(obj = present(name,env))) return obj;
	inv=all_inventory(env);
	for(i=0;i<sizeof(inv);i++)
	{
		if (filter_color(inv[i]->query("name"))==name)
		return inv[i];
	}
	return 0;
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

int help (object me)
{
        write(@HELP
ָ���ʽ: buy <��Ʒ> [from <���>]

��һ�����˹�����Ʒ��

���ָ�list

HELP);
	return 1;
}
