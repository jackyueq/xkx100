// wield.c
#include <ansi.h>

inherit F_CLEAN_UP;

int do_wield(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if( !arg ) return notify_fail("��Ҫװ��ʲô������\n");

	if(this_player()->query_temp("weapon"))
		return notify_fail("���Ѿ�װ�������ˡ�\n");

	if(arg=="all")
	{
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
			if(this_player()->query_temp("weapon")) break;
			if(do_wield(me, inv[i]) ) count ++;
		}
		write("���ˡ�\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");

	if( ob->query("equipped") )
		return notify_fail("���Ѿ�װ�����ˡ�\n");

	return do_wield(me, ob);
}

int do_wield(object me, object ob)
{
	string str;

	if( ob->wield() )
	{
		if( !stringp(str = ob->query("wield_msg")) )
			str = "$Nװ��$n��������\n";
		str += NOR;
		message_vision(str, me, ob);
		return 1;
	}
	else return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��wield <װ������>
 
���ָ������װ��ĳ����Ʒ�������������Ҫӵ��������Ʒ��
 
HELP
	);
	return 1;
}
