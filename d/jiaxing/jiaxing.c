// Room: /d/jiaxing/jiaxing.c
// Last Modified by winder on Nov. 17 2000


inherit ROOM;

void create()
{
	set("short", "���˳�");
	set("long", @LONG
�����ǽ������Ǽ��ˡ��Ƕ��Ƿ羰�续���Ϻ����Ǳ�������������
¥������ȫ������֮һ���𴦻��ͽ����߹־���������ԼѰ������֮��
��֪��ʲôԭ���������Ǩ�������ˡ�
LONG );
	set("exits", ([
		"west"  : __DIR__"jnroad2",
		"east"  : __DIR__"nanhu",
		"south" : __DIR__"jxnanmen",
	]));
	set("outdoors", "jiaxing");
	set("no_clean_up", 0);
	set("coor/x", 1500);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}