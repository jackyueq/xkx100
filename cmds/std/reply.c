// reply.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string target, mud;
	object obj;
	object *inv;
	int i;
	string *clist=({});

	if( !arg || arg=="" )
		return notify_fail("��Ҫ�ش�ʲô��\n");
	if (me->query_temp("quest_gift/got") && stringp(me->query_temp("quest_gift/type")))
	{
		inv = all_inventory(environment(me));
		for (i=0;i<sizeof(inv);i++)
		{
			if (inv[i]->is_manager())
				return inv[i]->accept_reply(me,inv[i],arg);
		}
	}
	if( !stringp(target = me->query_temp("reply")) )
		return notify_fail("�ղ�û���˺���˵������\n");

	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(lower_case(mud), lower_case(target), me, arg);
		write("��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");
		return 1;
	}

	obj = find_player(target);
	if(!obj || !me->visible(obj) || obj->query_temp("block_msg/all"))
		return notify_fail("�ղź���˵�����������޷������㣬�����Ѿ��뿪��Ϸ�ˡ�\n");
	if (stringp(obj->query("env/can_tell")))
	clist = explode(obj->query("env/can_tell"),",");
	if (!wizardp(me) && (obj->query("env/no_tell")=="all" || obj->query("env/no_tell")==me->query("id")) 
	&& (!arrayp(clist) || member_array(me->query("id"),clist)==-1))
		return notify_fail("����˲���������������\n");
	write(HIG "��ش�" + obj->name(1) + "��" + arg + "\n" NOR);
	tell_object(obj, sprintf(HIG "%s�ش��㣺%s\n"NOR,
		me->name(1)+"("+me->query("id")+")", arg));
	if (stringp(obj->query("env/auto_reply")) && query_idle(obj)>60)
	tell_object(me,HIW"(�Զ��ظ�)"NOR+obj->name()+"�ش��㣺"+obj->query("env/auto_reply")+"\n");
	message("channel:snp", HIB"��������"+me->query("name")+"�ش�"+obj->query("name")+"��"+arg+"\n"NOR, users());
	obj->set_temp("reply", me->query("id"));
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��reply <ѶϢ>

    ����������ָ��͸ղ��� tell ����˵����ʹ����˵����

see also : tell
HELP
	);
	return 1;
}
