// /cmds/usr/describe.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *txt;
	
	if( !arg ) return notify_fail("ָ���ʽ��describe <����>\n");
	if( arg == "none" ) 
	{
		me->delete("long");
		write("��ȡ���˶��Լ���������\n");
		return 1;
	}
	if( !wizardp(me) && (int)strlen(arg) > 40 )
	{
		txt = explode(arg,"\n");
		if( sizeof(txt) > 8 )
			return notify_fail("�뽫�����Լ������������ڰ������ڡ�\n");
		arg = implode(txt, "\n") + "\n";
	}

	me->set("long", arg);
	write("�����趨��ϡ�\n");
	return 1;
}

int help()
{
	write(@TEXT
ָ���ʽ��describe <���� | none>

     ���ָ�������趨�������� look ָ���ʱ�������������ͨ
���������������һ��ʱ������ to describe �ķ�ʽ�����롣

TEXT
	);
	return 1;
}
