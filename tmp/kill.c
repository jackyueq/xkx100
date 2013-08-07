// kill.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, hitter;
	string *killer, callname;

	if( environment(me)->query("no_fight") )
	{
		environment(me)->delete("no_fight");
//		return notify_fail("���ﲻ׼ս����\n");
	}
	if(me->is_busy())
		return notify_fail("����һ��������û����ɣ�\n");
	if( !arg )
		return notify_fail("����ɱ˭��\n");
	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
	if( obj->query("no_kill") )
		return notify_fail("����ڣ���Ȼ�µ���������֣�\n");
//
	obj->delete("dietime");
	me->delete("killertime");
//
/*
	if( objectp(hitter = obj->query_temp("last_damage_from")))
	{
		if( hitter->query("id") != me->query("id"))
		{
			if ((obj->query("name") ==
				me->query("family_quest/betrayer/name") ||
			obj->query("name") ==
				me->query("family_quest/thief/name") ||
			obj->query("name") ==
				me->query("quest/shan/quest") ||
			obj->query("name") ==
				me->query("quest/helian/quest")) &&
			(!living(obj) ||obj->query_temp("noliving") ||
				obj->query("qi") < obj->query("max_qi")/2) )
				return notify_fail("��������˵ģ��㲻��ɱ�����������\n");
			else
				message_vision("\n$N����$n�����Ц������"+obj->query("name")+"�����ջ���㵹ù���������������ˣ���������ҾͲ������ˣ���\n\n", me, obj);
		}
	}

	if(me->query("id") != obj->query_temp("bt_ownname") &&
		me->query_temp("bt/working"))
		return notify_fail("����Ϊ���죬ִ�й��񣬿ɲ���ɱ��ð����\n");
*/
	if(obj==me) return notify_fail("�� suicide ָ���ȽϿ�:P��\n");
/*
	if((int)obj->query("age") <= 15 && userp(obj))
		return notify_fail("Ϊ����������ã��Ź�С���Ӱ�.\n");
*/

	callname = RANK_D->query_rude(obj);
	if (random(3) > 1)
		message_vision("\n$N����$n�ȵ�����" + callname + "�����ղ������������һ��\n\n", me, obj);
	else
		message_vision("\n$N����$n�ȵ�����" + callname + "��������վ�����ļ��գ���\n\n", me, obj);

	me->delete("env/combatd");
	obj->delete("env/combatd");

	me->kill_ob(obj);
	if ( userp(obj))
		write_file("/log/static/ATTEMP_KILL", sprintf("%s   ��ͼɱ��   %s on %s\n", me->name(1),obj->name(1), ctime(time()) ));
// Look for PKS 
	if( !userp(obj) ) obj->kill_ob(me);
	else
	{
		obj->fight_ob(me);
		tell_object(obj, HIR "�����Ҫ��" + me->name() + "�����ಫ������Ҳ���������һ�� kill ָ�\n" NOR);
	}

	return 1;
}
int help(object me)
{
	write(@HELP
ָ���ʽ : kill <����>
 
    ���ָ������������ʼ����һ�����������ͼɱ���Է���kill �� fight 
���Ĳ�ͬ���˫�������浶ʵǹ�ش򶷣�Ҳ����˵����������ˡ���� kill 
ֻ�赥����һ����Ը�Ϳ��Գ������������κ���ʹ�� kill ָ��Ὺʼս����
ͨ������Է��� NPC �Ļ�������Ҳ��ͬ������ʹ�� kill��

    �����˶���ʹ�� kill ָ��ʱ����ֺ�ɫ�����������㣬���һ����Ҷ��ԣ�
�����û�ж�һ������ʹ�ù� kill ָ��Ͳ��Ὣ�Է���Ĵ��˻�ɱ��( ʹ��
��������)��

�������ָ��: hit, fight

HELP
	);
	return 1;
}
 

