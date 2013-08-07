#include <ansi.h>
inherit F_CLEAN_UP;
int color_len(string str);

int main(object me, string arg)
{
        mapping goods;
        string *gks;
        object *obs, obj, env, *inv;
        string msg;
        int i, have_vendor = 0;

        mapping price;
        mapping unit;
        string short_name;
        string prefix;
        string *dk;

        env = environment(me);

	if (! arg)
        {
                inv = all_inventory(env);

                if (! inv)
                        return notify_fail("�뵽bug����������˵����\n");

                msg = HIC "�����������ʱС���У�"
                      HIY "\n����������������������������\n" NOR;
                for (i = 0; i < sizeof(inv); i++)
                {
                        if (userp(inv[i]) && inv[i]->query_temp("on_baitan"))
                        {
                                have_vendor = 1;
                                msg += WHT + inv[i]->name(1) + "���ӻ�̯(" +
                                       inv[i]->query("id") + ")\n";
                        }
                }
                if (! have_vendor)
                        return notify_fail(WHT "Ŀǰ���ﲢû���κΰ�̯�����ˡ�\n" NOR);
                else
                        msg += HIY "����������������������������\n" NOR;
                write(msg);
                return 1;
        }

        if (! (obj = present(arg, env)) || ! userp(obj))
                return notify_fail("���ﲢû��������ˡ�\n");

        if (! obj->query("is_vendor"))
                return notify_fail(obj->name(1) + "���������ˡ�\n");

        if (! obj->query_temp("on_baitan"))
                return notify_fail(obj->name(1) + "Ŀǰ��û���ڰ�̯��\n");

        SHOP_D->reset_goods(obj);

        goods = obj->query("vendor_goods");
        
        if (! sizeof(goods))
                return notify_fail(obj->name(1) + "Ŀǰ��û�ж����κλ��\n");


        unit = ([]);
        price = ([]);

        gks = keys(goods);
        
        for (i = 0; i < sizeof(gks); i++)
        {
                object gob;

                // gob = present(gks[i],obj);
                gob = find_object(gks[i]);
//                if (environment(gob) != obj) continue;
                short_name = gob->name(1) + "(" + gob->query("id") + ")";

                if (gob->query("base_unit"))
                        prefix = "base_";
                else
                        prefix = "";

                unit  += ([ short_name : gob->query(prefix + "unit") ]);
                price += ([ short_name : goods[gks[i]] ]);
        }

        msg = HIC + obj->name(1) + "Ŀǰ����������Ʒ��"
              HIY "\n��������������������������������������������������\n" NOR;
        dk = sort_array(keys(unit), 1);

        for (i = 0; i < sizeof(dk); i++)
        {
                int p;
                p = price[dk[i]];

                msg += sprintf("%" + sprintf("%d", (30 + color_len(dk[i]))) +
                               "-s��ÿ%s%s" CYN "\n" NOR, 
                               dk[i], unit[dk[i]], MONEY_D->price_str(p));
        }
        msg += HIY "��������������������������������������������������\n" NOR;
        write(msg);
        return 1;
}
int color_len(string str)
{
	int i;
	int extra;

	extra = 0;
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] == ESC[0])
		{
			while((extra++, str[i] != 'm') && i < strlen(str))
				i++;
		}
	}
	return extra;
}
int help (object me)
{
        write(@HELP
ָ���ʽ: list [<���ID>]
 
�г�һ���������ڳ��۵���Ʒ��
 
HELP);
        return 1;
}
