// Room: /d/huangshan/diezhang.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "���ַ�");
	set("long", @LONG
ɽ��ʵ���Ƕ࣬�ഫ��ɽ��ǧ���ٷ壬�ӵ��ַ�������ֻ�����й�
֮������һ��ɽ������Լ��㣬Ⱥ����֣�����һ������������Ⱥ�壬
Ҳ��˵�徿�����ж��٣���ȥ�Ǽ������ߣ�������������ʯ�ף�������
���˱�������ɵ����ɽ���ɹ��֡�
LONG
	);
	set("exits", ([ 
		"southeast" : __DIR__"qingliang",
		"north"     : __DIR__"songgu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
