// Room: /d/chengdu/wanliqiao.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������������ˣ����ŵĵ�������һ�䡰ǧ��֮��ʼ�����¡���
��˵��ʱ��ʫ�˱����ڴ������˾�ġ��źܿ������Ǻ���������ˣ�
�����ϵ���ʨ��ͷ����һ������ʮ��ͷ֮�ࡣ���±����Ϻӣ�ˮ���峺
���ף�һȺС����ˮ����Ϸ���֡�
LONG	);

	set("outdoors", "chengdu");
	set("exits", ([
		"west" : __DIR__"wangjianglou1",
		"east" : __DIR__"xuetao",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8020);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}



