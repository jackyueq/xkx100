// Room: /d/chengdu/chaguan3.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ�����Ű���
��һ���ſ��������˿��ˣ������̸Ц����ͷ�Ӷ���ֻ����ȫ��Щ��
�Ŵ���������֮ͽ����Ҫ������������ƹʺ�ҥ�ԣ������Ǹ������ڡ�
��ҪЩ��ˮ�͵��Ŀ���ЩС����
LONG	);
	set("no_fight",1);
	set("exits", ([
		"north" : __DIR__"dongjie3",
	]));
	set("objects", ([
		__DIR__"npc/boss1" : 1,
	]));
	set("coor/x", -8020);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

