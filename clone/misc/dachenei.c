// Last Modified by Winder on May. 21 2001
// /clone/misc/dachenei/.c

#include <ansi.h>
inherit ROOM;
 
void create()
{
	set("short", "����");
	set("long",@LONG
����ɸɾ�����������������Ĵ����ӡ����������������������
��϶��͸���������⿴�����ľ��£��е�׳�ۣ��е�Ҳ��Ȥ�����ǻ��
������˯ȥ��Ҳ����·�����˶�á��������һ�����壬���������š�
��������ǰ�棬һ·������һ·����غ���ʲôС����
LONG);   
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_beg", 1);
	set("no_get", 1);
	setup();
	replace_program(ROOM);
}
