// kickto.c ��ĳ��������

#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string wiz_status, tmpstr;

	if( me!=this_player(1) ) return 0;
	if( !arg )
		return notify_fail("��Ҫ��˭��\n");
	wiz_status=SECURITY_D->get_status(me) ;
//	if (wiz_status != "(admin)" )
//		return notify_fail("��ʲô�ߣ�\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("��... ���������\n");
	if ( !living(ob) || !ob->is_character() || ob==me )
		return notify_fail("ob error!\n");
	message_vision( HIW"\n$Nһ������$n��ƨ���ϣ�$n��ʱһ����ƨ�����ƽɳ����ʽ�������ŷ��˳�ȥ��\n\n"NOR, me,ob);

	tell_object( me, "��� " + ob->query("name") + " �ߵ�����ȥ�ˡ�\n");
	seteuid(getuid(ob));
	me->save();
	seteuid(ROOT_UID);
	ob->move("/d/beijing/jail");
	ob->save();
	seteuid(getuid());
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : kickto <ĳ��>
��    �� : ��ֹĳЩ��ҵ��ҡ�
HELP);
	return 1;
}

