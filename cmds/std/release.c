// Filename : /cmds/std/release.c
// Last Modified by winder on Aug. 5 2001

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me)
{
	object *inv;
	int j = 0, i = 0;

	inv = all_inventory(environment(me));
	while( i < sizeof(inv) && i >= 0 )
	{
		if( inv[i]->query_temp("owner") == me->query("id") && //ѱ��
			inv[i]->query("owner") != me->query("id"))    //����
		{
			message_vision("$N�ܴȱ��ذ�$n���룬����ع���Ȼ�ˡ�\n", me, inv[i]);
			inv[i]->delete_temp("owner");
			inv[i]->delete_temp("ownername");
			j=1;
		}
		i++;
	}
	if (j == 0) message_vision("$N�����������ûɶ�ɷŵġ�\n", me);
	
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : release

    ��ָ���������ĳ���������ū״̬����������롣���ﲻ�ܷ�����

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

