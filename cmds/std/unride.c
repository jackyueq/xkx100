// Filename : /cmds/std/unride.c
// Last Modified by winder on Aug. 5 2001

#include <ansi.h>
inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me)
{
	object obj, *inv;
	int i = 0;

	inv = all_inventory(me);
	while( i < sizeof(inv) && i >= 0 )
	{
		if( inv[i]->query_temp("is_rided_by") == me )
		{
			obj = inv[i];
			i = -10;
		}
		i++;
	}
	if( i >= 0 ) return notify_fail("��ʲô�£��������û���\n");
	message_vision("$N��$n�Ϸ������¡�\n", me, obj);
//���¶����������������
	if( !living(obj) || obj->query_temp("noliving"))
		return notify_fail("��������Լ����ε��ˣ���Ҳû�����ˡ�\n");
/*
	if(obj->query("dex"))
		me->delete_temp("apply/dexerity");
	if(obj->query("str"))
		me->delete_temp("apply/strength");
*/
	obj->move( environment(me) );
	obj->delele("is_rided_by");
	me->delete_temp("is_riding");
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : unride
 
    ���ָ�������������ŵ���ѱ���Ķ�������������
 
    �����Ѿ�ѱ���Ķ�����Խ�������ָ�

����ָ�
        come <������>:                  �ö�����������ж���
        stay:                           ֹͣ����ĸ���״̬��
        attack <ĳ��>:                  �ö��﹥�����ˡ�
        stop <������>:                  �ö���ֹͣ���˵Ĺ�����
        release:                        ������ū״̬����������롣

����ָ���ֻ��ĳЩ�������ã�
        ride <������>:                  ���������������ȡ�
        unride <������>:                �£��뿪���
        feed <����> to <������>:        �涯��ιʳ��
        imbibe <������>:                ��������ˮ��

HELP
	);
	return 1;
}

