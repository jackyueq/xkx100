// Room: /d/huangshan/yingke.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "ӭ����");
	set("long", @LONG
�Ӱ�ɽ�¹�����һ������������ԶԶ����Կ���һ����������˫
�ۡ���������ӭԶ�͡��ɸ�ʮ���ף�����ï�ܣ�����ӭ���ɣ���־����
���Ѿ�̤�롰��ɽ�����£������Դ��С�������Ժ�ˡ�
LONG
	);
	set("exits", ([ 
		"southdown" : __DIR__"guanyin",
		"northwest" : __DIR__"yuping",
		"northeast" : __DIR__"wenzhu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
