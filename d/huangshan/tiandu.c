// Room: /d/huangshan/tiandu.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "�춼��");
	set("long", @LONG
�춼��������������Ϊ�վ���һ�����ųơ�Ⱥ������������Ϊ����
���ᡣ����·��������ɽ��͵�ʯ��������Χ���ĵ�ɽ����������Ȼ��
���С����������족֮�С�;����һʯ���磬���С��������������֣�
�ɴ˴�Զ�������ƹַ壬ɽȪ�ɺ��������۵ס�
LONG
	);
	set("exits", ([ 
		"westdown"  : __DIR__"jiyu",
		"northdown" : __DIR__"yixian",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
