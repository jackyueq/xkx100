// Room: /yangzhou/qiqifang.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","������������");
	set("long",@LONG
�������������ݵ��Ṥ���˽�ǧ�����������ǧ����������������
�쳣���£����������������Ī������һ�׽�ǧ�����������Ϊ������
�ݳ�����̴�������ˮ���������ڼ����������ͽ�ǧ������Щʲô��
���ϵ�һ���ʷ�ģ������ִ�ʼ��š�������Ľ������ƺ�û�����⡣
LONG );
	set("exits", ([
		"south" : __DIR__"dashixijie",
	]));
	set("objects", ([
		__DIR__"npc/jiangqianli" : 1,
	]));
	set("coor/x", 55);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}